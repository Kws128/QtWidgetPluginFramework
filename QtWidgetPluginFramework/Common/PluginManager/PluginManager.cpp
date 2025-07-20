
#include "PluginManager.h"

PluginManager::PluginManager()
{}
PluginManager::~PluginManager()
{ UnloadAll(); }

PluginErrorCode PluginManager::LoadPlugin(const std::string& path, PluginContext* ctx)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	
	if (m_plugins.find(path) != m_plugins.end())
		return PluginErrorCode::AlreadyLoaded;

	PluginInfo info;
	if (!info.loader.Load(path))
		return PluginErrorCode::LoadLibraryFailed;

	fnCreate create = static_cast<fnCreate>(info.loader.GetSymbol("CreatePlugin"));
	info.destroy    = static_cast<fnDestroy>(info.loader.GetSymbol("DestroyPlugin"));

	if (!create)
		return PluginErrorCode::GetCreateFuncFailed;
	if (!info.destroy)
		return PluginErrorCode::GetDestroyFuncFailed;

	info.instance = create(ctx);
	if (!info.instance)
		return PluginErrorCode::CreatePluginFailed;

	if (!info.instance->Initialize())
	{
		info.destroy(info.instance);
		return PluginErrorCode::InitializeFailed;
	}
	
	info.path = path;

	m_plugins[path] = std::move(info);

	return PluginErrorCode::Success;
}

PluginErrorCode PluginManager::UnLoadPlugin(const std::string& path)
{
	std::lock_guard<std::mutex> lock(m_mutex);

	auto iter = m_plugins.find(path);
	if ( iter == m_plugins.end())
		return PluginErrorCode::Success;

	PluginInfo& info = iter->second;
	
	if (info.instance && !info.instance->Shutdown())
		return PluginErrorCode::ShutdownFailed;

	if (info.destroy && info.instance)
	{
		info.destroy(info.instance);
		info.instance = nullptr;
	}

	m_plugins.erase(iter);

	return PluginErrorCode::Success;
}

PluginErrorCode PluginManager::ReLoadPlugin(const std::string& path, PluginContext* ctx)
{
	auto ret  = UnLoadPlugin(path);
	if ( ret != PluginErrorCode::Success)
		return ret;
	
	std::lock_guard<std::mutex> lock(m_mutex);

	return LoadPlugin(path, ctx);
}

void PluginManager::ExecuteAll()
{
	std::lock_guard<std::mutex> lock(m_mutex);

	for (auto& kv : m_plugins)
	{
		if (!kv.second.instance)
			continue;
		PluginExecuteError err = kv.second.instance->Execute();
		switch (err)
		{
		case PluginExecuteError::Success:
			break;
		case PluginExecuteError::Failed:
			break;
		default:break;
		}		
	}
}

void PluginManager::UnloadAll()
{
	std::lock_guard<std::mutex> lock(m_mutex);
	
	for (auto iter = m_plugins.begin(); iter != m_plugins.end();)
	{
		if (iter->second.instance)
		{
			iter->second.instance->Shutdown();
			if (iter->second.destroy)
				iter->second.destroy(iter->second.instance);
		}
		iter = m_plugins.erase(iter);
	}
}

PluginMeta PluginManager::GetPluginMeta(const std::string& path)
{
	std::lock_guard<std::mutex> lock(m_mutex);

	auto iter = m_plugins.find(path);
	if (iter == m_plugins.end())
		return PluginMeta();
	if (!(iter->second.instance))
		return PluginMeta();

	return iter->second.instance->GetMeta();
}

PluginInfo* PluginManager::GetPluginInfo(const std::string& path)
{
	std::lock_guard<std::mutex> lock(m_mutex);

	auto iter = m_plugins.find(path);	
	if (iter == m_plugins.end())
		return nullptr;

	return &(iter->second);
}

bool PluginManager::IsLoad(const std::string& path)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_plugins.find(path) != m_plugins.end();
}

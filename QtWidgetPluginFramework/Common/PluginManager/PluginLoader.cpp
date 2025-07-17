
#include "PluginLoader.h"

PluginLoader::PluginLoader() : m_hModule(nullptr)
{ }

PluginLoader::PluginLoader(const std::string& path) : m_hModule(nullptr)
{ Load(path); }

PluginLoader::~PluginLoader()
{ UnLoad(); }

PluginLoader::PluginLoader(PluginLoader&& other) noexcept
{
	if (other.m_hModule)
	{
		m_hModule = other.m_hModule;
		other.m_hModule = nullptr;
	}
}

PluginLoader& PluginLoader::operator=(PluginLoader&& other) noexcept
{
	if (this != (&other))
	{
		UnLoad();

		m_hModule = other.m_hModule;
		other.m_hModule = nullptr;
	}
	return *this;
}

bool PluginLoader::Load(const std::string& path)
{
	m_hModule = LoadLibraryA(path.c_str());
	return (m_hModule != nullptr);
}

void PluginLoader::UnLoad()
{
	if (m_hModule) {
		FreeLibrary(m_hModule);
		m_hModule = nullptr;
	}
}

void* PluginLoader::GetSymbol(const std::string& name)
{
	if (!m_hModule) return nullptr;
	return static_cast<void*>(GetProcAddress(m_hModule, name.c_str()));
}
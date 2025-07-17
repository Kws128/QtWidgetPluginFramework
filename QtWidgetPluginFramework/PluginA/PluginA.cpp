
#include "PluginA.h"

PluginA::PluginA() : m_ui(nullptr)
{}

PluginA::~PluginA()
{
	Shutdown();
}

bool PluginA::Initialize()
{
	if (!m_ui)
	{
		m_ui = dynamic_cast<QWidget*>(new PluginAUI);
		if (!m_ui)
			return false;
	}
	return true;
}

PluginExecuteError PluginA::PluginA::Execute()
{
	return PluginExecuteError::Success;
}

bool PluginA::Shutdown()
{
	if (m_ui)
	{
		delete m_ui;
		m_ui = nullptr;
	}
	
	return true;
}

PluginMeta PluginA::GetMeta() const
{
	PluginMeta meta;
	meta.name = "PluginA";
	meta.version = "1.0.0.1";
	meta.path = "";
	meta.description = "";
	meta.author = "Kws128";

	return meta;
}
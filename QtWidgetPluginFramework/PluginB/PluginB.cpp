
#include "PluginB.h"

PluginB::PluginB() : m_ui(nullptr)
{}

PluginB::~PluginB()
{
	Shutdown();
}

bool PluginB::Initialize()
{
	if (!m_ui)
	{
		m_ui = dynamic_cast<QWidget*>(new PluginBUI);
		if (!m_ui)
			return false;
	}

	return true;
}

PluginExecuteError PluginB::PluginB::Execute()
{
	return PluginExecuteError::Success;
}

bool PluginB::Shutdown()
{
	if (m_ui)
	{
		delete m_ui;
		m_ui = nullptr;
	}

	return true;
}

PluginMeta PluginB::GetMeta() const
{
	PluginMeta meta;
	meta.name = "PluginB";
	meta.version = "1.0.0.1";
	meta.path = "";
	meta.description = "";
	meta.author = "Kws128";

	return meta;
}
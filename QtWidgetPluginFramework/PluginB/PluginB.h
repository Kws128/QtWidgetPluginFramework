#pragma once

#include "PluginBUI.h"
#include "pluginb_global.h"
#include "PluginBContext.h"
#include "../Common/PluginManager/QIPlugin.h"

class PluginB : public QIPlugin
{
public:
    PluginB();
	~PluginB();

	bool Initialize() override;
	bool Shutdown() override;
	PluginMeta			GetMeta() const override;
	PluginExecuteError	Execute() override;

	QWidget* GetUI() { return m_ui; }

protected:
	QWidget* m_ui;
};


extern "C" __declspec(dllexport) IPlugin * CreatePlugin(PluginContext * ctx)
{
	PluginBContext* ctx_a = dynamic_cast<PluginBContext*>(ctx);
	return dynamic_cast<IPlugin*>(new PluginB);
}

extern "C" __declspec(dllexport) void DestroyPlugin(IPlugin * p)
{
	if (!p)return;
	delete p; p = nullptr;
}


#pragma once

#include "PluginAUI.h"
#include "plugina_global.h"
#include "PluginAContext.h"
#include "../Common/PluginManager/QIPlugin.h"

class PluginA : public QIPlugin
{
public:
    PluginA();
	~PluginA();

	bool Initialize() override;
	bool Shutdown() override;
	PluginMeta			GetMeta() const override;
	PluginExecuteError	Execute() override;

	QWidget* GetUI() override { return m_ui; }

protected:
	QWidget* m_ui;
};


extern "C" __declspec(dllexport) IPlugin* CreatePlugin(PluginContext* ctx)
{
	PluginAContext* ctx_a = dynamic_cast<PluginAContext*>(ctx);
	return dynamic_cast<IPlugin*>(new PluginA);
}

extern "C" __declspec(dllexport) void DestroyPlugin(IPlugin* p)
{
	if (!p)return;
	delete p; p = nullptr;
}


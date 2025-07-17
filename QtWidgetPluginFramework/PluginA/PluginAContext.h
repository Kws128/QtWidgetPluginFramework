
#pragma once
#include <QtWidgets/QWidget>
#include "../Common/PluginManager/PluginContext.h"

class PluginAContext : public PluginContext
{
public:
	QWidget* parent;

	PluginAContext() : parent(nullptr) { }
};

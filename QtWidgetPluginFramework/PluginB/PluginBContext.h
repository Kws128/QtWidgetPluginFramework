
#pragma once

#include <QtWidgets/QWidget>
#include "../Common/PluginManager/PluginContext.h"

class PluginBContext : public PluginContext
{
public:
	QWidget* parent;

	PluginBContext() : parent(nullptr) { }
};

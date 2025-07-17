#pragma once

#include <QtWidgets/QWidget>
#include "ui_PluginBUI.h"

class PluginBUI : public QWidget
{
	Q_OBJECT

public:
	PluginBUI(QWidget *parent = nullptr);
	~PluginBUI();

private:
	Ui::PluginBUIClass ui;
};


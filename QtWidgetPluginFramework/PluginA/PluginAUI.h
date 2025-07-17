#pragma once

#include <QWidget>
#include "ui_PluginAUI.h"

class PluginAUI : public QWidget
{
	Q_OBJECT

public:
	PluginAUI(QWidget *parent = nullptr);
	~PluginAUI();

private:
	Ui::PluginAUIClass ui;
};


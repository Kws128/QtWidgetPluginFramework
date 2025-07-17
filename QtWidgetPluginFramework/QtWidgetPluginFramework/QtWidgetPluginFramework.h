#pragma once

#include <QLibrary>
#include "BasicWidget.h"
#include "../Common/PluginManager/QIPlugin.h"
#include "../Common/PluginManager/PluginManager.h"
#include "../PluginA/PluginAContext.h"
#include "../PluginB/PluginBContext.h"
#include "ui_QtWidgetPluginFramework.h"

class QtWidgetPluginFramework : public BasicWidget
{
    Q_OBJECT

public:
    QtWidgetPluginFramework(QWidget *parent = nullptr);
    ~QtWidgetPluginFramework();

protected:
    void Init();
    void ShowPlugin(std::string path);
    std::string nameToPath(std::string name);

protected slots:
    void on_btnPluginA_clicked();
    void on_btnPluginB_clicked();

private:
    Ui::QtWidgetPluginFrameworkClass ui;
    PluginManager*  m_pluginManager;
	QWidget*        m_currentWidget;
};


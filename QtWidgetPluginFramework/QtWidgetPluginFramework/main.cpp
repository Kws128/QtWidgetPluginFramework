#include "QtWidgetPluginFramework.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QtWidgetPluginFramework window;
    window.show();
    return app.exec();
}

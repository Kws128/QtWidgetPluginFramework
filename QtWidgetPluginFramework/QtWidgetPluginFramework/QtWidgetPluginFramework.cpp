#include "QtWidgetPluginFramework.h"

QtWidgetPluginFramework::QtWidgetPluginFramework(QWidget *parent)
    : BasicWidget(parent)
    , m_pluginManager(nullptr)
    , m_currentWidget(nullptr)
{
    ui.setupUi(this);
    Init();
}

QtWidgetPluginFramework::~QtWidgetPluginFramework()
{
    if (m_pluginManager)
    {
        delete m_pluginManager;
        m_pluginManager = nullptr;
    }
}

void QtWidgetPluginFramework::Init()
{
	ui.workspace->setLayout(new QGridLayout);

	setWindowIcon(QIcon(":/MaterialManager/res/main.png"));
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground, true);

	connect(ui.btnMin, &QPushButton::clicked, [&]() {showMinimized(); });
	connect(ui.btnClose, &QPushButton::clicked, [&]() {close(); });
	connect(ui.btnMax, &QPushButton::clicked, [&]() {
			isMaximized() ? ui.btnMax->setIcon(QIcon(QString::fromUtf8(":/QtWidgetPluginFramework/res/maxsize.png"))) : ui.btnMax->setIcon(QIcon(QString::fromUtf8(":/QtWidgetPluginFramework/res/maxsize-2.png")));
			isMaximized() ? showNormal() : showMaximized(); });

    m_pluginManager = new PluginManager;

	PluginAContext ctx_a;
	PluginAContext ctx_b;
	if (PluginErrorCode::Success != m_pluginManager->LoadPlugin(nameToPath("PluginA.dll"), &ctx_a))
		return;
	if (PluginErrorCode::Success != m_pluginManager->LoadPlugin(nameToPath("PluginB.dll"), &ctx_b))
		return;

	ShowPlugin(nameToPath("PluginA.dll"));

}

void QtWidgetPluginFramework::ShowPlugin(std::string path)
{
	PluginInfo* pInfo = m_pluginManager->GetPluginInfo(path);
	if (!pInfo)return;
	if (!pInfo->instance)return;

	QIPlugin* pa = dynamic_cast<QIPlugin*>(pInfo->instance);
	if (!pa)return;

	QWidget* w = pa->GetUI();
	if (!w)return;

	if (m_currentWidget)
	{
		if (!m_currentWidget->close())
			return;
	}

	ui.workspace->layout()->addWidget(w);
	w->show();
	m_currentWidget = w;
}

std::string QtWidgetPluginFramework::nameToPath(std::string name)
{
	QString dirPath = QApplication::applicationDirPath();
	QString dllPath = QString("%1/%2").arg(dirPath).arg(name.c_str());
	return dllPath.toStdString();
}

void QtWidgetPluginFramework::on_btnPluginA_clicked()
{
    ShowPlugin(nameToPath("PluginA.dll"));
}

void QtWidgetPluginFramework::on_btnPluginB_clicked()
{
    ShowPlugin(nameToPath("PluginB.dll"));
}

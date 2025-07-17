#pragma once

#include <QWidget>
#include <QMouseEvent>

class BasicWidget : public QWidget
{
public:
	explicit BasicWidget(QWidget* parent = nullptr);
	virtual ~BasicWidget();

protected:
	virtual void mousePressEvent(QMouseEvent* event)Q_DECL_OVERRIDE;
	virtual void mouseReleaseEvent(QMouseEvent* event)Q_DECL_OVERRIDE;
	virtual void mouseMoveEvent(QMouseEvent* event)Q_DECL_OVERRIDE;

private:
	bool    m_bPress = false;
	QPoint  m_point = QPoint(0, 0);

};

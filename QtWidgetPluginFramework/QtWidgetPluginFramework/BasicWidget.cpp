#include "BasicWidget.h"

BasicWidget::BasicWidget(QWidget* parent) : QWidget(parent)
{
	setWindowFlags(Qt::FramelessWindowHint);
}

BasicWidget::~BasicWidget()
{}

void BasicWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_point = event->globalPos();
		m_bPress = true;
	}
	event->ignore();
}

void BasicWidget::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
		m_bPress = false;
	event->ignore();
}

void BasicWidget::mouseMoveEvent(QMouseEvent* event)
{
	if (m_bPress)
	{
		QPoint movePos = event->globalPos();
		move(pos() + movePos - m_point);
		m_point = movePos;
	}
	event->ignore();
}
#include <clock_widget.h>

#include <QPainter>
#include <QTime>
#include <iostream>

Clock::Clock(QWidget* parent)
	: QWidget(parent)
	, _hours(0)
	, _minutes(0)
	, _seconds(0)
{
	setMinimumSize(100,100);
	startTimer(1000);
}

void Clock::timerEvent(QTimerEvent*)
{
	QTime t  = QTime::currentTime();
	_hours   = t.hour();
	_minutes = t.minute();
	_seconds = t.second();
	update();
}


void drawArrow(QPainter& p)
{
	p.drawLine(0,0,  0,10);
	p.drawLine(0,10,-3, 7);
	p.drawLine(0,10, 3, 7);
}

void Clock::paintEvent(QPaintEvent*)
{
	QPainter p(this);
	QPoint center(width()/2, height()/2);
	p.translate(center);

	// seconds
	p.save();
	p.rotate(_seconds * 6);
	p.scale(10,10);
	p.setPen(Qt::blue);
	drawArrow(p);
	p.restore();
}


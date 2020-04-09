#pragma once
#include <QGraphicsItem>

class border:public QGraphicsItem
{
	QGraphicsLineItem *topBorder;
	QGraphicsLineItem *bottomBorder;
	QGraphicsLineItem *rightBorder;
	QGraphicsLineItem *leftBorder;
};


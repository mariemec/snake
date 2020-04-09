#pragma once
#include <QGraphicsTextItem>
#include <QString>
#include <QFont>

class Message:public QGraphicsTextItem
{

public:
	Message();
private:
	QFont font;
};


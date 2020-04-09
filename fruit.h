#include <QGraphicsRectItem>
#include <QPen>
#include "defines.h"

class Fruit : public QGraphicsRectItem {
public:
	Fruit();
	void randomizeFruit();
	void changeColor();
	int getX() { return fruitX; };
	int getY() { return fruitY; };

private:
	int fruitX, fruitY;
};
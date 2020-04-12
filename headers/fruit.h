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
	void setX(int x) { fruitX = x; };
	void setY(int y) { fruitY = y; };

private:
	int fruitX, fruitY;
};
#include <QGraphicsRectItem>
#include "defines.h"

class Fruit : public QGraphicsRectItem {
public:
	Fruit();
	void randomizeFruit();
	int getX() { return fruitX; };
	int getY() { return fruitY; };

private:
	int fruitX, fruitY;

};
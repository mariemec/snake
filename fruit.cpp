#include "fruit.h"


Fruit::Fruit() {
	setRect(0, 0, DOTSIZE, DOTSIZE);
	randomizeFruit();
	setPos(fruitX, fruitY);

	setBrush(Qt::red);
}

void Fruit::randomizeFruit() {
	fruitX = (qrand() % (WIDTH/DOTSIZE))*DOTSIZE;
	fruitY = (qrand() % (WIDTH/DOTSIZE))*DOTSIZE;
}

void Fruit::changeColor() {
	setBrush(Qt::darkGreen);
}

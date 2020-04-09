#include "fruit.h"

Fruit::Fruit() {
	setRect(0, 0, DOTSIZE, DOTSIZE);
	randomizeFruit();
	setPos(fruitX, fruitY);
}

void Fruit::randomizeFruit() {
	fruitX = (qrand() % (WIDTH/DOTSIZE))*DOTSIZE;
	fruitY = (qrand() % (WIDTH/DOTSIZE))*DOTSIZE;
}
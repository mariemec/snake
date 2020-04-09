#include "snake.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>

#include <QDebug>

Snake::Snake() {
	setPos(WIDTH/2, HEIGHT/2);
	headX = x(); 
	headY = y();
	gameOver = 0; //GAME NOT STARTED
	
	QTimer *timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(checkCollision()));
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));
	timer->start(100);
}

void Snake::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_S) {								//S to start
		scene()->addItem(fruit);
		qDebug() << fruit->getX() << ", " << fruit->getY();
		gameOver = 1; //GAME STARTED
	}
	else if (event->key() == Qt::Key_Left && right == false) {
		up = false; down = false; left = true; right = false;
	}
	else if (event->key() == Qt::Key_Right && left == false) {
		up = false; down = false; left = false; right = true;
	}

	else if (event->key() == Qt::Key_Up && down==false) {
		up = true; down = false; left = false; right = false;
	}

	else if (event->key() == Qt::Key_Down && up==false) {
		up = false; down = true; left = false; right = false;
	}

	else if (event->key() == Qt::Key_Escape) {						//PAUSE
		gameOver = 3;
		qDebug() << headX << " " << headY;
	}
}

void Snake::growSnake()
{
	qDebug() << "SNAKE SHOULD GROW!";
	sizeOfSnake++;
	generateFruit();
}

void Snake::generateFruit() {
	newFruit = new Fruit;
	//for (int i = 0; i < sizeOfSnake; i++) {
	//	if (newFruit->pos() == snake[i]->pos())
	//		newFruit->randomizeFruit();
	//}

	scene()->addItem(newFruit);
	snake.push_back(fruit);
	fruit = newFruit;
}

void Snake::checkCollision()
{
	//qDebug() << x() << ", " << y();

	if (y() < 0) {						//TOP WALL
		qDebug() << "top wall hit";
		gameOver = 3;
	}

	if (y() > (HEIGHT - DOTSIZE) ){		//BOTTOM WALL
		qDebug() << "bottom wall hit";
		gameOver = 3;
	}

	if (x() < 0) {						//LEFT WALL
		qDebug() << "left wall hit";
		gameOver = 3;
	}

	if (x() > WIDTH - DOTSIZE) {		//RIGHT WALL
		qDebug() << "right wall hit";
		gameOver = 3;
	}

	if (x() == fruit->getX() && y() == fruit->getY()) {			//FRUIT
		growSnake();
	}

	for (int i = 0; i < snake.size(); i++) {		//COLLISION WITH ITSELF
		if (headX == snake[i]->x() && headY == snake[i]->y()) {
			qDebug() << "Same column";
			gameOver == 3;
		}
	}
}

void Snake::move() {
	if (gameOver == 3) {
		scene()->clear();
	}
	else if (up) {
		setPos(x(), y() - DOTSIZE); updateCoord();
	}
	else if (down) {
		setPos(x(), y() + DOTSIZE); updateCoord();
	}
	else if (left) {
		setPos(x() - DOTSIZE, y()); updateCoord();
	}
	else if (right) {
		setPos(x() + DOTSIZE, y()); updateCoord();
	}
	else if (gameOver) {
		setPos(x(), y());
	}
}

void Snake::updateCoord() {
	for (int i = sizeOfSnake-1; i >=0; i--) {
		if (i != 0)
			snake[i]->setPos(snake[i - 1]->pos());
		else
			snake[i]->setPos(headX, headY);
	}
	headX = x();
	headY = y();

}
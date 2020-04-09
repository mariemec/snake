#include "snake.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QLabel>
#include <QString>
#include <QFont>

#include <QDebug>

Snake::Snake() {

	init();
	connect(timer, SIGNAL(timeout()), this, SLOT(checkCollision()));
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->start(100);
}

void Snake::init() {
	setPos(WIDTH / 2, HEIGHT / 2);
	headX = x();
	headY = y();
	sizeOfSnake = 0;

	gameOver = 0; //GAME NOT STARTED
	clicked = false;
	up = false;
	down = false;
	right = false;
	left = false;

	QString startmsg("Press 'ENTER' to start game. Use arrow keys to move.");
	start = new QGraphicsTextItem(startmsg, this);
	start->adjustSize();
	start->setPos(-WIDTH/2, -HEIGHT/2);
	setBrush(Qt::darkGreen);
}

void Snake::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Return) {						//Enter to start
		setFocus();
		scene()->addItem(fruit);
		qDebug() << fruit->getX() << ", " << fruit->getY();
		gameOver = 1; //GAME STARTED
	}
	if (gameOver == 1 && clicked == false) {
		if (event->key() == Qt::Key_Left && right == false) {
			up = false; down = false; left = true; right = false; clicked = true;
		}
		else if (event->key() == Qt::Key_Right && left == false) {
			up = false; down = false; left = false; right = true; clicked = true;
		}

		else if (event->key() == Qt::Key_Up && down == false) {
			up = true; down = false; left = false; right = false; clicked = true;
		}

		else if (event->key() == Qt::Key_Down && up == false) {
			up = false; down = true; left = false; right = false; clicked = true;
		}
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
	for (int i = 0; i < body.size(); i++) {
		if (newFruit->pos() == body[i]->pos()) {
			newFruit->randomizeFruit();
			newFruit->setPos(newFruit->getX(), newFruit->getY());
		}
	}
	scene()->addItem(newFruit);
	body.push_back(fruit);
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
		fruit->changeColor();
		growSnake();
	}

	if (body.empty() == false) {
		qDebug() << "Head: " << x() << ", " << y();
		qDebug() << body.size();
		for (int i = 0; i < body.size()-1; i++) {		//COLLISION WITH ITSELF
			if (x() == body[i]->x() && y() == body[i]->y()) {
				gameOver = 3;
			}
			qDebug() << body[i]->x() << ", " << body[i]->y();
		}

	}

}

void Snake::move() {
	if (gameOver == 1) {
		if (up) {
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
		clicked = false;
	}

	else if (gameOver==3) {		//Game Over
		qDebug() << "Game over";
	}
}

void Snake::updateCoord() {
	for (int i = sizeOfSnake-1; i >=0; i--) {
		if (i != 0)
			body[i]->setPos(body[i - 1]->pos());
		else
			body[i]->setPos(headX, headY);
	}
	headX = x();
	headY = y();
}

void Snake::update() {
	if (gameOver == 0 && startMsgVisible == false) {
		startMsgVisible = true;
	}
	if (gameOver == 1) {
		if (startMsgVisible == true) {
			scene()->removeItem(start);
			startMsgVisible = false;
		}
		//UPDATE SCORE
	}

	if (gameOver == 3) {
		//SHOW GAME OVER
		timer->stop();
	}
}
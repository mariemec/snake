#include "Game.h"
#include <QDebug>

Game::Game()
{
	scene = new QGraphicsScene();
	snake = new Snake();
	borders = new QGraphicsRectItem;
	viewGame = new QGraphicsView(scene);
	goToMenu = new QPushButton("&Menu");
	setItems();
	addToScene();
	viewGame->setWindowTitle("Snake - P13: In game");
	connect(goToMenu, SIGNAL(clicked()), viewGame, SLOT(close()));
}

void Game::setItems()
{
	snake->setRect(0, 0, DOTSIZE, DOTSIZE);
	borders->setRect(0, 0, WIDTH, HEIGHT);
	snake->setFlag(QGraphicsItem::ItemIsFocusable);
	snake->setFocus();
	viewGame->setFixedSize(WIDTH + 3 * DOTSIZE, HEIGHT + 3 * DOTSIZE); //Adjust the size of the window
	viewGame->setSceneRect(0, 0, WIDTH, HEIGHT); //Adjust the size of the HxW scene/game area with the (0,0) of the view
	viewGame->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	viewGame->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	goToMenu->setGeometry(QRect(WIDTH - buttonSizeW, HEIGHT+10, buttonSizeW, buttonSizeH));
}

void Game::addToScene()
{
	scene->addItem(borders);
	scene->addItem(snake);
	scene->addWidget(goToMenu);
}

void Game::show()
{
	viewGame->show();
}



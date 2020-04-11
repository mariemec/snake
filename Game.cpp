#include "Game.h"

Game::Game()
{
	scene = new QGraphicsScene();
	snake = new Snake();
	borders = new QGraphicsRectItem;
	viewGame = new QGraphicsView(scene);
	setItems();
	addToScene();

}

void Game::setItems()
{
	snake->setRect(0, 0, DOTSIZE, DOTSIZE);
	borders->setRect(0, 0, WIDTH, HEIGHT);
	snake->setFlag(QGraphicsItem::ItemIsFocusable);
	snake->setFocus();
	viewGame->setFixedSize(WIDTH + 2 * DOTSIZE, HEIGHT + 2 * DOTSIZE); //Adjust the size of the window
	viewGame->setSceneRect(0, 0, WIDTH, HEIGHT); //Adjust the size of the HxW scene/game area with the (0,0) of the view
	viewGame->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	viewGame->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void Game::addToScene()
{
	scene->addItem(borders);
	scene->addItem(snake);
}

void Game::show()
{
	viewGame->show();
}

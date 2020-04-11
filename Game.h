#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "snake.h"

class Game
{
	QGraphicsScene *scene;
	Snake *snake;
	QGraphicsRectItem *borders;
	QGraphicsView *viewGame;


public:
	Game();
	void setItems();
	void addToScene();
	void show();
	Snake* getSnake() { return snake; }
};


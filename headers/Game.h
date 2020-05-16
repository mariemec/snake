#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QPushButton>
#include <QObject>
#include "snake.h"

class Game: public QObject
{
	Q_OBJECT
	QGraphicsScene *scene;
	Snake *snake;
	QGraphicsRectItem *borders;
	QGraphicsView *viewGame;
	QPushButton *goToMenu;


public:
	Game();
	void setItems();
	void addToScene();
	void show();
	Snake* getSnake() { return snake; }
};


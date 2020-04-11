#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include <QGraphicsTextItem>
#include <QString>
#include "defines.h"
#include "Game.h"
#include "HighScores.h"

class Menu: public QObject
{
	Q_OBJECT
	QGraphicsScene *sceneMenu;
	QPushButton *play;
	QPushButton *highScoresbtn;
	QPushButton *Quit;
	QGraphicsPixmapItem *howTo;
	QGraphicsPixmapItem *title;
	QGraphicsView *viewMenu;
	int buttonSizeW;
	int buttonSizeH;
	Game* game;
	

public:
	Menu();
	void setItems();
	void addToScene();
	void show();
	QGraphicsScene* getScene() { return sceneMenu; }

public slots:
	void playGame();
	void highScores();

};


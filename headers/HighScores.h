#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QString>
#include <QPushButton>
#include <QObject>
#include "defines.h"

class HighScores: public QObject
{
	Q_OBJECT
	int* Score;
	QGraphicsScene *scene;
	QGraphicsView *view;
	QPushButton *goToMenu;
	
public:
	HighScores(int* s);
	void highScores();
	void SetScene();
	void show();
};


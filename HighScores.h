#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QString>
#include <string>
#include "defines.h"

class HighScores
{
	int* Score;
	QGraphicsScene *scene;
	QGraphicsView *view;
	
	
public:
	HighScores(int* s);
	void highScores();
	void SetScene();
	void show();
};


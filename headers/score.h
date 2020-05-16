#pragma once
#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem
{
public:
	Score(QGraphicsItem *parent = 0);
	void increase();
	void gameOver();
	int getScore() { return score; };
private:
	int score;
};


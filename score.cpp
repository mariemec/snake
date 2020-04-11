#include <QFont>
#include "score.h"
#include "defines.h"

Score::Score(QGraphicsItem *parent)
{
	score = 0;
	setPlainText(QString("Score: ") + QString::number(score));
	setFont(QFont("Helvetica", 25));
}

void Score::increase()
{
	score++;
	setPlainText(QString("Score: ") + QString::number(score));
}

void Score::gameOver()
{
	setPlainText(QString("GAME OVER!\n Your score: ") + QString::number(score));

}

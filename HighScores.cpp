#include "HighScores.h"
#include <QDebug>



HighScores::HighScores(int* s)
{
	Score = s;
	scene = new QGraphicsScene();
	view = new QGraphicsView(scene);
	goToMenu = new QPushButton("&Menu");
	goToMenu->setGeometry(QRect(WIDTH - buttonSizeW, HEIGHT + 10, buttonSizeW, buttonSizeH));
	highScores();
	SetScene();
	connect(goToMenu, SIGNAL(clicked()), view, SLOT(close()));
}


void HighScores::highScores()
{

	QString s("HIGHEST SCORES :");
	QGraphicsTextItem* text = new QGraphicsTextItem(s);
	text->setTextWidth(500);
	text->setFont(QFont("Helvetica", 31));
	qDebug() << text->textWidth();
	text->setPos(WIDTH / 2-(text->textWidth()/2), ((HEIGHT / 12)*0)+100);
	scene->addItem(text);
	for (int i = 0; i < 10; i++)
	{
		
		QGraphicsTextItem* text = new QGraphicsTextItem(QString("#") + QString::number(i+1) + QString(" : ") + QString::number(Score[i]));
		text->setTextWidth(100);
		text->setFont(QFont("Helvetica", 10));
		text->setPos(WIDTH / 2-50, (((HEIGHT / 12)*(i+2))-(i*30)+100));
		scene->addItem(text);
	}
}

void HighScores::SetScene()
{
	view->setFixedSize(WIDTH + 2 * DOTSIZE, HEIGHT + 2 * DOTSIZE); //Adjust the size of the window
	view->setSceneRect(0, 0, WIDTH, HEIGHT); //Adjust the size of the HxW scene/game area with the (0,0) of the view
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scene->addWidget(goToMenu);
}

void HighScores::show()
{
	view->show();
}

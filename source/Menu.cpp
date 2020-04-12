#include "Menu.h"


Menu::Menu()
{
	sceneMenu = new QGraphicsScene();
	play = new QPushButton("&Play");
	highScoresbtn = new QPushButton("&Highscores");
	Quit = new QPushButton("&Quit");
	howTo = new QGraphicsPixmapItem();
	viewMenu = new QGraphicsView(sceneMenu);
	game = new Game();
	setItems();
	addToScene();
	viewMenu->setWindowTitle("Snake - P13");
	connect(play, SIGNAL(clicked()), this, SLOT(playGame()));
	connect(highScoresbtn, SIGNAL(clicked()), this, SLOT(highScores()));
	connect(Quit, SIGNAL(clicked()), viewMenu, SLOT(close()));
}


void Menu::setItems()
{
	play->setGeometry(QRect(((WIDTH / 4) * 1) - buttonSizeW / 2, ((HEIGHT / 4) * 3) - buttonSizeH / 2, buttonSizeW, buttonSizeH));
	highScoresbtn->setGeometry(QRect(((WIDTH / 4) * 2) - buttonSizeW / 2, ((HEIGHT / 4) * 3) - buttonSizeH / 2, buttonSizeW, buttonSizeH));
	Quit->setGeometry(QRect(((WIDTH / 4) * 3) - buttonSizeW / 2, ((HEIGHT / 4) * 3) - buttonSizeH / 2, buttonSizeW, buttonSizeH));
	howTo->setPixmap(QPixmap("./Images/HowTo.png").scaled(buttonSizeW*2 + WIDTH / 2, HEIGHT / 2, Qt::IgnoreAspectRatio));
	howTo->setPos(WIDTH / 2 - (buttonSizeW*2 + WIDTH / 2) / 2, HEIGHT / 2 - HEIGHT / 3);
	viewMenu->setFixedSize(WIDTH + 2 * DOTSIZE, HEIGHT + 2 * DOTSIZE); //Adjust the size of the window
	viewMenu->setSceneRect(0, 0, WIDTH, HEIGHT); //Adjust the size of the HxW scene/game area with the (0,0) of the view
	viewMenu->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	viewMenu->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void Menu::addToScene()
{
	sceneMenu->addItem(howTo);
	sceneMenu->addWidget(play);
	sceneMenu->addWidget(highScoresbtn);
	sceneMenu->addWidget(Quit);
}

void Menu::show()
{
	viewMenu->show();
}

void Menu::highScores()
{
	int score[10];
	game->getSnake()->sortScore();
	for (int i = 0; i < 10; i++)
	{	
		score[i] = game->getSnake()->Scores[i];
	}
	HighScores* high = new HighScores(score);
	high->show();
}

void Menu::playGame()
{
	game->show();   
	game = new Game();
}


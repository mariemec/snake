#include "./headers/snake.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QLabel>
#include <QString>
#include <QFont>
#include <fstream>

#include <QDebug>

// Constructor connects the QTimer with the snake's slots (check for collisions, move the snake, update score)
Snake::Snake() {

	init();
	connect(timer, SIGNAL(timeout()), this, SLOT(checkCollision()));
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->start(100);
}

// Initialize the game layout (snake rectangle, fruit rectangle, score label, start instructions)
void Snake::init() {
	setPos(WIDTH / 2, HEIGHT / 2);
	fruit->setX(WIDTH / 2);
	fruit->setY(HEIGHT / 4);
	fruit->setPos(fruit->getX(), fruit->getY());
	headX = x();
	headY = y();
	sizeOfSnake = 0;

	gameOver = 0; //GAME NOT STARTED
	clicked = false;
	up = false;
	down = false;
	right = false;
	left = false;

	QString startmsg("To begin: CLICK on the GREEN SNAKE. Then, press 'ENTER'. Use arrow keys to move.");
	start = new QGraphicsTextItem(startmsg, this);
	start->adjustSize();
	start->setPos(-WIDTH/2, -HEIGHT/2);

	score->setPos(0, 0);
	
	setBrush(Qt::darkGreen);
}

// Checks for key presses, Enter to start the game, change direction depending on arrow key, 
void Snake::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Return) {						//Enter to start
		scene()->addItem(fruit);
		gameOver = 1; //GAME STARTED
	}
	if (gameOver == 1 && clicked == false) {
		if (event->key() == Qt::Key_Left && right == false) {
			up = false; down = false; left = true; right = false; clicked = true;
		}
		else if (event->key() == Qt::Key_Right && left == false) {
			up = false; down = false; left = false; right = true; clicked = true;
		}

		else if (event->key() == Qt::Key_Up && down == false) {
			up = true; down = false; left = false; right = false; clicked = true;
		}

		else if (event->key() == Qt::Key_Down && up == false) {
			up = false; down = true; left = false; right = false; clicked = true;
		}
	}
}

//Grows the snake by 1, generates a new fruit
void Snake::growSnake()
{
	sizeOfSnake = sizeOfSnake+1;
	score->increase();
	generateFruit();
}

// Puts current fruit in body of the snake (turns it to color green), generates a new Fruit object and checks that its position is not on the body of the snake
void Snake::generateFruit() {
	newFruit = new Fruit;
	for (int i = 0; i < body.size(); i++) {
		if (newFruit->pos() == body[i]->pos()) {
			newFruit->randomizeFruit();
			newFruit->setPos(newFruit->getX(), newFruit->getY());
		}
	}
	scene()->addItem(newFruit);
	body.push_back(fruit);
	fruit = newFruit;
	fruit->setZValue(-1);
}

// Checks the position of the snake's head, if collision occurs-> GAME OVER. if collision with fruit -> GrowSnake, increase Score.
void Snake::checkCollision()
{
	if (y() < 0) {						//TOP WALL
		qDebug() << "top wall hit";
		gameOver = 3;
	}

	if (y() > (HEIGHT - DOTSIZE) ){		//BOTTOM WALL
		qDebug() << "bottom wall hit";
		gameOver = 3;
	}

	if (x() < 0) {						//LEFT WALL
		qDebug() << "left wall hit";
		gameOver = 3;
	}

	if (x() > WIDTH - DOTSIZE) {		//RIGHT WALL
		qDebug() << "right wall hit";
		gameOver = 3;
	}

	if (body.empty() == false) {
		for (int i = 0; i < body.size()-1; i++) {		//COLLISION WITH ITSELF
			if (x() == body[i]->x() && y() == body[i]->y()) {
				gameOver = 3;
			}
		}
	}

	if (x() == fruit->getX() && y() == fruit->getY()) {		//COLLISION WITH FRUIT
		fruit->changeColor();
		growSnake();
	}
}

// Moves the Snake's head's position in the scene depending on current direction
void Snake::move() {
	if (gameOver == 1) {
		if (up) {
			setPos(x(), y() - DOTSIZE); updateCoord();
		}
		else if (down) {
			setPos(x(), y() + DOTSIZE); updateCoord();
		}
		else if (left) {
			setPos(x() - DOTSIZE, y()); updateCoord();
		}
		else if (right) {
			setPos(x() + DOTSIZE, y()); updateCoord();
		}
		clicked = false;
	}

}

// Moves the rest of the Snake's body depending on direction
void Snake::updateCoord() {
	for (int i = sizeOfSnake-1; i >=0; i--) {
		if (i != 0)
			body[i]->setPos(body[i - 1]->pos());
		else
			body[i]->setPos(headX, headY);
	}
	headX = x();
	headY = y();
}

// Updates the items on the scene depending on state of gameOver (0: Game Not started, 1: Game Started, 3: Game over)
void Snake::update() {
	if (gameOver == 0 && startMsgVisible == false) {
		startMsgVisible = true;
	}

	if (gameOver == 1) {
		if (startMsgVisible == true) {
			scene()->removeItem(start);
			startMsgVisible = false;
		}

		//UPDATE SCORE
		if (scoreVisible == false){
			score->setPos(0, HEIGHT);
			scene()->addItem(score);
			scoreVisible = true;
		}
	}

	if (gameOver == 3) {
		//SHOW GAME OVER
		timer->stop();
		saveScore();
		setBrush(Qt::NoBrush);
		setPen(Qt::NoPen);
		for (int i = 0; i < sizeOfSnake; i++) {
			body[i]->setBrush(Qt::NoBrush);
			body[i]->setPen(Qt::NoPen);
		}
		score->gameOver();
		score->setZValue(1);
		score->setPos(WIDTH / 2-150, HEIGHT / 2-100);
	}
}


// saveScore() and sortScore() handles the highscores.txt file
void Snake::saveScore()
{
	sortScore();
	bool isDejaRemplace = false; //pour pas remplacer plein de fois la valeur la plus basse si il y en a plusieur ex: dans la .txt les trois pires highscore son 2
	fstream file;
	file.open("highscore.txt", ios::out);

	for (int j = 0; j < 10; ++j) {

		if (Scores[j] == valueMin && !isDejaRemplace)//si la valeur de score est la plus petite il va la remplacer avec la nouveau highscore
		{
			isDejaRemplace = true;
			if (sizeOfSnake > valueMin)//si le nouveau highscore est plus petit, il laisse la valeur minimal precedente
				Scores[j] = sizeOfSnake;
		}

		if (j == 9)//ajoute un point virgule à la fin du fichier .txt
			file << Scores[j] << ";";
		else//met des virgule en chaque score dans le .txt
			file << Scores[j] << ",";
	}
	file.close();
}

void Snake::sortScore()
{
	fstream file;
	string temp;

	file.open("highscore.txt", ios::in);//ouvre le fichier .txt pour avoir les highscore precedent

	getline(file, temp, ';');//prend tout le fichier .txt jusqu'a la fin (un point virgule)


	int cpt = 0;//valeur incrementer à chaque insertion dans le tableau de scores
	for (int i = 0; i < temp.length(); ++i) {
		if (temp.at(i) != ',')// si n'est pas une virgule -> est un chiffre
		{
			Scores[cpt] = stoi(temp.substr(i), nullptr, 10);//prend le chiffre
			cpt++;
			if (i < temp.length() - 1)//si le chiffre à deux décimal, il incremente i de un pour pas qu'il reprenne le meme chiffre apres
			{
				if (temp.at(i + 1) != ',')
				{
					i++;
				}
			}
			if (i < temp.length() - 2)//si le chiffre à trois décimal, il incremente i de deux pour pas qu'il reprenne le meme chiffre apres
			{
				if (temp.at(i + 1) != ',')
				{
					i++;
				}
			}

		}
	}
	int max = -1;//initialise max à -1 pour pas que quand le tableau soit remplit de 0 il y ai une erreur d'index_out_of_bound
	int indmax;//indince à laquelle la valeur mac à ete trouver
	int ScoreTemp[10];//tableaupour stocker temporairement le score
	for (int k = 0; k < 10; ++k)//boucle pour trier les score en ordre de grosseur
	{
		for (int j = 0; j < 10; ++j) {
			if (Scores[j] > max)//si le score est plus gros que max max devient le score
			{
				max = Scores[j];
				indmax = j;
			}
		}
		ScoreTemp[k] = Scores[indmax];//met le socre en ordre dans le tableau temporaire
		Scores[indmax] = 0;
		max = 0;
	}
	for (int l = 0; l < 10; ++l) //remettre le tableau temporaire dans le vrai tableau
	{

		Scores[l] = ScoreTemp[l];
	}
	valueMin = Scores[9];//savoir quelle valeur est la plus petite pour pouvoir la rmeplacer plus tard si on fait un meilleure score
}
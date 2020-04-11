#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QObject>
#include <QTimer>
#include <QLabel>
#include <QLCDNumber>
#include <vector>
#include "score.h"
#include "fruit.h"


using namespace std;

class Snake : public QObject, public QGraphicsRectItem {
	Q_OBJECT
public:
	Snake();
	void init();
	void keyPressEvent(QKeyEvent *event);
	void growSnake();
	void generateFruit();
	void updateCoord();
	void saveScore();
	void sortScore();
	int Scores[10];

private slots:
	void move();
	void checkCollision();
	void update();

private:
	QTimer *timer = new QTimer();
	Fruit *fruit = new Fruit();
	Fruit *newFruit;

	int headX;
	int headY;
	vector <Fruit*> body;

	int sizeOfSnake;
	int valueMin;
	

	int gameOver; //0 : not started, 1:started, 3:Over
	bool up;
	bool down;
	bool right;
	bool left;
	bool clicked;

	bool startMsgVisible = false;
	bool scoreVisible = false;
	QGraphicsTextItem *start;
	Score *score = new Score();
};
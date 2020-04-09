#include <QGraphicsRectItem>
#include <QObject>
#include "fruit.h"
#include <vector>

using namespace std;

class Snake : public QObject, public QGraphicsRectItem {
	Q_OBJECT
public:
	Snake();
	void keyPressEvent(QKeyEvent *event);
	void growSnake();
	void generateFruit();
	void updateCoord();

private slots:
	void move();
	void checkCollision();

private:
	Fruit *fruit = new Fruit();
	Fruit *newFruit;
	int headX;
	int headY;
	vector <Fruit*> snake;

	int sizeOfSnake = 0;

	int gameOver; //0 : not started, 1:started, 3:Over
	bool up = false;
	bool down = false;
	bool right = false;
	bool left = false;
};
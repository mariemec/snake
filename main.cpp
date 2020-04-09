#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <snake.h>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	//Create a scene
	QGraphicsScene *scene = new QGraphicsScene();

	//Create an item
	Snake *snake = new Snake();
	snake->setRect(0, 0, DOTSIZE, DOTSIZE);

	//Create outline of game
	QGraphicsRectItem *borders = new QGraphicsRectItem;
	borders->setRect(0, 0, WIDTH,HEIGHT);

	//Add the item to the scene
	scene->addItem(borders);
	scene->addItem(snake);

	//Make item focusable (only focused item will respond to keypress)
	snake->setFlag(QGraphicsItem::ItemIsFocusable);
	snake->setFocus();

	//Add a view, to see the scene
	QGraphicsView *view = new QGraphicsView(scene); //scene as a parameter is the same thing as writing a separate line: view->setScene(scene);
	view->setFixedSize(WIDTH+2*DOTSIZE, HEIGHT+2*DOTSIZE); //Adjust the size of the window
	view->setSceneRect(0, 0, WIDTH, HEIGHT); //Adjust the size of the HxW scene/game area with the (0,0) of the view
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->show();

	return app.exec();
}

#include <QApplication>
#include "Menu.h"
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	Menu menu;
	menu.show();

	
	app.exec();
}

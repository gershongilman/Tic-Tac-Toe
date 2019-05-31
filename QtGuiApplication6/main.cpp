#include "makinggrid.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	logic logic;
	makinggrid w(&logic);
	w.show();
	return a.exec();
}

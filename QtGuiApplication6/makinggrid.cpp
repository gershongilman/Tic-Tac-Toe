#include "makinggrid.h"
#include <QtGui>
#include <QLayoutItem>

makinggrid::makinggrid(logic *loc) :
	button9(new QPushButton("Reset/New Game"))
{
	setWindowTitle("Tic-Tac Toe");
	closeButton = new QPushButton("End Game");
//	button9 = new QPushButton("Reset/New Game");
	mainLayout = new QGridLayout;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			QPushButton *button = new QPushButton("_");
			mainLayout->addWidget(button, i, j, 1, 1);
			connect(button, &QPushButton::clicked, this, [=]() {this->checkClick(i, j,loc); });
			connect(button9.get(), &QPushButton::clicked, this, [=]() {this->reset(loc, button); });
		}
	}
	
	
	QObject::connect(closeButton, SIGNAL(clicked()), this, SLOT(exit()));
	mainLayout->addWidget(closeButton, 3, 0, 1, 1);
	mainLayout->addWidget(button9.get(), 3, 1, 1, 2);
	setLayout(mainLayout);

}

void makinggrid::checkClick(int i, int j, logic *loc) {
	QLayoutItem *layoutItem = mainLayout->itemAtPosition(i, j);
	QWidget *widget = layoutItem->widget();
	QPushButton *butclick = dynamic_cast<QPushButton*>(widget);
	if (loc->legal(i, j)) {
		if (firstClick) {
			firstClick = false;
			butclick->setText("O");
			lastCol = i;
			lastRow = j;
			loc->move(lastRow, lastCol, 1);
		}
		else {
			firstClick = true;
			butclick->setText("X");
			lastCol = i;
			lastRow = j;
			loc->move(lastRow, lastCol, 2);
		}
	}
	if (loc->gameFinished()) {
		setWindowTitle("YAY");
	}

}


void makinggrid::reset(logic* loc, QPushButton *button) {
	loc->reset();
	button->setText("_");
	setWindowTitle("Tic-Tac Toe");
}
	

void makinggrid::exit() {
	makinggrid::close();
}
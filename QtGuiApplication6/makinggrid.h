#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_makinggrid.h"
#include<QPushButton>
#include<QGridLayout>
#include <QtGui>
#include<QDialog>
#include <vector>
#include <memory>
#include <QLayoutItem>
#include <logic.h>
#ifndef MYWINDOW_H
#define MYWINDOW_H
using namespace std;

class makinggrid:public QDialog {
	Q_OBJECT

public:
	makinggrid(logic *logic);
	
private slots:
	void checkClick(int i, int j,logic *loc);
	void reset(logic *loc, QPushButton *button);
	void exit();

private:
	unique_ptr<QPushButton> button9;
	QPushButton *closeButton;
	QGridLayout *mainLayout;
	bool firstClick = true;
	int lastRow;
	int lastCol;
	logic *loc;
	
};
#endif // MYWINDOW_H

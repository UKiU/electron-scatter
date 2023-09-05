#pragma once

#include <QWidget>
#include "ui_Data.h"

class Data : public QWidget
{
	Q_OBJECT

public:
	Data(QWidget *parent = nullptr);
	~Data();
	
	double clkd, clhd, gkjmd, cyzgs, hyzgs, oyzgs;
	int clxh, cllx;

	Ui::DataClass ui;


private slots:
	int onclxh();
	int oncllx();
	double onclkd();
	double onclhd();
	double ongkjmd();
	int oncyzgs();
	int onhyzgs();
	int onoyzgs();
};

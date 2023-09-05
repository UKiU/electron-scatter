#pragma once

#include <QWidget>
#include "ui_Drawpic.h"
#include<QtCharts>
using namespace QtCharts;
class Drawpic : public QWidget
{
	Q_OBJECT

public:
	Drawpic(QWidget *parent = nullptr);
	~Drawpic();

	Ui::DrawpicClass ui;
	//void createChart(QLineSeries* series, const char* axis, double X);
private:

};

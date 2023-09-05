#pragma once

#include <QtWidgets/QMainWindow>
#include <QtDataVisualization>
#include <QtCharts>
#include "ui_Initial.h"
#include "Data.h"
#include"Pictures.h"
#include"Drawpic.h"
using namespace	QtDataVisualization;
using namespace QtCharts;
using namespace std;

class Initial : public QMainWindow
{
    Q_OBJECT

public:
    Initial(QWidget *parent = nullptr);
    ~Initial();

private:
    Ui::InitialClass ui;

	Data* datawin;
	Pictures* picwin;
	double dzsrsnl, dzsbj;
	int N, NS;
	int sstype;
	//创建Q3DScatter三维散点图类对象
	Q3DScatter scatter;
	QLineSeries* lineseriesr,* lineseriesz;


	void createChart(QLineSeries* series, const char* axis,double* X);

private slots:
	void onlrwb();
	void onsjlr();

	double ondzsrsnl();
	double ondzsbj();
	int ondzgs();
	int onclcs();
	int onsstype();

	void onstart();
	void onszsj();

	void on3d();
	void onz();
	void onr();
};

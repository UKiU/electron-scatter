#include "Initial.h"
#include "confirm.h"
#include "lrqd.h"
#include "Drawpic.h"
#include "ui_Data.h"
#include"ui_Pictures.h"

#include"formula.h"
#include"eupdate.h"

#include<vector>
#include <QtDataVisualization>
#include <QtCharts>
#include<qchartview.h>

using namespace QtCharts;
using namespace	QtDataVisualization;
using namespace std;

substrate* Subtest1=NULL;
vector<epos>* eline=NULL;
double* zxy = new double[2];
double *rxy=new double[2];
Initial::Initial(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);


	datawin = new Data(this);
	datawin->setWindowFlags(Qt::Window);
	picwin = new Pictures(this);
	picwin->setWindowFlags(Qt::Window);

	dzsrsnl = 10, dzsbj = 20;
	N = 1000, NS = 2;
	sstype = 0;
	connect(ui.dzsrsnl, SIGNAL(currentIndexChanged(int)), this, SLOT(ondzsrsnl()));
	connect(ui.dzsbj, SIGNAL(currentIndexChanged(int)), this, SLOT(ondzsbj()));
	connect(ui.dzgs, SIGNAL(currentIndexChanged(int)), this, SLOT(ondzgs()));
	connect(ui.clcs, SIGNAL(currentIndexChanged(int)), this, SLOT(onclcs()));
	connect(ui.sstype, SIGNAL(currentIndexChanged(int)), this, SLOT(onsstype()));

	connect(ui.dzsrsnl, SIGNAL(editTextChanged(const QString)), this, SLOT(ondzsrsnl()));
	connect(ui.dzsbj, SIGNAL(editTextChanged(const QString)), this, SLOT(ondzsbj()));
	connect(ui.dzgs, SIGNAL(editTextChanged(const QString)), this, SLOT(ondzgs()));
	connect(ui.clcs, SIGNAL(editTextChanged(const QString)), this, SLOT(onclcs()));
	connect(ui.sstype, SIGNAL(editTextChanged(const QString)), this, SLOT(onsstype()));


	connect(ui.dzsrsnl, SIGNAL(activated(int)), this, SLOT(ondzsrsnl()));
	connect(ui.dzsbj, SIGNAL(activated(int)), this, SLOT(ondzsbj()));
	connect(ui.dzgs, SIGNAL(activated(int)), this, SLOT(ondzgs()));
	connect(ui.clcs, SIGNAL(activated(int)), this, SLOT(onclcs()));
	connect(ui.sstype, SIGNAL(activated(int)), this, SLOT(onsstype()));

	connect(ui.szsj, SIGNAL(clicked(bool)), this, SLOT(onszsj()));
	connect(ui.start, SIGNAL(clicked(bool)), this, SLOT(onstart()));

	connect(datawin->ui.sjlr, SIGNAL(clicked(bool)), this, SLOT(onsjlr()));
	connect(datawin->ui.lrwb, SIGNAL(clicked(bool)), this, SLOT(onlrwb()));
	
	connect(picwin->ui.pic3d, SIGNAL(clicked(bool)), this, SLOT(on3d()));
	connect(picwin->ui.picz, SIGNAL(clicked(bool)), this, SLOT(onz()));
	connect(picwin->ui.picr, SIGNAL(clicked(bool)), this, SLOT(onr()));

}

int Initial::ondzgs() {
	int index = ui.dzgs->currentIndex();
	QString temp_gs = ui.dzgs->currentText();
	N = temp_gs.toInt();
	return N;
}
int Initial::onclcs() {
	int index = ui.clcs->currentIndex();
	QString temp = ui.clcs->currentText();
	NS = temp.toInt();
	return NS;
}
double Initial::ondzsrsnl() {
	int index = ui.dzsrsnl->currentIndex();
	QString temp = ui.dzsrsnl->currentText();
	dzsrsnl = temp.toDouble();

	return dzsrsnl;
}
double Initial::ondzsbj() {
	int index = ui.dzsbj->currentIndex();
	QString temp = ui.dzsbj->currentText();
	dzsbj = temp.toDouble();

	return dzsbj;
}
int Initial::onsstype() {
	int index = ui.sstype->currentIndex();
	QString temp = ui.sstype->currentText();
	sstype = index;

	return sstype;
}

void Initial::onszsj() {
	//初始化材料
	ondzgs();
	onclcs();
	ondzsrsnl();
	ondzsbj();
	Subtest1 = new substrate[NS];//模拟__层材料：
	datawin->show();
}

void Initial::onlrwb() {
	
	datawin->close();
}
void Initial::onsjlr() {
	

	Subtest1[datawin->clxh].type = datawin->cllx;
	switch (Subtest1[datawin->clxh].type)
	{
		//PMMA
	case 0:
	{
		subinitialize(Subtest1[datawin->clxh], datawin->cllx, datawin->clkd, datawin->clhd, datawin->gkjmd, datawin->cyzgs, datawin->hyzgs, datawin->oyzgs);
		break;
	}
	//Si
	case 1:
	{
		subinitialize(datawin->clkd, datawin->clhd, 2.33e-21, 28, 14, 0.822, 172.25, Subtest1[datawin->clxh]);
		break;
	}
	//Al
	case 2:
	{
		subinitialize(datawin->clkd, datawin->clhd, 2.7e-21, 27, 13, 0.815, 163, Subtest1[datawin->clxh]);
		break;
	}
	
	//Ni
	case 3:
	{
		subinitialize(datawin->clkd, datawin->clhd, 8.9e-21, 58.69, 28, 0.83, 304.499, Subtest1[datawin->clxh]);
		break;
	}
	//Fe
	case 4:
	{

		subinitialize(datawin->clkd, datawin->clhd, 7.86e-21, 56, 26, 0.83, 285.422, Subtest1[datawin->clxh]);
		break;
	}
	//Cu
	case 5:
	{

		subinitialize(datawin->clkd, datawin->clhd, 8.96e-21, 63.546, 29, 0.83, 314.051, Subtest1[datawin->clxh]);
		break;
	}
	//Ag
	case 6:
	{
	
		subinitialize(datawin->clkd, datawin->clhd, 10.53e-21, 108, 47, 0.852, 487, Subtest1[datawin->clxh]);
		break;
	}
	//Au
	case 7:
	{

		subinitialize(datawin->clkd, datawin->clhd, 19.32e-21, 197, 79, 0.851, 796.675, Subtest1[datawin->clxh]);
		break;
	}
	//SiO2
	case 8:
	{
	
		subinitialize(datawin->clkd, datawin->clhd, 2.2e-21, 20, 10, 0.82, 115, Subtest1[datawin->clxh]);
		break;
	}
	default:break;
	}
	
	lrqd qd(this);
	qd.show();
	qd.exec();
}

void Initial::createChart(QLineSeries* series,const char* axis,double* X) {
	QChart* linechart = new QChart();
	linechart->setTitle("Energy Deposition");
	linechart->addSeries(series);

	QChartView* chartView = new QChartView(linechart);//QChartView 可以一步到位直接显示QChart
	chartView->setRenderHint(QPainter::Antialiasing);//继承来的抗锯齿方法
	chartView->setChart(linechart); //chart添加到chartView
	//QChartView* chartview = new QChartView();
	//this->setCentralWidget(chartview);
	//chartview->setRenderHint(QPainter::Antialiasing);//抗锯齿
	//
	//创建坐标轴
	QValueAxis* axisX = new QValueAxis();
	axisX->setTitleText(axis);//标题
	axisX->setRange(0, X[0]);
	QValueAxis* axisY = new QValueAxis();
	axisY->setRange(-X[1], X[1]); //设置坐标轴范围
	axisY->setTitleText("dE/dS (kev/nm/electron)");//标题
	linechart->setAxisX(axisX, series);
	linechart->setAxisY(axisY, series);
	
	chartView->resize(400, 300);
	chartView->show();
}

void Initial::on3d() {
	scatter.show();//绘制3d散点图
}
void Initial::onz() {
	createChart(lineseriesz, "depth",zxy);
}
void Initial::onr() {
	createChart(lineseriesr, "redius",rxy);
}

void Initial::onstart() {


	/*确认数值*/
	confirm con(this);
	con.gkj = QString::fromLocal8Bit("材料层数；") + QString::number(NS) + "\n";
	for(int m=0;m<NS;m++){
		con.gkj += QString::fromLocal8Bit("第") + QString::number(m) + QString::fromLocal8Bit("层材料") + "\n"
			+ QString::fromLocal8Bit("材料宽度；") + QString::number(Subtest1[m].width)+"nm" + "\n"
			+ QString::fromLocal8Bit("材料厚度；") + QString::number(Subtest1[m].length)+"nm" + "\n"
			+ QString::fromLocal8Bit("材料密度；") + QString::number(Subtest1[m].density)+"g/nm^3" + "\n";
	}

		/*+ QString::fromLocal8Bit("光刻胶厚度；") + QString::number(gkjhd) + "\n" +
		QString::fromLocal8Bit("光刻胶密度；") + QString::number(gkjmd);
	double yzl = (double)((12 * cyzgs + hyzgs + 16 * oyzgs) / (cyzgs + hyzgs + oyzgs)),
		yzxs = (double)((6 * cyzgs + hyzgs + 8 * oyzgs) / (cyzgs + hyzgs + oyzgs));*/

	//con.fzs = QString::fromLocal8Bit("光刻胶分子式：")
	//	+ "C" + QString::number(cyzgs) + "H" + QString::number(hyzgs) + "O" + QString::number(oyzgs) + "\n"
	//	+ QString::fromLocal8Bit("平均原子量：") + QString::number(yzl) + "\n"
	//	+ QString::fromLocal8Bit("平均原子序数：") + QString::number(yzxs);
	con.dzs = QString::fromLocal8Bit("电子束入射能量：") + QString::number(dzsrsnl)+"kev" + "\n"
		+ QString::fromLocal8Bit("电子束半径：") + QString::number(dzsbj) + "nm"+"\n"
		+ QString::fromLocal8Bit("模拟电子个数：") + QString::number(N)+"\n"
		+ QString::fromLocal8Bit("散射角公式：")+ QString::number(sstype) +"\n"
		+ QString::fromLocal8Bit("截面模型；卢瑟福模型");;
	con.showtext();
	int ret = con.exec();

	if (ret == QDialog::Accepted) {
		//设置三维面
		scatter.setFlags(scatter.flags() ^ Qt::FramelessWindowHint);
		//新建序列和数据
		QScatter3DSeries* series = new QScatter3DSeries;
		QScatterDataArray data;
		
		
		/*电子模拟*/
		srand((unsigned)time(NULL));
		epos EP;
		epos temp;

		/*"本次模拟N个电子轨迹："*/
		eline = new vector<epos>[N];
		
		
		int i = 0,j = 0;
		
		for (i = 0; i < NS; i++)
		{
			for (j = 0; j < i; j++)
			{
				Subtest1[i].length += Subtest1[j].length;
			}
		}


		//初始化电子束
		einitialize(EP, Subtest1[0], dzsrsnl,sstype);
		
		//颜色渐变
		QLinearGradient gr;
		QColor tempcolor;

		for (i = 0; i < N; i++)
		{
			//初始化电子入射位置
			XYinitialize(EP, dzsbj);
			data << QVector3D(EP.coordinate[0],EP.coordinate[2],EP.coordinate[1]);
			
			eline[i].push_back(EP);
			for (j = 0; j < NS; j++)
			{
				while ((eline[i].back().E > 0.05))
				{
					eupdate(eline[i], Subtest1[j], temp,sstype);
					if (outofrange(eline[i].back(), Subtest1[j]))
					{
						break;
					}
					else {
						data << QVector3D(eline[i].back().coordinate[0], eline[i].back().coordinate[2], eline[i].back().coordinate[1]);
					}
				}
				if ((eline[i].back().flag == 1) && (j < NS - 1))
				{
					BoundryDeal(eline[i], Subtest1[j], Subtest1[j + 1], temp,sstype);
					data << QVector3D(eline[i].back().coordinate[0], eline[i].back().coordinate[2], eline[i].back().coordinate[1]);
				}
			}
		}

		for (int m = 0; m < NS - 1; ++m) {
			for (int mm = 0; mm < 600; mm += 10) {
				//for (int mmm = 0; mmm < 600; mmm += 10) {
					data << QVector3D(mm - 300, Subtest1[m].length,300) << QVector3D(-300, Subtest1[m].length, mm - 300);
				//}
			}
		}

		
		for (int m = 0; m < eline[0].size(); m+=10) {
			double ttemp=eline[0][m].E / dzsrsnl;
			tempcolor.setRgb((int)(ttemp * 255), 0,(int)((1 - ttemp) * 255), 255);
			gr.setColorAt((1-eline[0][m].coordinate[2]/Subtest1[NS-1].length), tempcolor);

		}

						
		scatter.axisX()->setTitle("axis X");
		scatter.axisX()->setTitleVisible(true);
		scatter.axisX()->setRange(-Subtest1[0].width,Subtest1[0].width);
		
		scatter.axisY()->setTitle("axis Z");
		scatter.axisY()->setTitleVisible(true);
		scatter.axisY()->setReversed(true);
		scatter.axisY()->setRange(0,Subtest1[NS-1].length);
		
		scatter.axisZ()->setTitle("axis Y");
		scatter.axisZ()->setTitleVisible(true);
		scatter.axisZ()->setRange(-Subtest1[0].width, Subtest1[0].width);
		scatter.activeTheme()->setLabelBackgroundEnabled(false);
		series->setItemSize(0.05);
		series->dataProxy()->addItems(data);//输入3d图散点数集
		
		series->setBaseGradient(gr);
		series->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
		
		scatter.addSeries(series);
		scatter.resize(500, 300);

		
		//deposit* chartz;//能量沉积图
		//lineseriesz = new QLineSeries();//图表的数据集
		//vertical(eline, N, Subtest1, NS, chartz, lineseriesz,zxy);
		//lineseriesz->setName("variation curve");

		//lineseriesr = new QLineSeries();
		//deposit* chartr;
		//horizontal(eline, N, Subtest1, NS, chartr, lineseriesr,rxy);
		//lineseriesr->setName("variation curve");
		
		int ave1=avescatter(eline,N);
		double ave2=avedepth(eline, N);
		
		picwin->average += QString::fromLocal8Bit("平均散射次数：") + QString::number(ave1) + "\n"
			+ QString::fromLocal8Bit("平均入射深度：") + QString::number(ave2) + "\n";
		picwin->ui.ave->insertPlainText(picwin->average);
		picwin->show();

		for (int i = 0; i < N; i++)
			ClearVector(eline[i]);
		delete[] eline;
		delete[] Subtest1;
	}


}


Initial::~Initial()
{
	delete[]zxy;
	delete[]rxy;
}

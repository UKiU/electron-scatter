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
	//��ʼ������
	ondzgs();
	onclcs();
	ondzsrsnl();
	ondzsbj();
	Subtest1 = new substrate[NS];//ģ��__����ϣ�
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

	QChartView* chartView = new QChartView(linechart);//QChartView ����һ����λֱ����ʾQChart
	chartView->setRenderHint(QPainter::Antialiasing);//�̳����Ŀ���ݷ���
	chartView->setChart(linechart); //chart��ӵ�chartView
	//QChartView* chartview = new QChartView();
	//this->setCentralWidget(chartview);
	//chartview->setRenderHint(QPainter::Antialiasing);//�����
	//
	//����������
	QValueAxis* axisX = new QValueAxis();
	axisX->setTitleText(axis);//����
	axisX->setRange(0, X[0]);
	QValueAxis* axisY = new QValueAxis();
	axisY->setRange(-X[1], X[1]); //���������᷶Χ
	axisY->setTitleText("dE/dS (kev/nm/electron)");//����
	linechart->setAxisX(axisX, series);
	linechart->setAxisY(axisY, series);
	
	chartView->resize(400, 300);
	chartView->show();
}

void Initial::on3d() {
	scatter.show();//����3dɢ��ͼ
}
void Initial::onz() {
	createChart(lineseriesz, "depth",zxy);
}
void Initial::onr() {
	createChart(lineseriesr, "redius",rxy);
}

void Initial::onstart() {


	/*ȷ����ֵ*/
	confirm con(this);
	con.gkj = QString::fromLocal8Bit("���ϲ�����") + QString::number(NS) + "\n";
	for(int m=0;m<NS;m++){
		con.gkj += QString::fromLocal8Bit("��") + QString::number(m) + QString::fromLocal8Bit("�����") + "\n"
			+ QString::fromLocal8Bit("���Ͽ�ȣ�") + QString::number(Subtest1[m].width)+"nm" + "\n"
			+ QString::fromLocal8Bit("���Ϻ�ȣ�") + QString::number(Subtest1[m].length)+"nm" + "\n"
			+ QString::fromLocal8Bit("�����ܶȣ�") + QString::number(Subtest1[m].density)+"g/nm^3" + "\n";
	}

		/*+ QString::fromLocal8Bit("��̽���ȣ�") + QString::number(gkjhd) + "\n" +
		QString::fromLocal8Bit("��̽��ܶȣ�") + QString::number(gkjmd);
	double yzl = (double)((12 * cyzgs + hyzgs + 16 * oyzgs) / (cyzgs + hyzgs + oyzgs)),
		yzxs = (double)((6 * cyzgs + hyzgs + 8 * oyzgs) / (cyzgs + hyzgs + oyzgs));*/

	//con.fzs = QString::fromLocal8Bit("��̽�����ʽ��")
	//	+ "C" + QString::number(cyzgs) + "H" + QString::number(hyzgs) + "O" + QString::number(oyzgs) + "\n"
	//	+ QString::fromLocal8Bit("ƽ��ԭ������") + QString::number(yzl) + "\n"
	//	+ QString::fromLocal8Bit("ƽ��ԭ��������") + QString::number(yzxs);
	con.dzs = QString::fromLocal8Bit("����������������") + QString::number(dzsrsnl)+"kev" + "\n"
		+ QString::fromLocal8Bit("�������뾶��") + QString::number(dzsbj) + "nm"+"\n"
		+ QString::fromLocal8Bit("ģ����Ӹ�����") + QString::number(N)+"\n"
		+ QString::fromLocal8Bit("ɢ��ǹ�ʽ��")+ QString::number(sstype) +"\n"
		+ QString::fromLocal8Bit("����ģ�ͣ�¬ɪ��ģ��");;
	con.showtext();
	int ret = con.exec();

	if (ret == QDialog::Accepted) {
		//������ά��
		scatter.setFlags(scatter.flags() ^ Qt::FramelessWindowHint);
		//�½����к�����
		QScatter3DSeries* series = new QScatter3DSeries;
		QScatterDataArray data;
		
		
		/*����ģ��*/
		srand((unsigned)time(NULL));
		epos EP;
		epos temp;

		/*"����ģ��N�����ӹ켣��"*/
		eline = new vector<epos>[N];
		
		
		int i = 0,j = 0;
		
		for (i = 0; i < NS; i++)
		{
			for (j = 0; j < i; j++)
			{
				Subtest1[i].length += Subtest1[j].length;
			}
		}


		//��ʼ��������
		einitialize(EP, Subtest1[0], dzsrsnl,sstype);
		
		//��ɫ����
		QLinearGradient gr;
		QColor tempcolor;

		for (i = 0; i < N; i++)
		{
			//��ʼ����������λ��
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
		series->dataProxy()->addItems(data);//����3dͼɢ������
		
		series->setBaseGradient(gr);
		series->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
		
		scatter.addSeries(series);
		scatter.resize(500, 300);

		
		//deposit* chartz;//��������ͼ
		//lineseriesz = new QLineSeries();//ͼ������ݼ�
		//vertical(eline, N, Subtest1, NS, chartz, lineseriesz,zxy);
		//lineseriesz->setName("variation curve");

		//lineseriesr = new QLineSeries();
		//deposit* chartr;
		//horizontal(eline, N, Subtest1, NS, chartr, lineseriesr,rxy);
		//lineseriesr->setName("variation curve");
		
		int ave1=avescatter(eline,N);
		double ave2=avedepth(eline, N);
		
		picwin->average += QString::fromLocal8Bit("ƽ��ɢ�������") + QString::number(ave1) + "\n"
			+ QString::fromLocal8Bit("ƽ��������ȣ�") + QString::number(ave2) + "\n";
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

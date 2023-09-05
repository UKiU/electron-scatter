#include "Data.h"

Data::Data(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	clkd = 300, clhd = 1000, gkjmd = 1.2e-21, cyzgs = 5, hyzgs = 8, oyzgs = 2;
	clxh = 0, cllx = 0;


	connect(ui.clkd, SIGNAL(currentIndexChanged(int)), this, SLOT(onclkd()));
	connect(ui.clhd, SIGNAL(currentIndexChanged(int)), this, SLOT(onclhd()));
	connect(ui.clxh, SIGNAL(currentIndexChanged(int)), this, SLOT(onclxh()));
	connect(ui.cllx, SIGNAL(currentIndexChanged(int)), this, SLOT(oncllx()));
	
	connect(ui.gkjmd, SIGNAL(currentIndexChanged(int)), this, SLOT(ongkjmd()));
	connect(ui.oyzgs, SIGNAL(currentIndexChanged(int)), this, SLOT(onoyzgs()));
	connect(ui.cyzgs, SIGNAL(currentIndexChanged(int)), this, SLOT(oncyzgs()));
	connect(ui.hyzgs, SIGNAL(currentIndexChanged(int)), this, SLOT(onhyzgs()));

	connect(ui.clhd, SIGNAL(activated(int)), this, SLOT(onclhd()));
	connect(ui.clxh, SIGNAL(activated(int)), this, SLOT(onclxh()));
	connect(ui.cllx, SIGNAL(activated(int)), this, SLOT(oncllx()));
	connect(ui.clkd, SIGNAL(activated(int)), this, SLOT(onclkd()));

	connect(ui.gkjmd, SIGNAL(activated(int)), this, SLOT(ongkjmd()));
	connect(ui.oyzgs, SIGNAL(activated(int)), this, SLOT(onoyzgs()));
	connect(ui.cyzgs, SIGNAL(activated(int)), this, SLOT(oncyzgs()));
	connect(ui.hyzgs, SIGNAL(activated(int)), this, SLOT(onhyzgs()));


	connect(ui.clkd, SIGNAL(editTextChanged(const QString)), this, SLOT(onclkd()));
	connect(ui.clhd, SIGNAL(editTextChanged(const QString)), this, SLOT(onclhd()));
	connect(ui.clxh, SIGNAL(editTextChanged(const QString)), this, SLOT(onclxh()));
	connect(ui.cllx, SIGNAL(editTextChanged(const QString)), this, SLOT(oncllx()));
	
	connect(ui.gkjmd, SIGNAL(editTextChanged(const QString)), this, SLOT(ongkjmd()));
	connect(ui.oyzgs, SIGNAL(editTextChanged(const QString)), this, SLOT(onoyzgs()));
	connect(ui.cyzgs, SIGNAL(editTextChanged(const QString)), this, SLOT(oncyzgs()));
	connect(ui.hyzgs, SIGNAL(editTextChanged(const QString)), this, SLOT(onhyzgs()));

}
double Data::onclkd() {
	int index = ui.clkd->currentIndex();
	QString temp_kd = ui.clkd->currentText();
	clkd = temp_kd.toDouble();

	return clkd;
}
double Data::onclhd() {
	int index = ui.clhd->currentIndex();
	QString temp_hd = ui.clhd->currentText();
	clhd = temp_hd.toDouble();

	return clhd;
}
double Data::ongkjmd() {
	int index = ui.gkjmd->currentIndex();
	QString temp_md = ui.gkjmd->currentText();
	gkjmd = temp_md.toDouble();

	return gkjmd;
}
int Data::oncyzgs() {
	int index = ui.cyzgs->currentIndex();
	QString temp = ui.cyzgs->currentText();
	cyzgs = temp.toInt();

	return cyzgs;
}
int Data::onhyzgs() {
	int index = ui.hyzgs->currentIndex();
	QString temp = ui.hyzgs->currentText();
	hyzgs = temp.toInt();

	return hyzgs;
}
int Data::onoyzgs() {
	int index = ui.oyzgs->currentIndex();
	QString temp = ui.oyzgs->currentText();
	oyzgs = temp.toInt();

	return oyzgs;
}
int Data::onclxh() {
	int index = ui.clxh->currentIndex();
	QString temp = ui.clxh->currentText();
	clxh = temp.toInt();

	return clxh;
}
int Data::oncllx() {
	int index = ui.cllx->currentIndex();
	QString temp = ui.cllx->currentText();
	cllx = index;

	return cllx;
}

Data::~Data()
{}


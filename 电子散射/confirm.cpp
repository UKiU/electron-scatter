#include "confirm.h"

confirm::confirm(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.confirm1, SIGNAL(clicked(bool)), this, SLOT(onconfirm1()));
	connect(ui.confirm2, SIGNAL(clicked(bool)), this, SLOT(onconfirm2()));
}

void confirm::showtext() {
	ui.confirmtext->insertPlainText(gkj + "\n");
	//ui.confirmtext->insertPlainText(fzs + "\n");
	ui.confirmtext->insertPlainText(dzs + "\n");
}
void confirm::onconfirm1() {
	accept();
}
void confirm::onconfirm2() {
	reject();
}
confirm::~confirm()
{}

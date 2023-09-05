#include "lrqd.h"

lrqd::lrqd(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.qd, SIGNAL(clicked(bool)), this, SLOT(qd()));
}

void lrqd::qd() {
	accept();
}

lrqd::~lrqd()
{}

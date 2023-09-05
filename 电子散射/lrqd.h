#pragma once

#include <QDialog>
#include "ui_lrqd.h"

class lrqd : public QDialog
{
	Q_OBJECT

public:
	lrqd(QWidget *parent = nullptr);
	~lrqd();

private:
	Ui::lrqdClass ui;
private slots:
	void qd();
};

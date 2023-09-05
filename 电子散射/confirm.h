#pragma once

#include <QDialog>
#include "ui_confirm.h"

class confirm : public QDialog
{
	Q_OBJECT

public:
	confirm(QWidget *parent = nullptr);
	~confirm();
	QString gkj, fzs, dzs;
	void showtext();

private:
	Ui::confirmClass ui;

private slots:
	void onconfirm1();
	void onconfirm2();
};

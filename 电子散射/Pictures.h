#pragma once

#include <QWidget>
#include "ui_Pictures.h"

class Pictures : public QWidget
{
	Q_OBJECT

public:
	Pictures(QWidget *parent = nullptr);
	~Pictures();
	
	QString average;

	Ui::PicturesClass ui;
private:
	
};

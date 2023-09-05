/********************************************************************************
** Form generated from reading UI file 'lrqd.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LRQD_H
#define UI_LRQD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_lrqdClass
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *qd;

    void setupUi(QDialog *lrqdClass)
    {
        if (lrqdClass->objectName().isEmpty())
            lrqdClass->setObjectName(QString::fromUtf8("lrqdClass"));
        lrqdClass->resize(283, 98);
        verticalLayout = new QVBoxLayout(lrqdClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(lrqdClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        qd = new QPushButton(lrqdClass);
        qd->setObjectName(QString::fromUtf8("qd"));

        verticalLayout->addWidget(qd);


        retranslateUi(lrqdClass);

        QMetaObject::connectSlotsByName(lrqdClass);
    } // setupUi

    void retranslateUi(QDialog *lrqdClass)
    {
        lrqdClass->setWindowTitle(QApplication::translate("lrqdClass", "\345\275\225\345\205\245\347\241\256\345\256\232", nullptr));
        label->setText(QApplication::translate("lrqdClass", "\345\275\225\345\205\245\346\210\220\345\212\237", nullptr));
        qd->setText(QApplication::translate("lrqdClass", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lrqdClass: public Ui_lrqdClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LRQD_H

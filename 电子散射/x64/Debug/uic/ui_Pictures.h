/********************************************************************************
** Form generated from reading UI file 'Pictures.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTURES_H
#define UI_PICTURES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PicturesClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *pic3d;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *picz;
    QPushButton *picr;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QTextEdit *ave;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *PicturesClass)
    {
        if (PicturesClass->objectName().isEmpty())
            PicturesClass->setObjectName(QString::fromUtf8("PicturesClass"));
        PicturesClass->resize(821, 646);
        verticalLayout_2 = new QVBoxLayout(PicturesClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pic3d = new QPushButton(PicturesClass);
        pic3d->setObjectName(QString::fromUtf8("pic3d"));

        verticalLayout->addWidget(pic3d);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        picz = new QPushButton(PicturesClass);
        picz->setObjectName(QString::fromUtf8("picz"));

        horizontalLayout->addWidget(picz);

        picr = new QPushButton(PicturesClass);
        picr->setObjectName(QString::fromUtf8("picr"));

        horizontalLayout->addWidget(picr);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_3);

        ave = new QTextEdit(PicturesClass);
        ave->setObjectName(QString::fromUtf8("ave"));

        verticalLayout_2->addWidget(ave);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);


        retranslateUi(PicturesClass);

        QMetaObject::connectSlotsByName(PicturesClass);
    } // setupUi

    void retranslateUi(QWidget *PicturesClass)
    {
        PicturesClass->setWindowTitle(QApplication::translate("PicturesClass", "\347\273\230\345\233\276\345\261\225\347\244\272", nullptr));
        pic3d->setText(QApplication::translate("PicturesClass", "\347\224\265\345\255\220\346\225\243\345\260\2043D\346\225\243\347\202\271\345\233\276", nullptr));
        picz->setText(QApplication::translate("PicturesClass", "\350\203\275\351\207\217\347\272\265\345\220\221\346\262\211\347\247\257", nullptr));
        picr->setText(QApplication::translate("PicturesClass", "\350\203\275\351\207\217\346\250\252\345\220\221\346\262\211\347\247\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PicturesClass: public Ui_PicturesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTURES_H

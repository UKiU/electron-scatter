/********************************************************************************
** Form generated from reading UI file 'Initial.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITIAL_H
#define UI_INITIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InitialClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_5;
    QComboBox *dzsrsnl;
    QSpacerItem *horizontalSpacer_11;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_6;
    QComboBox *dzsbj;
    QSpacerItem *horizontalSpacer_21;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QSpacerItem *verticalSpacer_10;
    QComboBox *dzgs;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_13;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_9;
    QComboBox *clcs;
    QSpacerItem *horizontalSpacer_15;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_11;
    QPushButton *szsj;
    QSpacerItem *verticalSpacer_12;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *verticalSpacer_15;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_17;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QSpacerItem *verticalSpacer_13;
    QComboBox *jmmx;
    QSpacerItem *horizontalSpacer_16;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_14;
    QComboBox *sstype;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *start;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InitialClass)
    {
        if (InitialClass->objectName().isEmpty())
            InitialClass->setObjectName(QString::fromUtf8("InitialClass"));
        InitialClass->resize(841, 622);
        centralWidget = new QWidget(InitialClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_8 = new QVBoxLayout(centralWidget);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_12);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(100, 0));
        label_2->setMaximumSize(QSize(16777215, 16777215));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_7->addItem(verticalSpacer_5);

        dzsrsnl = new QComboBox(centralWidget);
        dzsrsnl->addItem(QString());
        dzsrsnl->setObjectName(QString::fromUtf8("dzsrsnl"));
        dzsrsnl->setEditable(true);

        verticalLayout_7->addWidget(dzsrsnl);


        horizontalLayout_4->addLayout(verticalLayout_7);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_4);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_6->addItem(verticalSpacer_6);

        dzsbj = new QComboBox(centralWidget);
        dzsbj->addItem(QString());
        dzsbj->setObjectName(QString::fromUtf8("dzsbj"));
        dzsbj->setEditable(true);

        verticalLayout_6->addWidget(dzsbj);


        horizontalLayout_4->addLayout(verticalLayout_6);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_21);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setEnabled(true);
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(100, 0));
        label_7->setMaximumSize(QSize(16777215, 16777215));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_7);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_5->addItem(verticalSpacer_10);

        dzgs = new QComboBox(centralWidget);
        dzgs->addItem(QString());
        dzgs->addItem(QString());
        dzgs->addItem(QString());
        dzgs->setObjectName(QString::fromUtf8("dzgs"));
        dzgs->setEditable(true);

        verticalLayout_5->addWidget(dzgs);


        horizontalLayout_4->addLayout(verticalLayout_5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout_8->addLayout(horizontalLayout_4);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_8->addItem(verticalSpacer_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_13);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(true);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(100, 0));
        label_3->setMaximumSize(QSize(16777215, 16777215));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_9);

        clcs = new QComboBox(centralWidget);
        clcs->addItem(QString());
        clcs->addItem(QString());
        clcs->addItem(QString());
        clcs->addItem(QString());
        clcs->addItem(QString());
        clcs->setObjectName(QString::fromUtf8("clcs"));
        sizePolicy.setHeightForWidth(clcs->sizePolicy().hasHeightForWidth());
        clcs->setSizePolicy(sizePolicy);
        clcs->setEditable(true);

        verticalLayout->addWidget(clcs);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_15);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_11);

        szsj = new QPushButton(centralWidget);
        szsj->setObjectName(QString::fromUtf8("szsj"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(szsj->sizePolicy().hasHeightForWidth());
        szsj->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(szsj);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_12);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_14);


        verticalLayout_8->addLayout(horizontalLayout_2);

        verticalSpacer_15 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_8->addItem(verticalSpacer_15);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_17);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_3->addItem(verticalSpacer_13);

        jmmx = new QComboBox(centralWidget);
        jmmx->addItem(QString());
        jmmx->setObjectName(QString::fromUtf8("jmmx"));

        verticalLayout_3->addWidget(jmmx);


        horizontalLayout_3->addLayout(verticalLayout_3);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_16);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_5);

        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_14);

        sstype = new QComboBox(centralWidget);
        sstype->addItem(QString());
        sstype->addItem(QString());
        sstype->setObjectName(QString::fromUtf8("sstype"));

        verticalLayout_4->addWidget(sstype);


        horizontalLayout_3->addLayout(verticalLayout_4);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_18);


        verticalLayout_8->addLayout(horizontalLayout_3);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_8->addItem(verticalSpacer_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        start = new QPushButton(centralWidget);
        start->setObjectName(QString::fromUtf8("start"));

        horizontalLayout->addWidget(start);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_8->addLayout(horizontalLayout);

        InitialClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(InitialClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 841, 26));
        InitialClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(InitialClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        InitialClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(InitialClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        InitialClass->setStatusBar(statusBar);

        retranslateUi(InitialClass);

        QMetaObject::connectSlotsByName(InitialClass);
    } // setupUi

    void retranslateUi(QMainWindow *InitialClass)
    {
        InitialClass->setWindowTitle(QApplication::translate("InitialClass", "\345\210\235\345\247\213\347\225\214\351\235\242", nullptr));
        label_2->setText(QApplication::translate("InitialClass", "\347\224\265\345\255\220\346\235\237\345\205\245\345\260\204\350\203\275\351\207\217\357\274\210kev\357\274\211", nullptr));
        dzsrsnl->setItemText(0, QApplication::translate("InitialClass", "10", nullptr));

        label_4->setText(QApplication::translate("InitialClass", "\347\224\265\345\255\220\346\235\237\345\215\212\345\276\204\357\274\210nm\357\274\211", nullptr));
        dzsbj->setItemText(0, QApplication::translate("InitialClass", "20", nullptr));

        label_7->setText(QApplication::translate("InitialClass", "\346\250\241\346\213\237\347\224\265\345\255\220\344\270\252\346\225\260", nullptr));
        dzgs->setItemText(0, QApplication::translate("InitialClass", "1000", nullptr));
        dzgs->setItemText(1, QApplication::translate("InitialClass", "100", nullptr));
        dzgs->setItemText(2, QApplication::translate("InitialClass", "20", nullptr));

        label_3->setText(QApplication::translate("InitialClass", "\346\250\241\346\213\237\346\235\220\346\226\231\345\261\202\346\225\260", nullptr));
        clcs->setItemText(0, QApplication::translate("InitialClass", "2", nullptr));
        clcs->setItemText(1, QApplication::translate("InitialClass", "1", nullptr));
        clcs->setItemText(2, QApplication::translate("InitialClass", "3", nullptr));
        clcs->setItemText(3, QApplication::translate("InitialClass", "4", nullptr));
        clcs->setItemText(4, QApplication::translate("InitialClass", "5", nullptr));

        szsj->setText(QApplication::translate("InitialClass", "\350\256\276\347\275\256\346\235\220\346\226\231\346\225\260\346\215\256", nullptr));
        label->setText(QApplication::translate("InitialClass", "\346\225\243\345\260\204\346\210\252\351\235\242\346\250\241\345\236\213", nullptr));
        jmmx->setItemText(0, QApplication::translate("InitialClass", "\345\215\242\347\221\237\347\246\217\346\210\252\351\235\242", nullptr));

        label_5->setText(QApplication::translate("InitialClass", "\346\225\243\345\260\204\350\247\222\345\205\254\345\274\217", nullptr));
        sstype->setItemText(0, QApplication::translate("InitialClass", "\344\270\255\351\253\230\350\203\275\347\224\265\345\255\220", nullptr));
        sstype->setItemText(1, QApplication::translate("InitialClass", "\344\275\216\350\203\275\347\224\265\345\255\220", nullptr));

        start->setText(QApplication::translate("InitialClass", "\345\274\200\345\247\213", nullptr));
        mainToolBar->setWindowTitle(QApplication::translate("InitialClass", "\345\210\235\345\247\213\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InitialClass: public Ui_InitialClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITIAL_H

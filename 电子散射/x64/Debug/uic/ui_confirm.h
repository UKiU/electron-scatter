/********************************************************************************
** Form generated from reading UI file 'confirm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRM_H
#define UI_CONFIRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_confirmClass
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *confirmtext;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *confirm1;
    QPushButton *confirm2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *confirmClass)
    {
        if (confirmClass->objectName().isEmpty())
            confirmClass->setObjectName(QString::fromUtf8("confirmClass"));
        confirmClass->resize(600, 400);
        horizontalLayout_2 = new QHBoxLayout(confirmClass);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        confirmtext = new QPlainTextEdit(confirmClass);
        confirmtext->setObjectName(QString::fromUtf8("confirmtext"));

        verticalLayout->addWidget(confirmtext);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        confirm1 = new QPushButton(confirmClass);
        confirm1->setObjectName(QString::fromUtf8("confirm1"));

        horizontalLayout->addWidget(confirm1);

        confirm2 = new QPushButton(confirmClass);
        confirm2->setObjectName(QString::fromUtf8("confirm2"));

        horizontalLayout->addWidget(confirm2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(confirmClass);

        QMetaObject::connectSlotsByName(confirmClass);
    } // setupUi

    void retranslateUi(QDialog *confirmClass)
    {
        confirmClass->setWindowTitle(QApplication::translate("confirmClass", "\347\241\256\350\256\244\344\277\241\346\201\257", nullptr));
        confirm1->setText(QApplication::translate("confirmClass", "\347\241\256\350\256\244", nullptr));
        confirm2->setText(QApplication::translate("confirmClass", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class confirmClass: public Ui_confirmClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRM_H

/********************************************************************************
** Form generated from reading UI file 'Drawpic.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWPIC_H
#define UI_DRAWPIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawpicClass
{
public:
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *DrawpicClass)
    {
        if (DrawpicClass->objectName().isEmpty())
            DrawpicClass->setObjectName(QString::fromUtf8("DrawpicClass"));
        DrawpicClass->resize(600, 400);
        horizontalLayout = new QHBoxLayout(DrawpicClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        retranslateUi(DrawpicClass);

        QMetaObject::connectSlotsByName(DrawpicClass);
    } // setupUi

    void retranslateUi(QWidget *DrawpicClass)
    {
        DrawpicClass->setWindowTitle(QApplication::translate("DrawpicClass", "Drawpic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawpicClass: public Ui_DrawpicClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWPIC_H

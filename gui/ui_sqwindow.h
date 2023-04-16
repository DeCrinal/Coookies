/********************************************************************************
** Form generated from reading UI file 'sqwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQWINDOW_H
#define UI_SQWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SqWindow
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QWidget *SqWindow)
    {
        if (SqWindow->objectName().isEmpty())
            SqWindow->setObjectName(QString::fromUtf8("SqWindow"));
        SqWindow->setWindowModality(Qt::NonModal);
        SqWindow->setEnabled(true);
        SqWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SqWindow->sizePolicy().hasHeightForWidth());
        SqWindow->setSizePolicy(sizePolicy);
        SqWindow->setMinimumSize(QSize(800, 600));
        SqWindow->setMaximumSize(QSize(1000000, 100000));
        graphicsView = new QGraphicsView(SqWindow);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 800, 600));
        graphicsView->setMinimumSize(QSize(800, 600));

        retranslateUi(SqWindow);

        QMetaObject::connectSlotsByName(SqWindow);
    } // setupUi

    void retranslateUi(QWidget *SqWindow)
    {
        SqWindow->setWindowTitle(QApplication::translate("SqWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SqWindow: public Ui_SqWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQWINDOW_H

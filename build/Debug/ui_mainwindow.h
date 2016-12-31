/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnLoadImage;
    QPushButton *btnChangeFilter;
    QPushButton *btnSaveImage;
    QSlider *imageSlider;
    QLabel *imageLabel;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(508, 434);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnLoadImage = new QPushButton(centralWidget);
        btnLoadImage->setObjectName(QStringLiteral("btnLoadImage"));

        horizontalLayout->addWidget(btnLoadImage);

        btnChangeFilter = new QPushButton(centralWidget);
        btnChangeFilter->setObjectName(QStringLiteral("btnChangeFilter"));

        horizontalLayout->addWidget(btnChangeFilter);

        btnSaveImage = new QPushButton(centralWidget);
        btnSaveImage->setObjectName(QStringLiteral("btnSaveImage"));

        horizontalLayout->addWidget(btnSaveImage);


        verticalLayout->addLayout(horizontalLayout);

        imageSlider = new QSlider(centralWidget);
        imageSlider->setObjectName(QStringLiteral("imageSlider"));
        imageSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(imageSlider);

        imageLabel = new QLabel(centralWidget);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));

        verticalLayout->addWidget(imageLabel);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btnLoadImage->setText(QApplication::translate("MainWindow", "Load Image", 0));
        btnChangeFilter->setText(QApplication::translate("MainWindow", "Change Filter", 0));
        btnSaveImage->setText(QApplication::translate("MainWindow", "Save Image", 0));
        imageLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

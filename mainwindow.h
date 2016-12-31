#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPixmap>
#include "filterdata.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnLoadImage_clicked();

    void on_btnChangeFilter_clicked();
    void onFilterChange(int status);
private:
    FilterData filterData;
    QImage* image;
    QPixmap* filtered;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

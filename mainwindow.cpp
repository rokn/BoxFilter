#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filterchanger.h"
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    filterData(3)
{
    ui->setupUi(this);
    ui->imageLabel->setScaledContents(true);
    ui->imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    image = new QImage();
    filtered = new QPixmap();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete filtered;
}


void MainWindow::on_btnLoadImage_clicked()
{
    QUrl url = QFileDialog::getOpenFileUrl(this, "Select an image", QUrl(), QString("Images (*.png *.xpm *.jpg)"));

    if(url.isValid())
    {
        image->load(url.path());
        filtered->load(url.path());
        ui->imageLabel->setPixmap(*filtered);
    }
}

void MainWindow::on_btnChangeFilter_clicked()
{
    FilterChanger *changer = new FilterChanger(&filterData, this);
    changer->show();
    connect(changer, SIGNAL(finished(int)), this, SLOT(onFilterChange(int)));
}

void MainWindow::onFilterChange(int status)
{
    QImage filteredImage(image->width(), image->height(), image->format());

    int filterRange = filterData.filterSize() / 2;

    for (int x = 0; x < image->width(); ++x) {
        for (int y = 0; y < image->height(); ++y) {
            int r = 0, g = 0, b = 0, a = 0;
            int valids = 0;
            for (int i = -filterRange; i <= filterRange; ++i) {
                for (int j = -filterRange; j <= filterRange; ++j) {
                    if(filteredImage.valid(x + j, y + i)) {
                        QColor color = image->pixelColor(x + j, y + i);
                        r += color.red() * filterData[i * filterData.filterSize() + j];
                        g += color.green() * filterData[i * filterData.filterSize() + j];
                        b += color.blue() * filterData[i * filterData.filterSize() + j];
                        a += color.alpha() * filterData[i * filterData.filterSize() + j];
                        valids++;
                    }
                }
            }

            r /= valids;
            g /= valids;
            b /= valids;
            a /= valids;

            filteredImage.setPixelColor(x, y, QColor::fromRgb(r,g,b,a));
        }
    }

    filtered->convertFromImage(filteredImage);
    ui->imageLabel->setPixmap(*filtered);
}

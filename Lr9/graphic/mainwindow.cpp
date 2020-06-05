#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPointF>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->ChartL->addWidget(chartV);
    chart->addSeries(series);
    chart->legend()->hide();

            axisX->setLabelFormat("%i");
            axisX->setTickCount(500);
            axisX->setMax(500);
            chart->addAxis(axisX, Qt::AlignBottom);
            series->attachAxis(axisX);

            axisY->setLabelFormat("%i");
            axisY->setTickCount(10);
            axisY->setMax(500000);
            axisY->setMin(-500000);
            chart->addAxis(axisY, Qt::AlignLeft);
            series->attachAxis(axisY);

    chartV->setChart(chart);

    thread = new QThread(this);
    connect(thread, &QThread::started,[&](){
        QTimer *timer = new QTimer;
        timer->moveToThread(thread);
        timer->setInterval(1000);
        connect(timer, &QTimer::timeout,[&](){
            auto item = values->returnValues(massive->returnMassive());
            series->clear();
            for (int i = 0; i < 500; ++i){
                      *series << QPointF(i,item[i]);
              }
        });
        timer->start();
    });

    connect(massive, &QThread::started,[&](){
        thread->start();
    });
    connect(massive, &QThread::finished,[&](){
        thread->terminate();
    });
    connect(ui->Start, &QPushButton::pressed,[&](){
    if (ui->Start->text() == "start"){

        massive->start();

        ui->Start->setText("stop");
    } else {
        massive->terminate();
        
        ui->Start->setText("stopped");
    }
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}


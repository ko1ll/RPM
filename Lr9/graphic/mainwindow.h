#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "massive.h"
#include <QTimer>
#include "middlevalue.h"
#include <QLogValueAxis>
#include <QLineSeries>
#include <QValueAxis>
#include <QChart>
#include <QChartView>
using namespace QtCharts;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Massive *massive = new Massive(this);
    QThread *thread;

    QChartView *chartV = new QChartView(this);
    QLineSeries *series = new QLineSeries();
    QChart *chart = new QChart();
    QValueAxis *axisX = new QValueAxis();
    QValueAxis *axisY = new QValueAxis();

    MiddleValue *values;
    Ui::MainWindow *ui;
private slots:
    void smth(){
        qInfo() << 1;
    }
};
#endif // MAINWINDOW_H

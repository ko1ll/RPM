#ifndef EXCELMAIN_H
#define EXCELMAIN_H

#include <QAxBase>
#include <QAxObject>
#include <QTableWidget>

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class excelMain; }
QT_END_NAMESPACE

class excelMain : public QMainWindow
{
    Q_OBJECT

public:
    excelMain(QWidget *parent = nullptr);
    ~excelMain();

private:
    QAxObject *excel = new QAxObject("Excel.Application");
    QAxObject *books = excel->querySubObject("Workbooks");
    QAxObject *file;
    QAxObject *sheets;
    QAxObject *page;

    int rowCount;
    int columnCount;
    int countPages;

    bool canCheckOut;
    Ui::excelMain *ui;
};
#endif // EXCELMAIN_H

#include "excelmain.h"
#include "ui_excelmain.h"
excelMain::excelMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::excelMain)
{
    ui->setupUi(this);

    file = books->querySubObject("Add()");
    sheets = file->querySubObject("Sheets");
    countPages = sheets->dynamicCall("Count()").toInt();
    page = sheets->querySubObject("Item(const int&)",countPages);

    QAxObject *rows = page->querySubObject("Rows()");
    QAxObject *columns = page->querySubObject("Columns()");

    rowCount = rows->dynamicCall("Count()").toInt();
    columnCount = columns->dynamicCall("Count()").toInt();
    delete rows;
    delete columns;

    ui->table->setRowCount(rowCount/500);
    ui->table->setColumnCount(columnCount/500);

    connect(ui->table,&QTableWidget::cellChanged,[&](const int& row,const int& column){
    QAxObject *value = page->querySubObject("Cells(int,int)",row+1,column+1);
    value->dynamicCall("SetValue(const QVariant&)",QVariant(ui->table->item(row,column)->text()));
    delete value;
    });





}

excelMain::~excelMain()
{
    file->dynamicCall("Close(const bool&,const QString&)",QVariant(true),QVariant("new_file"));

    delete file;
    books->dynamicCall("Close()");
    excel->dynamicCall("Quit()");
    delete books;
    delete excel;
}


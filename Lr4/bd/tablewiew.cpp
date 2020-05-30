#include "tablewiew.h"
#include "ui_tablewiew.h"

tablewiew::tablewiew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tablewiew)
{
    ui->setupUi(this);
    model = new QSqlQueryModel;
    connect(ui->usebtm,&QPushButton::pressed,[=](){
        model->setQuery(ui->query->text());
        ui->Table->setModel(model);
    });
}

tablewiew::~tablewiew()
{
    delete ui;
}

void tablewiew::on_close_pressed()
{
   accept();
}

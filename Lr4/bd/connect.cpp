#include "connect.h"
#include "ui_connect.h"

connect::connect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connect)
{
    ui->setupUi(this);
}

connect::~connect()
{
    delete ui;
}

void connect::on_ok_pressed()
{
    first_name = ui->first->text();
    last_name = ui->second->text();
    accept();
}

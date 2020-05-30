#include "update.h"
#include "ui_update.h"

update::update(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::update)
{
    ui->setupUi(this);
}

update::~update()
{
    delete ui;
}

void update::on_pushButton_pressed()
{
    first_name = ui->first->text();
    second_name = ui->second->text();
    accept();
}

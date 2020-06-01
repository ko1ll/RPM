#include "settingsmenu.h"
#include "ui_settingsmenu.h"

settingsMenu::settingsMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingsMenu)
{
    ui->setupUi(this);
    ui->label_ip->setToolTip("If(null) = any");
    connect(ui->Ok,&QPushButton::pressed,[&](){
    Ip_ = ui->Ip->text();
    Port_ = ui->Port->text();
    accept();
    });
    connect(ui->Back,&QPushButton::pressed,[&](){
        reject();
    });
}

settingsMenu::~settingsMenu()
{
    delete ui;
}


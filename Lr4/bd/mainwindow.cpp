/**
* @file mainwindow.cpp
* @author Kirpichenko Daniil <ko1lmain4@gmail.com>
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tablename->setReadOnly(true);
    ui->infotext->setReadOnly(true);
    DataBase* bd = new DataBase(this,"QSQLITE");
    connect(ui->tablebtm,&QPushButton::clicked,[bd,this](){ //Задать вопрос
        bool connect;
        const QString Name = QInputDialog::getText(this,
                                             "Table Name",
                                             "Name:",
                                             QLineEdit::Normal,
                                             "",
                                             &connect,
                                             Qt::CustomizeWindowHint |  Qt::WindowStaysOnTopHint | Qt::WindowMinimizeButtonHint,
                                             Qt::InputMethodHint::ImhLowercaseOnly);

        if(connect == true) {
           bd->useTable(Name);
        }
    });
    connect(bd,&DataBase::SetResult,ui->tablename,&QLineEdit::setText);
    connect(ui->addbtm,&QPushButton::pressed,[=](){
       bd->insert(ui->namevalue->text(),ui->lastnamevalue->text());
    });
    connect(bd,&DataBase::up_date,[&](QString first,QString second,QString min,QString max){
        ui->namevalue->setText(first);
        ui->lastnamevalue->setText(second);
        ui->infotext->setText(min+"/"+max);
    });
    connect(ui->nextbtm,&QPushButton::clicked,bd,&DataBase::next);
    connect(ui->prevbtm,&QPushButton::clicked,bd,&DataBase::prev);
    connect(ui->deletebtm,&QPushButton::clicked,bd,&DataBase::del);
}

MainWindow::~MainWindow()
{
    delete ui;
}


#include "server.h"
#include "ui_server.h"
#include "webserver.h"
#include "settingsmenu.h"
server::server(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::server)
{
    //////////////////////////////SERVER SETTINGS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    ///

    ui->setupUi(this);
    MainServer = new webserver(this);
    connect(ui->OpenServer,&QPushButton::pressed,[&](){
        QSettings SettingsForApplication("Org","App");
        SettingsForApplication.beginGroup("SettingsConnection");
        if (MainServer->listen(QHostAddress::Any,
                               SettingsForApplication.value("Port").toInt())) {
            ui->MsgForServer->addItem("Server started with settings: "
                                      +SettingsForApplication.value("Ip").toString()
                                      + ":"
                                      +SettingsForApplication.value("Port").toString());
        } else ui->MsgForServer->addItem("Unable to start server");
        SettingsForApplication.endGroup();
    });

    connect(ui->ChangeSettings,&QPushButton::pressed,[&](){
    settingsMenu b(this);
    if (b.exec() == QDialog::Accepted){
        QSettings SettingsForApplication("Org","App");
        SettingsForApplication.beginGroup("SettingsConnection");
        SettingsForApplication.setValue("Port",b.port());
        if(b.ip() != ""){
            SettingsForApplication.setValue("Ip",b.ip());
        } else SettingsForApplication.setValue("Ip","QHostAddress::Any");
        ui->MsgForServer->addItem("Setting changed on: "
                                  +SettingsForApplication.value("Ip").toString()
                                  + ":"
                                  +SettingsForApplication.value("Port").toString());
        SettingsForApplication.endGroup();

    }
    });

    connect(ui->CloseServer,&QPushButton::pressed,[&](){
        MainServer->userAction("Server closed");
        ui->MsgForServer->addItem("Server closed");
        MainServer->close();
    });

    connect(ui->Exit,&QPushButton::pressed,[&](){
        this->reject();
    });

    //////////////////////////////SERVER SETTINGS\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    ///

    //////////////////////////////ICON SETTINGS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    ///
    setWindowIcon(QIcon(":/tray.jpg"));
    trayIconMenu = new QMenu(this);
    for(const auto& item : actions){
    trayIconMenu->addAction(item);
    }
    trayIcon->setContextMenu(trayIconMenu);

    connect(actions[0],&QAction::triggered,ui->CloseServer,&QPushButton::pressed);
    connect(actions[1],&QAction::triggered,ui->OpenServer,&QPushButton::pressed);
    connect(actions[2],&QAction::triggered,ui->ChangeSettings,&QPushButton::pressed);
    connect(actions[2],&QAction::triggered,this,&QDialog::show);
    connect(actions[3],&QAction::triggered,this,&QDialog::accept);

    connect(trayIcon,&QSystemTrayIcon::activated,[&](QSystemTrayIcon::ActivationReason reason){
        switch (reason) {
        case 0: {break;};
        case 1: {break;};
        case 2: {break;};
        case 3: {
            if (!(this->isVisible())){
                this->show();
                trayIcon->hide();
            } else this->hide();
            break;};
        case 4: {break;};
        }
    });

    //////////////////////////////ICON SETTINGS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    ///
}


server::~server()
{
    delete ui;
}

void server::closeEvent(QCloseEvent *event){
    if (!(trayIcon->isVisible())){
        trayIcon->show();
        this->hide();
        event->ignore();
        trayIcon->showMessage("Systray","The program will keep running in the system tray");
    }
}


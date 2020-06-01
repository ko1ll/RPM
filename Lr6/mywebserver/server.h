#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QSettings>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QAction>
#include <QCloseEvent>
#include <QMenu>
QT_BEGIN_NAMESPACE
namespace Ui { class server; }
QT_END_NAMESPACE
class webserver;
class server : public QDialog
{
    Q_OBJECT

public:
    server(QWidget *parent = nullptr);
    ~server();
    void closeEvent(QCloseEvent* e);

private slots:
private:
    Ui::server *ui;
    webserver *MainServer;
    QList<QAction*> actions{new QAction(QIcon(":/close.jpg"),"Close"),
                            new QAction(QIcon(":/open.jpg"),"Open"),
                            new QAction(QIcon(":/settings.jpg"),"Settings"),
                            new QAction(QIcon(":/exit.jpg"),"Exit")};

    QSystemTrayIcon *trayIcon = new QSystemTrayIcon(QIcon(":/tray.jpg"));
    QMenu *trayIconMenu;
};
#endif // SERVER_H

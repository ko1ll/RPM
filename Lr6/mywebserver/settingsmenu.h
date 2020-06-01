#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <QDialog>

namespace Ui {
class settingsMenu;
}

class settingsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit settingsMenu(QWidget *parent = nullptr);
    ~settingsMenu();
    QString& ip(){
     return Ip_;
    }
    QString& port(){
        return Port_;
    }
private:
    QString Ip_,Port_;
    Ui::settingsMenu *ui;
};

#endif // SETTINGSMENU_H

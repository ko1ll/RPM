#ifndef CONNECT_H
#define CONNECT_H

#include <QDialog>

namespace Ui {
class connect;
}

class connect : public QDialog
{
    Q_OBJECT

public:
    explicit connect(QWidget *parent = nullptr);
    ~connect();
    QString& first(){
        return first_name;
    }
    QString& second(){
        return last_name;
    }

private slots:
    void on_ok_pressed();

private:
    Ui::connect *ui;
    QString first_name,last_name;
};

#endif // CONNECT_H

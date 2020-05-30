#ifndef UPDATE_H
#define UPDATE_H

#include <QDialog>

namespace Ui {
class update;
}

class update : public QDialog
{
    Q_OBJECT

public:
    explicit update(QWidget *parent = nullptr);
    ~update();
    QString& first(){
        return first_name;
    }
    QString& second(){
        return second_name;
    }
private slots:
    void on_pushButton_pressed();

private:
    QString first_name,second_name;
    Ui::update *ui;
};

#endif // UPDATE_H

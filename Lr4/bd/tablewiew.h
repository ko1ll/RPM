#ifndef TABLEWIEW_H
#define TABLEWIEW_H

#include <QDialog>
#include <QSqlRelationalTableModel>
namespace Ui {
class tablewiew;
}

class tablewiew : public QDialog
{
    Q_OBJECT

public:
    explicit tablewiew(QWidget *parent = nullptr);
    ~tablewiew();

private slots:
    void on_close_pressed();

private:
    QSqlQueryModel *model;
    Ui::tablewiew *ui;
};

#endif // TABLEWIEW_H

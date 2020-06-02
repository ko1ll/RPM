#ifndef PIAINT_H
#define PIAINT_H

#include <QWidget>
#include <QMenu>
#include <QMouseEvent>
#include "painscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class piaint; }
QT_END_NAMESPACE

class piaint : public QWidget
{
    Q_OBJECT

public:
    piaint(QWidget *parent = nullptr);
    ~piaint();

private:
    painscene *scene = new painscene();
    QMenu *menu = new QMenu("Menu",this);
    QList<QAction*> actions{new QAction("Blue"),
                            new QAction("Red"),
                            new QAction("Green"),
                            new QAction(),
                            new QAction("ChangeBrushSize"),
                            new QAction("AddPhoto"),
                            new QAction("Clear"),
                            new QAction("Eraser")};
    void mousePressEvent(QMouseEvent*);
    void keyPressEvent(QKeyEvent *event);
    bool info;
    Ui::piaint *ui;
};
#endif // PIAINT_H

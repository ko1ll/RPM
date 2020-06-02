#ifndef PAINSCENE_H
#define PAINSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
class painscene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit painscene(QObject *parent = 0);
public:
    void setPen(const QPen&);
    void setBrush(const QBrush&);
    void setSize(const int&);
private:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    QPointF previousPoint;
    QPen pen = Qt::NoPen;
    QBrush brush = Qt::blue;
    int size = 10;
};

#endif // PAINSCENE_H

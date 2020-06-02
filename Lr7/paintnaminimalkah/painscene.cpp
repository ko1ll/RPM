#include "painscene.h"

#include <QFocusEvent>
#include <QGraphicsItem>
painscene::painscene(QObject *parent) : QGraphicsScene(parent)
{
}

void painscene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){

    }else return;

    addEllipse(event->scenePos().x() - 5,
               event->scenePos().y() - 5,
               size,
               size,
               QPen(pen),
               QBrush(brush));
    previousPoint = event->scenePos();
}

void painscene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(brush,size,Qt::SolidLine,Qt::RoundCap));
    previousPoint = event->scenePos();
}

void painscene::setPen(const QPen& pen){
this->pen = pen;
}
void painscene::setBrush(const QBrush& brush){
this->brush = brush;
}
void painscene::setSize(const int& size){
this->size = size;
}

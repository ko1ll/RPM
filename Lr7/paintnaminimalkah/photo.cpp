#include "photo.h"
#include <QDebug>
#include <QGraphicsScene>
photo::photo(QObject *parent,const QPixmap& map) :
    QObject(parent), QGraphicsPixmapItem(map)
{

}

//void photo::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//{
//    this->setPos(mapToScene(event->pos()));
//}

//void photo::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{

//    this->setCursor(QCursor(Qt::ClosedHandCursor));
//    Q_UNUSED(event);
//}

//void photo::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//{
//    this->setCursor(QCursor(Qt::ArrowCursor));
//    Q_UNUSED(event);
//}

#ifndef PHOTO_H
#define PHOTO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
class photo : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit photo(QObject *parent = 0,const QPixmap& map = {});
private:
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
//    void mousePressEvent(QGraphicsSceneMouseEvent *event);
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PHOTO_H

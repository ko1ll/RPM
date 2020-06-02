#include "piaint.h"
#include "ui_piaint.h"
#include <QInputDialog>
#include <QFileDialog>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include "photo.h"
piaint::piaint(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::piaint)
{
    ui->setupUi(this);
    ui->Scene->setScene(scene);

    actions[3]->setSeparator(true);
    for(const auto& item : actions){
     menu->addAction(item);
    }
    connect(actions[0],&QAction::triggered,[&](){
        scene->setBrush(Qt::blue);
    });
    connect(actions[1],&QAction::triggered,[&](){
        scene->setBrush(Qt::red);
    });
    connect(actions[2],&QAction::triggered,[&](){
        scene->setBrush(Qt::green);
    });
    connect(actions[4],&QAction::triggered,[&](){
        bool changed;
        const int size = QInputDialog::getInt(this,
                                                     "Change size",
                                                     "Size:",
                                                     0,
                                                     1,
                                                     10,
                                                     1,
                                                     &changed,
                                                     Qt::CustomizeWindowHint |  Qt::WindowStaysOnTopHint | Qt::WindowMinimizeButtonHint
                                                     );
        if(changed){
            scene->setSize(size);
        }
    });
    connect(actions[5],&QAction::triggered,[&](){
    QString str = QFileDialog::getOpenFileName(this, "Select Photo", "", "*.jpg *.png");
    auto smth = new photo(scene,QPixmap(str));
    scene->addItem(smth);
    });
    connect(actions[6],&QAction::triggered,[&](){
    scene->clear();
    });
    connect(actions[7],&QAction::triggered,[&](){
    scene->setBrush(Qt::white);
    });
    scene->setSceneRect(0,0, ui->Scene->width() + 1600, ui->Scene->height() + 900);
}

piaint::~piaint()
{
    delete ui;
}

void piaint::mousePressEvent(QMouseEvent * event){
    if (event->button() == Qt::RightButton){
        menu->exec(event->globalPos());
    }
}

void piaint::keyPressEvent(QKeyEvent *event){
    if(info == true and event->key() == 83){
        QString fileName = QFileDialog::getSaveFileName(this, "Select Photo", "", "*.jpg *.png");
        QImage image(scene->width(), scene->height(), QImage::Format_ARGB32_Premultiplied);
          image.fill(QColor(Qt::white).rgb());
          QPainter painter(&image);
          scene->render(&painter);
          image.save(fileName);
    } else info = false;
    if (event->key() == 16777249){
        info = true;
    }
};

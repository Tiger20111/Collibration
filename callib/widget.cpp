#include "widget.h"
#include "ui_widget.h"
#include "myitem.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPen>
#include <QThread>



void DrawBorder (QGraphicsScene *scene) {
  scene->setSceneRect(-10, -10, 300, 300);
  QPen mypen = QPen(Qt::red);

  QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
  QLineF LeftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
  QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
  QLineF BottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());

  scene ->addLine(TopLine, mypen);
  scene ->addLine(LeftLine, mypen);
  scene ->addLine(RightLine, mypen);
  scene ->addLine(BottomLine, mypen);
}


Widget::Widget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);
  QGraphicsView *view;
  QGraphicsScene *scene = new QGraphicsScene();
  view = new QGraphicsView (scene);

  DrawBorder(scene);

  MyItem *item = new MyItem();
  scene->addItem(item);
  //item->setX(100);
  view->show();
  QThread::sleep (100);
  item->setX(100);
}


Widget::~Widget()
{

  delete ui;
}






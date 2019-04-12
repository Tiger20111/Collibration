#include "myitem.h"
#include <iostream>
#include <fstream>

MyItem::MyItem() {
  int StartX = -1000;
  int StartY = -1000;
  setPos(StartX, StartY);
}

QRectF MyItem::boundingRect() const {
  return QRect(0, 0, 20, 20);
  //left, top angle position
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
  QRectF rec = boundingRect();
  QBrush Brush(Qt::green);

  painter->setBrush(Qt::red);
  painter->drawEllipse(rec);
}

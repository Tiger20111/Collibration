#include "widget.h"
#include <QApplication>
#include "callib.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  std::vector<std::pair<int, int>> points;
  points.push_back({100, 100});
  points.push_back({100, 100});
  points.push_back({200, 100});
  points.push_back({270, 200});
  points.push_back({100, 200});

  Callib* callibration = new Callib();
  callibration->runAnimation(points);
  return a.exec();
}

#include <QApplication>

#include "main_calculator/calc.h"

using namespace s21;

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Calc w;
  w.show();
  return a.exec();
}

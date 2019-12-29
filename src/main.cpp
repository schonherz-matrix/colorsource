#include <QApplication>
#include "colorsender.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  ColorSender w;
  w.setWindowFlags(w.windowFlags() | Qt::WindowMinimizeButtonHint);
  w.show();

  return a.exec();
}

#include "colorsender.h"

#include <QDebug>

ColorSender::ColorSender(QWidget *parent)
    : QColorDialog(parent), transmitter_(libmueb::MuebTransmitter::Instance()) {
  setOptions(QColorDialog::DontUseNativeDialog | QColorDialog::NoButtons);

  setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);

  connect(this, &ColorSender::currentColorChanged, this,
          &ColorSender::colorChanged);
}

void ColorSender::colorChanged(const QColor &color) {
  QImage frame{transmitter_.frame()};
  frame.fill(color);
  transmitter_.SendFrame(frame);
}

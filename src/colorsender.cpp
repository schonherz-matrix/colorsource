#include "colorsender.h"

#include <QDebug>

ColorSender::ColorSender(QWidget *parent)
    : QColorDialog(parent), m_transmitter(MuebTransmitter::getInstance()) {
  setOptions(QColorDialog::DontUseNativeDialog | QColorDialog::NoButtons);

  setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);

  connect(this, &ColorSender::currentColorChanged, this,
          &ColorSender::colorChanged);
}

void ColorSender::colorChanged(const QColor &color) {
  QImage frame{libmueb::defaults::frame};
  frame.fill(color);
  m_transmitter.sendFrame(frame);
}

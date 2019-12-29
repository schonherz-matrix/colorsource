#include "colorsender.h"

#include <QDebug>

ColorSender::ColorSender(QWidget *parent,
                         std::shared_ptr<MuebTransmitter> transmitter)
    : QColorDialog(parent) {
  setOptions(QColorDialog::DontUseNativeDialog | QColorDialog::NoButtons);

  setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);

  connect(this, &ColorSender::currentColorChanged, this,
          &ColorSender::colorChanged);

  if (!transmitter) m_transmitter = std::make_shared<MuebTransmitter>(this);
}

void ColorSender::colorChanged(const QColor &color) {
  QImage frame{libmueb::defaults::frame};
  frame.fill(color);
  m_transmitter->sendFrame(frame);
}

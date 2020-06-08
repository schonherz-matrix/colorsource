#ifndef COLOR_SENDER_H
#define COLOR_SENDER_H

#include <QColorDialog>

#include "muebtransmitter.h"

class ColorSender : public QColorDialog {
  Q_OBJECT

 public:
  ColorSender(QWidget* parent = nullptr);

 private:
  MuebTransmitter& m_transmitter;

  void colorChanged(const QColor& color);
};

#endif

#ifndef COLOR_SENDER_H
#define COLOR_SENDER_H

#include <QColorDialog>
#include <memory>
#include "muebtransmitter.h"

class ColorSender : public QColorDialog {
  Q_OBJECT

 public:
  ColorSender(QWidget* parent = nullptr,
              std::shared_ptr<MuebTransmitter> transmitter = nullptr);

 private:
  std::shared_ptr<MuebTransmitter> m_transmitter{nullptr};

  void colorChanged(const QColor& color);
};

#endif

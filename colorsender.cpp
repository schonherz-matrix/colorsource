#include "colorsender.h"
#include <thread>
#include <QDebug>

#include "rpc.h"
#include "matrix.h"
#include "array2D.hpp"

ColorSender::ColorSender(): id_{0}, color_{QColor{0,0,0}} {
	config_ = getConfiguration("Color source");
	timer_ = std::unique_ptr<Timer>{new Timer(std::bind(&ColorSender::packetCallback, this), std::chrono::milliseconds(1000 / config_.framerate))};
	timer_->start();
}

void ColorSender::setColor(const QColor& color) {
	m_.lock();
	color_= color;
	m_.unlock();
}

void ColorSender::packetCallback() {
	m_.lock();
	RGB rgb = RGB{color_.red(), color_.green(), color_.blue()};
	m_.unlock();
	Frame frame;
	frame.id = id_++;
	frame.pixels = Array2D<RGB>(config_.width, config_.height);
	for (int x = 0; x < config_.width; x++) {
		for (int y = 0; y < config_.height; y++) {
			frame.pixels(x,y) = rgb;
		}
	}
	sendFrame(frame, frame);
}

ColorSender::~ColorSender() {
	timer_->stop();
}

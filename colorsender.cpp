#include "colorsender.h"
#include "core/array2D.hpp"
#include <thread>
#include <exception>
#include <cmath>
#include <QDebug>

ColorSender::ColorSender(): id_{0}, color_{QColor{0,0,0}} {
	socket_ = std::unique_ptr<LocalSocket>{LocalSocket::create()};
	socket_->connectToServer("/tmp/lofasz", 1000);
	socket_->readTimeout(1000);
	socket_->writeTimeout(1000);
	pipe_ = std::unique_ptr<PipeInterpreter<ColorSender, DaemonSourceInterface>>{new PipeInterpreter<ColorSender, DaemonSourceInterface>{this, socket_.release()}};
	config_ = pipe_->getSourceConfiguration("Color source");
	timer_ = std::unique_ptr<Timer>{new Timer(std::bind(&ColorSender::packetCallback, this), std::chrono::milliseconds((int) ceil(2000.0 / config_.framerate)))};
	timer_->start();
}

void ColorSender::setColor(const QColor& color) {
	m_.lock();
	color_= color;
	m_.unlock();
}

void ColorSender::packetCallback() {
	m_.lock();
	Color rgb = Color{color_.red(), color_.green(), color_.blue()};
	m_.unlock();
	Frame frame;
	frame.id = id_++;
	frame.pixels = Array2D<Color>(config_.width, config_.height);
	for (int x = 0; x < config_.width; x++) {
		for (int y = 0; y < config_.height; y++) {
			frame.pixels(x,y) = rgb;
		}
	}
	pipe_->sendFrame(frame, frame);
}

ColorSender::~ColorSender() {
	timer_->stop();
	pipe_->disconnect();
}

#ifndef COLOR_SENDER_H_INCLUDED
#define COLOR_SENDER_H_INCLUDED

#include "timer.h"
#include <mutex>
#include <memory>
#include <QObject>
#include <QColor>

#include "rpc.h"
#include "matrix.h"

class ColorSender: public QObject {
	Q_OBJECT
	private:
		SourceConfiguration config_;
		int id_;
		QColor color_;
		std::mutex m_;
		std::unique_ptr<Timer> timer_;
		void packetCallback();
	public slots:
		void setColor(const QColor& color);
	public:
		ColorSender();
		virtual ~ColorSender();
};

#endif

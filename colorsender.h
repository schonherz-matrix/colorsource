#ifndef COLOR_SENDER_H_INCLUDED
#define COLOR_SENDER_H_INCLUDED

#include "timer.h"
#include "interface/frame.h"
#include "interface/sourceconfiguration.h"
#include "interface/sourceinterface.h"
#include "interface/daemonsourceinterface.h"
#include "stub/sourcedaemon.hpp"
#include "ipc-rpc/localsocket.h"
#include "ipc-rpc/pipeinterpreter.hpp"
#include "ipc-rpc/pipeinterpreterbase.hpp"
#include "core/color.h"
#include <mutex>
#include <memory>
#include <QObject>
#include <QColor>


class ColorSender: public QObject, public SourceInterface {
	Q_OBJECT
	
	private:
		std::unique_ptr<LocalSocket> socket_;
		std::unique_ptr<PipeInterpreter<ColorSender, DaemonSourceInterface>> pipe_;
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

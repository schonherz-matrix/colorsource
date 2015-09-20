#include "rpc.h"
#include <iostream>

void updateConfiguration(const DaemonConfiguration&) {
}

void sourceEvent(const SourceEvent&) {
}

void sendFrame(Frame f1, Frame f2) {
	std::cout << "Source ------(sendFrame)-----> Daemon, id: " << f1.id << ", color:" << "(" << (int) f1.pixels[0].r << "," << (int) f1.pixels[0].g << "," << (int) f1.pixels[0].b << ")" << std::endl;
}

SourceConfiguration getConfiguration(std::string name) {
	std::cout << "Daemon --(getConfiguration)--> Source" << std::endl;
	SourceConfiguration config;
	config.id = 0;
	config.name = name;
	config.height = 10;
	config.width = 10;
	config.framerate = 5;
	config.audio_latency = 0;
	config.bit_depth = 12;
	return config;
}

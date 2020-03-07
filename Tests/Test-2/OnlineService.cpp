#include "OnlineService.h"
#include <iostream>

OnlineService::OnlineService(const unsigned int newPort, unsigned int conn, 
	const unsigned int maxConn) : port(newPort) {

	// Fail if we try to set more connected devices than maximum allowed
	if (conn > maxConn) {
		conn = 0;
	}

	connected = conn;
	maxConnected = maxConn;
}

bool OnlineService::isConnected() const {
	return connected > 0;
}

const unsigned int OnlineService::getPort() const {
	return port;
}

void OnlineService::setPort(const unsigned int newPort) {
	port = newPort;
}

bool OnlineService::connectDevice() {
	if (connected < maxConnected) {
		connected++;

		std::cout << "Successful connection!" << std::endl;

		return true;
	}

	std::cout << "Unsuccessful connection!" << std::endl;

	return false;
}

void OnlineService::disconnectDevice() {
	connected--;
	std::cout << "Disconnected device!" << std::endl;
}
#ifndef __ONLINE_SERVICE_H
#define __ONLINE_SERVICE_H

class OnlineService {
	unsigned int port;
	unsigned int connected;
	unsigned int maxConnected;

public:
	OnlineService(const unsigned int newPort = 0, unsigned int conn = 0, const unsigned int maxConn = 0);

	// Getters
	const unsigned int getPort() const;

	// Setters
	void setPort(const unsigned int newPort);

	// Other methods
	bool connectDevice();
	void disconnectDevice();
	bool isConnected() const;
};

#endif
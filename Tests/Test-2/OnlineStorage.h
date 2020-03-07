#ifndef __ONLINE_STORAGE_H
#define __ONLINE_STORAGE_H

#include "Storage.h"
#include "OnlineService.h"

class OnlineStorage : public Storage, public OnlineService {
	double pricePerMonth;

public:
	OnlineStorage(const double pricePerMonth = 0);
	OnlineStorage(const Storage& storage, const OnlineService& service, const double pricePerMonth = 0);
	OnlineStorage(const char* hash = "", const char* name = "", const double maxCap = 0, const double usedCap = 0,
		const unsigned int port = 0, const unsigned int connectedDevices = 0, const unsigned int maxConnected = 0,
		const double pricePerMonth = 0);

	// Other methods
	void uploadFiles(const unsigned int filesize);
	const double calculatePerMonth() const;
};

#endif
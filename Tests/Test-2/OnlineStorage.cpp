#include "OnlineStorage.h"
#include <iostream>

OnlineStorage::OnlineStorage(const double pricePerMonth) : pricePerMonth(pricePerMonth) {

}

OnlineStorage::OnlineStorage(const Storage& storage, const OnlineService& service, const double pricePerMonth) :
	Storage(storage), OnlineService(service), pricePerMonth(pricePerMonth) {

}

OnlineStorage::OnlineStorage(const char* hash, const char* name, const double maxCap, const double usedCap,
	const unsigned int port, const unsigned int connectedDevices, const unsigned int maxConnected,
	const double pricePerMonth) : Storage(hash, name, maxCap, usedCap), 
	OnlineService(port, connectedDevices, maxConnected), pricePerMonth(pricePerMonth) {

}

void OnlineStorage::uploadFiles(const unsigned int filesize) {
	// Convert the filesize into GB
	double sizeInGB = filesize / (double)1024;

	// Check if the device is not connected
	if (!isConnected()) {
		// Fail to upload files
		std::cout << "Unable to upload " << sizeInGB << "GB, device is not connected!" << std::endl;
		return;
	}

	// Check if there is not enough room
	if ((getMaxCap() - getUsedCap()) < sizeInGB) {
		// Fail to upload files
		std::cout << "Unable to upload " << sizeInGB << "GB, there is not enough space!" << std::endl;
		return;
	}

	// Able to upload files
	setUsedCap(getUsedCap() + sizeInGB);
}

const double OnlineStorage::calculatePerMonth() const {
	// Round up the used capacity upwards
	int used = ceil(getUsedCap());

	// Calculate the total price per month
	double total = used * pricePerMonth;

	return total;
}
#include <iostream>
#include "DNSRecord.h"

DNSRecord::DNSRecord() {
	setDomain("");
	setIpAddress("");
}

DNSRecord::~DNSRecord() {
	delete[] domainName;
	delete[] ipAddress;
}

DNSRecord::DNSRecord(const char* domain, const char* ipaddr) {
	setDomain(domain);
	setIpAddress(ipaddr);
}

// Copy constructor
DNSRecord::DNSRecord(const DNSRecord& toCopy) {
	setDomain(toCopy.domain());
	setIpAddress(toCopy.ipaddr());
}

// Operator =, used later in the DNSCache class
DNSRecord& DNSRecord::operator=(const DNSRecord& toCopy) {
	if (this != &toCopy) {
		setDomain(toCopy.domain());
		setIpAddress(toCopy.ipaddr());
	}

	return *this;
}

const char* DNSRecord::domain() const {
	return domainName;
}

const char* DNSRecord::ipaddr() const {
	return ipAddress;
}

void DNSRecord::setDomain(const char* domain) {
	if (domain == nullptr) {
		return;
	}

	delete[] domainName;

	// Strlen for domain string
	int size = strlen(domain) + 1;

	// Allocate needed memory
	domainName = new char[size];

	// Copy the domain string, including the terminating zero
	strcpy_s(domainName, size, domain);
}

void DNSRecord::setIpAddress(const char* ipaddr) {
	if (ipaddr == nullptr) {
		return;
	}

	delete[] ipAddress;

	// Strlen for ipaddr string
	int size = strlen(ipaddr) + 1;

	// Allocate needed memory
	ipAddress = new char[size];

	// Copy the domain string, including the terminating zero
	strcpy_s(ipAddress, size, ipaddr);
}

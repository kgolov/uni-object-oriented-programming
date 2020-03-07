#ifndef __DNSRECORD_H
#define __DNSRECORD_H

class DNSRecord {
	char* domainName = nullptr;
	char* ipAddress = nullptr;

public:
	DNSRecord();
	~DNSRecord();
	DNSRecord(const char* domain, const char* ipaddr);
	DNSRecord(const DNSRecord& toCopy);

	DNSRecord& operator=(const DNSRecord& toCopy);

	// Getters
	const char* domain() const;
	const char* ipaddr() const;

	// Setters
	void setDomain(const char* domain);
	void setIpAddress(const char* ipaddr);
};

#endif
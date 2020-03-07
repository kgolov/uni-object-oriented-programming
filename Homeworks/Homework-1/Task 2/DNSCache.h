#ifndef __DNSCACHE_H
#define __DNSCACHE_H

#include "DNSRecord.h"
#include <cstring>

const int EMPTY_CACHE = -1;

class DNSCache {
	DNSRecord* cache;
	int top;
	int size;

	bool isFull() const;
	void resize();

public:
	DNSCache();
	~DNSCache();
	DNSCache(const DNSRecord& toAdd);
	DNSCache(const DNSCache& toCopy);

	DNSCache& operator=(const DNSCache& toCopy);
	void operator+=(const DNSRecord& toAdd);

	// Getters
	const char* lookup(const char* domain) const;
	void print() const;
	bool isEmpty() const;

	// Setters
	void add(const DNSRecord& toAdd);
	void flush();
};

#endif
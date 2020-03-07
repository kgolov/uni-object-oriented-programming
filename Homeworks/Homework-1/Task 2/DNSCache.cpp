#include <iostream>
#include "DNSCache.h"

DNSCache::DNSCache() {
	size = 1;
	cache = new DNSRecord[size];
	top = EMPTY_CACHE;
}

DNSCache::~DNSCache() {
	delete[] cache;
}

DNSCache::DNSCache(const DNSRecord& toAdd) {
	size = 1;
	cache = new DNSRecord[size];
	top = EMPTY_CACHE;

	add(toAdd);
}

// Copy constructor
DNSCache::DNSCache(const DNSCache& toCopy) {
	size = toCopy.size;
	cache = new DNSRecord[size];
	top = toCopy.top;

	for (int i = 0; i <= top; i++) {
		cache[i] = toCopy.cache[i];
	}
}

DNSCache& DNSCache::operator=(const DNSCache& toCopy) {
	if (this != &toCopy) {
		size = toCopy.size;
		delete[] cache;

		cache = new DNSRecord[size];
		top = toCopy.top;

		for (int i = 0; i <= top; i++) {
			cache[i] = toCopy.cache[i];
		}
	}

	return *this;
}

// Operator += with the same function as the add method
void DNSCache::operator+=(const DNSRecord& toAdd) {
	add(toAdd);
}

const char* DNSCache::lookup(const char* domain) const {
	if (isEmpty() || domain == nullptr) {
		return NULL;
	}

	for (int i = 0; i <= top; i++) {
		if (strcmp(domain, cache[i].domain()) == 0) {
			return cache[i].ipaddr();
		}
	}

	return NULL;
}

bool DNSCache::isFull() const {
	return top >= size - 1;
}

bool DNSCache::isEmpty() const {
	return top == EMPTY_CACHE;
}

void DNSCache::print() const {
	std::cout << std::endl;
	std::cout << "Current DNS Records:" << std::endl;
	std::cout << "N - Domain - IP Address" << std::endl;
	std::cout << "-----------------------" << std::endl;

	if (isEmpty()) {
		std::cout << "No records found." << std::endl;
		return;
	}

	for (int i = 0; i <= top; i++) {
		std::cout << (i + 1) << '\t' << cache[i].domain() << '\t' << cache[i].ipaddr() << std::endl;
	}
}

void DNSCache::add(const DNSRecord& toAdd) {
	if (isFull()) {
		resize();
	}

	cache[++top] = toAdd;
}

void DNSCache::resize() {
	size *= 2;
	DNSRecord* newCache = new DNSRecord[size];

	for (int i = 0; i <= top; i++) {
		newCache[i] = cache[i];
	}

	delete[] cache;
	cache = newCache;
}

// Delete all records, create an empty cache.
void DNSCache::flush() {
	delete[] cache;
	size = 1;
	cache = new DNSRecord[size];
	top = EMPTY_CACHE;
}
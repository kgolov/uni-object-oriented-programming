#include <iostream>
#include "DNSCache.h"

// Original tests for DNS Record class
void testDNSRecord() {
	DNSRecord record1;

	std::cout << "Domain: " << record1.domain() << ", expected empty string" << std::endl;
	std::cout << "IP Address: " << record1.ipaddr() << ", expected empty string" << std::endl;

	record1.setDomain("google.com");
	record1.setIpAddress("216.58.212.46");
	DNSRecord record2(record1);
	record2.setDomain("google.co.uk");

	std::cout << "Domain: " << record1.domain() << ", expected google.com" << std::endl;
	std::cout << "IP Address: " << record1.ipaddr() << ", expected 216.58.212.46" << std::endl;

	std::cout << "Domain: " << record2.domain() << ", expected google.co.uk" << std::endl;
	std::cout << "IP Address: " << record2.ipaddr() << ", expected 216.58.212.46" << std::endl;

	record1 = record2;

	std::cout << "Domain: " << record1.domain() << ", expected google.co.uk" << std::endl;
	std::cout << "IP Address: " << record1.ipaddr() << ", expected 216.58.212.46" << std::endl;
}

// Tests for DNS Cache class
void testDNSCache() {
	// Test constructor
	DNSCache cache1;

	// Test isEmpty function
	std::cout << "Is empty: " << cache1.isEmpty() << ", expected 1" << std::endl;

	// Test add method
	cache1.add(DNSRecord("example.com", "1.1.1.1"));

	// Test isEmpty function
	std::cout << "Is empty: " << cache1.isEmpty() << ", expected 0" << std::endl;
	
	// Test operator +=
	cache1 += DNSRecord("test.com", "8.8.8.8");

	// Test copy constructor
	DNSCache cache2(cache1);

	// Test flush method
	cache1.flush();

	// Test print method
	cache1.print();
	std::cout << "Expected no records found." << std::endl;
	cache2.print();
	std::cout << "Expected 2 records found." << std::endl;

	// Test operator =
	cache1 = cache2;
	cache1.print();
	std::cout << "Expected 2 records found." << std::endl;

	// Test lookup method
	std::cout << std::endl;
	std::cout << "Lookup of domain example.com found the following IP Address: " << std::endl;
	std::cout << cache1.lookup("example.com") << ", expected 1.1.1.1" << std::endl;
	std::cout << "Lookup of domain google.com found the following IP Address: " << std::endl;
	if (cache1.lookup("google.com") == NULL) {
		std::cout << "NULL";
	} 
	else {
		std::cout << cache1.lookup("google.com");
	}
	std::cout << ", expected NULL" << std::endl;
}

int main() {
	// Original tests for DNSRecord class
	// testDNSRecord();
	
	// Tests for DNSCache class
	testDNSCache();

	return 0;
}
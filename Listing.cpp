// Created by group 3.1.2 
#include "Listing.h"

using namespace std;

void Listing::add(Advertisement* ptr) {
	if (ptr != NULL) {
        objects.push_back(ptr);
	} else {
		// notification for user or provoking class
    }
}

Listing::iterator Listing::begin() {
	return objects.begin();
}

Listing::iterator Listing::end() {
	return objects.end();
}

Advertisement* Listing::operator[] (const int& number) {
	for (iterator it = objects.begin(); it != objects.end(); it ++) {
		if ((*it)->getNumber() == number) {
			return *it;
		}
	}
	return NULL;
}
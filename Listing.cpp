#include "Listing.h"

void Listing::add(Advertisement* ptr) {
	Listing::objects.push_back(ptr);
}

Listing::iterator Listing::begin() {
	return objects.begin();
}

Listing::iterator Listing::end() {
	return objects.end();
}

Advertisement* Listing::operator[] (const int& number) {
	for (Advertisement* adv : objects) {
		if ((*adv).getNumber() == number) return adv;
	}
	throw exception("No such an element");
}
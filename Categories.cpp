// Created by group 3.1.2 
#include "Categories.h"

using namespace std;

void Categories::add (Category* ptr) {
	if (ptr != NULL) {
        objects.push_back(ptr);
	} else {
		// notification for user or provoking class
    }

}

Category* Categories::operator[] (const int& number) {
	for (iterator it = objects.begin(); it != objects.end(); it ++) {
		if ((*it)->getNumber() == number) {
			return *it;
		}
	}
	return NULL;
}

Categories::iterator Categories::begin(){
	return objects.begin();
}

Categories::iterator Categories::end(){
	return objects.end();
}
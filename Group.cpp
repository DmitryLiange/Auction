// Created by group 3.1.2 
#include "Group.h"

using namespace std;

void Group::add(Client* ptr) {
    if (ptr != NULL) {
        objects.push_back(ptr);
	} else {
		// notification for user or provoking class
    }
}

Group::iterator Group::begin() {
    return objects.begin();
}

Group::iterator Group::end() {
    return objects.end();
}

Client* Group::operator[](const string& email) {
	for (iterator it = objects.begin(); it != objects.end(); it ++) {
        if ((*it)->getEmail() == email) {
			return *it;
		}
	}
    return NULL;
}
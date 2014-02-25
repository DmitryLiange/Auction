// Created by group 3.1.2 
#include "Group.h"
#include "Client.h"

using namespace std;

Client* Group::operator[](const string& email) {
	for (iterator it = objects.begin(); it != objects.end(); it ++) {
        if ((*it)->getEmail() == email) {
			return *it;
		}
	}
    return NULL;
}

void Group::add(Client* ptr) {
    if (ptr != NULL) {
        objects.push_back(ptr);
	} else {
    }
}

Group::iterator Group::begin() {
    return objects.begin();
}

Group::iterator Group::end() {
    return objects.end();
}
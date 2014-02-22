#include "Group.h"
#include "Client.h"

using namespace std;

Client* Group::operator[](const string& email) {
	for (Client *client : objects)
        if ((*client).getEmail() == email) return client;
    return NULL;
}

void Group::add(Client* ptr) {
    if (ptr != NULL)
        objects.push_back(ptr);
    else {
    }
}

Group::iterator Group::begin() {
    return objects.begin();
}

Group::iterator Group::end() {
    return objects.end();
}
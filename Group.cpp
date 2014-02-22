#include "Group.h"
#include "Client.h"

using namespace std;

Client* Group::operator[](const string& email) {
    for (int i = 0; i < objects.size(); i++) {
        Client *result = objects[i];
        if ((*result).getEmail() == email)
            return result;
    }
    return NULL;
}

void Group::add(Client* ptr) {
    if (ptr != NULL)
        objects.push_back(ptr);
    else {
    }
}

Group::iterator begin() {
    return objects.begin();
}

Group::iterator end() {
    return objects.end();
}
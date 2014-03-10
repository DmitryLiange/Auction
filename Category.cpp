#include "Category.h"
using namespace std;

Category::Category() : parent(0), name("") {}

Category::Category(int parent, string name) : parent(parent), name(name) {}

int Category::getNumber(void) const {
	return this->number;
}
int Category::getParent(void) const {
	return this->parent;
}
string Category::getName(void) const {
	return this->name;
}
void Category::setNumber(int number) {
	this->number = number;
}
void Category::setParent(int parent) {
	this->parent = parent;
}
void Category::setName(string name) {
	this->name = name;
}

void Category::addSubCategory(Category* ptr) {
	sub_categories.push_back(ptr);
}

void Category::addItem(int item) {
	items.push_back(item);
}

vector<int>::iterator Category::itemsBegin() {
	return items.begin();
}

vector<int>::iterator Category::itemsEnd() {
	return items.end();
}

vector<Category*>::iterator Category::subCategoriesBegin() {
	return sub_categories.begin();
}

vector<Category*>::iterator Category::subCategoriesEnd() {
	return sub_categories.end();
}

bool Category::operator==(const Category& rhs) {
	return this->getNumber() == rhs.getNumber();
}

void Category::findOfferings(Listing::iterator start, Listing::iterator finish, Listing &matches) {
	
	for (Listing::iterator iter = start; iter != finish; iter++) {
		for (vector<int>::iterator secondIter = itemsBegin(); secondIter != itemsEnd(); secondIter++) {
			if (*secondIter == (*iter)->getNumber()) {
				matches.add(*iter);
			}
		}
	}

}

void Category::findOfferingsRecursive(Listing::iterator start, Listing::iterator finish, Listing &matches) {

	findOfferings(start, finish, matches);

	vector<Category*>::iterator iter;
	
	for (iter = this->subCategoriesBegin(); iter != this->subCategoriesEnd(); iter++) {
		(*iter)->findOfferingsRecursive(start, finish, matches);
	}
}

istream &operator>>(istream &stream, Category &c) {

	string currentName;
	int currentParent;
	
	stream >> currentParent >> currentName;

	c.setName(currentName);
	c.setParent(currentParent);

	return stream;
}

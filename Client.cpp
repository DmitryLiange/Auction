// Created by group 3.1.2 
#include "Client.h"
#include <string>

using namespace std;

Client::Client(void): fname(""), lname(""), email(""), passwd("") {}; //default constructor

Client::Client(Client const &c) : //copy constructor
	fname(c.fname), lname(c.lname), email(c.email), passwd(c.passwd) {};

Client::Client(string &fname, string &lname, string &email, string &passwd)://parametrized constructor
	fname(fname), lname(lname), email(email), passwd(passwd) {};

void Client::setFname(const string &fname) { //mutator for first name
	this->fname = fname;
}

void Client::setLname(const string &lname) { //mutator for last name
	this->lname = lname;
}
void Client::setEmail(const string &email) { //mutator for e-mail
	this->email = email;
}
	
void Client::setPasswd(const string &passwd) { //mutator for password
	this->passwd = passwd;
}


string Client::getFname () const { //accessor for first name
	return fname;
}

string Client::getLname () const { //accessor for last name
	return lname;
}

string Client::getEmail () const { //accessor for e-mail
	return email;
}

string Client::getPasswd () const { //accessor for password
	return passwd;
}

bool Client::verifyPasswd(string passwd) { //verifing password, returns true if password matches parameter
	return this->passwd == passwd;
}

istream &operator>>(istream &stream, Client &c) { //override for stream input 
	string fname, lname, email, passwd;

	stream >> fname >> lname >> email >> passwd;
	c.setFname(fname);
	c.setLname(lname);
	c.setEmail(email);
	c.setPasswd(passwd);

	return stream;
}

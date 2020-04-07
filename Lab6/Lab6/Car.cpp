#include "Car.h"
#include <string.h>
#include <sstream>

Car::Car() {
	this->name = NULL;
	this->numar = NULL;
	this->status = NULL;
}

Car::Car(const char* name, const char* numar, const char* status) {
	if (name) {
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	if (status) {
		this->status = new char[strlen(status) + 1];
		strcpy_s(this->status, strlen(status) + 1, status);
	}
	if (numar) {
		this->numar = new char[strlen(numar) + 1];
		strcpy_s(this->numar, strlen(numar) + 1, numar);
	}
}

Car::Car(const Car& e) {
	if (e.name) {
		this->name = new char[strlen(e.name) + 1];
		strcpy_s(this->name, strlen(e.name) + 1, e.name);
	}
	if (e.status) {
		this->status = new char[strlen(e.status) + 1];
		strcpy_s(this->status, strlen(e.status) + 1, e.status);
	}
	if (e.numar) {
		this->numar = new char[strlen(e.numar) + 1];
		strcpy_s(this->numar, strlen(e.numar) + 1, e.numar);
	}
}

Car::Car(string line) {
	std::istringstream iss(line);
	string tok1, tok2, tok3;
	iss >> tok1 >> tok2 >> tok3;
	this->name = new char[tok1.length() + 1];
	strcpy_s(this->name, tok1.length() + 1, tok1.c_str());
	this->numar = new char[tok3.length() + 1];
	strcpy_s(this->numar, tok3.length() + 1, tok3.c_str());
	this->status = new char[tok3.length() + 1];
	strcpy_s(this->status, tok3.length() + 1, tok3.c_str());
}

char* Car::getName() {
	return this->name;
}

char* Car::getNumar() {
	return this->numar;
}

char* Car::getStatus() {
	return this->status;
}

void Car::setName(const char* name) {
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Car::setNumar(const char* numar) {
	if (this->numar) {
		delete[] this->numar;
	}
	this->numar = new char[strlen(numar) + 1];
	strcpy_s(this->numar, strlen(numar) + 1, numar);
}

void Car::setStatus(const char* status) {
	if (this->status&&(this->status=="ocupat"||this->status=="liber")) {
		delete[] this->status;
	}
	this->status = new char[strlen(status) + 1];
	strcpy_s(this->status, strlen(status) + 1, status);
}

Car::~Car() {
	if (this->name) delete[] this->name;
	if (this->status) delete[] this->status;
	if (this->numar) delete[] this->numar;
}

Car& Car::operator =(const Car& e) {
	if (this == &e) return *this; //in case of self assignment
	if (e.name) {
		if (this->name)delete[]this->name;
		this->name = new char[strlen(e.name) + 1];
		strcpy_s(this->name, strlen(e.name) + 1, e.name);
	}
	if (e.status) {
		if (this->status)delete[]this->status;
		this->status = new char[strlen(e.status) + 1];
		strcpy_s(this->status, strlen(e.status) + 1, e.status);
	}
	if (e.numar) {
		if (this->numar)delete[]this->numar;
		this->numar = new char[strlen(e.numar) + 1];
		strcpy_s(this->numar, strlen(e.numar) + 1, e.numar);
	}
	return *this;
}

bool Car::operator==(const Car& e) {
	if (this->name and e.name and this->status and e.status and this->numar and e.numar) {
		return (strcmp(this->name, e.name) == 0) and (strcmp(this->numar, e.numar) == 0) and (strcmp(this->status, e.status) == 0);
	}
	return false;
}

bool Car::operator<(const Car& e) {
	return (strcmp(this->name, e.name) < 0);
}

ostream& operator<<(ostream& os, Car e) {
	os << e.name << " " << e.numar << " " << e.status << endl;
	return os;
}

istream& operator >>(istream& is, Car& e) {
	cout << "Give the name: ";
	char* name = new char[10];
	is >> name;
	cout << "Give the number: ";
	char* numar = new char[10];
	is >> numar;
	cout << "Give the status: ";
	char* status = new char[10];
	is >> status;
	e.setName(name);
	e.setNumar(numar);
	e.setStatus(status);
	delete[] name;
	delete[] status;
	return is;
}
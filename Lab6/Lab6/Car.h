#pragma once
#include<iostream>
#include<string>
using namespace std;
class Car {
private:
	char* name;
	char* numar;
	char* status;
public:
	Car();
	Car(const char*, const char*, const char*);
	Car(const Car&);
	Car& operator= (const Car&);
	Car(string); 

	char* getName();
	char* getNumar();
	char* getStatus();
	void setName(const char*);
	void setNumar(const char*);
	void setStatus(const char*);

	bool operator ==(const Car&);
	bool operator <(const Car&);

	friend ostream& operator <<(ostream& os, Car e);
	friend istream& operator >>(istream& is, Car& e);

	~Car();
};
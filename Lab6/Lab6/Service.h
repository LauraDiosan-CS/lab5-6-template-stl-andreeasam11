#pragma once
#include<list>
#include"Repo.h"
#include<iostream>
using namespace std;

class Service {
private:
	Repo rep;
public:
	Service();
	Service(const Repo&);
	int getSize();
	void addElem(const char*,const char*,const char*);
	void delElem(const char*);
	void updateElem(const char*,const char*,const char*,const char*);
	list<Car> getAll();
	Car elemAtPoz(int j);
	~Service();
};

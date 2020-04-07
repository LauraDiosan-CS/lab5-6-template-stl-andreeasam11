#pragma once
#include"Car.h"
#include<list>
using namespace std;

class Repo {
private:
	list<Car> elem;
public:
	Repo();
	void addElem(Car e);
	int findElem(Car e);
	int size();
	int delElem(Car e);
	void updateElem(Car, const char*, const char*, const char*);
	list<Car>getAll();
	Car elemAtPoz(int);
	~Repo();
};
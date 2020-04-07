#include"Repo.h"
#include"Car.h"
#include<vector>
#include<list>
#include<iterator>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

Repo::Repo() {
}

void Repo::addElem(Car e) {
	elem.push_back(e);
	
}

int Repo::size() {
	return elem.size();
}
int Repo::findElem(Car e)
{
	list<Car>::iterator it;
	it = find(elem.begin(), elem.end(),e);
	if (it != elem.end()) {
		return distance(elem.begin(), it);
	}
	return -1;
}

int Repo::delElem(Car e)
{
	list<Car>::iterator it;
	it = find(elem.begin(), elem.end(), e);
	if (it != elem.end()) {
		elem.erase(it);
		return 0;
	}
	return -1;

}

void Repo::updateElem(Car e, const char* name, const char* numar, const char* status)
{
	list<Car>::iterator it;
	it = find(elem.begin(), elem.end(), e);
	if (it != elem.end()) {
		(*it).setNumar(numar);
		(*it).setName(name);
		(*it).setStatus(status);
	}

}

list<Car>Repo::getAll() {
	return elem;
}
Car Repo::elemAtPoz(int j) {
	list<Car>::iterator it = elem.begin();
	for (int i = 0;i < elem.size();i++)
	{
		if (i == j)
			return *it;
		advance(it, 1);
	}
}

Repo::~Repo() {
}

 
#include"Repo.h"

Repo::Repo() {
}

void Repo::addElem(Car e) {
	//list<int, int>::iterator it;
	elem.push_back(e);
}

int Repo::getSize() {
	return elem.size();
}

list<Car> Repo::getAll() {
	return elem;
}

Repo::~Repo() {
}

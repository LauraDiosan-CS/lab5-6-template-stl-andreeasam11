#include "Repo.h"
#include "testRepo.h"
#include <assert.h>
#include <iostream>

using namespace std;

void testRepo() {
	Car car1("Adina", "BT11ADA", "ocupat"), car2("ION", "BT11ION", "liber"), car3("Andrei", "BT11AND", "liber"), car4("Andreea", "BT11EEA", "ocupat");
	Repo repo;
	repo.addElem(car1);
	repo.addElem(car2);
	list<Car> rez = repo.getAll();
	assert(rez.size() == 2);
	repo.delElem(car2);
	assert(repo.size() == 1);
	repo.addElem(car3);
	assert(repo.findElem(car3) == 1);
	repo.updateElem(car3, "Andreea", "BT11EEA", "ocupat");
	assert(repo.findElem(car4) == 1);
	assert(repo.elemAtPoz(1) == car4);
	cout << "Repository tests done!" << endl;
}
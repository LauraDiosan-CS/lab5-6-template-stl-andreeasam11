#include "RepositoryFile.h"
#include "TestRepository.h"
#include <assert.h>
#include <iostream>

using namespace std;

void testRepository() {
	RepositoryFile<Masina> repo("repositoryTests.txt");
	Masina car5("sebi", "bt24seb", "liber");
	assert(repo.findElem(car5) == 1);
	repo.delElem(car5);
	Masina car1("Anaa", "CJ03ANA", "ocupat"), car2("depis", "BT14SEB", "liber"), car3("gigi", "B130GIG", "liber"), car4("Becali", "B13GIG", "ocupat");
	repo.addElem(car1);
	repo.addElem(car2);
	list<Masina> rez = repo.getAll();
	assert(rez.size() == 2);
	repo.delElem(car2);
	assert(repo.size() == 1);
	repo.addElem(car3);
	assert(repo.findElem(car3) == 2);
	repo.updateElem(car3, car4);
	assert(repo.findElem(car4) == 2);
	repo.delElem(car4);
	repo.delElem(car1);
	cout << "Repository tests done!" << endl;
}
#include <iostream>
#include <assert.h>
#include "Masina.h"
#include "RepoTemplate.h"
#include "Service.h"

using namespace std;

void testService() {
	int op;
	RepositoryFile<Masina> r("serviceTests.txt");
	Service service(r);
	service.setLocuriParcare(3);
	Masina car1("radu", "BT03RAD", "liber"), car2("Anaa", "CJ03ANA", "liber"), car3("depis", "BT14SEB", "liber"), car4("gigi", "B130GIG", "liber");
	assert(service.addMasina(car2) == 0);
	op = service.addMasina(car3);
	op = service.addMasina(car4);
	assert(service.getAll().size() == 3);
	service.delMasina(car3);
	assert(service.getAll().size() == 2);
	service.updateMasina(car4, car3);
	assert(service.getAll().back() == car3);
	Masina m1("depis", "BT14SEB", "liber"), m2("laur", "BT09AUR", "ocupat"), m3("ana", "B03UIJ", "liber"), m4("laur", "BT09AUR", "liber");
	assert(service.addMasina(m1) == 2);
	assert(service.addMasina(m2) == 3);
	op = service.addMasina(m3);
	assert(service.addMasina(m4) == 1);
	assert(service.getDepasesteCapacitatea() == 1);
	remove("serviceTests.txt");
	cout << "Service tests done!" << endl;
}
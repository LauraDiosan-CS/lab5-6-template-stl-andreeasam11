#include <iostream>
#include <assert.h>
#include "Car.h"
#include "Repo.h"
#include "Service.h"

using namespace std;

void testService() {
	Repo r;
	Service service(r);
	Car c1("Andreea", "BT11EEA", "liber");
	service.addElem("Adina", "BT05ADA", "ocupat");
	service.addElem("Simona", "BT10SIM", "liber");
	service.addElem("Dan", "BT12DAN", "liber");
	assert(service.getAll().size() == 3);
	service.delElem("BT10SIM");
	assert(service.getAll().size() == 2);
	service.updateElem("BT12DAN", "Andreea", "BT11EEA", "liber");
	assert(service.getAll().back() == c1);
	cout << "Service tests done!" << endl;
}
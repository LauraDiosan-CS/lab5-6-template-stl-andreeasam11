#include <assert.h>
#include <iostream>
#include <string.h>
#include "Masina.h"
#include "TestDomain.h"

using namespace std;

void testMasina() {
	Masina car1("Ana", "CJ03ANA", "ocupat"), car2;
	assert(strcmp(car1.getNumePosesor(), "Ana") == 0);
	assert(strcmp(car1.getNrInmatriculare(), "CJ03ANA") == 0);
	assert(strcmp(car1.getStatus(), "ocupat") == 0);
	car2 = car1;
	assert(car2 == car1);
	cout << "tests done!" << endl;
}
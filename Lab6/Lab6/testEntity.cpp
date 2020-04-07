#include"testEntity.h"
#include"Car.h"
#include<assert.h>
#include<iostream>
using namespace std;
void testEntity() {
	Car e1("aaaa", "BT 53 AAA", "liber");
	Car e2(e1);
	Car e3;
	assert(e3.getName() == NULL);
	assert(e3.getNumar() == NULL);
	assert(e3.getStatus() == NULL);
	e3 = e2;
	assert(strcmp(e3.getName(), "aaaa") == 0);
	assert(strcmp(e2.getName(), "aaaa") == 0);
	assert(e1 == e2);
	e2.setNumar("BT 53 SSS");
	assert(strcmp(e2.getNumar(), "BT 53 SSS") == 0);
	cout << "Test Entity successful!";
}
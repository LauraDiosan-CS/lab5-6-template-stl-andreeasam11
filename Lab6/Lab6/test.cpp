#include "test.h"
#include "assert.h"
#include<iostream>
#include<string.h>
#include <vector>
using namespace std;

Tests::Tests() {
}

void Tests::testDomain() {
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
}

void Tests::testRepo() {
	Car e1("aaa", "BT 53 AAA", "liber");
	Car e2("bbb", "MS 54 AAA", "ocupat");
	Car e3("ccc", "MS 55 AAA", "liber");
	Car e4("ddd", "MS 56 AAA", "ocupat");
	Repo rep;
	rep.addElem(e1);
	rep.addElem(e2);
	rep.addElem(e3);
	rep.addElem(e4);
	assert(rep.getSize() == 4);
}
Tests::~Tests() {
	}

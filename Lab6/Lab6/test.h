#pragma once
#include"Repo.h"
class Tests {
private:
	Repo repo;
public:
	Tests();
	void testDomain();
	void testRepo();
	~Tests();
};
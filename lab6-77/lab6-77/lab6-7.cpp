// Lab6-7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tests.h"
#include "Repository.h"
#include "RepoFile.h"
#include "Service.h"
#include "UI.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Start tests..." << endl;
	testCar();
	testRepo();
	testService();
	testRepoFile();
	cout << "Tests finished succesfully!" << endl;
	//Repository repo;
	/*Car c("ion", "CJ23AAA", "liber");
	Car c1("ana", "CJ44BBB", "ocupat");
	Car c2("maria", "CJ42BCB", "liber");
	Car c3("ioana", "B47HHH", "ocupat");
	repo.addElem(c);
	repo.addElem(c1);
	repo.addElem(c2);
	repo.addElem(c3);*/
	RepoFile repo("Cars.txt");
	Service serv(repo);
	UI ui(serv);
	ui.run();
	return 0;
}


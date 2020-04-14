#include <iostream>
#include "TestDomain.h"
#include "TestRepository.h"
#include "TestService.h"
#include "RepositoryFile.h"
#include "Service.h"
#include "UserInterface.h"

using namespace std;

int main()
{
	testMasina();
	testRepository();
	testService();
	RepositoryFile<Masina> r("masini.txt");
	Service s(r);
	UserInterface ui(s);
	ui.run();
}
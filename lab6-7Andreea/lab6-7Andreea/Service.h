#pragma once
#include <list>
#include "Masina.h"
#include "RepositoryFile.h"

using namespace std;

class Service {
private:
	RepositoryFile<Masina> repo;
	int locuriParcare, depasesteCapacitatea;
public:
	Service();
	Service(const RepositoryFile<Masina>&);
	int addMasina(Masina&);
	int delMasina(Masina&);
	void setLocuriParcare(int);
	void updateMasina(Masina&, Masina&);
	int getDepasesteCapacitatea();
	list<Masina> getAll();
	~Service();
};
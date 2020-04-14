#include "Service.h"

Service::Service() {
	depasesteCapacitatea = 0;
	locuriParcare = 0;
}

Service::Service(const RepositoryFile<Masina>& r) {
	repo = r;
	locuriParcare = 0;
	depasesteCapacitatea = 0;
}

void Service::setLocuriParcare(int n) {
	locuriParcare = n;
}

int Service::addMasina(Masina& m) {
	if (repo.size() == locuriParcare)
	{
		depasesteCapacitatea++;
		return 1;
	}
	list<Masina> lista = repo.getAll();
	list<Masina>::iterator it = lista.begin();
	for (int i = 0;i < lista.size();i++)
	{
		if (strcmp((*it).getNrInmatriculare(), m.getNrInmatriculare()) == 0)
			return 2;
		advance(it, 1);
	}
	if (strcmp(m.getStatus(), "ocupat") == 0)
		return 3;
	m.setStatus("ocupat");
	repo.addElem(m);
	repo.saveToFile();
	depasesteCapacitatea = 0;
	return 0;
}

list<Masina> Service::getAll() {
	return repo.getAll();
}

int Service::getDepasesteCapacitatea() {
	return depasesteCapacitatea;
}

int Service::delMasina(Masina& m) {
	if (strcmp(m.getStatus(), "liber") == 0)
		return -1;
	repo.delElem(m);
	depasesteCapacitatea = 0;
	repo.saveToFile();
	return 0;
}

void Service::updateMasina(Masina& masinaVeche, Masina& masinaNoua) {
	repo.updateElem(masinaVeche, masinaNoua);
	repo.saveToFile();
}

Service::~Service()
{
}
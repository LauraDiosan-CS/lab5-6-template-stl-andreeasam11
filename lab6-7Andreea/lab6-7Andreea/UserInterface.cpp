#include <iostream>
#include "UserInterface.h"

using namespace std;

UserInterface::UserInterface() {
}

UserInterface::UserInterface(const Service& s) {
	service = s;
}

void UserInterface::showMenu() {
	cout << "---Menu---" << endl;
	cout << "1. Adauga masina" << endl;
	cout << "2. Update masina" << endl;
	cout << "3. Sterge masina" << endl;
	cout << "4. Afiseaza masini" << endl;
	cout << "5. Numarul de masini cu care se depaseste capacitatea" << endl;
	cout << "0. Exit" << endl;
	cout << endl;
}

void UserInterface::addMasina() {
	int op;
	Masina m;
	cout << "Dati masina: "; cin >> m;
	op = service.addMasina(m);
	if (op == 1)
		cout << "Parcarea este plina!" << endl;
	if (op == 2)
		cout << "Masina este deja in parcare!" << endl;
	if (op == 3)
		cout << "Masina are statusul ocupat!" << endl;
	if (op == 0)
		cout << "Masina adaugata!" << endl;
	cout << endl;
}

void UserInterface::depasesteCapacitatea() {
	cout << "Numarul de masini care depasesc capacitatea este: " << service.getDepasesteCapacitatea() << endl;
}

void UserInterface::printMasini() {
	list<Masina> masini = service.getAll();
	for (Masina m : masini)
		cout << m;
	cout << endl;
}

void UserInterface::deleteMasina() {
	int op;
	Masina m;
	cout << "Dati masina: ";	cin >> m;
	op = service.delMasina(m);
	if (op == -1)
	{
		cout << "Masina are statusul liber";
		cout << endl;
	}
	else
	{
		cout << "Masina a fost stearsa!";
		cout << endl;
	}
}

void UserInterface::updateMasina() {
	Masina masinaVeche, masinaNoua;
	cout << "Dati masina: "; cin >> masinaVeche;
	cout << "Dati masina noua: "; cin >> masinaNoua;
	service.updateMasina(masinaVeche, masinaNoua);
	cout << "Update realizat!" << endl;
	cout << endl;
}

void UserInterface::run() {
	int nr;
	cout << "Nr. locuri de parcare: ";	cin >> nr;
	service.setLocuriParcare(nr);
	cout << endl;
	bool gata = true;
	while (gata)
	{
		int op;
		showMenu();
		cout << "Optiunea aleasa: ";
		cin >> op;
		switch (op)
		{
		case 0: {gata = false; break;}
		case 1: {addMasina(); break;}
		case 2: {updateMasina(); break;}
		case 3: {deleteMasina(); break;}
		case 4: {printMasini(); break;}
		case 5: {depasesteCapacitatea(); break;}
		}
	}
}

UserInterface::~UserInterface() {
}
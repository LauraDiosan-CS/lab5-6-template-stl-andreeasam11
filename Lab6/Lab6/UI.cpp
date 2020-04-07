#include"UI.h"
#include"Car.h"
#include<iostream>
using namespace std;
UI::UI() {
}


UI::UI(const Service& ser) {
	s = ser;
}
void UI::display() {
	cout << "\n";
	cout << "********** Main Menu **********" << endl;
	cout << "Alegeti o optiune: " << endl;
	cout << "(1): Adaugare masina." << endl;
	cout << "(2): Afisare masini." << endl;
	cout << "(3): Stergere masina." << endl;
	cout << "(4): Modificare masina." << endl;
	cout << "(5):  Exit." << endl;
	cout << endl;
}


void UI::PrintMenu() {
	int opt;
	do {
		display();
		while (true)
		{
			cin >> opt;
			if (opt == 1)
			{
				char* name = NULL;
				char* numar = NULL;
				char* status = NULL;
				name = new char[20];
				numar = new char[20];
				status = new char[20];
				cout << "\n Introduceti nume: ";
				cin >> name;
				cout << " Introduceti numar: ";
				cin >> numar;
				cout << " Introduceti status:  ";
				cin >> status;
				cout << endl;
				Car e(name, numar, status);
				s.addElem(name, numar, status);
				if (name)
					delete[] name;
				if (numar)
					delete[]numar;
				if (status)
					delete[]status;
				cout << "Masina adaugata!" << endl;
				cout << endl;
				break;
			}
			if (opt == 2)

			{
				for (int i = 0;i < s.getAll().size();i++)
					cout << s.elemAtPoz(i).getName() << " " << s.elemAtPoz(i).getNumar() << " " << s.elemAtPoz(i).getStatus() << endl;
				cout << endl;
				break;
			}
			if (opt == 3)
			{
				char* numar = NULL;
				numar = new char[20];
				cout << "Nr. de inmatriculare: ";	cin >> numar;
				s.delElem(numar);
				if (numar)
					delete[] numar;
				cout << "Masina stearsa!" << endl;
				cout << endl;
				break;
			}
			if (opt == 4)
			{
				char* numar = NULL, * newNume = NULL, * newNumar = NULL, * newStatus = NULL;
				numar = new char[20];
				newNume = new char[20];
				newNumar = new char[20];
				newStatus = new char[20];
				cout << "Nr. inmatriculare: ";	cin >> numar;
				cout << "Noul posesor: ";	cin >> newNume;
				cout << "Noul nr. de inmatriculare: ";	cin >> newNumar;
				cout << "Noul status: ";	cin >> newStatus;
				s.updateElem(numar, newNume, newNumar, newStatus);
				if (numar)
					delete[] numar;
				if (newNume)
					delete[] newNume;
				if (newNumar)
					delete[] newNumar;
				if (newStatus)
					delete[] newStatus;
				cout << "Update realizat!" << endl;
				cout << endl;
				break;
			}
			if (opt == 5) {
				cout << "Exit.";
				exit(0);
			}

			if (opt != 1 && opt != 2 && opt != 3 && opt != 4 && opt != 5) {
				cout << "ERROR!You have selected an invalid choice.";
				break;

			}



		}
	} while (opt != 6);

	}

UI::~UI() {

}
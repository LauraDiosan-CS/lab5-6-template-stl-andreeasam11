#include "Masina.h"
#include <sstream>
#include <string.h>

Masina::Masina() {
	numePosesor = NULL;
	nrInmatriculare = NULL;
	status = NULL;
}

Masina::Masina(const char* numePosesor, const char* nrInmatriculare, const char* status) {
	this->numePosesor = new char[strlen(numePosesor) + 1];
	strcpy_s(this->numePosesor, strlen(numePosesor) + 1, numePosesor);
	this->nrInmatriculare = new char[strlen(nrInmatriculare) + 1];
	strcpy_s(this->nrInmatriculare, strlen(nrInmatriculare) + 1, nrInmatriculare);
	this->status = new char[strlen(status) + 1];
	strcpy_s(this->status, strlen(status) + 1, status);
}

Masina::Masina(string linie) {
	std::istringstream iss(linie);
	string tok1, tok2, tok3;
	iss >> tok1 >> tok2 >> tok3;
	numePosesor = new char[tok1.length() + 1];
	strcpy_s(numePosesor, tok1.length() + 1, tok1.c_str());
	nrInmatriculare = new char[tok2.length() + 1];
	strcpy_s(nrInmatriculare, tok2.length() + 1, tok2.c_str());
	status = new char[tok3.length() + 1];
	strcpy_s(status, tok3.length() + 1, tok3.c_str());
}

Masina::Masina(const Masina& m) {
	this->numePosesor = new char[strlen(m.numePosesor) + 1];
	strcpy_s(this->numePosesor, strlen(m.numePosesor) + 1, m.numePosesor);
	this->nrInmatriculare = new char[strlen(m.nrInmatriculare) + 1];
	strcpy_s(this->nrInmatriculare, strlen(m.nrInmatriculare) + 1, m.nrInmatriculare);
	this->status = new char[strlen(m.status) + 1];
	strcpy_s(this->status, strlen(m.status) + 1, m.status);
}

Masina& Masina::operator=(const Masina& m) {
	if (this == &m) return *this;
	if (numePosesor) delete[] numePosesor;
	numePosesor = new char[strlen(m.numePosesor) + 1];
	strcpy_s(numePosesor, strlen(m.numePosesor) + 1, m.numePosesor);
	if (nrInmatriculare) delete[] nrInmatriculare;
	nrInmatriculare = new char[strlen(m.nrInmatriculare) + 1];
	strcpy_s(nrInmatriculare, strlen(m.nrInmatriculare) + 1, m.nrInmatriculare);
	if (status) delete[] status;
	status = new char[strlen(m.status) + 1];
	strcpy_s(status, strlen(m.status) + 1, m.status);
	return *this;
}

char* Masina::getNumePosesor() {
	return numePosesor;
}

char* Masina::getNrInmatriculare() {
	return nrInmatriculare;
}

char* Masina::getStatus() {
	return status;
}

void Masina::setNumePosesor(const char* n) {
	if (numePosesor) delete[] numePosesor;
	numePosesor = new char[strlen(n) + 1];
	strcpy_s(numePosesor, strlen(n) + 1, n);
}

void Masina::setNrInmatriculare(const char* nr) {
	if (nrInmatriculare) delete[] nrInmatriculare;
	nrInmatriculare = new char[strlen(nr) + 1];
	strcpy_s(nrInmatriculare, strlen(nr) + 1, nr);
}

void Masina::setStatus(const char* stat) {
	if (status) delete[] status;
	status = new char[strlen(stat) + 1];
	strcpy_s(status, strlen(stat) + 1, stat);
}

bool Masina::operator==(const Masina& m) {
	return (strcmp(numePosesor, m.numePosesor) == 0) and (strcmp(nrInmatriculare, m.nrInmatriculare) == 0) and (strcmp(status, m.status) == 0);
}

ostream& operator<<(ostream& os, Masina m) {
	os << m.getNumePosesor() << " " << m.getNrInmatriculare() << " " << m.getStatus() << endl;
	return os;
}

istream& operator>>(istream& is, Masina& m) {
	char* numePosesor = NULL, * nrInmatriculare = NULL, * status = NULL;
	numePosesor = new char[20];
	nrInmatriculare = new char[20];
	status = new char[20];
	cout << "Nume posesor: ";	is >> numePosesor;
	cout << "Numar inmatriculare: ";	is >> nrInmatriculare;
	cout << "Status (ocupat, liber): ";	is >> status;
	m.setNumePosesor(numePosesor);
	m.setNrInmatriculare(nrInmatriculare);
	m.setStatus(status);
	if (numePosesor)
		delete[] numePosesor;
	if (nrInmatriculare)
		delete[] nrInmatriculare;
	if (status)
		delete[] status;
	return is;
}

Masina::~Masina() {
	if (numePosesor) delete[] numePosesor;
	numePosesor = NULL;
	if (nrInmatriculare) delete[] nrInmatriculare;
	nrInmatriculare = NULL;
	if (status) delete[] status;
	status = NULL;
}
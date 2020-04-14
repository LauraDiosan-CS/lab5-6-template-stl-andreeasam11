#pragma once
#include "RepoTemplate.h"
#include <fstream>
#include <string.h>
using namespace std;


template<class T> class RepositoryFile : public RepoTemplate<Masina> {
private:
	const char* fis;
public:
	RepositoryFile();
	RepositoryFile(const char*);
	void loadFromFile(const char*);
	void saveToFile();
	~RepositoryFile();
};

template<class T>
RepositoryFile<T>::RepositoryFile() {
}

template<class T>
RepositoryFile<T>::RepositoryFile(const char* fileName) {
	fis = fileName;
	string linie;
	ifstream fin(fileName);
	while (getline(fin, linie))
	{
		T m(linie);
		addElem(m);
	}
	fin.close();
}

template<class T>
void RepositoryFile<T>::loadFromFile(const char* fileName) {
	elem.clear();
	fis = fileName;
	string linie;
	ifstream fin(fileName);
	while (getline(fin, linie))
	{
		T m(linie);
		addElem(m);
	}
	fin.close();
}

template<class T>
void RepositoryFile<T>::saveToFile() {
	ofstream fout(fis);
	typename list<T>::iterator it = elem.begin();
	for (int i = 0;i < size();i++)
	{
		fout << (*it);
		advance(it, 1);
	}
}

template<class T>
RepositoryFile<T>::~RepositoryFile() {
}
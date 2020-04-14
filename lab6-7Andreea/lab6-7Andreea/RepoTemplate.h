#pragma once
#include <list>
#include "Masina.h"
#include <algorithm>
using namespace std;

template <class T>class RepoTemplate
{
protected:
	list<T> elem;
public:
	RepoTemplate<T>() {}
	void addElem(const T&);
	int delElem(const T&);
	int findElem(const T&);
	int size();
	void updateElem(const T& s, const T nou);
	list<T> getAll();
	~RepoTemplate();
};





template<class T>
void RepoTemplate<T>::addElem(const T& e)
{
	elem.push_back(e);
}

template<class T>
int RepoTemplate<T>::delElem(const T& m)
{
	typename list<T>::iterator it;
	it = find(elem.begin(), elem.end(), m);
	if (it != elem.end())
		elem.erase(it);
	return 0;
}

template<class T>
int RepoTemplate<T>::findElem(const T& e)
{
	int index = 0;
	for (T crt : elem) {
		index++;
		if (crt == e) return index;
	}
	return -1;
}

template<class T>
int RepoTemplate<T>::size()
{
	return elem.size();
	return 0;
}

template<class T>
void RepoTemplate<T>::updateElem(const T& vechi, const T nou)
{
	replace(elem.begin(), elem.end(), vechi, nou);
}

template<class T>
list<T> RepoTemplate<T>::getAll()
{
	return elem;
	return list<T>();
}


template <class T> RepoTemplate<T>::~RepoTemplate()
{
}
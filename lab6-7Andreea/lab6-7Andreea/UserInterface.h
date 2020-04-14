#pragma once
#include "Service.h"

class UserInterface {
private:
	Service service;
public:
	UserInterface();
	UserInterface(const Service&);
	void showMenu();
	void addMasina();
	void deleteMasina();
	void updateMasina();
	void printMasini();
	void depasesteCapacitatea();
	void run();
	~UserInterface();
};
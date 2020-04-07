#pragma once
#include"Service.h"
class UI {
private:
	Service s;
public:
	void display();
	void PrintMenu();
	UI();
	UI(const Service&);
	~UI();
};
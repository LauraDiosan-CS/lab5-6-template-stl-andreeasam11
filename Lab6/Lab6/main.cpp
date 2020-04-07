#include"testEntity.h"
#include"testRepo.h"
#include"testService.h"
#include"Service.h"
#include"UI.h"
#include"Repo.h"
#include<iostream>
using namespace std;

int main() {
	cout << "start" << endl;
	UI u;
	testEntity();
	testRepo();
	testService();
	u.PrintMenu();
	cout << "succes" << endl;

	return 0;
}

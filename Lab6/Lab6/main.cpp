#include"test.h"
#include"Repo.h"

int main() {
	cout << "start" << endl;
	Tests test;
	test.testDomain();
	test.testRepo();
	cout << "succes" << endl;

	return 0;
}

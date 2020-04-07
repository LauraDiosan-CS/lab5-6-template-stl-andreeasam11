#include"Service.h"
Service::Service() {

}

Service::Service(const Repo& r) {
	rep = r;
}

int Service::getSize() {
	return rep.size();

}

void Service::addElem(const char* name,const char*numar,const char* status) {
	Car e(name, numar, status);
	rep.addElem(e);
}

void Service::delElem(const char* numar) {
	for (int i = 0;i < rep.size();i++)
	{
		Car e = rep.elemAtPoz(i);
		if (strcmp(e.getNumar(), numar) == 0)
		{
			rep.delElem(e); break;
		}
	}
}

list<Car> Service::getAll() {
	return rep.getAll();
}


void Service::updateElem(const char* numar, const char* newNume, const char* newNumar, const char* newStatus) {
	for (int i = 0;i < rep.size();i++)
	{
		Car e = rep.elemAtPoz(i);
		if (strcmp(e.getNumar(), numar) == 0)
		{
			rep.updateElem(e, newNume, newNumar, newStatus); 
			break;
		}
	}
}
Car Service::elemAtPoz(int j)
{
	return rep.elemAtPoz(j);
}
Service::~Service() {

}

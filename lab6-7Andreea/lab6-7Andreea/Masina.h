#pragma once
#include <string>
#include <iostream>

using namespace std;

class Masina {
private:
    char* numePosesor, * nrInmatriculare, * status;
public:
    Masina();
    Masina(const char*, const char*, const char*);
    Masina(string);
    Masina(const Masina&);
    Masina& operator=(const Masina&);
    char* getNumePosesor();
    char* getNrInmatriculare();
    char* getStatus();
    void setNumePosesor(const char*);
    void setNrInmatriculare(const char*);
    void setStatus(const char*);
    bool operator==(const Masina&);
    friend ostream& operator<<(ostream&, Masina);
    friend istream& operator>>(istream&, Masina&);
    ~Masina();
};
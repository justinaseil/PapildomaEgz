#ifndef MYLIB_H
#define MYLIB_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cctype>
#include <set>
#include <iomanip>

using namespace std;

struct Tekstas {
    map<string, int> zodziai;
    set<int> eilutes;
};

string Skyryba(const string& zodis);
Tekstas TekstoApdor(const string& ivedimoFailas);
bool Rezultatas(const string& isvedimoFailas, const Tekstas& tekstas);

string getFilas();

#endif // MYLIB_H



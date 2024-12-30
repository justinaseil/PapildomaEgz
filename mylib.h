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
#include <algorithm>
#include <vector>
#include <regex>

using namespace std;

struct Tekstas {
    map<string, set<int>> zodziai;
    map<string, int> zodziuKiekis;
    set<int> eilutes;
};

string Skyryba(const string& zodis);
Tekstas TekstoApdor(const string& ivedimoFailas);
bool Rezultatas(const string& isvedimoFailas, const Tekstas& tekstas);
string getFailas();
bool ZodziaiEilutese(const map<string, set<int>>& zodziuEilutes, const map<string, int>& zodziuKiekis, const string& isvedimoFailas);
vector<string> RastiURL(const string& failoPavadinimas);
bool IšvediURLįFailą(const string& isvedimoFailas, const vector<string>& urls);

#endif // MYLIB_H




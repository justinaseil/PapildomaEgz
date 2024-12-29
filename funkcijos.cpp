#include "mylib.h"

string Skyryba(const string& zodis) {
    string valymas;
    for (char ch : zodis) {
        if (isalnum(static_cast<unsigned char>(ch))) {
            valymas += tolower(static_cast<unsigned char>(ch));
        }
    }
    return valymas;
}

Tekstas TekstoApdor(const string& ivedimoFailas) {
    ifstream ived(ivedimoFailas);
    Tekstas tekstas;

    if (!ived) {
        cerr << "Nepavyko atidaryti failo!" << endl;
        return tekstas;
    }

    string line;
    int lineNumber = 0;
    while (getline(ived, line)) {
        ++lineNumber;
        istringstream linestream(line);
        string zodis;
        while (linestream >> zodis) {
            string isvalytasZodis = Skyryba(zodis);
            if (!isvalytasZodis.empty()) {
                tekstas.zodziai[isvalytasZodis].insert(lineNumber);
                tekstas.zodziuKiekis[isvalytasZodis]++;
                tekstas.eilutes.insert(lineNumber);
            }
        }
    }
    ived.close();

    cout << "Tekste yra " << lineNumber << " eilučių." << endl;

    return tekstas;
}

bool Rezultatas(const string& isvedimoFailas, const Tekstas& tekstas) {
    ofstream isved(isvedimoFailas);
    if (!isved) return false;

    for (const auto& [key, value] : tekstas.zodziuKiekis) {
        if (value > 1) {
            isved << key << ": " << value << "\n";
        }
    }

    isved.close();
    return true;
}

bool ZodziaiEilutese(const map<string, set<int>>& zodziuEilutes, const map<string, int>& zodziuKiekis, const string& isvedimoFailas) {
    ofstream isved(isvedimoFailas);
    if (!isved) return false;

    int maxEilute = 0;
    for (const auto& [zodis, eilutes] : zodziuEilutes) {
        for (int eilute : eilutes) {
            if (eilute > maxEilute) {
                maxEilute = eilute;
            }
        }
    }

    vector<string> zodziai;
    for (const auto& [zodis, kiekis] : zodziuKiekis) {
        if (kiekis > 1) {
            zodziai.push_back(zodis);
        }
    }

    if (zodziai.empty()) {
        isved << "Nėra žodžių, kurie pasikartoja daugiau nei 1 kartą.\n";
        return true;
    }

    for (const auto& zodis : zodziai) {
        isved << setw(15) << left << zodis;
    }
    isved << "\n";

    for (int eilute = 1; eilute <= maxEilute; ++eilute) {
        isved << setw(10) << left << eilute;

        for (const auto& zodis : zodziai) {
            auto it = zodziuEilutes.find(zodis);
            if (it != zodziuEilutes.end() && it->second.count(eilute) > 0) {
                int count = 0;
                for (const auto& el : it->second) {
                    if (el == eilute) {
                        count++;
                    }
                }
                isved << setw(10) << count;
            } else {
                isved << setw(10) << "0";
            }
        }
        isved << "\n";
    }

    isved.close();
    return true;
}

string getFailas() {
    string filas;
    cout << "Įvaskite failo pavadinimą: ";
    getline(cin, filas);
    return filas;
}

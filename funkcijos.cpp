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
                tekstas.eilutes.insert(lineNumber);
            }
        }
    }
    ived.close();
    return tekstas;
}

bool Rezultatas(const string& isvedimoFailas, const Tekstas& tekstas) {
    ofstream isved(isvedimoFailas);
    if (!isved) return false;

    for (const auto& [key, value] : tekstas.zodziai) {
        if (value.size() > 1) {
            isved << key << ": " << value.size() << "\n";
        }
    }

    isved.close();
    return true;
}

bool ZodziaiEilutese(const map<string, set<int>>& zodziuEilutes, const string& isvedimoFailas) {
    ofstream isved(isvedimoFailas);
    if (!isved) return false;

    for (const auto& [zodis, eilutes] : zodziuEilutes) {
        if (eilutes.size() > 1) {
            isved << zodis << ": ";
            for (int eilute : eilutes) {
                isved << eilute << " ";
            }
            isved << "\n";
        }
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

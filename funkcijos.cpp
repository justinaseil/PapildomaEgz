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

    while (!ived) {
        cerr << "Nepavyko atidaryti failo '" << ivedimoFailas << "'! Bandykite dar kartą." << std::endl;
        ived.clear();
        string naujasFailas = getFilas();
        if (naujasFailas.empty()) {
            cerr << "Nenurodytas failas. Išeinama." << std::endl;
            return tekstas;
        }
        ived.open(naujasFailas);
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
                tekstas.zodziai[isvalytasZodis]++;
                tekstas.eilutes.insert(lineNumber);
            }
        }
    }

    ived.close();
    return tekstas;
}

bool Rezultatas(const string& isvedimoFailas, const Tekstas& tekstas) {
    ofstream isved(isvedimoFailas);
    if (!isved) {
        return false;
    }

    for (const auto& [key, value] : tekstas.zodziai) {
        if (value > 1) {
            isved << key << ": " << value << "\n";
        }
    }

    isved << "Eilučių numeriai: ";
    for (int eilute : tekstas.eilutes) {
        isved << eilute << " ";
    }
    isved << "\n";

    isved.close();
    return true;
}

string getFilas() {
    string filas;
    cout << "Įveskite failo pavadinimą: ";
    getline(cin, filas);
    return filas;
}

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

vector<string> RastiURL(const string& failoPavadinimas) {
    vector<string> urls;

    ifstream failas(failoPavadinimas);
    if (!failas) {
        cerr << "Nepavyko atidaryti failo: " << failoPavadinimas << endl;
        return urls;
    }

    stringstream buffer;
    buffer << failas.rdbuf();
    string tekstas = buffer.str();

    regex url_pattern(R"((https?|ftp):\/\/[^\s\/$.?#].[^\s]*|www\.[^\s\/$.?#].[^\s]*)");

    auto words_begin = sregex_iterator(tekstas.begin(), tekstas.end(), url_pattern);
    auto words_end = sregex_iterator();

    for (auto it = words_begin; it != words_end; ++it) {
        string url = it->str();
        cout << "Rastas URL: " << url << endl;
        urls.push_back(url);
    }

    return urls;
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

    for (size_t i = 0; i < zodziai.size(); ++i) {
        isved << setw(15) << setfill('-') << "" << setfill(' ');
    }
    isved << "\n";

    for (int eilute = 1; eilute <= maxEilute; ++eilute) {
        for (const auto& zodis : zodziai) {
            auto it = zodziuEilutes.find(zodis);
            if (it != zodziuEilutes.end() && it->second.count(eilute) > 0) {
                isved << setw(15) << "1";
            } else {
                isved << setw(15) << "0";
            }
        }
        isved << "\n";
    }

    isved.close();
    return true;
}

bool IšvediURLįFailą(const string& isvedimoFailas, const vector<string>& urls) {
    ofstream isved(isvedimoFailas);
    if (!isved) {
        cerr << "Nepavyko sukurti failo '" << isvedimoFailas << "'!" << endl;
        return false;
    }

    if (urls.empty()) {
        isved << "Nera URL adresu tekste.\n";
    } else {
        for (const auto& url : urls) {
            isved << url << "\n";
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

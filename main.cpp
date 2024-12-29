#include "mylib.h"

int main() {
    string ivedimoFailas = getFailas();
    string isvedimoFailasRezultatai = "zodziu_kiekis.txt";
    string isvedimoFailasCrossRef = "zodziaieilutese.txt";

    Tekstas tekstas = TekstoApdor(ivedimoFailas);

    if (!Rezultatas(isvedimoFailasRezultatai, tekstas)) {
        cerr << "Nepavyko sukurti failo '" << isvedimoFailasRezultatai << "'!" << endl;
        return 1;
    }

    if (!ZodziaiEilutese(tekstas.zodziai, tekstas.zodziuKiekis, isvedimoFailasCrossRef)) {
        cerr << "Nepavyko sukurti cross-reference lentelės failo '" << isvedimoFailasCrossRef << "'!" << endl;
        return 1;
    }

    cout << "Rezultatai išsaugoti faile '" << isvedimoFailasRezultatai << "'!" << endl;
    cout << "Cross-reference lentelė išsaugota faile '" << isvedimoFailasCrossRef << "'!" << endl;

    return 0;
}

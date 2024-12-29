#include "mylib.h"

int main() {
    string ivedimoFailas = getFilas();
    string isvedimoFailas = "rezultatai.txt";

    Tekstas tekstas = TekstoApdor(ivedimoFailas);

    if (!Rezultatas(isvedimoFailas, tekstas)) {
        cerr << "Nepavyko sukurti failo '" << isvedimoFailas << "'!" << std::endl;
        return 1;
    }

    cout << "Rezultatai išsaugoti faile '" << isvedimoFailas << "'!" << std::endl;

    return 0;
}

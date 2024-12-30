# Žodžių analizės programa

Ši programa skirta atlikti teksto analizę, naudojant C++ programavimo kalbą. Ji apdoroja pateiktą tekstinį failą ir išveda šiuos rezultatus į atskirus failus:

1. **Žodžių dažnio analizė**: kiekvieno daugiau nei vieną kartą pasikartojusio žodžio dažnis.
2. **Cross-reference lentelė**: kuriose teksto eilutėse daugiau nei vieną kartą pasikartoję žodžiai buvo paminėti.
3. **URL adresų suradimas**: visi tekste esantys URL adresai.

---

## Funkcionalumas

1. **Žodžių dažnio analizė**
   - Programa suskaičiuoja, kiek kartų kiekvienas žodis pasikartoja tekste.
   - Žodžiai, kurie pasikartoja daugiau nei vieną kartą, yra išvedami į failą `zodziu_kiekis.txt`.

2. **Cross-reference lentelė**
   - Sugeneruojama lentelė, rodanti, kuriose teksto eilutėse (jei yra) pasikartojantys žodžiai atsiranda.
   - Rezultatai išsaugomi faile `zodziaieilutese.txt`.

3. **URL adresų suradimas**
   - Tekste ieškoma URL adresų (pvz., `https://`, `www.` ir pan.) naudojant reguliarias išraiškas.
   - Rasti URL adresai išvedami į failą `urls.txt`.

---

### 2. Failų įvestis ir išvestis
- Programa paprašys įvesti apdorojamo failo pavadinimą (pvz., `tekstas.txt`).
- Rezultatai bus išsaugoti šiuose failuose:
  - `zodziu_kiekis.txt` – žodžių dažnio analizė.
  - `zodziaieilutese.txt` – cross-reference lentelė.
  - `urls.txt` – rasti URL adresai.

---

## Kodo apžvalga

### Pagrindinės funkcijos

1. **`Skyryba`**
   - Pašalina skyrybos ženklus ir mažina didžiąsias raides.
   
2. **`TekstoApdor`**
   - Skaito tekstą iš failo ir atlieka žodžių analizę:
     - Saugo žodžius, jų pasikartojimus ir eilučių numerius.

3. **`Rezultatas`**
   - Išsaugo daugiau nei vieną kartą pasikartojusius žodžius į failą.

4. **`ZodziaiEilutese`**
   - Sugeneruoja lentelę, rodydama žodžių pasikartojimus eilutėse.

5. **`RastiURL`**
   - Naudoja reguliarias išraiškas URL adresų paieškai.

---

## Pavyzdiniai failai ir rezultatai

### Pateiktas tekstinis failas (`tekstas.txt`):

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>  // Dla użycia zbioru (set)
using namespace std;

// Funkcja do znajdowania duplikatów metodą brute force
void znajdzDuplikatyBruteForce(int tablica[], int rozmiar, ofstream &plikWyjsciowy, int &lp) {
    unordered_set<int> duplikaty; // Zbiór, aby przechowywać już wypisane duplikaty
    bool znalezionoDuplikaty = false;
    for (int i = 0; i < rozmiar; i++) {
        for (int j = i + 1; j < rozmiar; j++) {
            lp++; // Zliczamy operację porównania
            if (tablica[i] == tablica[j] && duplikaty.find(tablica[i]) == duplikaty.end()) {
                plikWyjsciowy << "Duplikat znaleziony (brute force): " << tablica[i] << endl;
                duplikaty.insert(tablica[i]); // Dodajemy duplikat do zbioru
                znalezionoDuplikaty = true;
            }
        }
    }
    if (!znalezionoDuplikaty) {
        plikWyjsciowy << "Brak duplikatow (brute force)." << endl;
    }
    plikWyjsciowy << "Liczba operacji : " << lp << endl; // Zapisujemy liczbę operacji do pliku


    cout << "Liczba operacji : " << lp << endl;
}

int main() {
    // Wczytaj dane z pliku wejściowego
    string nazwaPlikuWejsciowego = "dane_wejsciowe_brute.txt";
    string nazwaPlikuWyjsciowego = "wyniki_brute.txt";

    ifstream plikWejsciowy(nazwaPlikuWejsciowego);
    if (!plikWejsciowy.is_open()) {
        cerr << "Nie mozna otworzyc pliku wejsciowego!" << endl;
        return 1;
    }

    vector<int> tablica;
    int liczba;
    while (plikWejsciowy >> liczba) {
        tablica.push_back(liczba);
    }
    plikWejsciowy.close();

    int rozmiar = tablica.size();
    if (rozmiar < 2) {
        cerr << "Tablica musi miec co najmniej dwa elementy!" << endl;
        return 1;
    }

    // Otwieramy plik wyjściowy
    ofstream plikWyjsciowy(nazwaPlikuWyjsciowego);
    if (!plikWyjsciowy.is_open()) {
        cerr << "Nie mozna otworzyc pliku wyjsciowego!" << endl;
        return 1;
    }

    int lp = 0;  // Zmienna do zliczania liczby operacji
    // Wywołanie funkcji
    znajdzDuplikatyBruteForce(tablica.data(), rozmiar, plikWyjsciowy, lp);

    plikWyjsciowy.close();
    cout << "Wyniki zapisane do pliku: " << nazwaPlikuWyjsciowego << endl;

    return 0;
}

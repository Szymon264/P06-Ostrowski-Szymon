#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>  // Dla użycia zbioru (set)
using namespace std;

// Funkcja do znajdowania duplikatów metodą tablicy pomocniczej
void znajdzDuplikatyTablicaPomocnicza(int tablica[], int rozmiar, ofstream &plikWyjsciowy, int &lp) {
    unordered_set<int> duplikaty; // Zbiór, aby przechowywać już wypisane duplikaty
    int* tablicaPomocnicza = new int[rozmiar](); // Alokujemy tablicę pomocniczą
    bool znalezionoDuplikaty = false;
    for (int i = 0; i < rozmiar; i++) {
        lp++; // Zliczamy operację (dostęp do tablicy pomocniczej)
        tablicaPomocnicza[tablica[i]]++;
        if (tablicaPomocnicza[tablica[i]] == 2 && duplikaty.find(tablica[i]) == duplikaty.end()) {
            plikWyjsciowy << "Duplikat znaleziony (tablica pomocnicza): " << tablica[i] << endl;
            duplikaty.insert(tablica[i]); // Dodajemy duplikat do zbioru
            znalezionoDuplikaty = true;
        }
    }
    if (!znalezionoDuplikaty) {
        plikWyjsciowy << "Brak duplikatów (tablica pomocnicza)." << endl;
    }
    delete[] tablicaPomocnicza; // Zwalniamy pamięć

    // Wypisujemy liczbę operacji do CMD
    cout << "Liczba operacji porownan: " << lp << endl;
}

int main() {
    // Wczytaj dane z pliku wejściowego
    string nazwaPlikuWejsciowego = "dane_wejsciowe_tablica.txt";
    string nazwaPlikuWyjsciowego = "wyniki_tablica.txt";

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
        cerr << "Nie można otworzyc pliku wyjsciowego!" << endl;
        return 1;
    }

    int lp = 0;  // Zmienna do zliczania liczby operacji
    // Wywołanie funkcji
    znajdzDuplikatyTablicaPomocnicza(tablica.data(), rozmiar, plikWyjsciowy, lp);

    plikWyjsciowy.close();
    cout << "Wyniki zapisane do pliku: " << nazwaPlikuWyjsciowego << endl;

    return 0;
}


#include "../inc/Tablica.hh"

void Tablica::powieksz(int o_rozmiar) {
	int nowy_rozmiar = Tablica::rozmiar + o_rozmiar;
	int * nowa_tablica = new int [nowy_rozmiar];
	for (int i=0; i<wypelnienie; i++){
        nowa_tablica[i] = tablica[i];
	}
	if (tablica != nullptr)
		delete[] tablica;
	rozmiar = nowy_rozmiar;
	tablica = nowa_tablica;
	nowa_tablica = nullptr;
}

void Tablica::dodajElem_o1(int pozycja, int wartosc) {
	while (pozycja >= rozmiar) {
		powieksz(1);
	}
	tablica[pozycja] = pozycja;
	wypelnienie++;
}

void Tablica::dodajElem_2x(int pozycja, int wartosc) {
	while (pozycja >= rozmiar) {
		powieksz(rozmiar);
	}
	tablica[pozycja] = wartosc;
	wypelnienie++;
}

int Tablica::odczytaj(int pozycja) {
    if (pozycja >= 0 && pozycja <= rozmiar){
        return tablica[pozycja];
    } else {
		//std::cout << "error: Nie ma pola o takim indeksie.";
        return 0;
    }
}

void Tablica::reset(int nowy_rozmiar){
	if (tablica != nullptr)
	{
		delete[] tablica;
		tablica = nullptr;
	}
	rozmiar = nowy_rozmiar;
	wypelnienie = 0;
	tablica = new int [rozmiar];
}

Tablica::Tablica(int rozmiar_pocz) {
	rozmiar = rozmiar_pocz;
	wypelnienie = 0;
	tablica = new int [rozmiar];
}

Tablica::Tablica() {
	rozmiar = 10;
	wypelnienie = 0;
	tablica = new int [rozmiar];
}

Tablica::~Tablica() {
	if (tablica != nullptr)
		delete[] tablica;
}

int Tablica::get_rozmiar() {
	return rozmiar;
}

int Tablica::get_wypelnienie() {
	return wypelnienie;
}



void Tablica::wykonaj_obliczenia(int nr_alogrytmu, int ilosc_elem, int wartosc_elem){
	if (nr_alogrytmu == 1){
		this->reset(10);
		for (int i = 0; i < ilosc_elem; i++) {
			this->dodajElem_o1(i, wartosc_elem);
		}
	}
	if (nr_alogrytmu == 2){
		this->reset(10);
		for (int i = 0; i < ilosc_elem; i++) {
			this->dodajElem_2x(i, wartosc_elem);
		}
	}
}
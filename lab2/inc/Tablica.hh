#ifndef _TABLICA_HH_
#define _TABLICA_HH_

#include "Testowalny.hh"
#include <iostream>

class Tablica: public Testowalny {
    int *tablica;
    int rozmiar;
    int wypelnienie;
	void powieksz(int o_rozmiar);
public:
	void dodajElem_o1(int pozycja, int wartosc); // nr alg 1
	void dodajElem_2x(int pozycja, int wartosc); // nr alg 2
	int odczytaj(int pozycja);
	void reset(int nowy_rozmiar);

    Tablica(int rozmiar_pocz);
	Tablica();
    ~Tablica();

	int get_rozmiar();
	int get_wypelnienie();

	virtual void wykonaj_obliczenia(int nr_alogrytmu, int ilosc_elem, int wartosc_elem);
};

#endif //_TABLICA_HH_


#include <iostream>
#include <fstream>
#include "../inc/Tablica.hh"
#include "../inc/Stoper.hh"

int main() {

	Tablica *obiekt = new Tablica();
	Stoper stoper;
    std::ofstream file;
	int ilosc_pomiarow = 20;
	int alg1 = 1; 	// zwiekszanie o 1
	int alg2 = 2;	// zwiekszanie 2x

	remove("t2x.dat");
	file.open("t2x.dat"); // std::ios::app
	for (int ilosc_elem = 10; ilosc_elem <= 1000000; ilosc_elem *= 10) {
		stoper.wykonaj_pomiar(obiekt, ilosc_pomiarow, alg2, ilosc_elem);
		stoper.wypisz_pomiar(file);
		stoper.wypisz_pomiar(std::cout);
	}
	file.close();

	remove("to1.dat");
    file.open("to1.dat");
    for (int ilosc_elem = 10; ilosc_elem <= 10000; ilosc_elem *= 10) {
		// zeby program dobrze zapisal plik nie moze byc przerwania,
		// dlatego daje mniej elementow
        stoper.wykonaj_pomiar(obiekt, ilosc_pomiarow, alg1, ilosc_elem);
        stoper.wypisz_pomiar(file);
		stoper.wypisz_pomiar(std::cout);
	}
    file.close();

    return 0;
}


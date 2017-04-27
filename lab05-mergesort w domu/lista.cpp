#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include "stoper.h"
#include "lista_klasa.h"
#include "Mergesort.hh"

//Tomasz Perczyñski 226481, PAMSI œroda 14:00-16:00.
// LISTA

using namespace std;

int main()
{
	srand(time(NULL));
	Merge_sort sort;
	stoper s;
	lista powaznalista;
	int ilosc;
	ilosc = 100000;
	s.mierz_czas_start();
	powaznalista.wypelnij(ilosc);
	//cout << endl;
	sort.sort(powaznalista, 0, ilosc-1);
	s.mierz_czas_stop();
	powaznalista.wyczysc();
	
	return 0;
}

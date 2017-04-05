#ifndef _STOPER_HH
#define _STOPER_HH

#include <ctime>
#include <iostream>
#include "../inc/ITestowalny.hh"

class Stoper {
	double av_time;
	int wyp_ilosc_elem;
public:
	double wykonaj_pomiar(ITestowalny *obiekt, int ilosc_pomiarow, int nr_algorytmu, int ilosc_elem);
	void wypisz_pomiar(std::ostream & stream);

	Stoper();
	~Stoper();
};


#endif //_STOPER_HH

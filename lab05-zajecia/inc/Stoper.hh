#ifndef _STOPER_HH
#define _STOPER_HH

#include "../inc/ITestowalny.hh"
#include "../inc/Libs.hh"

class Stoper {
	double av_time;
	int wyp_ilosc_elem;
public:
	double wykonaj_pomiar(ITestowalny *obiekt, int ilosc_pomiarow, int pom_algorytm, int ilosc_elem);
	void wypisz_pomiar(std::ostream & stream);

	Stoper();
	~Stoper();
};


#endif //_STOPER_HH

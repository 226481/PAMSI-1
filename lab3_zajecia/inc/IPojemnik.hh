#ifndef _POJEMNIK_HH
#define _POJEMNIK_HH

#include "../inc/Elem.hh"
#include "../inc/ITestowalny.hh"

class IPojemnik: ITestowalny {
public:
	virtual void push(Elem element_push) = 0;	// dodaje element do pojemnika
	virtual Elem pop() = 0;						// zwraca element i usuwa go z pojemnika
	virtual int get_size() = 0;					// zwraca wielkosc pojemnika (liczbe elem)
	virtual Elem* find(Elem element_find) = 0;	// zwraca wskaznik na podany element

	virtual void wykonaj_obliczenia(int nr_algorytmu, int ilosc_elem, int wartosc_elem) = 0;
};

#endif //_POJEMNIK_HH

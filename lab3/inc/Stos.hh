#ifndef _STOS_HH
#define _STOS_HH

#include "../inc/IPojemnik.hh"
#include "../inc/ITestowalny.hh"

class Stos: IPojemnik, ITestowalny {
	Elem* head;
	int size;
public:
	virtual void push(Elem element_push);	// dodaje element do pojemnika za head
	virtual Elem* pop();						// zwraca element i usuwa go z pojemnika za head
	virtual int get_size();					// zwraca wielkosc pojemnika (liczbe elem)
	virtual Elem* find(int key);	// zwraca wskaznik na podany element

	Elem* top();							// zwraca wskaznik na element za head

	Stos();
	~Stos();

	virtual void wykonaj_obliczenia(int nr_algorytmu, int ilosc_elem, int wartosc_elem);
};

#endif //_STOS_HH

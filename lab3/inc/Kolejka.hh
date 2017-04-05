#ifndef _KOLEJKA_HH
#define _KOLEJKA_HH

#include "../inc/IPojemnik.hh"
#include "../inc/ITestowalny.hh"

class Kolejka: IPojemnik, ITestowalny {
	Elem* head;
	Elem* tail;
	int size;
public:
	virtual void push(Elem element_push);	// dodaje element do pojemnika domyslnie za tail
	virtual Elem* pop();						// zwraca element i usuwa go z pojemnika za head
	virtual int get_size();					// zwraca wielkosc pojemnika (liczbe elem)
	virtual Elem* find(int key);	// zwraca wskaznik na podany element

	Elem* top();							// zwraca wskaznik na element za head

	Kolejka();
	~Kolejka();

	virtual void wykonaj_obliczenia(int nr_algorytmu, int ilosc_elem, int wartosc_elem);
};

#endif //_KOLEJKA_HH

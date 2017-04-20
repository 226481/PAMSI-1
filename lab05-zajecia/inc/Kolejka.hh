#ifndef _KOLEJKA_HH
#define _KOLEJKA_HH

#include "../inc/IPojemnik.hh"
#include "../inc/ITestowalny.hh"
#include "../inc/Elem.hh"
#include "../inc/Libs.hh"

class Kolejka: public IPojemnik, public ITestowalny {
	Elem* wsk_head;
	Elem* wsk_tail;
	int size;
public:
	virtual bool push(Elem *_elem_in);			// dodaje element do pojemnika domyslnie za head
	virtual Elem* pop();										// zwraca element i usuwa go z pojemnika z tail
	virtual int get_size();									// zwraca wielkosc pojemnika (liczbe elem)
	virtual Elem* find(int key);						// zwraca wskaznik na podany element i usuwa go

	Elem* first();														// zwraca wskaznik na element za tail

	Kolejka();
	~Kolejka();

	virtual bool wykonaj_algorytm(int pom_algorytm);
	virtual void fill(int ilosc, int wartosc_klucza_0_MAX);
	void print(std::ostream & stream);
};

#endif //_KOLEJKA_HH

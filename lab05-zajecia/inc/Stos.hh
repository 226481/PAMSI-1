#ifndef _STOS_HH
#define _STOS_HH

#include "../inc/IPojemnik.hh"
#include "../inc/ITestowalny.hh"
#include "../inc/Elem.hh"
#include "../inc/Libs.hh"

class Stos: public IPojemnik, public ITestowalny {
	Elem* wsk_head;
	int size;
public:
	virtual bool push(Elem *_elem_in);	// dodaje element do pojemnika za head
	virtual Elem* pop();						// zwraca element i usuwa go z pojemnika za head
	virtual int get_size();					// zwraca wielkosc pojemnika (liczbe elem)
	virtual Elem* find(int key);	// zwraca wskaznik na podany element

	Elem* top();							// zwraca wskaznik na element za head

	Stos();
	~Stos();

	virtual bool wykonaj_algorytm(int pom_algorytm);
	virtual void fill(int ilosc, int wartosc_klucza_0_MAX);
	void print(std::ostream & stream);
};

#endif //_STOS_HH

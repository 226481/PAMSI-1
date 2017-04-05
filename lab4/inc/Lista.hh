#ifndef _LISTA_HH
#define _LISTA_HH

#include "../inc/IPojemnik.hh"
#include "../inc/ITestowalny.hh"
#include "../inc/Elem.hh"
#include <iostream>

class Lista: IPojemnik, ITestowalny  {
	Elem* head;
	Elem* tail;
	int size; // == -1 jeśli pusty;
public:
	virtual bool push(Elem *elem_p);		// dodaje element na początku
	virtual Elem* pop();					// zwraca wskaźnik na pierwszy element i usuwa go z listy
	virtual int get_size();					// zwraca liczbę elementów
	virtual Elem* find(int key);			// zwraca wskaznik na podany element i usuwa go z listy

	bool insert(Elem *elem_i, int idx_i);	// dodaje element pod podany indeks, nastepne
											// przesuna sie dalej
	Elem* check(int idx_rm);					// zwraca adres elementu o podanym indeksie

	Lista();
	~Lista();

	virtual bool wykonaj_algorytm(int pom_algorytm);
	virtual void fill(int ilosc, int wartosc_elem, int wartosc_klucza);

	Elem* operator[](int num);
	void print(std::ostream & stream);
	void swamp(Elem* a, Elem* b);
};

#endif //_LISTA_HH

#ifndef _LISTA_HH
#define _LISTA_HH

#include "../inc/IPojemnik.hh"

class Lista: IPojemnik {
	Elem* head;
	Elem* tail;
	int size;
public:
	virtual void push(Elem element_push);	// dodaje element do pojemnika domyslnie za head
	virtual Elem pop();						// zwraca element i usuwa go z pojemnika za head
	virtual int get_size();					// zwraca wielkosc pojemnika (liczbe elem)
	virtual Elem* find(Elem element_find);	// zwraca wskaznik na podany element

	void insert(Elem element_ins, int idx_ins);	// dodaje element pod podany indeks, nastepne
												// przesuna sie dalej
	Elem* remove(int idx_rm);					// zwraca adres elementu o podanym indeksie

	Lista();
	~Lista();

	virtual void wykonaj_obliczenia(int nr_algorytmu, int ilosc_elem, int wartosc_elem);
};

#endif //_LISTA_HH

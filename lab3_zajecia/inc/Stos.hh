#ifndef _STOS_HH
#define _STOS_HH

#include "IPojemnik.hh"

class Stos: IPojemnik{
	Elem* head;
	int size;
public:
	virtual void push(Elem element_push);	// dodaje element do pojemnika za head
	virtual Elem pop();						// zwraca element i usuwa go z pojemnika za head
	virtual int get_size();					// zwraca wielkosc pojemnika (liczbe elem)
	virtual Elem* find(Elem element_find);	// zwraca wskaznik na podany element

	Elem* top();							// zwraca wskaznik na element za head

	Stos();
	~Stos();
};

#endif //_STOS_HH

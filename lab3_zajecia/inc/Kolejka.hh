#ifndef _KOLEJKA_HH
#define _KOLEJKA_HH

#include "IPojemnik.hh"

class Kolejka: IPojemnik{
	Elem* head;
	Elem* tail;
	int size;
public:
	virtual void push(Elem element_push);	// dodaje element do pojemnika domyslnie za tail
	virtual Elem pop();						// zwraca element i usuwa go z pojemnika za head
	virtual int get_size();					// zwraca wielkosc pojemnika (liczbe elem)
	virtual Elem* find(Elem element_find);	// zwraca wskaznik na podany element

	Elem* top();							// zwraca wskaznik na element za head

	Kolejka();
	~Kolejka();
};

#endif //_KOLEJKA_HH

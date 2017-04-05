#ifndef _POJEMNIK_HH
#define _POJEMNIK_HH

#include "../inc/Elem.hh"


class IPojemnik {
public:
	virtual bool push(Elem *elem_p) = 0;	// dodaje element do pojemnika
	virtual Elem* pop() = 0;			// zwraca element i usuwa go z pojemnika
	virtual int get_size() = 0;			// zwraca wielkosc pojemnika (liczbe elem)
	virtual Elem* find(int key) = 0;	// zwraca wskaznik na podany element
	virtual ~IPojemnik() {};
};

#endif //_POJEMNIK_HH

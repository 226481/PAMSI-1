#ifndef _ELEM_HH
#define _ELEM_HH

class Elem{
	Elem* wsk_prev;		// adres poprzedniego elementu
	int value;			// wartosc elementu
	Elem* wsk_next;		// adres nastepnego elementu
public:
	int get_value();
	Elem* next();
	Elem* prev();
};

#endif //_ELEM_HH

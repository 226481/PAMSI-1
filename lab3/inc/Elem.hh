#ifndef _ELEM_HH
#define _ELEM_HH

class Elem{
	Elem* wsk_prev;		// adres poprzedniego elementu
	int value;			// wartosc elementu
	int priority;		// priorytet
	Elem* wsk_next;		// adres nastepnego elementu
public:
	void set_value(int val);
	int get_value();

	void set_priority(int prio);
	int get_priority();

	void set_next(Elem* next);
	void set_prev(Elem* prev);

	Elem* get_next();
	Elem* get_prev();

	Elem();
	Elem(int val, int prio);
	~Elem();
};

#endif //_ELEM_HH

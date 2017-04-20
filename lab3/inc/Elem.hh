#ifndef _ELEM_HH
#define _ELEM_HH

class Elem {
	Elem* wsk_prev;		// adres poprzedniego elementu
	int value;				// wartosc elementu
	int priority;			// priorytet/klucz
	Elem* wsk_next;		// adres nastepnego elementu
public:
	void set_value(int val);
	int get_value();

	void set_priority(int prio);
	int get_priority();

	void set_next(Elem* _next);
	Elem* get_next();

	void set_prev(Elem* _prev);
	Elem* get_prev();

	Elem();
	Elem(int val, int prio);
	~Elem();
};

#endif //_ELEM_HH

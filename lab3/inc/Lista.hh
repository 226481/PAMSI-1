#ifndef _LISTA_HH
#define _LISTA_HH

#include "../inc/IPojemnik.hh"
#include "../inc/ITestowalny.hh"
#include "../inc/Elem.hh"
#include "../inc/Libs.hh"

class Lista: public IPojemnik, public ITestowalny {
	Elem* wsk_head;
	Elem* wsk_tail;
	int size;
public:
	virtual bool push(Elem *_elem_in);	// dodaje element na początku listy
	virtual Elem* pop();								// zwraca wskaźnik na pierwszy element i usuwa go z listy
	virtual int get_size();							// zwraca liczbę elementów
	virtual Elem* find(int key);				// zwraca wskaznik na element o podanym kluczu i usuwa go z listy

	bool insert(Elem *_elem_in, int idx);	// dodaje element pod podany indeks, ten pod tym indeksem i dalsze przesuna sie dalej o 1
	Elem* remove(int idx);							// zwraca wskaźnik do elementu o podanym indeksie, i usuwa go z listy
	Elem* get(int idx);									// zwraca wskaźnik do elementu o podanym indeksie

	Lista();
	~Lista();

	virtual bool wykonaj_algorytm(int pom_algorytm);
	virtual void fill(int ilosc, int wartosc_klucza_0_MAX);
	void print(std::ostream & stream);
};

#endif //_LISTA_HH

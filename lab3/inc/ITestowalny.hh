#ifndef _ITESTOWALNY_HH
#define _ITESTOWALNY_HH

class ITestowalny {
public:
	virtual bool wykonaj_algorytm(int pom_algorytm) = 0;
	virtual void fill(int ilosc, int wartosc) = 0;
	virtual ~ITestowalny() {};
};

#endif //_ITESTOWALNY_HH

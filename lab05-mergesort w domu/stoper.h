#ifndef STOPER_KLASA_HH
#define STOPER_KLASA_HH

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <ctime>

//Tomasz Perczyñski, 226481, PAMSI 14:00-16:15
using namespace std;



class stoper
	{
		clock_t start;
		int pomiar;
		
		public:
		virtual void srednia();
		virtual void mierz_czas_start();
		virtual void mierz_czas_stop();
	};
	
void stoper::mierz_czas_start()
{
	start = clock();
	pomiar = 0;
}

void stoper::mierz_czas_stop()
{
	cout <<"Zmierzony czas to: "<<clock()<<" ms";
	pomiar+=clock()-start;
}

void stoper::srednia()
{
	cout <<endl;
	cout <<"Srednia po 20 pomiarach to: "<<clock()/20;
}

#endif

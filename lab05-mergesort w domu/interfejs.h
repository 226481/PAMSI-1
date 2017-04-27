#ifndef INTERFEJS_HH
#define INTERFEJS_HH

#include<cstdio>
#include<iostream>
#include<fstream>
//Tomasz Perczyñski 226481, PAMSI œroda 14:00-16:00.

using namespace std;

class interfejs
{
	public:
	interfejs();
	virtual void add(int element);
	virtual int get();
	virtual void find(int element);
	virtual int size();
	virtual ~interfejs();
};

interfejs::interfejs()
{
}

interfejs::~interfejs()
{
}

void interfejs::add(int element)
{
}

int interfejs::get()
{
}

void interfejs::find(int element)
{
}

int interfejs::size()
{
}

#endif

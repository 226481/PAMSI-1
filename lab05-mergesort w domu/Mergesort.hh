#ifndef _MERGESORT_HH
#define _MERGESORT_HH

#include "lista_klasa.h"



using namespace std;

class Merge_sort {
	private:
		lista lista1;
		int start;
		int middle;
		int end;
	public:
		void merge(lista lista1, int start, int middle, int end);
		void sort(lista lista1, int start, int end);
};

void Merge_sort::merge(lista lista1, int start, int middle, int end) {
	lista temp;
	costam* wsk=lista1.pierwszy;
	costam* wsk1;
	int i = start;
	int j = middle + 1;
	int k = 0;

	while (i <= middle && j <= end) {
		if (lista1.at(i)->a < lista1.at(j)->a)
		 {
			temp.add(lista1.at(j)->a);
			j++;
		} else {
			temp.add(lista1.at(i)->a);
			i++;
		}
		k++;
	}

	if (i <= middle) {
		while (i <= middle) {
			temp.add(lista1.at(i)->a);
			i++;
			k++;
		}
	} else {
		while (j <= end) {
			temp.add(lista1.at(j)->a);
			j++;
			k++;
		}
	}

	for (i = 0; i <= end-start; i++)
	{
		lista1.at(start+i)->a = temp.at(i)->a;
	}
};

void Merge_sort::sort(lista lista1, int start, int end) {
	int s;
	if(start != end) {
		s = (start + end)/2;
		sort(lista1, start, s);
		sort(lista1, s+1, end);
		merge(lista1, start, s, end);
	}
};

#endif

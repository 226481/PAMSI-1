#include <iostream>
#include "../inc/Lista.hh"

void quick_sort(Lista lista, int lewy, int prawy) {
	int i = lewy;
	int j = prawy;
	int pivot = 0;

	Elem* wsk_pivot = nullptr;
	wsk_pivot = lista.check( lista.get_size() / 2 );
	pivot = wsk_pivot->get_value();

//	while(1) {
//		lista.swamp(a, b);
//
//		break;
//	}
//					swamp lub przesuwanie elementów
// 					z "jednej tablicy do drugiej"
// 					przy pomocy jakichś push'y

	if ( j > lewy ) {
		quick_sort(lista, lewy, j);
	}
	if ( i < prawy ) {
		quick_sort(lista, i, prawy);
	}

}

int main() {
	srand(time(NULL));

	Lista lista;
	int N = 30;
	int val_MAX = 100;
	int key_MAX = 10;

	lista.fill(N, val_MAX, key_MAX);
	lista.print(std::cout);
//	quick_sort(lista, 0, N);
//	lista.print(std::cout);

	return 0;
}


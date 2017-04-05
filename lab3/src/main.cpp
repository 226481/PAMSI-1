#include <iostream>
#include "../inc/Stoper.hh"
#include "../inc/Lista.hh"


int main() {

	Lista lista;

	Elem* elem1 = new Elem(10,10);
	Elem* elem2 = nullptr;
	Elem* elem3 = nullptr;

	std::cout << "elem1 " << elem1->get_value() << std::endl;

	std::cout << "size " << lista.get_size() << std::endl;
	lista.push(elem1);
	std::cout << "size " << lista.get_size() << std::endl;

	elem2 = lista.check(0);
	std::cout << "elem2 " << elem2->get_value() << std::endl;
	std::cout << "size " << lista.get_size() << std::endl;
	elem3 = lista.pop();
	std::cout << "size " << lista.get_size() << std::endl;

	srand(time(NULL));
	lista.fill(100,rand()%100);
	std::cout << "size " << lista.get_size() << std::endl;

	elem3 = new Elem(666,5);

	lista.insert(elem3,5);
	std::cout << "size " << lista.get_size() << std::endl;

	Elem* elem4;
	elem4 = lista.find(5);
	if (elem4 != nullptr)
		std::cout << "znalazłem!" << std::endl;
	std::cout << "size " << lista.get_size() << std::endl;

	Elem* elem5 = nullptr;

	elem5 = lista.pop();
	std::cout << "size " << lista.get_size() << std::endl;

	std::cout << elem5->get_priority() << std::endl;

	return 0;
}


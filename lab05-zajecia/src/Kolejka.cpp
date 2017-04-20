#include "../inc/Kolejka.hh"

bool Kolejka::push(Elem *_elem_in) { // To samo co Lista::push
  _elem_in->set_next(wsk_head);
  if (wsk_head != nullptr) {
    wsk_head->set_prev(_elem_in);
  }
  wsk_head = _elem_in;
  size++;
  return true;
}

Elem* Kolejka::pop() {
  Elem* _elem_pom = wsk_tail;
	if (wsk_tail != nullptr) {
		wsk_tail = wsk_tail->get_prev();
		size--;
		wsk_tail->set_next(nullptr);
		_elem_pom->set_prev(nullptr);
		_elem_pom->set_next(nullptr);
	}
	return _elem_pom;
}

int Kolejka::get_size() {
  return size;
}

Elem* Kolejka::find(int key) { // To samo co Lista::find
  Elem* _elem_pom = wsk_head;

	if ( _elem_pom->get_priority() == key ) { // pierwszy na liście
		pop();
		size--;
		return _elem_pom;
	} else {
		while ( _elem_pom->get_next() != nullptr ) { // dalej
			if ( _elem_pom->get_priority() == key ) {
				if ( _elem_pom->get_prev() != nullptr ) {
					( _elem_pom->get_prev() )->set_next( _elem_pom->get_next() );
				}
				if (_elem_pom->get_next() != nullptr) {
					( _elem_pom->get_next() )->set_prev( _elem_pom->get_prev());
				}
				_elem_pom->set_next(nullptr);
				_elem_pom->set_prev(nullptr);
				size--;
				return _elem_pom;
			} else {
				_elem_pom = _elem_pom->get_next();
			}
		}
	}
	return nullptr;
}

Elem* Kolejka::first() {
  return wsk_tail;
}

Kolejka::Kolejka() {
	wsk_head = nullptr;
	wsk_tail = nullptr;
	size = -1;
}

Kolejka::~Kolejka() {
	wsk_head = nullptr;
	wsk_tail = nullptr;
	size = -1;
}

bool Kolejka::wykonaj_algorytm(int pom_algorytm) {
  return find(pom_algorytm) != nullptr;
}

void Kolejka::fill(int ilosc, int wartosc_klucza_0_MAX) { // To samo co Lista:fill
  Elem* _elem_in;

	for (int i=0; i<ilosc; i++) {
		_elem_in = new Elem();
		_elem_in->set_priority(rand()%wartosc_klucza_0_MAX);
		_elem_in->set_value(i*1000);
		push(_elem_in);
	}
}

void Kolejka::print(std::ostream & stream) { // To samo co Lista:print z tym że zaczyna od tail
  Elem *_elem_pom = wsk_tail;

	for (int i=0; i<=size; i++) {
		stream << "i:" << i << " " << "p:" << _elem_pom->get_priority() << " " << "v:" << _elem_pom->get_value() << "\n";
		_elem_pom = _elem_pom->get_prev();
	}
	_elem_pom = nullptr;
}

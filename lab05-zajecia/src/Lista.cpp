#include "../inc/Lista.hh"

int Lista::get_size() {
	return size;
}

bool Lista::push(Elem *_elem_in) {
  _elem_in->set_next(wsk_head);
  if (wsk_head != nullptr) {
    wsk_head->set_prev(_elem_in);
  }
  wsk_head = _elem_in;
  size++;
  return true;
}

Elem* Lista::pop() {
	Elem* _elem_pom = wsk_head;
	if (wsk_head != nullptr) {
		wsk_head = wsk_head->get_next();
		size--;
		wsk_head->set_prev(nullptr);
		_elem_pom->set_prev(nullptr);
		_elem_pom->set_next(nullptr);
	}
	return _elem_pom;
}

Elem* Lista::find(int key) {
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

bool Lista::insert(Elem* _elem_in, int idx) {
	Elem* _elem_pom = wsk_head;

	for (int i=0; i<=size; i++) {
		if ( i == idx ) {
			if ( _elem_pom->get_prev() != nullptr ) {
				_elem_in->set_prev( _elem_pom->get_prev() );
				( _elem_in->get_prev() )->set_next(_elem_in);
			}
			if ( _elem_pom->get_next() != nullptr) {
				_elem_in->set_next( _elem_pom );
				( _elem_in->get_next() )->set_prev(_elem_in);
			}
			size++;
			return true;
		} else {
			_elem_pom = _elem_pom->get_next();
		}
	}
	return false;
}

Elem* Lista::remove(int idx) {
	Elem* _elem_pom = get(idx);

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
}

Elem* Lista::get(int idx) {
	Elem* _elem_pom = wsk_head;

	for (int i=0; i<=size; i++) {
		if (i == idx) {
			return _elem_pom;
		} else {
			_elem_pom = _elem_pom->get_next();
		}
	}
	return nullptr;
}

Lista::Lista() {
	wsk_head = nullptr;
	wsk_tail = nullptr;
	size = -1;
}

Lista::~Lista() {
	wsk_head = nullptr;
	wsk_tail = nullptr;
	size = -1;
}

bool Lista::wykonaj_algorytm(int pom_algorytm) {
	return find(pom_algorytm) != nullptr;
}

void Lista::fill(int ilosc, int wartosc_klucza_0_MAX) {
	Elem* _elem_in;

	for (int i=0; i<ilosc; i++) {
		_elem_in = new Elem();
		_elem_in->set_priority(rand()%wartosc_klucza_0_MAX);
		_elem_in->set_value(i*1000);
		push(_elem_in);
	}
}

void Lista::print(std::ostream & stream){
	Elem *_elem_pom = wsk_head;

	for (int i=0; i<=size; i++) {
		stream << "i:" << i << " " << "p:" << _elem_pom->get_priority() << " " << "v:" << _elem_pom->get_value() << "\n";
		_elem_pom = _elem_pom->get_next();
	}
	_elem_pom = nullptr;
}

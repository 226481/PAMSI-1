#include "../inc/Lista.hh"

int Lista::get_size() {
	return size;
}

bool Lista::push(Elem *elem_p) {
	if (size > -1) { // przynajmniej jeden
		elem_p->Elem::set_next(head);
		head->set_prev(elem_p);
		head = elem_p;
		head->set_prev(nullptr);
		size++;
		return true;
	}

	if (size == -1) { // brak elementow
		head = elem_p;
		head->set_prev(nullptr);
		tail = elem_p;
		tail->set_next(nullptr);
		size++;
		return true;
	}

	return false;
}

Elem* Lista::pop() {
	Elem* elem_out = nullptr;

	if (size >= 1) { // przynajmniej dwa
		elem_out = head;
		head = elem_out->get_next();
		head->set_prev(nullptr);

		elem_out->set_next(nullptr);
		elem_out->set_prev(nullptr);
		size--;
	}

	if (size == 0) { // jeden
		elem_out = head;
		head = nullptr;
		tail = nullptr;
		size--;
	}

	if (size == -1) { // brak elementow
		elem_out = nullptr;
	}

	return elem_out;
}

Elem* Lista::find(int klucz) {
	Elem* pom = head;

	while (pom->get_next() != nullptr) {
		if (pom->get_priority() == klucz) {
			if (pom->get_prev() != nullptr) {
				( pom->get_prev() )->set_next( pom->get_next() );
			}
			if (pom->get_next() != nullptr) {
				( pom->get_next() )->set_prev( pom->get_prev());
			}
			size--;
			return pom;
		} else {
			pom = pom->get_next();
		}
	}
	return nullptr;
}

bool Lista::insert(Elem *elem_i, int idx_i) {
	Elem* pom = head;

	for (int i=0;i<=size+1;i++) {
		if (i == idx_i) {
			if (pom->get_prev() != nullptr) {
				elem_i->set_prev( pom->get_prev() );
				( elem_i->get_prev() )->set_next(elem_i);
			}
			if (pom->get_next() != nullptr) {
				elem_i->set_next( pom );
				( elem_i->get_next() )->set_prev(elem_i);
			}
			size++;
			return true;
		} else {
			pom = pom->get_next();
		}
	}
	return false;
}

Elem* Lista::check(int idx_rm) {
	Elem* pom = head;

	for (int i=0;i<=size;i++) {
		if (i == idx_rm) {
			return pom;
		} else {
			pom = pom->get_next();
		}
	}

	return nullptr;
}

Lista::Lista() {
	head = nullptr;
	tail = nullptr;
	size = -1;
}

Lista::~Lista() {
	head = nullptr;
	tail = nullptr;
	size = -1;
}

bool Lista::wykonaj_algorytm(int pom_algorytm) {
	return find(pom_algorytm) == nullptr;
}

void Lista::fill(int ilosc, int wartosc_elem_0_MAX, int wartosc_klucza_0_MAX) {
	Elem* elem;
	for (int i=0; i<ilosc; i++) {
		elem = new Elem();
		elem->set_priority(rand()%wartosc_klucza_0_MAX);
		elem->set_value(rand()%wartosc_elem_0_MAX);
		push(elem);
	}
}

Elem* Lista::operator[](int num) {
	return check(num);
}

void Lista::print(std::ostream & stream) {
	for (int i=0; i<size; i++) {
		stream << operator[](i)->get_value() << " ";
	}
	stream << "\n";
}

void swamp(Elem* a, Elem* b) {
	Elem* a_next = a->get_next();
	Elem* a_prev = a->get_prev();

	a->set_next( b->get_next() );
	a->set_prev( b->get_prev() );

	b->set_next( a_next );
	b->set_prev( a_prev );

	a_next = nullptr;
	a_prev = nullptr;
}



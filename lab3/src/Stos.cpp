#include "../inc/Stos.hh"

bool Stos::push(Elem *_elem_in) {
  _elem_in->set_next(wsk_head);
  wsk_head = _elem_in;
  size++;
  return true;
}

Elem* Stos::pop() {
  Elem* _elem_pom = wsk_head;
  if (wsk_head != nullptr) {
    wsk_head = wsk_head->get_next();
    size--;
    _elem_pom->set_next(nullptr);
  }
  return _elem_pom;
}

int Stos::get_size() {
  return size;
}

Elem* Stos::find(int key) {
  Elem* _elem_pom = nullptr;
  Stos* _stos;
  _stos = new Stos();

  _elem_pom = this->pop();
  while ( _elem_pom != nullptr ) {
    if (_elem_pom->get_priority() != key) {
      _stos->push(_elem_pom);
      _elem_pom = this->pop();
    } else {
      break;
    }
  }
  while (_stos->get_size() != -1) {
    this->push(_stos->pop());
  }
  return _elem_pom;
}

Elem* Stos::top() {
  return wsk_head;
}

Stos::Stos() {
  wsk_head = nullptr;
  size = -1;
}

Stos::~Stos() {
  wsk_head = nullptr;
  size = -1;
}

bool Stos::wykonaj_algorytm(int pom_algorytm) {
  return find(pom_algorytm) != nullptr;
}

void Stos::fill(int ilosc, int wartosc_klucza_0_MAX) {
  Elem* _elem_in;

  for (int i=0; i<ilosc; i++) {
    _elem_in = new Elem();
    _elem_in->set_priority(rand()%wartosc_klucza_0_MAX);
    _elem_in->set_value(i*1000);
    push(_elem_in);
  }
}

void Stos::print(std::ostream & stream) {
  Elem *_elem_pom = wsk_head;

  for (int i=0; i<=size; i++) { // szybko przy pomocy adresów w elementach
    stream << "i:" << i << " " << "p:" << _elem_pom->get_priority() << " " << "v:" << _elem_pom->get_value() << "\n";
    _elem_pom = _elem_pom->get_next();
  }
  _elem_pom = nullptr;
}

#include "../inc/Elem.hh"

void Elem::set_value(int val) {
	value = val;
}

int Elem::get_value() {
	return value;
}

void Elem::set_next(Elem* next) {
	wsk_next = next;
}

void Elem::set_prev(Elem* prev) {
	wsk_prev = prev;
}

Elem* Elem::get_next() {
	return wsk_next;
}

Elem* Elem::get_prev() {
	return wsk_prev;
}

Elem::Elem() {
	wsk_prev = nullptr;
	value = 0;
	priority = 0;
	wsk_next = nullptr;
}

Elem::Elem(int val, int prio) {
	wsk_prev = nullptr;
	value = val;
	priority = prio;
	wsk_next = nullptr;
}

Elem::~Elem() {
	wsk_prev = nullptr;
	value = 0;
	priority = 0;
	wsk_next = nullptr;
}

void Elem::set_priority(int prio) {
	priority = prio;
}

int Elem::get_priority() {
	return priority;
}
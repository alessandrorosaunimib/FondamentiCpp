#include "cerchio.h"

Cerchio::Cerchio(const Cerchio &other) : Forma(other), _centro(other._centro), _raggio(other._raggio) {}

Cerchio& Cerchio::operator=(const Cerchio &other) {
	if (this != &other) {
		Cerchio tmp(other);
		tmp.swap(*this);
	}

	return *this;
}

Cerchio::Cerchio(const std::string &id, unsigned int colore, bool pieno, const Punto &c, double r) :
	Forma(id,colore,pieno), _centro(c), _raggio(r) {}

const Punto& Cerchio::centro() const {
	return _centro;
}

double Cerchio::raggio() const {
	return _raggio;
}

void Cerchio::set_centro(const Punto &c) {
	_centro = c;
}

void Cerchio::set_raggio(double r) {
	_raggio = r;
}

double Cerchio::perimetro() const {
	return 2 * 3.14 * _raggio;
}

void Cerchio::swap(Cerchio &other){
	Forma::swap(other);
	std::swap(_centro, other._centro);
	std::swap(_raggio, other._raggio);
}

std::ostream &operator<<(std::ostream &os, const Cerchio &c){
	os << static_cast<const Forma&>(c) << std::endl;
	os << "centro: " << c.centro() << std::endl;
	os << "raggio: " << c.raggio();
	return os;
}
#include "triangolo.h"

Triangolo::Triangolo(
		const std::string &id,
		int colore,
		bool pieno,
		const Punto &v1,
		const Punto &v2,
		const Punto &v3) : Forma(id,colore,pieno), _v1(v1), _v2(v2), _v3(v3) {}

Triangolo::Triangolo(const Triangolo &other) : Forma(other), _v1(other._v1), _v2(other._v2), _v3(other._v3) {}

Triangolo &Triangolo::operator=(const Triangolo &other) {
	if (this != &other) {
		Forma::operator=(other);
		_v1 = other._v1;
		_v2 = other._v2;
		_v3 = other._v3;
	}	

	return *this;
}

const Punto& Triangolo::v1(void) const {
	return _v1;	
}

const Punto& Triangolo::v2(void) const {
	return _v2;
}

const Punto& Triangolo::v3(void) const {
	return _v3;
}

void Triangolo::set_v1(const Punto &p1) {
	_v1 = p1;
}
		
void Triangolo::set_v2(const Punto &p2) {
	_v2 = p2;
}

void Triangolo::set_v3(const Punto &p3) {
	_v3 = p3;
}

void Triangolo::set(const Punto &p1, const Punto &p2, const Punto &p3) {
	_v1 = p1;
	_v2 = p2;
	_v3 = p3;
}

double Triangolo::perimetro(void) const {
	double l1 = _v1 - _v2;
	double l2 = _v2 - _v3;
	double l3 = _v3 - _v1;

	return l1 + l2 + l3;
}	

void Triangolo::swap(Triangolo &other) {
	Forma::swap(other);
	std::swap(_v1,other._v1);
	std::swap(_v2,other._v2);
	std::swap(_v3,other._v3);		
}

std::ostream &operator<<(std::ostream &os, 
	const Triangolo &t) {

	// Stampo le informazioni di Forma
	os << static_cast<const Forma &>(t) << std::endl;

	// Stampo le informazioni di Triangolo
	os << "v1: " << t.v1() << std::endl;
	os << "v2: " << t.v2() << std::endl;
	os << "v3: " << t.v3();

	return os;	
}
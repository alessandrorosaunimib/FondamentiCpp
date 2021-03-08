#include "forma.h"
#include <algorithm>


Forma::~Forma(void) { }
	
Forma::Forma(const Forma &other) :
 _id(other._id), _pieno(other._pieno), _colore(other._colore) {}
	
Forma &Forma::operator=(const Forma &other) {
	if (this != &other) {
		_id = other._id;
		_colore = other._colore;
		_pieno = other._pieno;
	}	

	return *this;
}
	
Forma::Forma(const std::string &id, unsigned int colore, bool pieno)
: _id(id), _pieno(pieno),_colore(colore) {}

std::string Forma::id(void) const {
	return _id;
}

bool Forma::pieno(void) const {
	return _pieno;
}

unsigned int Forma::colore(void) const {
	return _colore;
}

void Forma::set_colore(unsigned int colore)  {
	_colore = colore;
}	

void Forma::set_pieno(bool pieno) {
	_pieno = pieno;
}

void Forma::swap(Forma &other) {
	std::swap(_id, other._id);
	std::swap(_colore, other._colore);
	std::swap(_pieno, other._pieno);	
}

std::ostream &operator<<(std::ostream& os, const Forma &f) {
	os << "id: " << f.id() << std::endl;
	os << "colore: " << f.colore() << std::endl;
	os << "pieno: " << f.pieno();
	return os;
}


Punto::Punto(void) : x(0), y(0) {}

Punto::Punto(double xx, double yy) 
	: x(xx), y(yy) {}

double operator-(const Punto &p1, const Punto &p2) {
	double dx = p1.x-p2.x;
	double dy = p1.y-p2.y;
	return std::sqrt(dx*dx+dy*dy);
}


std::ostream &operator<<(std::ostream &os, const Punto &p)  {
	os << "(" << p.x << ", " << p.y << ")";

	return os;
}
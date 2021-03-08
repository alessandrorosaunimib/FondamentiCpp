#ifndef CERCHIO_H
#define CERCHIO_H

#include "forma.h"
#include <string>
#include <ostream>

class Cerchio : public Forma {
	Punto _centro;
	double _raggio;

public:
	Cerchio(const Cerchio &other);
	Cerchio& operator=(const Cerchio &other);

	Cerchio(const std::string &id, unsigned int colore, bool pieno, const Punto &c, double r);

	const Punto& centro() const;
	double raggio() const;

	void set_centro(const Punto &c);
	void set_raggio(double r);

	double perimetro() const;

	void swap(Cerchio &other);
};

std::ostream &operator<<(std::ostream &os, const Cerchio &c);

#endif
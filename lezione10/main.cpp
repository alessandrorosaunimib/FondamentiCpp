#include <iostream>
#include "forma.h"
#include "triangolo.h"
#include "cerchio.h"
#include <vector>

struct is_color_10 {
	bool operator()(const Forma *f) const {
		return f->colore()==10;
	}
};

template <typename P>
void who_is(const std::vector<Forma *> &f, P pred) {
	std::vector<Forma *>::const_iterator i, ie;
	for(i=f.begin(), ie= f.end(); i!=ie; ++i) {
		if (pred(*i)) std::cout << (*i)->id() << std::endl;
	}
}

int main() {

	Triangolo t1("t1",10,false,Punto(0,0), Punto(10,10), Punto(100,0));

	std::cout << t1 << std::endl;

	std::cout << "perimetro di t1: " << t1.perimetro() << std::endl;

	Cerchio c1("c1",10,false,Punto(0,0),50);

	std::cout << c1 << std::endl;

	std::cout << "perimetro di c1: " << c1.perimetro() << std::endl;

	std::vector<Forma *> forme;

	forme.push_back(&t1);
	forme.push_back(&c1);

	who_is(forme, is_color_10());

	return 0;
}
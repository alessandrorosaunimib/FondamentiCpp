#ifndef TRIANGOLO_H
#define TRIANGOLO_H

#include "forma.h"
#include <ostream>
#include <string>

/**
	Classe che rappresenta un Triangolo

	@brief Forma Triangolo
*/
class Triangolo : public Forma {
	Punto _v1, _v2, _v3; ///< vertici del triangolo

public:

	//Triangolo(); // Non ha senso 

	/**
		Costruttore.
		@param id identificativo
		@param colore colore
		@param pieno modo di disegno (true=filled)
		@param v1 primo vertice
		@param v2 secondo vertice
		@param v3 terzo vertice
	*/
	Triangolo(
		const std::string &id,
		int  colore,
		bool pieno,
		const Punto &v1,
		const Punto &v2,
		const Punto &v3);

	/**
		Costruttore di copia
		@param other Triangolo da copiare
	*/
	Triangolo(const Triangolo &other);

	/**
		Operatore di assegnamento
		@param other Triangolo da copiare
		@return reference a this
	*/
	Triangolo &operator=(const Triangolo &other);

	// ~Triangolo(); // Non serve

	/**
		Ritorna il primo vertice
		@return il primo vertice
	*/
	const Punto& v1(void) const;

	/**
		Ritorna il secondo vertice
		@return il secondo vertice
	*/
	const Punto& v2(void) const;

	/**
		Ritorna il terzo vertice
		@return il terzo vertice
	*/
	const Punto& v3(void) const;

	/**
		Setta il primo vertice
		@param p1 il primo vertice
	*/
	void set_v1(const Punto &p1);
		
	/**
		Setta il secondo vertice
		@param p2 il secondo vertice
	*/
	void set_v2(const Punto &p2);

	/**
		Setta il terzo vertice
		@param p3 il terzo vertice
	*/
	void set_v3(const Punto &p3);

	/**
		Setta i tre vertici del triangolo
		@param p1 il primo vertice
		@param p2 il secondo vertice
		@param p3 il terzo vertice
	*/
	void set(
			const Punto &p1,
			const Punto &p2,
			const Punto &p3);

	/**
		Ritorna il perimetro del triangolo
		@return il perimetro del triangolo
	*/
	double perimetro(void) const;	

	void swap(Triangolo &other);
};

/**
	Operatore di stream per stampare il contenuto di un Triangolo
	@param os stream di output
	@param t Triangolo da stampare
	@return stream di output
*/
std::ostream &operator<<(std::ostream &os, 
	const Triangolo &t); 


#endif

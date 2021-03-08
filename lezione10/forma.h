#ifndef forma_H
#define forma_H
#include <ostream>
#include <string>
#include <cmath>


/**
	Classe che rappresenta una generica forma geometrica.
	La classe e' polimorfa grazie al metodo virtuale perimetro
	La classe non ha implementazione del metodo, lo acquisisce
	dalle classe figlie che lo implementano. 
	Tramite upcasting, quando chiamiamo il metodo perimetro su forma,
	viene eseguito il codice della classe figlia

	@brief Generica forma geometrica
*/
class Forma {
	std::string _id; ///< identificativo
	unsigned int _colore; ///< colore (per comodità usiamo un intero...)
	bool _pieno; ///< forma piena o vuota?

public:

	//Forma(); // Non ha senso implementarlo
	
	/**
		Distruttore 
	*/
	~Forma(void);
	
	/**
		Costruttore di copia

		@param other Forma da copiare
	*/
	Forma(const Forma &other);
	
	/**
		Operatore di assegnamento

		@param other Forma da copiare
		@return reference a this
	*/
	Forma &operator=(const Forma &other);
	
	/**
		Costruttore secondario (unico)
		@param id identificativo
		@param colore colore
		@param pieno modo di disegno (true=filled)
	*/
	Forma(
		const std::string &id,
		unsigned int colore,
		bool pieno);

	/**
		Identificativo della forma
		@return l'identificativo della forma
	*/
	std::string id(void) const;

	/**
		Ritorna la modalita' di disegno della forma
		@return true se la forma e' piena
	*/
	bool pieno(void) const;

	/**
		Ritorna il colore della forma
		@return il colore della forma
	*/
	unsigned int colore(void) const;

	/**
		Setta il colore della forma
		@param colore il colore della forma
	*/
	void set_colore(unsigned int colore);

	/**
		Setta la modalita' di disegno della forma
		@param pieno true se la forma e' da disegnare piena
	*/
	void set_pieno(bool pieno);

	/**
		Ritorna il perimetro della forma
		E' un metodo virtuale puro (senza implementazione)
		Questo rende la classe Forma NON istanziabile
		Le classi figlie, de vogliono essere istanziabili devono implementarlo

		@return il perimetro della forma
	*/
	virtual double perimetro(void) const = 0;

	/**
		Scambia gli attributi di this con quelli di other

		@param other Oggetto con cui scambiare gli attributi 
	*/
	void swap(Forma &other);
};

/**
	Operatore di stream per stampare il contenuto di una Forma
	@param os stream di output
	@param f Forma da stampare
	@return stream di output
*/
std::ostream &operator<<(std::ostream& os, const Forma &f);

/**
	Struttura che rappresenta un punto 2D 

	@brief Punto 2D in uno spazio cartesiano
*/
struct Punto {
	double x; ///< coordinata x
	double y; ///< coordinata y

	/**
		Costruttore di default. IL punto avra' coordinate (0,0)
	*/
	Punto(void);

	/**
		Costruttore
		@param xx coordinata x
		@param yy coordinata y
	*/
	Punto(double xx, double yy);

	// Per gli altri metodi fondamentali, vanno bene quelli di default
};

/**
	Operatore di stream per stampare il contenuto di un punto
	@param os stream di output
	@param p punto da stampare
	@return stream di output
*/
std::ostream &operator<<(std::ostream &os, const Punto &p);

/**
	Funzione (operatore-) che calcola la distanza Euclidea tra due punti 
	@param p1 primo punto (operando di sinistra)
	@param p2 secondo punto (operando di destra)
	@return distanza Euclidea tra i due punti (double)
*/
double operator-(const Punto &p1, const Punto &p2);

#endif
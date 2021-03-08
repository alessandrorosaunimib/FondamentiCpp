#ifndef DBUFFER_H
#define DBUFFER_H

#include <ostream> //std::ostream

/**
	@file dbuffer.h
	@brief Dichiarazione della classe dbuffer
*/

/**
	@brief Array dinamico di interi

	Classe che rappresenta un array dinamico di interi.
	La dimensione dell'aaray dinamico dell'array poò essere scelta in fase di costruzione.
*/
class dbuffer{

public:
	typedef int value_type;
	typedef unsigned int size_type;


private:
	value_type * _buffer; ///< Puntatore all'array dinamico di interi
	size_type _size; ///< Dimensione dell'array

public:
	/**
		@brief Costruttore di default (METODO FONDAMENTALE 1)

		Costruttore di default per instanziare un dbuffer vuoto.

		@post _buffer == nullptr
		@post _size == 0
	*/
	dbuffer();

	/**
		@brief Costruttore secondario

		Costruttore secondario che crea un dbuffer dalla dimensione data.

		@param sz dimensione dbuffer da creare
	*/
	explicit dbuffer(size_type sz);

	/**
		@brief Costruttore secondario

		Costruttore secondario che crea un dbuffer dalla dimensione data e inizializza le celle dell'array al valore passato.

		@param sz dimensione dbuffer da creare
		@param value valore a cui inizializzare le celle dell'array
	*/
	dbuffer(size_type sz, value_type value);

	/**
		@brief Copy constructor (METODO FONDAMENTALE 3)

		Costruttore di copia tra un dbuffer e un altro.

		@param &other dbuffer da copiare
	*/
	dbuffer(const dbuffer &other);

	/**
		@brief Operatore di assegnamento (METODO FONDAMENTALE 4)

		Operatore di assegnamento che serve per copiare il contenuto di ther in *this

		@param &other dbuffer da copiare

		@return reference a dbuffer
	*/
	dbuffer& operator=(const dbuffer &other); // *this = other;

	/**
		@brief Distruttore della classe (METODO FONDAMENTALE 2)

		Distruttore della classe. Rimuove dallo heap l'array dinamico allocato in precedenza.

		@post _buffer == nullptr
		@post _size == 0
	*/
	~dbuffer();

	/**
		@brief Accesso ai dai in lettura (stile Java)
		
		Metodo getter per leggere il valore indexesimo dell'array

		@param index indice della cella dell'array da leggere

		@pre index < _size

		@return valore indice della cella indexesima
	*/
	value_type get_value(size_type index) const;

	/**
		@brief Accesso ai dai in scrittura (stile Java)
		
		Metodo setter per scrivere il valore nella cella indexesima dell'array

		@param index indice della cella dell'array da scrivere
		@param value valore da scrivere nella cella

		@pre index < _size
	*/
	void set_value(size_type index, value_type value);

	/**
		@brief Getter/Setter della cella indexesima (stile C++)

		Funzione che permette di leggere e/o scrivere la cella indexesima dell'array

		@param indice della cella da leggere/scrivere

		@return reference alla cella indexesima
	*/
	value_type &value(size_type index);

	/**
		@brief Getter della cella indexesima (stile C++)

		Funzione che permette di leggere  la cella indexesima dell'array

		@param indice della cella da leggere

		@return reference alla cella indexesima
	*/
	const value_type &value(size_type index) const;

	/**
		@brief Accesso alla dimensione dell'array (stile Java)

		Metodo per ottenere la dimensione dell'array dinamico

		@return dimensione dell'array dinamico
	*/
	size_type get_size() const;

	/**
		@brief Finzione cdi swap dei dati interni tradue dbuffer

		Funzione che scambia gli strati interni tra due dbuffer

		@param other dbuffer sorgente
	*/
	void swap(dbuffer &other);

	/**
		@brief Funzione di stampa del contenuto del dbuffer

		Funzione che stampa a schermo il contenuto della classe dbuffer
	*/
	void print() const;

	value_type &operator[](size_type index);

	const value_type &operator[](size_type index) const;
};

std::ostream& operator<<(std::ostream &os, const dbuffer &db);

#endif
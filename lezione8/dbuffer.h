#ifndef DBUFFER_H
#define DBUFFER_H

#include <ostream> //std::ostream
#include <iostream> //std::cout std::endl
#include <cassert> //assert
#include <algorithm> //std::swap

/**
	@file dbuffer.h
	@brief Dichiarazione della classe dbuffer
*/

/**
	@brief Array dinamico di interi

	Classe che rappresenta un array dinamico di interi.
	La dimensione dell'aaray dinamico dell'array poò essere scelta in fase di costruzione.
*/
template <typename T>
class dbuffer{

public:
	typedef T value_type;
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
	dbuffer(): _buffer(nullptr), _size(0) {
		#ifndef NDEBUG
		std::cout << "dbuffer::dbuffer()" << std::endl;
		#endif
	}

	/**
		@brief Costruttore secondario

		Costruttore secondario che crea un dbuffer dalla dimensione data.

		@param sz dimensione dbuffer da creare
	*/
	explicit dbuffer(size_type sz): _buffer(nullptr), _size(0) {
		_buffer = new value_type[sz];
		_size = sz;

		#ifndef NDEBUG
		std::cout << "dbuffer::dbuffer(size_type)" << std::endl;
		#endif
	}

	/**
		@brief Costruttore secondario

		Costruttore secondario che crea un dbuffer dalla dimensione data e inizializza le celle dell'array al valore passato.

		@param sz dimensione dbuffer da creare
		@param value valore a cui inizializzare le celle dell'array
	*/
	dbuffer(size_type sz, const value_type &value): _buffer(nullptr), _size(0) {
		_buffer = new value_type[sz];
		_size = sz;

		try{
			for (size_type i=0; i<sz; ++i)
				_buffer[i] = value;
		}
		catch(...){
			delete[] _buffer;
			_buffer = nullptr;
			_size = 0;
			throw;
		}

		#ifndef NDEBUG
		std::cout << "dbuffer::dbuffer(size_type, value_type)" << std::endl;
		#endif
	}

	/**
		@brief Costruttore di conversione

		Costruttore di conversione da un dbuffer<Q> a un dbuffer<T>.

		@param &other dbuffer da copiare
	*/
	template <typename Q>
	dbuffer(const dbuffer<Q> &other): _buffer(nullptr), _size(0) {
		_buffer = new value_type[other.get_size()];

		try{
		for(size_type i = 0; i < other.get_size(); ++i)
			_buffer[i] = static_cast<T>(other[i]);
		}
		catch(...){
			delete[] _buffer;
			_buffer = nullptr;
			_size = 0;
			throw;
		}

		_size = other.get_size();

		#ifndef NDEBUG
		std::cout << "dbuffer::dbuffer(const dbuffer&)" << std::endl;
		#endif
	}

	/**
		@brief Copy constructor (METODO FONDAMENTALE 3)

		Costruttore di copia tra un dbuffer e un altro.

		@param &other dbuffer da copiare
	*/
	dbuffer(const dbuffer &other): _buffer(nullptr), _size(0) {
		_buffer = new value_type[other._size];

		try{
		for(size_type i = 0; i < other._size; ++i)
			_buffer[i] = other._buffer[i];
		}
		catch(...){
			delete[] _buffer;
			_buffer = nullptr;
			_size = 0;
			throw;
		}

		_size = other._size;

		#ifndef NDEBUG
		std::cout << "dbuffer::dbuffer(const dbuffer&)" << std::endl;
		#endif
	}

	/**
		@brief Operatore di assegnamento (METODO FONDAMENTALE 4)

		Operatore di assegnamento che serve per copiare il contenuto di ther in *this

		@param &other dbuffer da copiare

		@return reference a dbuffer
	*/
	dbuffer& operator=(const dbuffer &other){
		if(&other != this){ 
			dbuffer tmp(other);
			tmp.swap(*this);
		}

		#ifndef NDEBUG
		std::cout << "dbuffer::operator=(const dbuffer&)" << std::endl;
		#endif

		return *this;
	}

	/**
		@brief Distruttore della classe (METODO FONDAMENTALE 2)

		Distruttore della classe. Rimuove dallo heap l'array dinamico allocato in precedenza.

		@post _buffer == nullptr
		@post _size == 0
	*/
	~dbuffer(){
		delete[] _buffer;
		_buffer = nullptr;
		_size = 0;

		#ifndef NDEBUG
		std::cout << "dbuffer::~dbuffer()" << std::endl;
		#endif
	}

	/**
		@brief Accesso ai dai in lettura (stile Java)
		
		Metodo getter per leggere il valore indexesimo dell'array

		@param index indice della cella dell'array da leggere

		@pre index < _size

		@return valore indice della cella indexesima
	*/
	const value_type &get_value(size_type index) const {
		assert(index < _size);
		return _buffer[index];
	}

	/**
		@brief Accesso ai dai in scrittura (stile Java)
		
		Metodo setter per scrivere il valore nella cella indexesima dell'array

		@param index indice della cella dell'array da scrivere
		@param value valore da scrivere nella cella

		@pre index < _size
	*/
	void set_value(size_type index, const value_type &value){
		assert(index < _size);
		_buffer[index] = value;
	}

	/**
		@brief Getter/Setter della cella indexesima (stile C++)

		Funzione che permette di leggere e/o scrivere la cella indexesima dell'array

		@param indice della cella da leggere/scrivere

		@return reference alla cella indexesima
	*/
	value_type &value(size_type index){
		assert(index < _size);
		return _buffer[index];
	}

	/**
		@brief Getter della cella indexesima (stile C++)

		Funzione che permette di leggere  la cella indexesima dell'array

		@param indice della cella da leggere

		@return reference alla cella indexesima
	*/
	const value_type &value(size_type index) const{
		assert(index < _size);
		return _buffer[index];
	}

	/**
		@brief Accesso alla dimensione dell'array (stile Java)

		Metodo per ottenere la dimensione dell'array dinamico

		@return dimensione dell'array dinamico
	*/
	size_type get_size() const{
		return _size;
	}

	/**
		@brief Finzione cdi swap dei dati interni tradue dbuffer

		Funzione che scambia gli strati interni tra due dbuffer

		@param other dbuffer sorgente
	*/
	void swap(dbuffer &other){
		std::swap(this->_buffer, other._buffer);
		std::swap(this->_size, other._size); 
	}

	/**
		@brief Funzione di stampa del contenuto del dbuffer

		Funzione che stampa a schermo il contenuto della classe dbuffer
	*/
	void print() const {
		std::cout << _size << std::endl;
		for(size_type i=0; i < _size; ++i)
			std::cout << _buffer[i] << " ";
		std::cout << std::endl;
	}

	value_type &operator[](size_type index){
		assert(index < _size);
		return _buffer[index];
	}

	const value_type &operator[](size_type index) const{
		assert(index < _size);
		return _buffer[index];
	}
};

template <typename U>
std::ostream& operator<<(std::ostream &os, const dbuffer<U> &db){
	os << db.get_size() << std::endl;
	for(typename dbuffer<U>::size_type i=0; i < db.get_size(); ++i)
		os << db.value(i) << " ";
	os << std::endl;
	return os;
};

#endif
#ifndef DBUFFER_H
#define DBUFFER_H

namespace dbuffer{
	/**
		Struct che rappresenta un array dinamico di interi
	*/
	struct dynamic_buffer{
		unsigned int size; //<< dimensione dell'array di interi
		int *buffer; //<< puntatore all'array di interi
	};

	/**
		Funzione che stampa il contenuto di un dynamic_buffer

		@param db dynamic_buffer da stampare

		@pre db.buffer != nullptr
	*/
	void stampa_buffer(const dynamic_buffer &db);

	/**
		Funzione che inizializza a zero il contenuto di un dynamic_buffer.
		Porta il dynamic_buffer in uno stato coerente (size=0 e buffer=nullptr)

		@param db dynamic_buffer da modificare

		@post db.size == 0
		@post db.buffer == nullptr
	*/
	void inizializza_buffer(dynamic_buffer &db);

	/**
		funzione che riempie il dynamic_buffer con un array dinamico

		@param db dynamic_buffer da modificare
		@param size dimensione dell'array di interi da allocare

		@post db.size == size
		@past db.buffer != nullptr
	*/
	void alloca_buffer(dynamic_buffer &db, unsigned int size);

	/**
		Fuzione che dealloca la memoria contenuta nel dynamic_buffer

		@param db dynamic_buffer da modificare

		@post db.size ==0
		@post db.buffer == nullptr
	*/
	void dealloca_buffer(dynamic_buffer &db);

	/**
		Funzione che riempie le celle dell'array di interi in dynamic_buffer
		In questa verisne i dati vengono da un altro array di interi che ha la stessa size

		@param db dynamic_buffer da modificare
		@param values puntatore all'array da usare
		@param val_size dimensione dell'array di interi

		@pre db.buffer != nullptr
		@pre values != nullptr
		@pre val_size == db.size
	*/
	void riempi_buffer(dynamic_buffer &db, const int *values, unsigned int val_size);

	/**
		Funzione che clona il contenuto di un dynamic_buffer in un nuovo dynamic_buffer

		@param src dynamic_buffer da copiare
		@return un nuovo dynamic_buffer con il contenuto di src

		@post 
	*/
	dynamic_buffer copia_buffer(const dynamic_buffer &src);
}

#endif
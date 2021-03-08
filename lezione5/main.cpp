#include <iostream>
#include "dbuffer.h"

int main(){

	dbuffer::dynamic_buffer db;

	dbuffer::inizializza_buffer(db);
	std::cout << "db.size: " << db.size << std::endl;
	std::cout << "db.buffer: " << db.buffer << std::endl;

	int values[5] = {1, 2, 3, 4, 5};

	dbuffer::alloca_buffer(db, 5);
	dbuffer::riempi_buffer(db, values, 5);
	dbuffer::stampa_buffer(db);
	
	dbuffer::dynamic_buffer tmp;
	tmp = dbuffer::copia_buffer(db); //tmp.size = dst.size AND tmp.buffer = dst.buffer
	dbuffer::stampa_buffer(tmp);

	dbuffer::dealloca_buffer(db);
	dbuffer::dealloca_buffer(tmp);

	return 0;
}
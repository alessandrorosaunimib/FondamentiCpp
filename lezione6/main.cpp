#include "dbuffer.h"
#include <iostream>

void funct(dbuffer *d){

};

int main(){
	//dbuffer db; //chiamta al ctor di default
	//dbuffer adb[5]; //array statico di 5 dbuffer
	//dbuffer db(10, 1);
	/**
	db.set_value(5, 100);
	
	for (unsigned int i=0; i<10; ++i)
		std::cout << db.get_value(i) << std::endl;
	
	*/
	
	/**
	db.value(5) = 100; //db.set_value(5, 100);
	int i = db.value(1); //int i = db._buffer[1];
	db.value(0) = db.value(1); // db.set_value(0, db.get_value(1));
	for (unsigned int i=0; i<db.get_size(); ++i)
		std::cout << db.get_value(i) << std::endl;
	*/

	/**
	dbuffer db(3, 0);
	//dbuffer db2 (db); //copy constructor
	//dbuffer db2 = db; //copy constructor
	
	dbuffer db2;

	db2 = db; //assegnamento (no copy constructor)
	*/

	dbuffer db(10);

	db.print();
	std::cout << "--------------------" << std::endl;
	
	int value = db[1];
	db[6] = 9;

	std::cout << db << std::endl;

	return 0;
};
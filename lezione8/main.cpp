#include "dbuffer.h"
#include <iostream>

/**
void funct(dbuffer *d){

};
*/

//scrivere una funzione che prende un dbuffer<Int> e stampa a chermo i valori che superano i valori superiori a 5
template <typename T>
void funct5(const dbuffer<T> &db){
	for(typename dbuffer<T>::size_type i=0; i < db.get_size(); ++i){
		if(db[i] > 5)
			std::cout << db[i] << std::endl;
	}
}

int main(int argc, char *argv[]){
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

	/**
	dbuffer db(10);

	db.print();
	std::cout << "--------------------" << std::endl;
	
	int value = db[1];
	db[6] = 9;

	std::cout << db << std::endl;
	*/

	/**
	//test per metodi template
	dbuffer<int> db(100, 1);
	dbuffer<int> db1(100);
	dbuffer<int> db2(db1);
	db.swap(db1);
	db=db1;
	db[1] = db1[10];
	unsigned int s = db1.get_size();
	db.print();
	dbuffer<char> dbc;
	//dbc=db; //i due dbuffer non sono compatibili perchè uno ha dei dati char e int
	std::cout << db << std::endl;
	std::cout << dbc << std::endl;
	dbuffer<int> dbi(dbc);
	*/

	dbuffer<int> db5(10, 10);
	dbuffer<double> db6(10, 5.27);
	funct5(db5);
	funct5(db6);


	return 0;
};
/**
	@file dbuffer.cpp
	@brief definizione della classe dbuffer
*/

#include "dbuffer.h"
#include <iostream> //std::cout std::endl
#include <cassert> //assert
#include <algorithm> //std::swap

dbuffer::dbuffer() : _buffer(nullptr), _size(0) { //o inizialization list o assegnamento come commentato
	//_buffer = nullptr;
	//_size = 0;

	#ifndef NDEBUG
	std::cout << "dbuffer::dbuffer()" << std::endl;
	#endif
};

dbuffer::dbuffer(size_type sz): _buffer(nullptr), _size(0) {
	_buffer = new value_type[sz];
	_size = sz;

	#ifndef NDEBUG
	std::cout << "dbuffer::dbuffer(unsigned int)" << std::endl;
	#endif
};

dbuffer::dbuffer(size_type sz, value_type value): _buffer(nullptr), _size(0) {
	_buffer = new value_type[sz];
	_size = sz;

	for (size_type i=0; i<sz; ++i)
		_buffer[i] = value;

	#ifndef NDEBUG
	std::cout << "dbuffer::dbuffer(unsigned int, int)" << std::endl;
	#endif
};

dbuffer::dbuffer(const dbuffer &other): _buffer(nullptr), _size(0) {
	_buffer = new value_type[other._size];

	for(size_type i = 0; i < other._size; ++i)
		_buffer[i] = other._buffer[i];

	_size = other._size;

	#ifndef NDEBUG
	std::cout << "dbuffer::dbuffer(const dbuffer&)" << std::endl;
	#endif
};

dbuffer& dbuffer::operator=(const dbuffer &other){
	if(&other != this){ //controllo dell'auto-assegnamento "a = a";
		dbuffer tmp(other); //copy constructor
		tmp.swap(*this);
	}

	#ifndef NDEBUG
	std::cout << "dbuffer::operator=(const dbuffer&)" << std::endl;
	#endif

	return *this; //a=b=c; -> a=(b=c);
};

dbuffer::~dbuffer(){
	delete[] _buffer;
	_buffer = nullptr;
	_size = 0;

	#ifndef NDEBUG
	std::cout << "dbuffer::~dbuffer()" << std::endl;
	#endif
};

dbuffer::value_type dbuffer::get_value(size_type index) const {
	assert(index < _size);
	return _buffer[index];
};

void dbuffer::set_value(size_type index, value_type value){
	assert(index < _size);
	_buffer[index] = value;
};

dbuffer::value_type &dbuffer::value(size_type index){
	assert(index < _size);
	return _buffer[index];
};
const dbuffer::value_type &dbuffer::value(size_type index) const {
	assert(index < _size);
	return _buffer[index];
};

dbuffer::size_type dbuffer::get_size() const {
	return _size;
};

void dbuffer::swap(dbuffer &other){
	std::swap(this->_buffer, other._buffer); //scambio il contentuto delle due variabili puntatore
	std::swap(this->_size, other._size); //scambio il contentuto delle due variabili unsigned int
};

void dbuffer::print() const{
	std::cout << _size << std::endl;
	for(size_type i=0; i < _size; ++i)
		std::cout << _buffer[i] << " ";
	std::cout << std::endl;
};

std::ostream& operator<<(std::ostream &os, const dbuffer &db){
	os << db.get_size() << std::endl;
	for(dbuffer::size_type i=0; i < db.get_size(); ++i)
		os << db.value(i) << " ";
	os << std::endl;

	return os;
};

dbuffer::value_type &dbuffer::operator[](size_type index){
	assert(index < _size);
	return _buffer[index];
};

const dbuffer::value_type &dbuffer::operator[](size_type index) const{
	assert(index < _size);
	return _buffer[index];
};
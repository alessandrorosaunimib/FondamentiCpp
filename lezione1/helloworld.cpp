#include <iostream>
#include "file1.h"
// cd /mnt/c/cpp/lezione1
// g++ -c helloworld.cpp -o main.o
// g++ -c file1.cpp -o file1.o
// g++ main.o file1.o -o main.exe
// ./main.exe

int main(){
	std::cout << "Hello world";
	std::cout << std::endl;
	funct1();
	return 0;
} 
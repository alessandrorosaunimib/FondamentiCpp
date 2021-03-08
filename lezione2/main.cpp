#include <iostream>
#include <fstream>
#include <string>

void output_input(){

	std::cout << "Primo messaggio" << std::endl;

	int value = -1;

	//std::cin.exceptions(std::fstream::failbit | std::fstream::badbit);	//secondo metodo per eccezioni su input

	std::cout << "Inserisci un numero intero: ";
	std::cin >> value;

	while(std::cin.fail()){
		std::cin.clear();	//cancella il flag fail
		std::cin.ignore(4096, '\n');	//cancella il buffer cin

		std::cout << "Errore" << std::endl;

		std::cout << "Inserisci un numero intero: ";
		std::cin >> value;
	}

	std::cout << "Valore inserito: " << value << std::endl;
}

void tipi_di_dati_primitivi(){
	bool b;
	int i;
	float f;
	double d;
	char c;
	int *pi;
	double *pd;

	std::cout << "dimensione di b: " << sizeof(b) << std::endl;
	std::cout << "dimensione di i: " << sizeof(i) << std::endl;
	std::cout << "dimensione di f: " << sizeof(f) << std::endl;
	std::cout << "dimensione di d: " << sizeof(d) << std::endl;
	std::cout << "dimensione di c: " << sizeof(c) << std::endl;
	std::cout << "dimensione di pi: " << sizeof(pi) << std::endl;
	std::cout << "dimensione di pd: " << sizeof(pd) << std::endl;
}

void i_puntatori(){
	int *pin = nullptr; //oppure 0 oppure NULL
	int i = 100;
	pin= &i;
	std::cout << "valore di i iniziale: " << i << std::endl;
	*pin = 0;
	std::cout << "valore di i finale: " << i << std::endl;

	int *pj = pin;
	std::cout << "pin: " << pin << std::endl;
	std::cout << "pj: " << pj << std::endl;
	std::cout << "&i: " << &i << std::endl;

	std::cout << "&pin: " << &pin << std::endl;
	std::cout << "&pj: " << &pj << std::endl;

	pj = pj +1;
	std::cout << "pj+1: " << pj << std::endl;
}

void array_e_puntatori(){
	int array[100] = {1,2,3,4};
	int *pa = array;
	std::cout << "*pa: " << *pa << std::endl;
	std::cout << "pa: " << pa << std::endl;
	std::cout << "*pa+1: " << (*pa+1) << std::endl;
}

void reference_e_cont(){
	int n = 999;
	int &ref = n;
	std::cout << "n: " << n << std::endl;
	std::cout << "ref: " << ref << std::endl;
	std::cout << "&n: " << &n << std::endl;
	std::cout << "&ref: " << &ref << std::endl;

	const double pigreco = 3.14;
	//pigreco = 0;	//errore perchè la variabile è costante
	const double *pc = &pigreco;
	const double &pref = pigreco;
}

void le_stringhe(){
	char str[]="ciao a tutti";
	std::cout << "str: " << str << std::endl;
	char *pstr = str;
	std::cout << "pstr: " << pstr << std::endl;
	char *pstr2;
	std::cout << "pstr2: " << pstr2 << std::endl;
	std::string s = "pippo";
	std::cout << "s: " << s << std::endl;
}

int main(int argc; char*argv[]){

	/*
	output_input();
	tipi_di_dati_primitivi();
	i_puntatori();
	array_e_puntatori();
	reference_e_cont();
	*/
	le_stringhe();

	return 0;
}
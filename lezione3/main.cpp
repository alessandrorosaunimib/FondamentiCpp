#include <iostream>

int main(){

	int i;
	int a[10];

	int *pi = new int; //allocazione dinamica HEAP
	std::cout << "&i : " << &i << std::endl;
	std::cout << "&pi : " << &pi << std::endl;
	std::cout << "pi : " << pi << std::endl;

	*pi = 100;

	int *dyn_array = new int[100];

	dyn_array[10] = 10;

	delete pi;
	pi = nullptr;

	delete[] dyn_array;


	return 0;
}
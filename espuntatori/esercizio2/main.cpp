#include <iostream> // std::cout std::cin
#include <random> // std::mt19937
#include <ctime> // time

int main(){
	unsigned int dimensioneX;
	unsigned int dimensioneY;
	unsigned int numeroK;

	std::cout << "Inserisci la prima dimensione della matrice:" << std::endl;
	std::cin >> dimensioneX;

	while (std::cin.fail()) {
		std::cin.clear();

		std::cin.ignore(4096,'\n');

		std::cout<<"ERRORE"<<std::endl;

		std::cout << "Inserisci la prima dimensione della matrice:" << std::endl;
		std::cin >> dimensioneX;
	}

	std::cout << "Inserisci la seconda dimensione della matrice:" << std::endl;
	std::cin >> dimensioneY;

	while (std::cin.fail()) {
		std::cin.clear();

		std::cin.ignore(4096,'\n');

		std::cout<<"ERRORE"<<std::endl;

		std::cout << "Inserisci la seconda dimensione della matrice:" << std::endl;
		std::cin >> dimensioneY;
	}

	std::cout << "Scegli K:" << std::endl;
	std::cin >> numeroK;

	while (std::cin.fail()) {
		std::cin.clear();

		std::cin.ignore(4096,'\n');

		std::cout<<"ERRORE"<<std::endl;

		std::cout << "Scegli K:" << std::endl;
		std::cin >> numeroK;
	}

	int array[dimensioneX][dimensioneY];

	for(int i=0; i!=dimensioneX; ++i){
		for(int j=0; j!=dimensioneY; ++j){
			array[i][j]=0;
		}
	}

	int (*p)[dimensioneY] = array;

	std::mt19937 rnd(time(0)); // Mersenne Twister pseudo-random generator
	for (int k = 0; k < numeroK; ++k) {
		int i = rnd() % dimensioneX;
		int j = rnd() % dimensioneY;
		p=array+i;
		(*p)[j] += 1;
		std::cout << "modificato p["<<i<<"]["<<j<<"] : " << array[i][j] << std::endl;

	}
}
#include <iostream> // std::cout std::cin


void calcolaSomma(int *punt, unsigned int dimensione, int &somma){
	std::cout << "valore punt " << *punt << std::endl;
	for(unsigned int i=0; i != dimensione; ++i){
		somma += *punt;
		std::cout << "valore somma parziale " << somma << std::endl;
		punt++;
	}
}

int main(){

	unsigned int dimensione =0;
	std::cout << "Inserisci la dimensione dell'array: " << std::endl;
	std::cin >> dimensione;

	while (std::cin.fail()) {
		std::cin.clear();

		std::cin.ignore(4096,'\n');

		std::cout<<"errore"<<std::endl;

		std::cout << "Inserisci la dimensione dell'array: ";
		std::cin >> dimensione;
	}

	int ai[dimensione];

	int *pi=ai;

	unsigned int i = 0;
	while(i!=dimensione){
		int valore;
		std::cout << "Inserisci il valore dell'elemento " << i << " dell'array: " << std::endl;
		std::cin >> valore;

		while (std::cin.fail()) {

			std::cin.clear();

			std::cin.ignore(4096,'\n');

			std::cout<<"errore"<<std::endl;

			std::cout << "Inserisci il valore dell'elemento " << i << " dell'array: " << std::endl;
			std::cin >> valore;
		}

		*pi = valore;
		std::cout << "Inserito il valore  " << *pi << std::endl;
		pi++;

		++i;
	}

	int somma = 0;
	calcolaSomma(ai, dimensione, somma);
	std::cout << "La somma dei valori inseriti è " << somma << std::endl;

	return 0;
}


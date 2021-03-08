#include <iostream>
#include <cassert> //assert

void stampa_stringa(const char *str){
	assert(str != nullptr);
	const char *current = str;
	while(*current != '\0'){
		std::cout << *current << std::endl;
		current++; //current = current+1
	}
}

unsigned int lunghezza_stringa(const char *str){
	assert(str != nullptr);
	const char *current = str;
	//unsigned int lung = 0;
	while(*current != '\0'){
		//lung++;
		current++;
	}
	return static_cast<unsigned int>(current- str);
	//return lung;
}

void inverti_stringa(char *str){
	assert(str != nullptr);
	unsigned int sz = lunghezza_stringa(str);
	char *start = str;
	char *end = str + sz - 1;
	while(start < end){
		std::swap(*start, *end);
		start++;
		end--;
	}
}

char *clona_stringa(const char *str){
	assert(str != nullptr);
	unsigned int sz = lunghezza_stringa(str);
	char *out = new char[sz+1] //1 è il carattere di fine stringa
	for (unsigned int i = 0; i < sz+1; ++i){
		out[i] = str[i];
	}
	return out;
}

int main(int argc, char *argv[]){
	//argv[0] == nome dell'eseguibile
	//argv[1] == stringa passata dall'utente
	if (argc != 2){
		std::cout << "Necessaria una stringa come argomento" << std::endl;
		return 0;
	}

	stampa_stringa(argv[1]);
	std::cout << "La lunghezza della stringa è: " << lunghezza_stringa(argv[1]) << std::endl;

	inverti_stringa(argv[1]);
	std::cout << "Stringa invertita: " << argv[1] << std::endl;

	char *clone = clona_stringa(argv[1]);
	delete[] clone;
	clone = nullptr;

	return 0;
}
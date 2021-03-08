#include <iostream>
#include <cassert>
#include <cmath>

class vect3d{
	double _values[3];

public:
	vect3d(){
		_values[0]=_values[1]=_values[2]=0;
	}

	vect3d(double v0, double v1, double v2){
		_values[0] = v0;
		_values[1] = v1;
		_values[2] = v2;
	}

	explicit vect3d (double v){
		_values[0] = v;
		_values[1] = v;
		_values[2] = v;
	}

	~vect3d(){}

	vect3d(const vect3d &other){
		_values[0] = other._values[0];
		_values[1] = other._values[1];
		_values[2] = other._values[2];
	}

	vect3d operator=(const vect3d &other){
		if (this != &other){
			_values[0] = other._values[0];
			_values[1] = other._values[1];
			_values[2] = other._values[2];
		}
		return *this;
	}

	double& operator[](unsigned int index){
		assert(index <= 2);
		return _values[index];
	}

	const double& operator[](unsigned int index) const {
		assert(index <= 2);
		return _values[index];
	}

	//norma del vettore
	double operator!() const {
		double result;
		result = std::sqrt(_values[0]*_values[0]+_values[1]*_values[1]+_values[2]*_values[2]);
		return result;
	}

	//negazione del vettore
	vect3d operator-() const {
		vect3d v(-_values[0], -_values[1], -_values[2]);
		return v;
	}
	
};

//somma tra vettori
vect3d operator+(const vect3d &v1, const vect3d &v2){
	vect3d v3(v1[0]+v2[0], v1[1]+v2[1], v1[2]+v2[2]);
	return v3;
}

//differenza tra vettori
vect3d operator-(const vect3d &v1, const vect3d &v2){
	vect3d v3(v1[0]-v2[0], v1[1]-v2[1], v1[2]-v2[2]);
	return v3;
}

/** //norma del vettore fatta come funzione globale
double operator!(const vect3d &v){
	double result;
		result = std::sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
		return result;
}
*/

std::ostream& operator<<(std::ostream &os, const vect3d &v){
	os << "[" << v[0] <<  " " << v[1] << " " << v[2] << "]";
	return os;
}

int main(){
	vect3d v(1,1,1);
	std::cout << v << std::endl;
	std::cout << !v << " Norma" << std::endl;
	std::cout << -v << " Negazione" << std::endl;

	vect3d v1(1,2,3);
	vect3d v2 = v+v1;
	std::cout << v2 << " Somma tra vettori" << std::endl;
	assert(v2[0]==2);
	assert(v2[1]==3);
	assert(v2[2]==4);

	v2 = v-v1;
	std::cout << v2 << " Differenza tra vettori" << std::endl;
	assert(v2[0]==0);
	assert(v2[1]==-1);
	assert(v2[2]==-2);


	return 0; 
}
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#pragma once
using namespace std;

class categoria{
private:
	int codCategoria;
	string nombreCategoria;
public:
	categoria(){}
	categoria(int cod, string nom){
		this->codCategoria=cod;
		this->nombreCategoria=nom;
	}
	int getCodCategoria(){
		return codCategoria;
	}
	string getNombreCategoria(){
		return nombreCategoria;
	}
	void setcodcategoria(int cod){
		this->codCategoria=cod;
	}
	void setnombrecategoria(string nom){
		this->nombreCategoria=nom;
	}
};



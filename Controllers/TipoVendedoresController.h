#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "../Models/TipoVendedores.h"
#pragma once
using namespace std;

class tipocontroller{
private:
	vector <tipo> C;
public:
	tipocontroller(){
		Datos();
	}
	int size(){
		return C.size();
	}
	void add(tipo c){
		C.push_back(c);
	}
	tipo get(int pos){
		return C[pos];
	}
	int codigo(){
		if(size() == 0){
		return 1;
		}
		else{
			return 	C[size() - 1].getCodT() + 1;
		}}
	string getC(int codT){
		for(int i=0;i<size();i++){
			if(codT == C[i].getCodT()){
			return C[i].getNomT();
			}
		}
	return "Error";
	}
	void guardar_archivo(tipo obj){
		try{
		fstream archivoC;
		archivoC.open("TIPO.csv",ios::app);
			if(archivoC.is_open())
			{
				archivoC<<obj.getCodT()<<";"<<obj.getNomT()<<endl;
				archivoC.close();					
			}
		}
			catch(exception e){
				cout<<"Ocurrio un error al grabar el tipo de vendedor en el archivo\n";
			}
	}
	void Datos(){
		ifstream archivoC;
		archivoC.open("TIPO.csv", ios::in);
		string linea;
		char delimitador = ';';
	    while(getline(archivoC,linea)){
		stringstream stream(linea);
		string codigo, nombre;
		getline(stream,codigo,delimitador);
		getline(stream,nombre,delimitador);
		int c=stoi(codigo);
		tipo cat(c,nombre);
		add(cat);
		}
	}
	bool isEmpty(){
		return C.empty();
	}
};

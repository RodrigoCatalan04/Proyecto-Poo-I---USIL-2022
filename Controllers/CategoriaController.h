#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "../Models/categoria.h"
#pragma once
using namespace std;

class categoriacontroller{
private:
	vector <categoria> categorias;
public:
	categoriacontroller(){
		archivo_tovector();
	}
	int categoriasize(){
		return categorias.size();
	}
	void add(categoria c){
		categorias.push_back(c);
	}
	categoria get(int pos){
		return categorias[pos];
	}
	int codigo(){
		if(categoriasize() == 0){
			return 1;
		}
		else{
			return 	categorias[categoriasize() - 1].getCodCategoria() + 1;
		}
	}
	string getCategoria(int cod){
		for(int i=0;i<categoriasize();i++){
			if(cod == categorias[i].getCodCategoria()){
				return categorias[i].getNombreCategoria();
			}
		}
		return "Error";
	}
	void guardar_archivo(categoria obj){
		try{
			fstream archivoCategoria;
			archivoCategoria.open("categoria.csv",ios::app);
			if(archivoCategoria.is_open())
			{
				archivoCategoria<<obj.getCodCategoria()<<";"<<obj.getNombreCategoria()<<endl;
				archivoCategoria.close();					
			}
		}
		catch(exception e){
			cout<<"Ocurrio un error al grabar la categoria en el archivo\n";
		}
	}
	void archivo_tovector(){
		ifstream archivoCategoria;
		archivoCategoria.open("categoria.csv", ios::in);
		string linea;
		char delimitador = ';';
		while(getline(archivoCategoria,linea)){
			stringstream stream(linea);
			string codigo, nombre;
			getline(stream,codigo,delimitador);
			getline(stream,nombre,delimitador);
			int c=stoi(codigo);
			categoria cat(c,nombre);
			add(cat);
		}
	}
};


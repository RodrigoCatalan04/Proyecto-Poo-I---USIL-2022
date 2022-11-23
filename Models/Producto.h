#include <iostream>
#pragma once
using namespace std;

class ventamas{
private:
	int codigo;
	int codigoCategoria;
	string nombre;
	float precio;
	int stock;
public:
	ventamas(){ }
	ventamas(int c, string n, float p, int s, int cod){
		this->codigo=c;
		this->nombre=n;
		this->precio=p;
		this->stock=s;
		this->codigoCategoria=cod;
	}
	int getCodigo()
	{
		return codigo;
	}
	string getNombre()
	{
		return nombre;
	}
	float getPrecio()
	{
		return precio;
	}
	int getStock()
	{
		return stock;
	}
	int getCodigoCategoria(){
		return codigoCategoria;
	}
	void setcodigo(int c)
	{
		this->codigo =c;
	}
	void setnombre(string n)
	{
		this->nombre=n;
	}
	void setprecio(float p)
	{
		this->precio=p;
	}	
	void setStock(int s)
	{
		this->stock=s;
	}
	void setcodigoCategoria(int c){
		this->codigoCategoria=c;
	}
};


#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "../Models/Producto.h"
#pragma once


using namespace std;

class VentaController
{
private:
	vector <ventamas> vectorController;
public:
	VentaController()
	{
		archivo_tovector();
	}
	//Agregar objetos al arreglo
	void add(ventamas obj)
	{
		vectorController.push_back(obj);
	}
	//Agregar objetos al archivo
	void guardar_archivo(ventamas obj){
		try{
			fstream archivoProductos;
			archivoProductos.open("productos.csv",ios::app);
			if(archivoProductos.is_open())
			{
				archivoProductos<<obj.getCodigo()<<";"<<obj.getNombre()<<";"
					<<obj.getPrecio()<<";"<<obj.getStock()<<";"<<obj.getCodigoCategoria()<<endl;
				archivoProductos.close();					
			}
		}
		catch(exception e){
			cout<<"Ocurrio un error al grabar productos en el archivo\n";
		}
	}
	ventamas get(int pos)
	{
		return vectorController[pos];
	}
	//Cantidad de elementos
	int size()
	{
		return vectorController.size();
	}
	//Búsqueda
	ventamas busqueda(int c){
		ventamas objError;
		objError.setnombre("Error");
		int superior,inferior,mitad;
		inferior =0;
		superior = size();
		mitad = (inferior + superior)/2;
		while(inferior<=superior)
		{
			if(get(mitad).getCodigo() == c)
			{
				return vectorController[mitad];
				break;
			}
			if(get(mitad).getCodigo() > c)
			{
				superior = mitad - 1;
			}
			if(get(mitad).getCodigo() < c)
			{
				inferior = mitad + 1;
			}
			
			mitad = (inferior + superior)/2;
		}
		return objError;
	};
	int codigo(){
		if(size() == 0){
			return 1;
		}
		else{
			return 	vectorController[size() - 1].getCodigo() + 1;
		}
	}
	//Agregar del archivo al vector
	void archivo_tovector(){
		ifstream archivoProductos;
		archivoProductos.open("productos.csv", ios::in);
		string linea;
		char delimitador = ';';
		while(getline(archivoProductos,linea)){
			stringstream stream(linea);
			string codigo, nombre, precio,stock,categoria;
			getline(stream,codigo,delimitador);
			getline(stream,nombre,delimitador);
			getline(stream,precio,delimitador);
			getline(stream,stock,delimitador);
			getline(stream,categoria,delimitador);
			int c = stoi(codigo);
			int cod=stoi(categoria);
			float p = stof(precio);
			int s= stoi(stock);
			ventamas Producto(c,nombre,p,s,cod);
			add(Producto);
		}
	}
	int obtenerPosicionVector(ventamas obj){
		for(int i=0;i<vectorController.size();i++)		{
			if(obj.getCodigo() == vectorController[i].getCodigo()){
				return i;
			}
		}
		return -1;
	}
	void eliminar(ventamas obj){
		vectorController.erase(vectorController.begin() + obtenerPosicionVector(obj));
	}
	void grabarModificacionenarchivo(){
		fstream archivo;
		archivo.open("productos.csv",ios::out);
		if(archivo.is_open()){
			for(ventamas x:vectorController){
				archivo<<x.getCodigo()<<";"<<x.getNombre()<<";"
					<<x.getPrecio()<<";"<<x.getStock()<<";"<<x.getCodigoCategoria()<<endl;
			}
		}
		else{
				cout<<"Error al grabar modificaciones en el archivo";
		}
		archivo.close();
	}
	bool modificar(ventamas modificacion, ventamas datosNuevos){
		for(int i=0;i<vectorController.size();i++){
			if(modificacion.getCodigo() == vectorController[i].getCodigo()){
				vectorController[i].setnombre(datosNuevos.getNombre());		
				vectorController[i].setprecio(datosNuevos.getPrecio());
				vectorController[i].setStock(datosNuevos.getStock());
				vectorController[i].setcodigoCategoria(datosNuevos.getCodigoCategoria());
				return true;
			}
		}
		return false;
	}
	float ObtenerPrecio(int cod){
		for(int i=0;i<vectorController.size();i++){
			if(cod == vectorController[i].getCodigo()){
				return vectorController[i].getPrecio();
			}
		}
		return -1;
	}
	string ObtenerNombreProducto(int cod){
		for(int i=0;i<vectorController.size();i++){
			if(cod == vectorController[i].getCodigo()){
				return vectorController[i].getNombre();
			}
		}
		return "ERROR";
	}
};

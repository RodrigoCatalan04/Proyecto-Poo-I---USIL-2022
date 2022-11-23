#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "../Models/DetalleVenta.h"
#include "VentasController.h"
#include "ProductoController.h"
#pragma once
using namespace std;

class Detalleventacontroller
{
private:
	
	vector <DetalleVenta> detallecontroller;
	
public:
	Detalleventacontroller(){
		archivo_tovector();
	}
	void add(DetalleVenta v)
	{
		detallecontroller.push_back(v);
	}
	void guardar_archivo(DetalleVenta obj)
	{
		try{
			fstream archivodetalleV;
			archivodetalleV.open("detalleventa.csv",ios::app);
			if(archivodetalleV.is_open())
			{
				archivodetalleV<<obj.getCodVent()<<";"<<obj.getCodProduct()<<";"
					<<obj.getCantida()<<";"<<obj.getPrecioVent()<<endl;
				archivodetalleV.close();					
			}
		}
		catch(exception e){
			cout<<"Ocurrio un error al grabar \n";
		}
	}
	int size()
	{
		return detallecontroller.size();
	}
	DetalleVenta get(int pos)
	{
		return detallecontroller[pos];
	}
	
	DetalleVenta busquedaven(int b)
	{
		DetalleVenta objError;
		objError.setCodVent(0);
		int superior,inferior,mitad;
		inferior =0;
		superior = size();
		mitad = (inferior + superior)/2;
		while(inferior<=superior)
		{
			
			while(inferior<=superior)
			{
				if(get(mitad).getCodVent() == b)
				{
					return detallecontroller[mitad];
					break;
				}
				if(get(mitad).getCodVent() > b)
				{
					superior = mitad - 1;
				}
				if(get(mitad).getCodVent() < b)
				{
					inferior = mitad + 1;
				}
				
				mitad = (inferior + superior)/2;
			}
			return objError;
		}
	}
	DetalleVenta busquedaProduct(int b)
	{
		DetalleVenta objError;
		objError.setCodProduct(0);
		int superior,inferior,mitad;
		inferior =0;
		superior = size();
		mitad = (inferior + superior)/2;
		while(inferior<=superior)
		{
			
			while(inferior<=superior)
			{
				if(get(mitad).getCodProduct() == b)
				{
					return detallecontroller[mitad];
					break;
				}
				if(get(mitad).getCodProduct() > b)
				{
					superior = mitad - 1;
				}
				if(get(mitad).getCodProduct() < b)
				{
					inferior = mitad + 1;
				}
				
				mitad = (inferior + superior)/2;
			}
			return objError;
		}
	}
	void archivo_tovector()
	{
		ifstream archivoDetalleVentas;
		archivoDetalleVentas.open("detalleventa.csv", ios::in);
		string linea;
		char delimitador = ';';
		while(getline(archivoDetalleVentas,linea)){
			stringstream stream(linea);
			string codVenta, codProducto, cantidad,precioVenta;
			getline(stream,codVenta,delimitador);
			getline(stream,codProducto,delimitador);
			getline(stream,cantidad,delimitador);
			getline(stream,precioVenta,delimitador);
			int c = stoi(codProducto);
			int cod=stoi(codVenta);
			int ca= stoi(cantidad);
			float pre = stof(precioVenta);
			
			DetalleVenta Venta(c,cod,ca,pre);
			add(Venta);
		}
	}
	
	void Eliminar(int codigoVenta,int codigoProducto, int cantEliminada){
		for(int i=0;i<size();i++){
			if(codigoVenta == detallecontroller[i].getCodVent() && codigoProducto == detallecontroller[i].getCodProduct()){
				int Cant = detallecontroller[i].getCantida();
				int NuevaCant = Cant - cantEliminada;
				if(NuevaCant == 0){
					detallecontroller.erase(detallecontroller.begin() + i);
				}
				else{
					detallecontroller[i].setCantida(NuevaCant);
				}
			}
		}
	}
	void grabarModificacionenarchivo(){
		fstream archivo;
		archivo.open("detalleventa.csv",ios::out);
		if(archivo.is_open()){
			for(DetalleVenta x:detallecontroller){
				archivo<<x.getCodVent()<<";"<<x.getCodProduct()<<";"
				<<x.getCantida()<<";"<<x.getPrecioVent()<<endl;
			}
		}
		else{
			cout<<"Error al grabar modificaciones en el archivo";
		}
		archivo.close();
	}
	float TotalVenta(int cod){
		float total =0;
		for(int i=0;i<size();i++){
			if(cod == detallecontroller[i].getCodVent()){
				total = total + detallecontroller[i].getPrecioVent();
			}
		}
		return total;
	}
};

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "../Models/Ventas.h"
#pragma once
using namespace std;

class ventasController
{
private:
	
	vector <Venta> Ventas;
	
public:
	ventasController(){
		ArchivotoVector();
	}
	void add(Venta v)
	{
		Ventas.push_back(v);
	}
	int size()
	{
		return Ventas.size();
	}
	Venta get(int pos)
	{
		return Ventas[pos];
	}
	int codigo(){
		if(size() == 0){
			return 1;
		}
		else{
			return 	Ventas[size() - 1].getCodVenta()+1;
		}
	}
	void guardar_archivo(Venta obj){
		try{
			fstream archivoVentas;
			archivoVentas.open("ventas.csv",ios::app);
			if(archivoVentas.is_open())
			{
				archivoVentas<<obj.getCodVenta()<<";"<<obj.getFecVen()<<";"<<obj.getTotVen()
				<<";"<<obj.getEstVen()<<";"<<obj.getCodCli()<<";"<<obj.getCodPersonal()<<endl;
				archivoVentas.close();					
			}
		}
		catch(exception e){
			cout<<"Ocurrio un error al grabar la nueva venta en el archivo\n";
		}
	}
	void ArchivotoVector(){
		ifstream archivoVentas;
		archivoVentas.open("ventas.csv", ios::in);
		string linea;
		char delimitador = ';';
		while(getline(archivoVentas,linea)){
			stringstream stream(linea);
			string codigoV, fecha, total,estado,codigoC,codigoP;
			getline(stream,codigoV,delimitador);
			getline(stream,fecha,delimitador);
			getline(stream,total,delimitador);
			getline(stream,estado,delimitador);
			getline(stream,codigoC,delimitador);
			getline(stream,codigoP,delimitador);
			int codV = stoi(codigoV);
			int f = stoi(fecha);
			float t= stof(total);
			int codC = stoi(codigoC);
			int codP = stoi(codigoP);
			bool b = stoi(estado);
			Venta v(codV,f,t,b,codC,codP);
			add(v);
		}
	}
	Venta busqueda(int c){
		Venta Error;
		Error.setCodVenta(0);
		int superior,inferior,mitad;
		inferior =0;
		superior = size();
		mitad = (inferior + superior)/2;
		while(inferior<=superior)
		{
			if(get(mitad).getCodVenta() == c)
			{
				return Ventas[mitad];
				break;
			}
			if(get(mitad).getCodVenta() > c)
			{
				superior = mitad - 1;
			}
			if(get(mitad).getCodVenta() < c)
			{
				inferior = mitad + 1;
			}
			
			mitad = (inferior + superior)/2;
		}
		return Error;
	};
	void Anular(Venta obj){
		for(int i=0;i<size();i++){
			if(Ventas[i].getCodVenta() == obj.getCodVenta()){
				Ventas[i].CambiarEstado();
			}
		}
	}
	void grabarModificacionenarchivo(){
		fstream archivo;
		archivo.open("ventas.csv",ios::out);
		if(archivo.is_open()){
			for(Venta x:Ventas){
				archivo<<x.getCodVenta()<<";"<<x.getFecVen()<<";"<<x.getTotVen()
				<<";"<<x.getEstVen()<<";"<<x.getCodCli()<<";"<<x.getCodPersonal()<<endl;
			}
		}
		else{
			cout<<"Error al grabar modificaciones en el archivo";
		}
		archivo.close();
	}
	void TotalVenta(int cod, float total){
		for(int i=0;i<size();i++){
			if(cod == Ventas[i].getCodVenta()){
				Ventas[i].setTotVen(total);
			}
		}
	}
	void TotalVentaAlEliminar(int cod, float eliminar){
		for(int i=0;i<size();i++){
			if(cod == Ventas[i].getCodVenta()){
				float a = Ventas[i].getTotVen()-eliminar;
				Ventas[i].setTotVen(a);
			}
		}
	}
};

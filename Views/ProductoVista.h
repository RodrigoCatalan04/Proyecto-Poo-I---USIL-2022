#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "../Controllers/ProductoController.h"
#include "../Controllers/CategoriaController.h"
#pragma once
using namespace std;
//Variable Global
VentaController* ventacontroller = new VentaController();
categoriacontroller* Categoriacontroller = new categoriacontroller();

void productosVista();
void grabarproductos();
void listarproductos();
void busqueda();
void eliminar();
void modificar();
void agregarcategoria();
	
void productosVista(){
	int opcion;
	do{
		cout<<"\n\n\n\n\t\t\t\t\t'PRODUCTOS'\n";
		cout<<"\t\t\t\t\tAGREGAR PRODUCTO..............[1]\n";
		cout<<"\t\t\t\t\tAGREGAR CATEGORIA.............[2]\n";
		cout<<"\t\t\t\t\tLISTAR PRODUCTOS..............[3]\n";
		cout<<"\t\t\t\t\tBUSCAR PRODUCTO...............[4]\n";
		cout<<"\t\t\t\t\tMODIFICAR PRODUCTO............[5]\n";
		cout<<"\t\t\t\t\tELIMINAR PRODUCTO.............[6]\n";
		cout<<"\t\t\t\t\tSALIR AL MENU PRINCIPAL.......[7]\n";
		do{
			cout<<"\t\t\t\t\tElija una opcion[1-6]: ";
			cin>>opcion;
		} while(opcion>7 || opcion<1);
		switch(opcion){
		case 1:system("cls");grabarproductos();break;
		case 2:system("cls");agregarcategoria();break;
		case 3:system("cls");listarproductos(); system("pause");system("cls");break;
		case 4:system("cls");busqueda();break;
		case 5:system("cls");modificar();break;
		case 6:system("cls");eliminar();break;
		case 7:system("cls");break;
		}
	} while(opcion!=7);
}
void grabarproductos(){
	int cod,s,cat;
	string n, flag;
	float p;
	do
	{
		cod= ventacontroller->codigo();
		cout<<"\n\n\n\n\t\t\t\t\t****("<<cod<<")****\n";
		cin.ignore();
		cout<<"\t\t\t\t\tEscribe el nombre del producto: "; 
		getline(cin,n);
		cout<<"\t\t\t\t\tEscribe el precio del producto: "; 
		cin>>p;
		cout<<"\t\t\t\t\tEscriba el stock del producto:";
		cin>>s;
		cout<<"\t\t\t\t\t****CATEGORIA DEL PRODUCTO****\n";
		for(int i=0;i<Categoriacontroller->categoriasize();i++){
			cout<<"\t\t\t\t\t["<<Categoriacontroller->get(i).getCodCategoria()<<"]..."
				<<Categoriacontroller->get(i).getNombreCategoria()<<endl;
		}
		cout<<"\t\t\t\t\tSeleccione la categoria del producto:";
		cin>>cat;
		ventamas venta(cod,n,p,s,cat);
		ventacontroller->add(venta);
		ventacontroller->guardar_archivo(venta);
		cout<<"\t\t\t\t\tContinuar(S/s): "; 
		cin>>flag;
		system("cls");
	}while(flag == "S" || flag == "s");
	system("pause");
	system("cls");
}

void agregarcategoria(){
	string o, nombre;
	int c=Categoriacontroller->codigo();
	cout<<"\n\n\n\n\t\t\t\t\t****CATEGORIAS****\n";
	for(int i=0;i<Categoriacontroller->categoriasize();i++){
		cout<<"\t\t\t\t\t["<<Categoriacontroller->get(i).getCodCategoria()<<"]..."
		<<Categoriacontroller->get(i).getNombreCategoria()<<endl;
	}
	cout<<"\t\t\t\t\tDesea agregar una nueva categoria?[SI/NO]";
	cin>>o;
	if(o == "Si" || o == "si"){
		cout<<"\t\t\t\t\tCodigo: "<<c<<endl;
		cout<<"\t\t\t\t\tIngrese el nombre de la categoria: ";
		cin>>nombre;
		categoria obj(c,nombre);
		Categoriacontroller->add(obj);
		Categoriacontroller->guardar_archivo(obj);
	}
	system("pause");
	system("cls");
}
	
void listarproductos(){
	cout<<"\n\n\n\n\t\t\t\t\t*****LISTADO DE PRODUCTOS*****\n";
	cout<<"\t\t\t\t\t---------------------------------------------\n";
	cout<<"\t\t\t\t\tCodigo";
	cout<<"\tProducto";
	cout<<"\tPrecio";
	cout<<"\tStock";
	cout<<"\tCategoria\n";
	for(int i = 0;i<ventacontroller->size(); i++){
		int nombre = ventacontroller->get(i).getNombre().length();
		
		cout<<"\t\t\t\t\t"<<ventacontroller->get(i).getCodigo()<<"\t";
		cout<<ventacontroller->get(i).getNombre();
		if(nombre<15){
			int p = 15 - nombre;
			for(int i=0;i<p;i++){
				cout<<" ";
			}
		} cout<<"\t";
		cout<<ventacontroller->get(i).getPrecio()<<"\t";
		cout<<ventacontroller->get(i).getStock()<<"\t";
		cout<<Categoriacontroller->getCategoria(ventacontroller->get(i).getCodigoCategoria())<<endl;
	}
	cout<<"\t\t\t\t\t---------------------------------------------\n";
}

void busqueda(){
	int cod;
	cout<<"\n\n\n\n\t\t\t\t\tIngrese el codigo del producto a buscar:";
	cin>>cod;
	ventamas objproduct = ventacontroller->busqueda(cod);	
	if(objproduct.getNombre()!="Error"){
		cout<<"\t\t\t\t\tCodigo:"<<objproduct.getCodigo()<<endl;
		cout<<"\t\t\t\t\tProducto:"<<objproduct.getNombre()<<endl;
		cout<<"\t\t\t\t\tPrecio:"<<objproduct.getPrecio()<<endl;
		cout<<"\t\t\t\t\tStock:"<<objproduct.getStock()<<endl;
		cout<<"\t\t\t\t\tCategoria:"<<Categoriacontroller->getCategoria(objproduct.getCodigoCategoria())<<endl;
	}
	else{
		cout<<"\t\t\t\t\tNo se encontro el producto\n";		
	}
	system("pause");
	system("cls");
}

void modificar(){
	int cod;
	cout<<"\n\n\n\n\t\t\t\t\tIngrese el codigo del producto a modificar:";
	cin>>cod;
	ventamas objAModificar = ventacontroller->busqueda(cod);
	if(objAModificar.getNombre() != "Error")
	{
		string a;
		cout<<"\t\t\t\t\tCodigo:"<<objAModificar.getCodigo()<<endl;
		cout<<"\t\t\t\t\tNombre:"<<objAModificar.getNombre()<<endl;
		cout<<"\t\t\t\t\tPrecio:"<<objAModificar.getPrecio()<<endl;
		cout<<"\t\t\t\t\tStock:"<<objAModificar.getStock()<<endl;
		cout<<"\t\t\t\t\tCategoria:"<<Categoriacontroller->getCategoria(objAModificar.getCodigoCategoria())<<endl;	
		cout<<"\t\t\t\t\tSeguro desea modificar este producto?[Si/No]: ";
		cin>>a;
		if(a == "Si" || a == "si"){
			cin.ignore();
			string nombre;
			int stock, cat;
			float precio;
			cout<<"\t\t\t\t\tModificar Nombre:";
			getline(cin,nombre);
			cout<<"\t\t\t\t\tModificar Precio:";
			cin>>precio;
			cout<<"\t\t\t\t\tModificar Stock:";
			cin>>stock;
			cout<<"\t\t\t\t\t****CATEGORIA DEL PRODUCTO****";
			for(int i=0;i<Categoriacontroller->categoriasize();i++){
				cout<<"\t\t\t\t\t["<<Categoriacontroller->get(i).getCodCategoria()<<"]..."
					<<Categoriacontroller->get(i).getNombreCategoria()<<endl;
			}
			cout<<"\t\t\t\t\tSeleccione la categoria del producto:";
			cin>>cat;
			ventamas objNuevosDatos(objAModificar.getCodigo(),nombre,precio,stock,cat);
			bool modificacion = ventacontroller->modificar(objAModificar,objNuevosDatos);
			if(modificacion = true)
			{
				cout<<"\t\t\t\t\tProducto modificado satisfactoriamente\n";
				ventacontroller->grabarModificacionenarchivo();
			}
			else
			{
				cout<<"\t\t\t\t\tNo se pudo modifico el registro\n";				
			}
		}
	}
	else{
		cout<<"\t\t\t\t\tNo se encontro el codigo del producto a modificar";			
	}
	system("pause");
	system("cls");	
}
	
void eliminar(){
	int c;
	cout<<"\n\n\n\n\t\t\t\t\tIngrese el codigo del producto a eliminar:";
	cin>>c;
	ventamas objAEliminar = ventacontroller->busqueda(c);
	if(objAEliminar.getNombre()!="Error")
	{
		string answer;
		cout<<"\t\t\t\t\tSeguro que desea eliminar este producto?\n";
		cout<<"\t\t\t\t\tProducto:"<<objAEliminar.getNombre()<<endl;
		cout<<"\t\t\t\t\tPrecio:"<<objAEliminar.getPrecio()<<endl;
		cout<<"\t\t\t\t\tStock:"<<objAEliminar.getStock()<<endl;
		cout<<"\t\t\t\t\tCategoria:"<<Categoriacontroller->getCategoria(objAEliminar.getCodigoCategoria())<<endl;
		cout<<"\t\t\t\t\t[Si/No]: ";
		cin>>answer;
		if(answer == "Si" || answer == "si"){
			ventacontroller->eliminar(objAEliminar);
			cout<<"\t\t\t\t\tProducto eliminado satisfactoriamente\n";
			ventacontroller->grabarModificacionenarchivo();
		}
	}
	else
	{
		cout<<"\t\t\t\t\tNo se encontro el codigo del producto a eliminar\n";		
	}
	system("pause");
	system("cls");
}

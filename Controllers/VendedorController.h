#include <iostream>
#include <vector>
#include<fstream>
#include "../Models/Vendedor.h"

using namespace std;

#ifndef VENTAMAS1_0_VENDEDORCONTROLLER_H
#define VENTAMAS1_0_VENDEDORCONTROLLER_H

class Registro {
private:
	vector <Vendedor> V;
public:
	Registro() {
		Datos();
	}
	
	void add(Vendedor obj) {
		V.push_back(obj);
	}
	
	Vendedor get(int pos) {
		return V[pos];
	}
	
	int size() {
		return V.size();
	}
	
	int getCorrelativo() {
		if (size() == 0) {
			return 1;
		} else {
			return V[size() - 1].getCodigo() + 1;
		}
	}
	
	Vendedor buscarPorCodigo(int codigo) {//ingresará elcodigo porbuscar
		Vendedor E;//lo creamos
		E.setNomApe("Error");//si nohaynombre de nada manda un error
		int s, i, m;//superior,inferior,medio
		i = 0;
		s = size();//superior loigualamos con el numero de elementos(tamaño) que tiene nuestro arreglo
		m = (i + s) / 2;//va a ser el inferior mas el superior entre 2
		while (i <= s)//vemos si lo podemos encontrar con un condicional
		{
			if (get(m).getCodigo() ==
				codigo)//la m o mitad es laposicion en la que hagamos el arreglo. si el numerode la posicion esigualal codigo
			{
				return V[m];//retornaelvalor de mivetor V en dicha posicion
				break;//para que no siga buscando
			}
			if (get(m).getCodigo() > codigo) {
				s = m - 1;
			}
			if (get(m).getCodigo() < codigo) {
				i = m + 1;
			}
			
			m = (i + s) / 2;
		}
		return E;//cuando encuentra lo retorna,sino retorna el error que creamos a proposito
		
	};
	
	bool isEmpty(){
		return V.empty();
	}
		
		bool modificar(Vendedor obj1, string nomApe, int codT, Usuario usuario) {
			for (int i = 0; i < V.size(); i++) {
				if (obj1.getCodigo() == V[i].getCodigo()) {
					V[i].setNomApe(nomApe);
					V[i].setCodT(codT);
					V[i].setUsuario(usuario);
					return true;
				}
			}
			return false;
		}
		
		bool modificar2(Vendedor obj1, Vendedor DatosModificados, Usuario usuario) {
			for (int i = 0; i < V.size(); i++) {
				if (obj1.getCodigo() == V[i].getCodigo()) {
					V[i].setNomApe(DatosModificados.getNomApe());
					V[i].setCodT(DatosModificados.getCodT());
					V[i].setUsuario(usuario);
					return true;
				}
			}
			return false;
		}
		
		int getPostArray(Vendedor obj) {
			for (int i = 0; i < V.size(); i++) {
				if (obj.getCodigo() == V[i].getCodigo()) {
					return i;
				}
			}
			return -1;
		}
		
		void eliminar(Vendedor obj) {
			V.erase(V.begin() + getPostArray(obj));
		}
		
		void grabarEnArchivo(Vendedor obj) {
			try {
				fstream archivo;
				archivo.open("Vendedores.csv", ios::app);
				if (archivo.is_open()) {
					archivo << obj.getCodigo() << ";" << obj.getNomApe() << ";" << obj.getCodT() << ";"
						<< "Usuario" << obj.getCodigo() << ";" << endl;
					archivo.close();
				}
				Usuario usuario = obj.getUsuario();
				ofstream out("Usuario" + to_string(obj.getCodigo()) , ios::binary | ios::out );
				out.write((char*) (&usuario),sizeof(usuario));
				out.close();
			}
			catch (exception e) {
				cout << "Ocurrio un error al grabar el archivo";
			}
		}
		
		void grabarModificarEnArchivo() {
			try {
				fstream archivo;
				archivo.open("Vendedores.csv", ios::out);
				if (archivo.is_open()) {
					for (Vendedor x: V) {
						archivo << x.getCodigo() << ";" << x.getNomApe() << ";" << x.getCodT() << ";"
							<< "Usuario" << x.getCodigo() << ";" << endl;
						string file = "Usuario" + to_string(x.getCodigo()) + ".bin";
						remove(file.c_str());
						Usuario usuario = x.getUsuario();
						ofstream out("Usuario" + to_string(x.getCodigo()) + ".bin", ios::binary | ios::out );
						out.write((char*) (&usuario),sizeof(usuario));
						out.close();
					}
					archivo.close();
				}
				
			}
			catch (exception e) {
				cout << "Ocurrio un error al grabar el archivo";
			}
		}
		
		void Datos() {
			try {
				int i;
				size_t posi;
				string linea;
				string temporal[4];
				fstream archivo;
				archivo.open("Vendedores.csv", ios::in);
				if (archivo.is_open()) {
					while (!archivo.eof() && getline(archivo, linea)) {
						i = 0;
						while ((posi = linea.find(";")) != string::npos) {
							temporal[i] = linea.substr(0, posi);
							linea.erase(0, posi + 1);
							++i;
						}
						
						Usuario usuario;
						ifstream in(temporal[3],ios::binary | ios::in);
						in.read((char*) (&usuario), sizeof(usuario));
						in.close();
						
						
						Vendedor ven(stoi(temporal[0]), temporal[1],
									 stoi(temporal[2]), usuario);
						
						add(ven);
					}
				}
			}
			catch (exception e) {
				cout << "Ocurrio un error al grabar el archivo";
			}
		}
};

#endif //VENTAMAS1_0_VENDEDORCONTROLLER_H

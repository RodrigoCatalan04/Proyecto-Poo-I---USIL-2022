//
// Created by jalb2 on 1/11/2022.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "../Models/Cliente.h"
#pragma once
using namespace std;

class ClienteController {
private:
    vector<Cliente> C;
public:
    ClienteController() {
        Datos();
    }

    void add(Cliente obj) {
        C.push_back(obj);
    }

    Cliente get(int pos) {
        return C[pos];
    }

    int size() {
        return C.size();
    }

    int getCorrelativo() {
        if (size() == 0) {
            return 1;
        } else {
            return C[size() - 1].getCodigo() + 1;
        }
    }
	Cliente buscarPorCodigo(int codigo) {
		Cliente E;
		E.setNomApe("Error");
		int superior,inferior,mitad;
		inferior =0;
		superior = size();
		mitad = (inferior + superior)/2;
		while(inferior<=superior)
		{
			if(get(mitad).getCodigo() == codigo)
			{
				return C[mitad];
				break;
			}
			if(get(mitad).getCodigo() > codigo)
			{
				superior = mitad - 1;
			}
			if(get(mitad).getCodigo() < codigo)
			{
				inferior = mitad + 1;
			}
			
			mitad = (inferior + superior)/2;
		}
		return E;
	}

    bool modificar(Cliente obj1, string nomApe,string dir, long long int Ruc) {
        for (int i = 0; i < C.size(); i++) {
            if (obj1.getCodigo() == C[i].getCodigo()) {
                C[i].setNomApe(nomApe);
				C[i].setDir(dir);
                C[i].setRuc(Ruc);

                return true;
            }
        }
        return false;
    }

    bool modificar2(Cliente obj1, Cliente DatosModificados) {
        for (int i = 0; i < C.size(); i++) {
            if (obj1.getCodigo() == C[i].getCodigo()) {
                C[i].setNomApe(DatosModificados.getNomApe());
				C[i].setDir(DatosModificados.getDir());
                C[i].setRuc(DatosModificados.getRuc());

                return true;
            }
        }
        return false;
    }

    int getPostArray(Cliente obj) {
        for (int i = 0; i < C.size(); i++) {
            if (obj.getCodigo() == C[i].getCodigo()) {
                return i;
            }
        }
        return -1;
    }

    void eliminar(Cliente obj) {
        C.erase(C.begin() + getPostArray(obj));
    }

    void grabarEnArchivo(Cliente obj) {
        try {
            fstream archivoAlumno;
            archivoAlumno.open("Clientes.csv", ios::app);
            if (archivoAlumno.is_open()) {
				archivoAlumno<<obj.getCodigo()<<";"<<obj.getNomApe()<<";"<<obj.getDir()<<";"<<obj.getRuc()<<endl;
                archivoAlumno.close();
            }
        }
        catch (exception e) {
            cout << "Ocurrio un error al grabar el archivo de clientes";
        }
    }

    void grabarModificarEnArchivo() {
        try {
            fstream archivoAlumno;
            archivoAlumno.open("Clientes.csv", ios::out);
            if (archivoAlumno.is_open()) {
                for (Cliente x: C) {
                    archivoAlumno << x.getCodigo() << ";" << x.getNomApe() << ";"<<x.getDir()<<";"<< x.getRuc() << endl;
                    archivoAlumno.close();
                }
            }
        }
        catch (exception e) {
            cout << "Ocurrio un error al modificar el archivo de clientes";
            system("PAUSE");
        }
    }

	void Datos() {
		try {
			string linea;
			fstream archivoClientes;
			archivoClientes.open("Clientes.csv", ios::in);
			while (getline(archivoClientes, linea)) {
				stringstream stream(linea);
				string codigo, nombre,dir, ruc;
				getline(stream, codigo, ';');
				getline(stream, nombre, ';');
				getline(stream, dir, ';');
				getline(stream, ruc, ';');
				Cliente cliente(stoi(codigo), nombre,dir, stoll(ruc));
				add(cliente);
			}
		}
		catch (exception e) {
			cout << "Ocurrio un error al acceder al archivo de clientes";
		}
	}	
};

ClienteController clienteController;

void grabarCliente() {
    int numero;
    int cod;
    long long int ruc;
    string nApe,dir;
    cout << "Ingresar numero de clientes a registrar: ";
    cin >> numero;
    for (int i = 0; i < numero; i++) {
        cod = clienteController.getCorrelativo();
        cout << "******(" << cod << ")*******\n";
        cin.ignore();
        cout << "Nombres y Apellidos:";
        getline(cin, nApe);
		cout << "Direccion:";
		getline(cin, dir);
        cout << "Ruc:";
        cin >> ruc;
        Cliente A(cod, nApe,dir, ruc);
        clienteController.add(A);
        clienteController.grabarEnArchivo(A);
        system("cls");
    }
}

void buscarCliente() {
    int cod;
    cout << "Ingrese el codigo a buscar:";
    cin >> cod;

    Cliente A = clienteController.buscarPorCodigo(cod);
    if (A.getNomApe() != "Error") {
        cout << "Codigo:" << A.getCodigo() << endl;
        cout << "Nombre y Apellidos:" << A.getNomApe() << endl;
		cout << "Direccion:" << A.getDir() << endl;
        cout << "Ruc:" << A.getRuc() << endl;
    } else {
        cout << "No se encontro el codigo a buscar\n";
    }
    system("pause");
    system("cls");
}

void modificarCliente() {
    int cod;
    cout << "Ingrese el codigo a buscar:";
    cin >> cod;
    Cliente objVM = clienteController.buscarPorCodigo(cod);
    if (objVM.getNomApe() != "Error") {
        cout << "Codigo:" << objVM.getCodigo() << endl;
        cout << "Nombre y Apellidos:" << objVM.getNomApe() << endl;
		cout << "Direccion:" << objVM.getDir() << endl;
        cout << "Ruc:" << objVM.getRuc() << endl;
        cin.ignore();

        string nomApe,dir;
        long long int ruc;
        cout << "Modificar Nombres y Apellidos:";
        getline(cin, nomApe);
		cout << "Modificar Direccion:";
		getline(cin, dir);
        cout << "Modificar Ruc:";
        cin >> ruc;
        Cliente N(objVM.getCodigo(),
                  nomApe,
				  dir,
                  ruc);
        bool estadoModificado = clienteController.modificar2(objVM, N);
        if (estadoModificado = true) {
            cout << "Registro modificado satisfactoriamente\n";
            clienteController.grabarModificarEnArchivo();
        } else {
            cout << "No se modifico el registro\n";
        }
    } else {
        cout << "No se encontro el codigo a buscar";
    }
    system("pause");
    system("cls");
}

void eliminarCliente() {
    int cod;
    cout << "Ingrese el codigo a buscar:";
    cin >> cod;
    Cliente objVE = clienteController.buscarPorCodigo(cod);
    if (objVE.getNomApe() != "Error") {
        clienteController.eliminar(objVE);
        cout << "Registro eliminado satisfactoriamente\n";
        clienteController.grabarModificarEnArchivo();
    } else {
        cout << "No se encontro el codigo a buscar\n";
    }
    system("pause");
    system("cls");

}

void listarCliente() {
	cout<<"__________REPORTE GENERAL__________"<<endl;
	cout<<"CODIGO\tNOMBRES\t\tDireccion\t\tRUC\n";
    for (int i = 0; i < clienteController.size(); i++) {
        cout << clienteController.get(i).getCodigo() << "\t" << clienteController.get(i).getNomApe() << "\t"
			<< clienteController.get(i).getDir() << "\t"
             << clienteController.get(i).getRuc() << "\t" << endl;
    }

    system("pause");
    system("cls");
}

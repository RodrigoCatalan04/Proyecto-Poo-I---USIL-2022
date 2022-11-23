#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

#include "../Controllers/VendedorController.h"
#include "../Controllers/TipoVendedoresController.h"

using namespace std;

#ifndef VENTAMAS1_0_VENDEDORVISTA_H
#define VENTAMAS1_0_VENDEDORVISTA_H

Registro *regis = new Registro();
tipocontroller *Tipocontroller = new tipocontroller;

void addRegistro();

void listar();

void buscar();

void modificarVendedor();

void eliminarVendedor();

void tipovendedor();

void vendedorVista() {
	int x;
	do {
		cout << "\t\t..:MENU DE OPCIONES:.. " << endl;
		cout << "\t1. Agregar vendedor" << endl;
		cout << "\t2. Agregar tipo de vendedor" << endl;
		cout << "\t3. Buscar vendedor" << endl;
		cout << "\t4. Modificar vendedor" << endl;
		cout << "\t5. Eliminar vendedor" << endl;
		cout << "\t6. Listar vendedor" << endl;
		cout << "\t7. Salir" << endl;
		cout << endl << "\tOPCION: ";
		cin >> x;
		switch (x) {
		case 1:
			system("cls");
			addRegistro();
			break;
		case 2:
			system("cls");
			tipovendedor();
			break;
		case 3:
			system("cls");
			buscar();
			break;
		case 4:
			system("cls");
			modificarVendedor();
			break;
		case 5:
			system("cls");
			eliminarVendedor();
			break;
		case 6:
			system("cls");
			listar();
			break;
		case 7:
			system("cls");
			break;
		default:
			system("cls");
			cout << "Ingresa una opción correcta\n";
		}
	} while (x != 7);
}

void addRegistro() {
	int numero;
	int cod;
	string nApe;
	int codT;
	string res;
	Usuario usuario;
	do {
		cout << "Ingresar numero de vendedores a registrar: ";
		cin >> numero;
		for (int i = 0; i < numero; i++) {
			cod = regis->getCorrelativo();
			cout << "~~~~~~(CODIGO" << cod << ")~~~~~~\n";
			cin.ignore();
			cout << "Nombres y Apellidos:";
			getline(cin, nApe);
			cout << "****TIPO DE VENDEDOR****\n";
			for (int i = 0; i < Tipocontroller->size(); i++) {
				cout << "[" << Tipocontroller->get(i).getCodT() << "]..."
					<< Tipocontroller->get(i).getNomT() << endl;
			}
			cout << "Seleccione el tipo de vendedor:";
			cin >> codT;
			cout << "Ingrese su contrasena: ";
			cin >> usuario.pass;
			Vendedor A(cod, nApe, codT, usuario);
			regis->add(A);
			regis->grabarEnArchivo(A);
			system("cls");
		}
		cout << "¿Desea agregar a alguien mas? [si/no]: ";
		cin >> res;
	} while (res == "SI" || res == "si" || res == "Si");
	system("pause");
	system("cls");
}

void tipovendedor() {
	string o, nombre;
	int c = Tipocontroller->codigo();
	cout << "\n\n\n\n\t\t\t\t\t****TIPOS DE VENDEDOR****\n";
	for (int i = 0; i < Tipocontroller->size(); i++) {
		cout << "\t\t\t\t\t[" << Tipocontroller->get(i).getCodT() << "]..."
			<< Tipocontroller->get(i).getNomT() << endl;
	}
	cout << "\t\t\t\t\tDesea agregar un nuevo tipo de vendedor?[SI/NO]";
	cin >> o;
	if (o == "SI" || o == "Si" || o == "si") {
		cout << "\t\t\t\t\tCodigo: " << c << endl;
		cout << "\t\t\t\t\tIngrese el tipo de vendedor: ";
		getline(cin,nombre);
		cin.ignore();
		tipo obj(c, nombre);
		Tipocontroller->add(obj);
		Tipocontroller->guardar_archivo(obj);
	}
	system("pause");
	system("cls");
}

void buscar() {
	int cod;
	cout << "Ingrese el codigo a buscar:";
	cin >> cod;
	
	Vendedor A = regis->buscarPorCodigo(cod);
	if (A.getNomApe() != "Error") {
		cout << "Codigo:" << A.getCodigo() << endl;
		cout << "Nombre y Apellidos:" << A.getNomApe() << endl;
		cout << "Tipo:" << Tipocontroller->getC(A.getCodT()) << endl;
	} else {
		cout << "No se encontro el codigo a buscar\n";
	}
	system("pause");
	system("cls");
}

void modificarVendedor() {
	int cod;
	cout << "Ingrese el codigo a buscar:";
	cin >> cod;
	Vendedor objVM = regis->buscarPorCodigo(cod);
	if (objVM.getNomApe() != "Error") {
		cout << "Codigo:" << objVM.getCodigo() << endl;
		cout << "Nombre y Apellidos:" << objVM.getNomApe() << endl;
		cout << "Codigo Vendedor:" << objVM.getCodT() << endl;
		cout << "Tipo de vendedor:" << Tipocontroller->getC(objVM.getCodT()) << endl;
		cin.ignore();
		
		string nomApe;
		Usuario usuario;
		int codT;
		cout << "Modificar Nombres y Apellidos:";
		getline(cin, nomApe);
		cout << "****Tipo de vendedor****";
		for (int i = 0; i < Tipocontroller->size(); i++) {
			cout << "\t\t\t\t\t[" << Tipocontroller->get(i).getCodT() << "]..."
				<< Tipocontroller->get(i).getNomT() << endl;
		}
		cout << "\t\t\t\t\tSeleccione el tipo de vendedor:";
		cin >> codT;
		cout << "Ingrese una nueva contrasena: ";
		cin >> usuario.pass;
		Vendedor N(objVM.getCodigo(), nomApe, codT, usuario);
		bool estadoModificado = regis->modificar2(objVM, N, usuario);
		if (estadoModificado = true) {
			cout << "Registro modificado satisfactoriamente\n";
			regis->grabarModificarEnArchivo();
		} else {
			cout << "No se modifico el registro\n";
		}
	} else {
		cout << "No se encontro el codigo a buscar";
	}
	system("pause");
	system("cls");
}

void eliminarVendedor() {
	int cod;
	cout << "Ingrese el codigo a buscar:";
	cin >> cod;
	string file = "Usuario" + to_string(cod) + ".bin";
	
	Vendedor objVE = regis->buscarPorCodigo(cod);
	if (objVE.getNomApe() != "Error") {
		remove(file.c_str());
		regis->eliminar(objVE);
		cout << "Registro eliminado satisfactoriamente\n";
		regis->grabarModificarEnArchivo();
	} else {
		cout << "No se encontro el codigo a buscar\n";
	}
	system("pause");
	system("cls");
	
}

void listar() {
	cout << "\t\t\t\t\t..:LISTADO DE VENDEDORES:..\n" << endl;
	cout << "\t\tVENDEDORES" << "\t\t\t\t\t\t TIPO" << endl;
	for (int i = 0; i < regis->size(); i++) {
		cout << "\t\t" << regis->get(i).getCodigo() << ". " << regis->get(i).getNomApe() << "\t\t\t\t "
			<< Tipocontroller->getC(regis->get(i).getCodT()) << endl;
	}
	
	system("pause");
	system("cls");
}

#endif //VENTAMAS1_0_VENDEDORVISTA_H

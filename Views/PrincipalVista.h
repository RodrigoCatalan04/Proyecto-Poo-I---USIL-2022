#include <iostream>
#include "ProductoVista.h"
#include "ClienteVista.h"
#include "VendedorVista.h"
#include "VentasVista.h"
using namespace std;

void principalVista() {
	int opcion;
	do{
        system("CLS");
        cout << "\n\n\n\n\t\t\t\t\tSISTEMA DE VENTA 'VENTAMAS'\n";
        cout << "\t\t\t\t\tREGISTRO DE CLIENTES.....[1]\n";
        cout << "\t\t\t\t\tREGISTRO DE PRODUCTOS....[2]\n";
        cout << "\t\t\t\t\tREGISTRO DE VENDEDORES...[3]\n";
        cout << "\t\t\t\t\tVENTAS...................[4]\n";
        cout << "\t\t\t\t\tSALIR....................[5]\n";
        do {
            cout << "\t\t\t\t\tElija una opcion[1-5]: ";
            cin >> opcion;
        } while (opcion > 5 || opcion < 1);
        switch (opcion) {
            case 1:
                system("cls");
                clienteVista();
                break;
            case 2:
                system("cls");
                productosVista();
                break;
            case 3:
				system("cls");
                vendedorVista();
                break;
            case 4:
                system("cls");
				VentasVista();
                break;
            case 5:
                system("cls");
                cout << "\n\n\n\n\n\n\t\t\t\t\t\tSaliendo del programa...";
                break;
        }
    } while (opcion != 5);
}

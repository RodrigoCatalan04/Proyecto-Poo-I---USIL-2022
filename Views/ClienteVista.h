//
// Created by jalb2 on 1/11/2022.
//
#include "../Controllers/ClienteController.h"


#ifndef VENTAMAS1_0_CLIENTEVISTA_H
#define VENTAMAS1_0_CLIENTEVISTA_H

void clienteVista() {
    int x;
    do {
        system("CLS");
        cout << "**********MENU CLIENTES***********" << endl;
        cout << "\t1. Agregar Cliente" << endl;
        cout << "\t2. Buscar Cliente" << endl;
        cout << "\t3. Modificar Cliente" << endl;
        cout << "\t4. Eliminar Cliente" << endl;
        cout << "\t5. Listar Cliente" << endl;
        cout << "\t6. Salir" << endl;
        cout << "\t Opcion[ ]\b\b";
        cin >> x;
        switch (x) {
            case 1:
                system("cls");
                grabarCliente();
                break;
            case 2:
                system("cls");
                buscarCliente();
                break;
            case 3:
                system("cls");
                modificarCliente();
                break;
            case 4:
                system("cls");
                eliminarCliente();
                break;
            case 5:
                system("cls");
                listarCliente();
                break;
            case 6:
                system("cls");
                cout << "Gracias por usar nuestro programa\n";
                break;
            default:
                system("cls");
                cout <<"Ingresa una opcion correcta[1-6]\n";
        }
    } while (x != 6);
}

#endif //VENTAMAS1_0_CLIENTEVISTA_H

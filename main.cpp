#include <iostream>
#include "Views/PrincipalVista.h"

using namespace std;

void acceso(){
    while(1){
        system("cls");
        int cod;
        string pass;

        cout << "Ingrese el codigo del vendedor para ingresar al Sistema: ";
        cin >> cod;
        cout << "Ingrese la contrasena: ";
        cin >> pass;

        Vendedor vendedor = regis->buscarPorCodigo(cod);

        if(vendedor.getNomApe() == "Error"){
            cout << "Vendedor No Encontrado" << endl;
            system("PAUSE");
            exit(0);
        } else if(vendedor.getCodigo() == cod && vendedor.getUsuario().pass == pass){
            cout << "Acceso Concedido\n";
            system("PAUSE");
            principalVista();
        } else{
            cout << "Vendedor No Encontrado" << endl;
            system("PAUSE");
        }
    }
}

int main() {
    if(regis->isEmpty() && Tipocontroller->isEmpty()){
        tipovendedor();
        addRegistro();
    } else if(regis->isEmpty()){
        addRegistro();
    } else{
        acceso();
    }
}

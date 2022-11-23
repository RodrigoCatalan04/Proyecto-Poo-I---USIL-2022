#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "../Controllers/VentasController.h"
#include "../Controllers/Detalleventacontroller.h"
#include "ClienteVista.h"
#include "VendedorVista.h"
#include "ProductoVista.h"
using namespace std;
ventasController* ventas = new ventasController();
Detalleventacontroller* detallesV = new Detalleventacontroller();
void agregarventa();
void anularventa();
void listarventas();
void buscarventas();
void modificarventas();
void AgregarAVenta();
void EliminardeVenta();

void VentasVista(){
	int opcion;
	do{
		cout<<"\n\n\n\n\t\t\t\t\t'VENTAS'\n";
		cout<<"\t\t\t\t\tAGREGAR VENTA..............[1]\n";
		cout<<"\t\t\t\t\tANULAR VENTA...............[2]\n";
		cout<<"\t\t\t\t\tLISTAR VENTAS..............[3]\n";
		cout<<"\t\t\t\t\tBUSCAR VENTA...............[4]\n";
		cout<<"\t\t\t\t\tMODIFICAR VENTAS...........[5]\n";
		cout<<"\t\t\t\t\tSALIR AL MENU PRINCIPAL....[6]\n";
		do{
			cout<<"\t\t\t\t\tElija una opcion[1-6]: ";
			cin>>opcion;
		} while(opcion>6 || opcion<1);
		switch(opcion){
		case 1:system("cls");agregarventa();break;
		case 2:system("cls");anularventa();break;
		case 3:system("cls");listarventas();break;
		case 4:system("cls");buscarventas();break;
		case 5:system("cls");modificarventas();break;
		case 6:system("cls");break;
		}
	} while(opcion!=6);
	
}

void agregarventa(){
	int cod,f,cli,ven;
	string flag;
	do
	{
		cod= ventas->codigo();
		cout<<"\n\n\n\n\t\t\t\t\t****("<<cod<<")****\n";
		cin.ignore();
		cout<<"\t\t\t\t\tEscribe la fecha de la venta de esta manera,(01/02/2022)->01022022: "; 
		cin>>f;
		cout<<"\t\t\t\t\t****CLIENTES****\n";
		for(int i=0;i<clienteController.size();i++){
			cout<<"\t\t\t\t\t["<<clienteController.get(i).getCodigo()<<"]..." 
				<<clienteController.get(i).getNomApe()<<endl;
		}
		cout<<"\t\t\t\t\tSeleccione por su codigo, el cliente de esta venta:";
		cin>>cli;
		cout<<"\t\t\t\t\t****VENDEDORES****\n";
		for(int i=0;i<regis->size();i++){
			cout<<"\t\t\t\t\t["<<regis->get(i).getCodigo()<<"]..." 
				<<regis->get(i).getNomApe()<<endl;
		}
		cout<<"\t\t\t\t\tSeleccione el codigo del vendedor que realizo esta venta:";
		cin>>ven;
		Venta v(cod,f,0,true,cli,ven);
		ventas->add(v);
		ventas->guardar_archivo(v);
		cout<<"\t\t\t\t\tContinuar(S/s): "; 
		cin>>flag;
		system("cls");
	}while(flag == "S" || flag == "s");
	system("pause");
	system("cls");
}
	
void anularventa(){
	int cod;
	string answer;
	cout<<"\n\n\n\n\t\t\t\t\tIngrese el codigo de la venta a anular: ";
	cin>>cod;
	Venta objAnulado = ventas->busqueda(cod);
	Cliente c= clienteController.buscarPorCodigo(objAnulado.getCodCli());
	Vendedor v= regis->buscarPorCodigo(objAnulado.getCodPersonal());
	cout<<"\t\t\t\t\tCodigo de la venta:"<<objAnulado.getCodVenta()<<endl;
	cout<<"\t\t\t\t\tFecha de la venta:";objAnulado.Fecha();
	cout<<"\t\t\t\t\tTotal de la venta:"<<objAnulado.getTotVen()<<endl;
	cout<<"\t\t\t\t\tEstado de la Venta:"<<objAnulado.estado()<<endl;
	cout<<"\t\t\t\t\tCliente:"<<c.getNomApe()<<endl;
	cout<<"\t\t\t\t\tVendedor:"<<v.getNomApe()<<endl;
	cout<<"\t\t\t\t\tSeguro desea anular esta venta?[Si/No]:";
	cin>>answer;
	if(answer == "Si" || answer == "si"){
		ventas->Anular(objAnulado);
		ventas->grabarModificacionenarchivo();
		cout<<"\t\t\t\t\tVenta anulada satisfactoriamente...\n";
	}
	system("pause");
	system("cls");
}

void listarventas(){
	cout<<"\n\n\n\n\t\t\t\t\t*****LISTADO DE VENTAS*****\n";
	cout<<"\t\t\t\t\t---------------------------------------------\n";
	for(int i=0;i<ventas->size();i++){
		if(ventas->get(i).getEstVen() == true){
			Cliente c= clienteController.buscarPorCodigo(ventas->get(i).getCodCli());
			Vendedor v= regis->buscarPorCodigo(ventas->get(i).getCodPersonal());
			cout<<"\t\t\t\t\t*****VENTA("<<ventas->get(i).getCodVenta()<<")*****:\n";
			cout<<"\t\t\t\t\tFecha de la venta:";ventas->get(i).Fecha();
			cout<<"\t\t\t\t\tTotal de la venta:"<<ventas->get(i).getTotVen()<<endl;
			cout<<"\t\t\t\t\tCliente:"<<c.getNomApe()<<endl;
			cout<<"\t\t\t\t\tVendedor:"<<v.getNomApe()<<endl;
			cout<<"\t\t\t\t\t*****PRODUCTOS DE VENTA("<<ventas->get(i).getCodVenta()<<")*****:\n";
			for(int j = 0;j<detallesV->size();j++){
				if(ventas->get(i).getCodVenta() == detallesV->get(j).getCodVent()){
					ventamas cate = ventacontroller->busqueda(detallesV->get(j).getCodProduct());
					cout<<"\t\t\t\t\tProducto:"<<ventacontroller->ObtenerNombreProducto(detallesV->get(j).getCodProduct());
					cout<<"-"<<Categoriacontroller->getCategoria(cate.getCodigoCategoria());
					cout<<"\n\t\t\t\t\tCantidad:"<<detallesV->get(j).getCantida()<<endl;
				}
			}
			cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		}
	
	}
	cout<<"\t\t\t\t\t---------------------------------------------\n";
	system("pause");	
	system("cls");	
}

void buscarventas(){
	int cod;
	cout<<"\n\n\n\n\t\t\t\t\tIngrese el codigo de la venta a buscar: ";
	cin>>cod;
	Venta objproduct = ventas->busqueda(cod);
	Cliente c= clienteController.buscarPorCodigo(objproduct.getCodCli());
	Vendedor v= regis->buscarPorCodigo(objproduct.getCodPersonal());
	if(objproduct.getCodVenta() != 0){
		cout<<"\t\t\t\t\tCodigo de la venta:"<<objproduct.getCodVenta()<<endl;
		cout<<"\t\t\t\t\tFecha de la venta:";objproduct.Fecha();
		cout<<"\t\t\t\t\tTotal de la venta:"<<objproduct.getTotVen()<<endl;
		cout<<"\t\t\t\t\tEstado de la Venta:"<<objproduct.estado()<<endl;
		cout<<"\t\t\t\t\tCliente:"<<c.getNomApe()<<endl;
		cout<<"\t\t\t\t\tVendedor:"<<v.getNomApe()<<endl;
	}
	else{
		cout<<"\t\t\t\t\tNo se encontro la venta\n";		
	}
	system("pause");
	system("cls");
}


void modificarventas(){
	int opcion;
	do{
		cout<<"\n\n\n\n\t\t\t\t\t'MODIFICAR VENTAS'\n";
		cout<<"\t\t\t\t\tAGREGAR PRODUCTO A UNA VENTA.....[1]\n";
		cout<<"\t\t\t\t\tELIMINAR PRODUCTO DE UNA VENTA...[2]\n";
		cout<<"\t\t\t\t\tREGRESAR.........................[3]\n";
		do{
			cout<<"\t\t\t\t\tElija una opcion[1-3]: ";
			cin>>opcion;
		} while(opcion>3 || opcion<1);
		switch(opcion){
		case 1:system("cls");AgregarAVenta();break;
		case 2:system("cls");EliminardeVenta();break;
		case 3:system("cls");break;
		}
	} while(opcion!=3);
}

void AgregarAVenta(){
	int cod;
	string answer;
	cout<<"\n\n\n\n\t\t\t\t\tIngrese el codigo de la venta a la que desee agregar productos:";
	cin>>cod;
	Venta objproduct = ventas->busqueda(cod);
	Cliente c= clienteController.buscarPorCodigo(objproduct.getCodCli());
	Vendedor v= regis->buscarPorCodigo(objproduct.getCodPersonal());
	if(objproduct.getCodVenta() != 0){
		cout<<"\t\t\t\t\tCodigo de la venta:"<<objproduct.getCodVenta()<<endl;
		cout<<"\t\t\t\t\tFecha de la venta:";objproduct.Fecha();
		cout<<"\t\t\t\t\tTotal de la venta:"<<objproduct.getTotVen()<<endl;
		cout<<"\t\t\t\t\tEstado de la Venta:"<<objproduct.estado()<<endl;
		cout<<"\t\t\t\t\tCliente:"<<c.getNomApe()<<endl;
		cout<<"\t\t\t\t\tVendedor:"<<v.getNomApe()<<endl;
		cout<<"\t\t\t\t\tDesea agregar productos a esta venta?[Si/No]:";
		cin>>answer;
		if(answer == "Si" || answer == "si"){
			int codP, cant;
			float p;
			string a;
			do{
				system("cls");
				listarproductos();
				cout<<"\t\t\t\t\tIngrese el codigo del producto que desea agregar:";
				cin>>codP;
				ventamas cantidad = ventacontroller->busqueda(codP);
				do{
					cout<<"\t\t\t\t\tIngrese la cantidad del producto seleccionado a agregar a la venta:";
					cin>>cant;
					if(cantidad.getStock() - cant < 0){
						cout<<"\t\t\t\t\tEsa cantidad no esta disponible\n";
					}
				}while(cant > cantidad.getStock() ||cant<0);
				p=ventacontroller->ObtenerPrecio(codP);
				p = p*cant;
				DetalleVenta dv(cod, codP, cant,p);
				detallesV->add(dv);
				detallesV->guardar_archivo(dv);
				ventamas modificaciondelProducto(cantidad.getCodigo(),cantidad.getNombre()
				,cantidad.getPrecio(),cantidad.getStock()-cant,cantidad.getCodigoCategoria());
				bool m = ventacontroller->modificar(cantidad,modificaciondelProducto);
				if(m == true){
					ventacontroller->grabarModificacionenarchivo();
				}
				cout<<"\t\t\t\t\tDesea seguir agregando productos en la venta?[SI/NO]:";
				cin>>a;
			} while(a == "Si" || a=="si");
			float t = detallesV->TotalVenta(objproduct.getCodVenta());
			ventas->TotalVenta(objproduct.getCodVenta(),t);
			ventas->grabarModificacionenarchivo();
		}
	}
	else{
		cout<<"\t\t\t\t\tNo se encontro la venta\n";		
	}
	system("pause");
	system("cls");
}

void EliminardeVenta(){
	int cod;
	string answer;
	cout<<"\n\n\n\n\t\t\t\t\tIngrese el codigo de la venta a la que desee eliminar productos:";
	cin>>cod;
	Venta AEliminar = ventas->busqueda(cod);
	Cliente c= clienteController.buscarPorCodigo(AEliminar.getCodCli());
	Vendedor v= regis->buscarPorCodigo(AEliminar.getCodPersonal());
	if(AEliminar.getCodVenta() != 0){
		cout<<"\t\t\t\t\tCodigo de la venta:"<<AEliminar.getCodVenta()<<endl;
		cout<<"\t\t\t\t\tFecha de la venta:";AEliminar.Fecha();
		cout<<"\t\t\t\t\tTotal de la venta:"<<AEliminar.getTotVen()<<endl;
		cout<<"\t\t\t\t\tEstado de la Venta:"<<AEliminar.estado()<<endl;
		cout<<"\t\t\t\t\tCliente:"<<c.getNomApe()<<endl;
		cout<<"\t\t\t\t\tVendedor:"<<v.getNomApe()<<endl;
		cout<<"\t\t\t\t\tDesea eliminar productos a esta venta?[Si/No]:";
		cin>>answer;
		if(answer == "Si" || answer == "si"){
			system("cls");
			DetalleVenta objAEliminar;
			int pEliminado,cantEliminado;
			cout<<"\n\n\n\n\t\t\t\t*****PRODUCTOS DE LA VENTA*****\n";
			cout<<"\t\t\t\t---------------------------------------------\n";
			cout<<"\t\t\t\tCodigo";
			cout<<"\tProducto";
			cout<<"\tCategoria";
			cout<<"\tCantidad";
			cout<<"\tPrecio total\n";
			for(int i = 0;i<detallesV->size();i++){
				if(cod == detallesV->get(i).getCodVent()){
					int nombre=ventacontroller->ObtenerNombreProducto(detallesV->get(i).getCodProduct()).length();
					ventamas cate = ventacontroller->busqueda(detallesV->get(i).getCodProduct());
					cout<<"\t\t\t\t"<<detallesV->get(i).getCodProduct()<<"\t";
					cout<<ventacontroller->ObtenerNombreProducto(detallesV->get(i).getCodProduct());
					if(nombre<15){
						int p = 15 - nombre;
						for(int i=0;i<p;i++){
							cout<<" ";
						}
					} cout<<"\t";
					cout<<Categoriacontroller->getCategoria(cate.getCodigoCategoria())<<"\t";
					cout<<detallesV->get(i).getCantida()<<"\t";
					cout<<detallesV->get(i).getPrecioVent()<<endl;
				}
			}
			cout<<"\t\t\t\t\t---------------------------------------------\n";
			cout<<"\t\t\t\t\tIngrese el codigo del producto que desea eliminar: ";
			cin>>pEliminado;
			cout<<"\t\t\t\t\tIngrese la cantidad del producto a eliminar:";
			cin>>cantEliminado;
			detallesV->Eliminar(AEliminar.getCodVenta(),pEliminado,cantEliminado);
			detallesV->grabarModificacionenarchivo();
			ventamas c = ventacontroller->busqueda(pEliminado);
			ventamas modificaciondelProducto(c.getCodigo(),c.getNombre()
			 ,c.getPrecio(),c.getStock()+cantEliminado,c.getCodigoCategoria());
			bool m = ventacontroller->modificar(c,modificaciondelProducto);
			if(m == true){
				ventacontroller->grabarModificacionenarchivo();
			}
			float CantidadEliminar = c.getPrecio() * cantEliminado;
			ventas->TotalVentaAlEliminar(AEliminar.getCodVenta(),CantidadEliminar);
			ventas->grabarModificacionenarchivo();
		}
	}
	else{
		cout<<"\t\t\t\t\tNo se encontro la venta\n";		
	}
	system("pause");
	system("cls");
}

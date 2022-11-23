#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#pragma once
using namespace std;

class DetalleVenta
{
private:
	int codVenta;
	int codProducto;
	int cantidad;
	float precioVenta;
public:
	DetalleVenta(){};
	DetalleVenta(int codVent, int codProduct, int cantida, float precioVent)
	{
		codVenta = codVent;
		codProducto = codProduct;
		cantidad = cantida;
		precioVenta = precioVent;
	}
	void setCodVent(int codVent)
	{
		codVenta = codVent;
	}
	void setCodProduct(int codProduct)
	{
		codProducto = codProduct;
	}
	void setCantida(int cantida)
	{
		cantidad = cantida;
	}
	void setPrecioVent(float precioVent)
	{
		precioVenta = precioVent;
	}
	int getCodVent()
	{
		return codVenta;
	}
	int getCodProduct()
	{
		return codProducto;
	}
	int getCantida()
	{
		return cantidad;
	}
	float getPrecioVent()
	{
		return precioVenta;
	}
	
};

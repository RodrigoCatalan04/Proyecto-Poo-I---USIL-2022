#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#pragma once
using namespace std;

class Venta
{
private:
	int codVenta;
	int fecVen;
	float totVen;
	int codCli;
	bool estVen;
	int codPersonal;
	
public:
	Venta(){};
	Venta(int codV, int fecV,float t, bool estado,int codC, int codP)
	{
		codVenta = codV;
		fecVen = fecV;
		codCli = codC;
		totVen = t;
		estVen = estado;
		codPersonal = codP;
	}
	void setCodVenta(int codV)
	{
		codVenta = codV;
	}
	
	void setFecVen(int fecV)
	{
		fecVen = fecV;
	}
	
	void setTotVen(float totV)
	{
		totVen = totV;
	}
	
	void setCodCli(int codC)
	{
		codCli = codC;
	}
	
	void setEstVen(bool estV)
	{
		estVen = estV;
	}
	
	void setCodPersonal(int codP)
	{
		codPersonal = codP;
	}
	
	int getCodVenta()
	{
		return codVenta;
	}
	
	int getFecVen()
	{
		return fecVen;
	}
	
	float getTotVen()
	{
		return totVen + (totVen * 0.18); //IGV
	}
	
	int getCodCli()
	{
		return codCli;
	}
	
	bool getEstVen()
	{
		return estVen;
	}
	
    int getCodPersonal()
	{
		return codPersonal;
	}	
	string estado(){
		if(estVen == true){
			return "Activa";
		}
		else{
			return "Oculta";
		}
	}
	void Fecha(){
		int dia = fecVen/1000000;
		int mes = (fecVen%1000000)/10000;
		int a = fecVen%10000;
		cout<<dia<<"/"<<mes<<"/"<<a<<endl;
	}
	void CambiarEstado(){
		estVen = false;
	}
};

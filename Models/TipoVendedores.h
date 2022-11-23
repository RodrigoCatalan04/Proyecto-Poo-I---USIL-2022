#include <iostream>
#pragma once
using namespace std;

class tipo{
private:
	int codT;
	string nomT;
public:
	tipo(){}
	tipo(int codT, string nomT)
	{
		this->codT=codT;
		this->nomT=nomT;
	}
	void setCodT(int cod){
		this->codT=codT;
	}
	void setNomT(string nom){
		this->nomT=nomT;
	}
	int getCodT(){
		return codT;
	}
	string getNomT(){
		return nomT;
	}
};

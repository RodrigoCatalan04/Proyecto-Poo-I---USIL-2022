#pragma once

#include <iostream>
#include "Usuario.h"

#ifndef VENTAMAS1_0_VENDEDOR_H
#define VENTAMAS1_0_VENDEDOR_H

using namespace std;

class Vendedor {
private:
	int codigo;
	string nomApe;
	int codT;
	Usuario usuario;
public:
	Vendedor() {
		
	}
	
	~Vendedor() = default;
	
	Vendedor(int cod, string nomApe, int codT, Usuario usuario) {
		this->codigo = cod;
		this->nomApe = nomApe;
		this->codT = codT;
		this->usuario = usuario;
	}
	
	void setCodigo(int codigo) {
		this->codigo = codigo;
	}
	
	void setNomApe(string nomApe) {
		this->nomApe = nomApe;
	}
	
	void setCodT(int codT) {
		this->codT = codT;
	}
	
	int getCodigo() {
		return this->codigo;
	}
	
	string getNomApe() {
		return this->nomApe;
	}
	
	int getCodT() {
		return this->codT;
	}
	
	const Usuario &getUsuario() const {
		return usuario;
	}
	
	void setUsuario(const Usuario &usuario) {
		Vendedor::usuario = usuario;
	}
	
};

#endif //VENTAMAS1_0_VENDEDOR_H

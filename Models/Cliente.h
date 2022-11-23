//
// Created by jalb2 on 1/11/2022.
//
#pragma once

#include <string>

using namespace std;

#ifndef VENTAMAS1_0_CLIENTE_H
#define VENTAMAS1_0_CLIENTE_H

class Cliente {
private:
    int codigo;
    long long int Ruc;
    string nomApe,dir;
public:
    Cliente() {

    }

    ~Cliente() {

    }

    Cliente(int cod, string nomApe,string dir, long long int Ruc) {
        this->codigo = cod;
        this->Ruc = Ruc;
		this->dir = dir;
        this->nomApe = nomApe;

    }

    void setCodigo(int codigo) {
        this->codigo = codigo;
    }

    void setRuc(long long int Ruc) {
        this->Ruc = Ruc;
    }

    void setNomApe(string nomApe) {
        this->nomApe = nomApe;
    }
	void setDir(string dir) {
		this->dir = dir;
	}

    int getCodigo() {
        return this->codigo;
    }

    long long int getRuc() {
        return this->Ruc;
    }

    string getNomApe() {
        return this->nomApe;
    }
	
	string getDir() {
		return this->dir;
	}

};

#endif //VENTAMAS1_0_CLIENTE_H

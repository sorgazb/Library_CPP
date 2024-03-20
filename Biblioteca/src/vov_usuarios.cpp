/*
 * vovusuarios.cpp
 *
 *  Created on: 24 feb. 2022
 *      Author: alumno
 */

#include "vov_usuarios.h"

vovUsuarios::vovUsuarios() {
	ocupacion=0;
}

void vovUsuarios::insertar(Usuarios *&u) {
	if(ocupacion < MAX1){
		vov_usuarios[ocupacion]= u;
		ocupacion++;
	}
}

void vovUsuarios::obtener(int pos, Usuarios *&u) {
	u = vov_usuarios[pos];
}

void vovUsuarios::obtener(string identificador, Usuarios *&u) {
	Usuarios *uaux= nullptr;
	int i=0;
	bool enc=false;
	while(i< cuantos() && !enc){
		obtener(i, uaux);
		if(uaux->getIdentificador()==identificador){
			enc=true;
			u=uaux;
		}
		else{
			i++;
		}
	}

}

bool vovUsuarios::existe(string identificador) {
	Usuarios *uaux= nullptr;
	int i=0;
	bool existe=false;
	while(i<cuantos() && !existe){
		obtener(i, uaux);
		if(uaux->getIdentificador()==identificador){
			existe=true;
		}
		else{
			i++;
		}
	}
	return existe;
}

int vovUsuarios::cuantos() {
	return ocupacion;
}

void vovUsuarios::eliminar(string identificador) {
	Usuarios *uaux= nullptr;
	int i=0;
	bool enc=false;
	while(i<cuantos() && !enc){
		if(uaux->getIdentificador()==identificador){
			enc=true;
			delete uaux;
		}
		else{
			i++;
		}
	}
}

vovUsuarios::~vovUsuarios() {
}






/*
 * vov_libros.cpp
 *
 *  Autor: Juan A. Rico (jarico@unex.es)
 *  Fecha: 31 Enero 2022
 */

#include <iostream>

#include "vov_libros.h"

using namespace std;

vovLibros::vovLibros () {
	ocupacion=0;
}

void vovLibros::insertar (Libros *&l) {
	if (ocupacion < MAX) {
		vov_libros[ocupacion] = l;
		ocupacion++;
	}
}

void vovLibros::obtener (int pos, Libros *&l) {
	l = vov_libros[pos];
}

void vovLibros::obtener (string id, Libros *&l){
	Libros *laux= nullptr;
	int i=0;
	bool enc=false;
	while(i< cuantos() && !enc){
		obtener(i, laux);
		if(laux->getId()==id){
			enc=true;
			l=laux;
		}
		else{
			i++;
		}
	}
}

bool vovLibros::existe (string id){
	Libros *laux= nullptr;
	int i=0;
	bool existe=false;
	while(i<cuantos() && !existe){
		obtener(i, laux);
		if(laux->getId()==id){
			existe=true;
		}
		else{
			i++;
		}
	}
	return existe;
}

int  vovLibros::cuantos  () {
	return ocupacion;
}


void vovLibros::eliminar(string id) {
	int i=0;
	int posicion;
	bool enc=false;
	Libros *l=nullptr;
	while( i < this->ocupacion && !enc){
		l=vov_libros[i];
		if(l->getId()==id){
			enc=true;
			delete l;
		}
		else{
			i++;
		}
	}
	for(posicion=i; posicion <this->ocupacion+1 ; posicion++){
		vov_libros[posicion]=vov_libros[posicion+1];
	}
	this->ocupacion--;
}


vovLibros::~vovLibros(){
}

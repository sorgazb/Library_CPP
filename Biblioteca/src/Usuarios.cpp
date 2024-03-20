/*
 * Usuarios.cpp
 *
 *  Created on: 24 feb. 2022
 *      Author: alumno
 */

#include "Usuarios.h"

Usuarios::Usuarios() {
	identificador=" ";
	nombre=" ";
	apellidos=" ";
	correo=" ";
	this->lusuarios=NULL;
}

Usuarios::Usuarios(string identificador, string nombre, string apellidos,string correo, Libros *l) {
	this->identificador=identificador;
	this->nombre=nombre;
	this->apellidos=apellidos;
	this->correo=correo;
	this->lusuarios=l;
}

void Usuarios::setIdentificador(string identificador) {
	this->identificador=identificador;
}

void Usuarios::setNombre(string nombre) {
	this->nombre=nombre;
}

void Usuarios::setApellidos(string apellidos) {
	this->apellidos=apellidos;
}

void Usuarios::setCorreo(string correo) {
	this->correo=correo;
}





string Usuarios::getIdentificador() {
	return identificador;
}

string Usuarios::getNombre() {
	return nombre;
}

string Usuarios::getApellidos() {
	return apellidos;
}

string Usuarios::getCorreo() {
	return correo;
}



void Usuarios::mostrar() {
	cout<<identificador<<";"<<nombre<<";"<<apellidos<<";"<<correo<<";";
	if(lusuarios==nullptr){
		cout<<"sin-prestamo"<<endl;
	}
	else{
		cout<<lusuarios->getId()<<endl;
	}
}



Usuarios::~Usuarios() {
	// TODO Auto-generated destructor stub
}

Libros* Usuarios::getLibros() {
	return lusuarios;
}

void Usuarios::setLibros(Libros *lusuarios) {
	this->lusuarios=lusuarios;
}

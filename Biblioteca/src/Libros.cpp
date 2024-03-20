/*
 * Libros.cpp
 *
 *  Created on: 11 feb. 2022
 *      Author: alumno
 */

#include "Libros.h"

Libros::Libros() {
	id="";
	autor="";
	titulo="";
	tematica="";
	anioPublicacion=0;
	numPaginas=0;

}

Libros::Libros(string id, string autor, string titulo, string tematica, int anioPublicacion, int numPaginas) {
	this->id =id;
	this->autor=autor;
	this->titulo=titulo;
	this->tematica=tematica;
	this->anioPublicacion=anioPublicacion;
	this->numPaginas=numPaginas;

}

void Libros::setId(string id) {
	this->id =id;
}

void Libros::setAutor(string autor) {
	this->autor=autor;
}

void Libros::setTitulo(string titulo) {
	this->titulo=titulo;
}

void Libros::setTematica(string tematica) {
	this->tematica=tematica;
}

void Libros::setAnioPublicacion(int anioPublicacion) {
	this->anioPublicacion=anioPublicacion;
}

void Libros::setNumPaginas(int numPaginas) {
	this->numPaginas=numPaginas;
}



string Libros::getId() {
	return id;
}

string Libros::getAutor() {
	return autor;
}

string Libros::getTitulo() {
	return titulo;
}

string Libros::getTematica() {
	return tematica;
}

int Libros::getAnioPublicacion() {
	return anioPublicacion;
}

int Libros::getNumPaginas() {
	return numPaginas;
}




void Libros::mostrar() {
	cout<<id<<";"<<autor<<";"<<titulo<<";"<<tematica<<";"<<anioPublicacion<<";"<<numPaginas<<endl;
}

Libros::~Libros() {
	// TODO Auto-generated destructor stub
}



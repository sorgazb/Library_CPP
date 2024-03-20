/*
 * biblioteca.cpp
 *
 *  Autor: 
 *  Fecha: 
 */

#include <iostream>
#include <fstream>
#include <string>

#include "vov_libros.h"
#include "biblioteca.h"

using namespace std;

void Biblioteca::cargarLibros(){
	string id;
	string autor;
	string titulo;
	string tematica;
	string anioPub;
	string numeroPaginas;
	int anioPubint;
	int numeroPaginasint;
	ifstream ifs;
	Libros *l;
	ifs.open("libros.csv");
	if(ifs.is_open()){
		while(!ifs.eof()){
			getline(ifs, titulo, ';');
			if(!ifs.eof()){
				getline(ifs, autor, ';');
				getline(ifs, tematica, ';');
				getline(ifs, anioPub, ';');
				getline(ifs, numeroPaginas);
				anioPubint=stoi(anioPub);
				numeroPaginasint=stoi(numeroPaginas);
				id= titulo.substr(0,3)+"."+autor.substr(0,3)+"."+anioPub;
				l = new Libros (id,autor,titulo, tematica, anioPubint, numeroPaginasint);
				vLibros->insertar(l);
			}
		}
		ifs.close();
	}
}

void Biblioteca::cargarUsuarios() {
	string identificador;
	string nombre;
	string apellidos;
	string correo;
	string prestamo;
	ifstream f;
	f.open("usuarios.csv");
	if(f.is_open()){
		while(!f.eof()){
			getline(f, identificador, ';');
			getline(f, nombre, ';');
			getline(f, apellidos, ';');
			getline(f, correo, ';');
			getline(f, prestamo);
			Usuarios *u;
			Libros *l=nullptr;
			if(prestamo != "sin-prestamo"){
				vLibros->obtener(prestamo, l);
			}
			u= new Usuarios (identificador, nombre, apellidos, correo, l);
			vUsuarios->insertar(u);
		}
		f.close();
	}
}

void Biblioteca::guardarLibros() {
	Libros *l;
	ofstream fEscrituraL;
	int cantidad = vLibros->cuantos();
	fEscrituraL.open("libros.csv");
	if(fEscrituraL.is_open()){
		for(int i=0; i<cantidad; i++){
			vLibros->obtener(i, l);
			fEscrituraL<<l->getTitulo()<<";"<<l->getAutor()<<";"<<l->getTematica()<<";"<<l->getAnioPublicacion()<<";"<<l->getNumPaginas();
			if(i!=cantidad-1){
				fEscrituraL<<endl;
			}
		}
		fEscrituraL.close();
	}
}

void Biblioteca::guardarUsuarios() {
	Usuarios *u;
	ofstream fEscrituraU;
	int cantidad= vUsuarios->cuantos();
	fEscrituraU.open("usuarios.csv");
	if(fEscrituraU.is_open()){
		for(int i=0; i<cantidad; i++){
			vUsuarios->obtener(i, u);
			if(u->getLibros()==nullptr){
				fEscrituraU<<u->getIdentificador()<<";"<<u->getNombre()<<";"<<u->getApellidos()<<";"<<u->getCorreo()<<";"<<"sin-prestamo";
			}
			else{
				Libros *l;
				l=u->getLibros();
				fEscrituraU<<u->getIdentificador()<<";"<<u->getNombre()<<";"<<u->getApellidos()<<";"<<u->getCorreo()<<";"<<l->getId();
			}
			if(i!=cantidad-1){
				fEscrituraU<<endl;
			}
		}
		fEscrituraU.close();
	}
}

Biblioteca::Biblioteca() {
	nombre="";
	this->vLibros= new vovLibros();
	this->vUsuarios= new vovUsuarios();
	cargarLibros();
	cargarUsuarios();
}

Biblioteca::Biblioteca(string nombre) {
	this->nombre= nombre;
	this->vLibros= new vovLibros();
	this->vUsuarios= new vovUsuarios();
	cargarLibros();
	cargarUsuarios();
}

void Biblioteca::prestarLibro(string id, string identificador) {
	Usuarios *u=nullptr;
	if(vUsuarios->existe(identificador) && vLibros->existe(id)){
		vUsuarios->obtener(identificador, u);
		Libros *l=nullptr;
		vLibros->obtener(id, l);
		if(l!=nullptr){
			u->setLibros(l);
			cout<<"El libro: "<<l->getTitulo()<<" ha sido prestado a: "<<u->getNombre()<<" "<<u->getApellidos()<<endl;
		}
	}
}

void Biblioteca::mostrarLibrosTematica(string subcadena) {
	string tematica;
	for (int i=0; i<vLibros->cuantos(); i++){
		Libros *l;
		vLibros->obtener(i, l);
		tematica= l->getTematica();
		int pos= tematica.find(subcadena);
		if(pos!=-1){
			l->mostrar();
		}
	}
}

void Biblioteca::buscarLibroReferencia(string id) {
	Libros *l=nullptr;
	if(vLibros->existe(id)){
		vLibros->obtener(id, l);
		l->mostrar();
	}
}

void Biblioteca::mostrarLibros() {
	for(int i=0; i<vLibros->cuantos(); i++){
		Libros *l;
		vLibros->obtener(i, l);
		l->mostrar();
	}
}

void Biblioteca::mostrarUsuarios() {
	for(int i=0; i<vUsuarios->cuantos(); i++){
		Usuarios *u;
		vUsuarios->obtener(i, u);
		u->mostrar();
	}
}

void Biblioteca::mostrarUsuariosConLibrosPrestados() {
	for(int i=0; i<vUsuarios->cuantos(); i++){
		Usuarios *u;
		vUsuarios->obtener(i, u);
		if(u->getLibros()!=nullptr){
			u->mostrar();
		}
	}
}

void Biblioteca::descatalogarLibro(string id) {
	Usuarios *u;
	Libros *l;
	bool enc=false;
	int i=0;
	while(i<vUsuarios->cuantos() && !enc){
		vUsuarios->obtener(i, u);
		l= u->getLibros();
		if(l!=nullptr){
			if(l->getId()==id){
				enc=true;
			}
			else{
				i++;
			}
		}
		else{
			i++;
		}
	}
	if(!enc){
		if(vLibros->existe(id)){
			this->vLibros->eliminar(id);
			cout<<"El libro ha sido descatalogado."<<endl;
		}
	}
}

Biblioteca::~Biblioteca() {
	guardarLibros();
	guardarUsuarios();
	delete this->vLibros;
	delete this->vUsuarios;
}



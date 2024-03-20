/*
 * Libros.h
 *
 *  Created on: 11 feb. 2022
 *      Author: alumno
 */

#ifndef LIBROS_H_
#define LIBROS_H_
#include <iostream>
using namespace std;


class Libros {
	string id;
	string autor;
	string titulo;
	string tematica;
	int anioPublicacion;
	int numPaginas;

public:

	/*
	 * PRE = {}
	 * POST = {getId()="", getAutor()="", getTitulo()="", getTematica()="", getAnioPublicacion()=0, getNumPaginas()=0, getNumEjemplares=1}
	 * DESC: Crea un libro.
	 * COMPL: O(1)
	 */
	Libros();

	/*
	 * Constructor parametrizado
	 * PRE = {}
	 * POST = {getId()=id, getAutor()=autor, getTitulo()=titulo, getTematica()=tematica, getAnioPublicacion()=anioPublicacion, getNumPaginas()=numPaginas, getNumEjemplares()=numEjemplares}
	 * DESC: Crea un libro.
	 * COMPL: O(1)
	 */
	Libros(string id, string autor, string titulo, string tematica, int anioPublicacion, int numPaginas);


	//Metodos modificadores

	/*
	 * PRE = {}
	 * POST = {Modifica el Id del libro}
	 * COMPL: O(1)
	 */
	void setId(string id);
	/*
	 * PRE = {}
	 * POST = {Modifica el autor del libro}
	 * COMPL: O(1)
	 */
	void setAutor(string autor);
	/*
	 * PRE = {}
	 * POST = {Modifica el titulo del libro}
	 * COMPL: O(1)
	 */
	void setTitulo(string titulo);
	/*
	 * PRE = {}
	 * POST = {Modifica la tematica del libro}
	 * COMPL: O(1)
	 */
	void setTematica(string tematica);
	/*
	 * PRE = {}
	 * POST = {Modifica el año de la publicacion del libro}
	 * COMPL: O(1)
	 */
	void setAnioPublicacion(int anioPublicacion);
	/*
	 * PRE = {}
	 * POST = {Modifica el numero de paginas del libro}
	 * COMPL: O(1)
	 */
	void setNumPaginas(int numPaginas);

	//Metodos selectores

	/*
	 * PRE = {}
	 * POST = {Devuelve el Id del libro}
	 * COMPL: O(1)
	 */
	string getId();
	/*
	 * PRE = {}
	 * POST = {Devuelve el autor del libro}
	 * COMPL: O(1)
	 */
	string getAutor();
	/*
	 * PRE = {}
	 * POST = {Devuelve el titulo del libro}
	 * COMPL: O(1)
	 */
	string getTitulo();
	/*
	 * PRE = {}
	 * POST = {Devuelve la tematica del libro}
	 * COMPL: O(1)
	 */
	string getTematica();
	/*
	 * PRE = {}
	 * POST = {Devuelve el año de publicación del libro}
	 * COMPL: O(1)
	 */
	int getAnioPublicacion();
	/*
	 * PRE = {}
	 * POST = {Delvuelve el numero de paginas del libro}
	 * COMPL: O(1)
	 */
	int getNumPaginas();

	/*
	 * PRE = {}
	 * POST = {Muestra por pantalla la informacion del libro}
	 * COMPL: O(1)
	 */
	void mostrar();

	/*
	 * Destructor
	 * PRE = {}
	 * POST = {}
	 * DESC:
	 * COMPL: O(1)
	 */
	~Libros();
};

#endif /* LIBROS_H_ */

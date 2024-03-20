/*
 * vov_libros.h
 *
 *  Autor: Juan A. Rico (jarico@unex.es)
 *  Fecha: 31 Enero 2022
 */

#ifndef __VOV_LIBROS
#define __VOV_LIBROS

#include <iostream>
#include <fstream>
#include <string>
#include "Libros.h"
using namespace std;

// Máximo numero de libros
const int MAX = 100;

class vovLibros{
	Libros* vov_libros [MAX];
	int   ocupacion;
public:

	/*
	 * PRE  = { }
	 * POST = {ocupacion = 0}
	 * DESC:  Crea el vector de ocupación variable de Libros.
	 * COMPL: O(1)
	 */
	vovLibros();

	/*
	 *  PRE  = { }
	 *  POST = {ocupacion + 1 si ocupacion < MAX }
	 *  DESC:  Inserta un libro en la biblioteca si hay espacio.
	 *  COMPL: O(1)
	 */
	void insertar (Libros *&l);
	/*
	 * PRE  = {pos >= 0 && pos < ocupacion}
	 * POST = { Obtiene el libro en la posicion "pos"}
	 *COMPL: O(1)
	 */
	void obtener  (int pos, Libros *&l);
	/*
	 * PRE  = {}
	 * POST = {Obtiene el libro del identificador que se le pasa por parametros }
	 * COMPL: O(n)
	 */
	void obtener (string id, Libros *&l);
	/*
	 * PRE = {}
	 * POST = {Comprueba si existe un libro dado un identificador que se le pasa por parametros}
	 * COMPL: O(n)
	 */
	bool existe (string id);
	/*
	 * PRE  = { }
	 * POST = {Devuelve el numero de libros en la biblioteca}
	 * COMPL: O(1)
	 */
	int  cuantos  ();
	/*
	 * PRE = {}
	 * POST = {Borra el libro que tiene el identificador que se le pasa por parametros}
	 * COMPL: O(n)
	 */
	void eliminar(string id);

	/*
	 * Destructor
	 * PRE = {}
	 * POSRT = {}
	 * DESC:
	 * COMPL: O(n)
	 */
	~vovLibros();
};

#endif /* __VOV_LIBROS */

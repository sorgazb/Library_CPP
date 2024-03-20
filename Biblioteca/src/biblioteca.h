/*
 * biblioteca.h
 *
 *  Autor: Juan A. Rico (jarico@unex.es)
 *  Fecha: 31 Enero 2022
 */

#ifndef __BIBLIOTECA
#define __BIBLIOTECA

#include <iostream>
#include <fstream>
#include <string>
#include "vov_libros.h"
#include "vov_usuarios.h"

using namespace std;

class Biblioteca{
	vovLibros *vLibros;
	vovUsuarios *vUsuarios;
	string nombre;

	/*
	 * PRE = {Que el fichero de texto se haya abierto correctamente}
	 * POST = {Se encarga de cargar todo el fichero de texto a la bibilioteca}
	 * COMPL: O(n)
	 */
	void cargarLibros();
	/*
	 * PRE = {Que el fichero de texto se haya abierto correctamente}
	 * POST = {Se encarga de cargar todo el fichero de texto a la biblioteca}
	 * COMPL: O(n)
	 */
	void cargarUsuarios();
	/*
	 * PRE = {}
	 * POST = {Se encarga de devolver los archivos al fichero de texto con los cambios realizados}
	 * COMPL: O(n)
	 */
	void guardarLibros();
	/*
	 * PRE = {}
	 * POST = {Se encarga de devolver los archivos al fichero de texto con los cambios realizados}
	 * COMPL: O(n)
	 */
	void guardarUsuarios();

public:
	/*
	 * PRE = {}
	 * POST = {Crea una biblioteca}
	 * COMPL: O(1)
	 */
	Biblioteca();
	/*
	 * PRE = {}
	 * POST = {Crea una biblioteca}
	 * COMPL: O(1)
	 */
	Biblioteca(string nombre);
	/*
	 * PRE = {Que el identifacador de libro y de usuario exista}
	 * POST = {Presta un libro a un usuario}
	 * COMPL: O(n)
	 */
	void prestarLibro(string id, string identificador);
	/*
	 * PRE = {}
	 * POST = {Muestra todos los libros cuya tematica contiene la palabra que se le pasa por la subcadena}
	 * COMPL: O(n)
	 */
	void mostrarLibrosTematica(string subcadena);
	/*
	 * PRE = {Que el identificador existe}
	 * POST = {Muestra todos los libros con un determinado id}
	 * COMPL: O(1)
	 */
	void buscarLibroReferencia(string id);
	/*
	 * PRE = {}
	 * POST = {Muestra todos los libros del fichero}
	 * COMPL: O(n)
	 */
	void mostrarLibros();
	/*
	 * PRE = {}
	 * POST = {Muestra todos los usuarios del fichero}
	 * COMPL: O(n)
	 */
	void mostrarUsuarios();
	/*
	 * PRE = {}
	 * POST = {Muestra todos los usuarios que tienen un libro prestado}
	 * COMPL: O(n)
	 */
	void mostrarUsuariosConLibrosPrestados();
	/*
	 * PRE = {Que el id del libro exista}
	 * POST = {Borra un libro de la extructura}
	 * COMPL: O(n²)
	 */
	void descatalogarLibro(string id);


	~Biblioteca();
};



#endif /* __BIBLIOTECA */

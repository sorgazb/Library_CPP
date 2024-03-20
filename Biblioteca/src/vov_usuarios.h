/*
 * vovusuarios.h
 *
 *  Created on: 24 feb. 2022
 *      Author: alumno
 */

#ifndef VOV_USUARIOS_H_
#define VOV_USUARIOS_H_

#include <iostream>
#include <fstream>
#include <string>
#include "Usuarios.h"
using namespace std;

// Máximo numero de usuarios
const int MAX1 = 200;

class vovUsuarios {
	Usuarios* vov_usuarios [MAX1];
	int   ocupacion;
public:

	/*
	 * PRE = {}
	 * POST = {ocupacion = 0}
	 * DESC: Crea el vector de ocupación variable de Usuarios
	 * COMPL: O(1)
	 */
	vovUsuarios();


	/*
	 * PRE = {}
	 * POST = {ocupacion + 1 si ocupacion < MAX}
	 * DESC: Inserta un usuario en la biblioteca si hay espacio
	 * COMPL: O(1)
	 */
	void insertar (Usuarios *&u);
	/*
	 * PRE = {pos >=0 && pos < ocupacion}
	 * POST = {Obtiene el usuario en la posicion "pos"}
	 * COMPL: O(1)
	 */
	void obtener  (int pos, Usuarios *&u);
	/*
	 * PRE = {}
	 * POST = {Obtiene el usuario del identificador que se le pasa por parametros}
	 * COMPL: O(n)
	 */
	void obtener (string identificador, Usuarios *&u);
	/*
	 * PRE = {}
	 * POST = {Comprueba si existe el usuario dado el identificador que se le pasa por parametros}
	 * COMPL: O(n)
	 */
	bool existe (string identificador);
	/*
	 * PRE = {}
	 * POST = {Devuelve el numero de usuarios que hay la biblioteca}
	 * COMPL: O(1)
	 */
	int  cuantos  ();
	/*
	 * PRE = {}
	 * POST = {Borra el usuario que tiene el identificador que se le pasa por parametros}
	 * COMPL: O(n)
	 */
	void eliminar(string identificador);

	/*
	 * Destructor
	 * PRE = {}
	 * POST = {}
	 * DESC:
	 * COMPL: O(n)
	 */
	~vovUsuarios();
};

#endif /* VOV_USUARIOS_H_ */

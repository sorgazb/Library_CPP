/*
 * Usuarios.h
 *
 *  Created on: 24 feb. 2022
 *      Author: alumno
 */

#ifndef USUARIOS_H_
#define USUARIOS_H_
#include <iostream>
using namespace std;
#include "Libros.h"

class Usuarios {
	string identificador;
	string nombre;
	string apellidos;
	string correo;
	Libros *lusuarios;
public:

	/*
	 * PRE = {}
	 * POST = {getIdentificador()="", getNombre()="", getApellidos()="", getCorreo()="", getPrestamo()=""}
	 * DESC: Crea un usuario.
	 * COMPL: O(1)
	 */
	Usuarios();

	/*
	 * Constructor parametrizado
	 * PRE = {}
	 * POST = {getIdentificador()=identificador, getNombre()=nombre, getApellidos()=apellidos, getCorreo()=correo, getPrestamo()=prestamo}
	 * DESC: Crea un usuario.
	 * COMPL: O(1)
	 */
	Usuarios(string identificador, string nombre, string apellidos, string correo, Libros *l);


	//Metodos modificadores

	/*
	 * PRE = {}
	 * POST = {Modifica el identificador del usuario}
	 * COMPL: O(1)
	 */
	void setIdentificador(string identificador);
	/*
	 * PRE = {}
	 * POST = {Modifica el nombre del usuario}
	 * COMPL: O(1)
	 */
	void setNombre(string nombre);
	/*
	 * PRE = {}
	 * POST = {Modifica los apellidos del usuario}
	 * COMPL: O(1)
	 */
	void setApellidos(string apellidos);
	/*
	 * PRE = {}
	 * POST = {Modifica el correo del usuario}
	 * COMPL: O(1)
	 */
	void setCorreo(string correo);
	/*
	 * PRE = {}
	 * POST = {Modifica el prestamo del usuario}
	 * COMPL: O(1)
	 */
	void setLibros(Libros *lusuarios);


	//Metodos selectores

	/*
	 * PRE = {}
	 * POST = {Devuelve el identificador del usuario}
	 * COMPL: O(1)
	 */
	string getIdentificador();
	/*
	 * PRE = {}
	 * POST = {Devuelve el nombre del usuario}
	 * COMPL: O(1)
	 */
	string getNombre();
	/*
	 * PRE = {}
	 * POST = {Devuelve los apellidos del usuario}
	 * COMPL: O(1)
	 */
	string getApellidos();
	/*
	 * PRE = {}
	 * POST = {Devuelve el correo del usuario}
	 * COMPL: O(1)
	 */
	string getCorreo();
	/*
	 * PRE = {}
	 * POST = {Devuelve el prestamo del usuario}
	 * COMPL: O(1)
	 */
	Libros * getLibros();

	/*
	 * PRE = {}
	 * POST = {Muestra por pantalla la informacion del usuario}
	 * DESC: Se encarga de mostrar por pantalla la información del usuario.
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
	~Usuarios();


};

#endif /* USUARIOS_H_ */

/*
 * prog_principal.cpp
 *
 *  Autor: Juan A. Rico (jarico@unex.es)
 *  Fecha: 31 Enero 2022
 */

#include <iostream>
#include <fstream>
#include <string>

#include "biblioteca.h"
#include "vov_libros.h"
#include "vov_usuarios.h"

using namespace std;


// Muestra el menu por pantalla y devuelve una opcion elegida.
int menu() {

	int opcion;

	do {
		cout << endl;
		cout << "______________ MENU PRINCIPAL ______________"<< endl << endl;

		cout << "     1. Prestar un libro a un usuario                                  " << endl;
		cout << "     2. Mostrar los libros de una tematica determinada                 " << endl;
		cout << "     3. Buscar un libro por su referencia                              " << endl;
		cout << "     4. Mostrar todos los libros                                       " << endl;
		cout << "     5. Mostrar todos los usuarios                                     " << endl;
		cout << "     6. Mostrar todos los usuarios que tienen algún libro prestado     " << endl;
		cout << "     7. Descatalogar un libro                                          " << endl;
		cout << "     0. Finalizar.                         " << endl;
		cout << "                        Opcion:  ";
		cin >> opcion;
		cin.ignore();

	} while ((opcion < 0) || (opcion > 7));

	return opcion;
}


// Programa principal: 
int main() {

	Biblioteca *biblioteca;
	bool fin = false;
	int opcion;
	Libros *l;
	string id, dni, subcadena;

	biblioteca = new Biblioteca("Mi Biblioteca");


	do {
		opcion = menu();

		switch (opcion) {
			case 1:
				cout<<"Introduzca el DNI del usuario: "<<endl;
				getline(cin, dni);
				cout<<"Introduzca el ID del libro: "<<endl;
				getline(cin,id);
				biblioteca->prestarLibro(id, dni);
				break;

			case 2:
				cout<<"Introduzca la subcadena: "<<endl;
				getline(cin,subcadena);
				biblioteca->mostrarLibrosTematica(subcadena);
				break;

			case 3:
				cout<<"Introduce la referencia del Libro:"<<endl;
				getline(cin, id);
				biblioteca->buscarLibroReferencia(id);
				break;

			case 4:
				biblioteca->mostrarLibros();
				break;

			case 5:
				biblioteca->mostrarUsuarios();
				break;

			case 6:
				cout<<"Los usuarios con libros prestados son: "<<endl;
				biblioteca->mostrarUsuariosConLibrosPrestados();
				break;

			case 7:
				cout<<"Introduzca el identificador del libro para descatalogar: "<<endl;
				getline(cin, id);
				biblioteca->descatalogarLibro(id);
				break;

			case 0:
				fin = true;
				break;

			default:
				break;

		}
		
	} while (!fin);

	delete biblioteca;

	return 0;
}



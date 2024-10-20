#include <iostream>
#include "HashMap/HashMap.h"
using namespace std;

/*Biblioteca digital
Objetivo: Gestionar una colección de libros usando un sistema de hash.
● La clave será el ISBN del libro y el valor será el título del libro.
● Crea funciones para:
● Agregar nuevos libros a la biblioteca.
● Buscar un libro por su ISBN.
● Eliminar libros del sistema.
● Imprimir todos los libros registrados.
Desafíos:
● Implementar la resolución de colisiones.
● Verificar que no se repitan libros con el mismo ISBN*/

void menu(){
    cout << "\n----Biblioteca digital----" << endl;
    cout << "1. Agregar libro" << endl;
    cout << "2. Buscar libro" << endl;
    cout << "3. Eliminar libro" << endl;
    cout << "4. Ver todos los libros" << endl;
    cout << "0. Salir" << endl;
    cout << "Selecciona una opcion: " << endl;
}

int main() {
    unsigned tamanio = 11;
    HashMap<int, string> libros(tamanio);
    int opcion, isbn;
    string titulo;

    do {

        menu();
        cin >> opcion;

        switch (opcion) {

            case 1:

                cout << "\nIngrese el ISBN del libro: " << endl;
                cin >> isbn;
                cout << "Ingrese el titulo del libro: " << endl;
                cin.ignore();
                getline(cin, titulo);

                try {
                    libros.put(isbn, titulo);
                    cout << "Libro agregado" << endl;
                } catch (int e) {
                    cout << "Colision, intente nuevamente" << endl;
                }
                break;

            case 2:

                cout << "\nIngrese el ISBN del libro: " << endl;
                cin >> isbn;

                try {
                    cout << "Titulo: " << libros.get(isbn) << endl;
                } catch (int e) {
                    cout << "Libro no encontrado" << endl;
                }
                break;

            case 3:

                cout << "\nIngrese el ISBN del libro: " << endl;
                cin >> isbn;

                try {
                    libros.remove(isbn);
                    cout << "Libro eliminado" << endl;
                } catch (int e) {
                    cout << "Libro no encontrado" << endl;
                }
                break;

            case 4:

                cout << "\nLibros registrados:" << endl;
                libros.print();
                break;

            case 0:

                cout << "\nSaliendo..." << endl;
                break;

            default:

                cout << "\nOpcion invalida" << endl;
                break;
        }

    } while (opcion != 0);

    return 0;
}
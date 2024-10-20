#include <iostream>
#include "HashMap/HashMap.h"
using namespace std;

/*Simulación de un pequeño diccionario. Utilizaremos el HashMap para almacenar pares de
palabras (clave) y sus significados (valor).
El usuario podrá:
● Agregar nuevas palabras y sus significados.
● Buscar el significado de una palabra.
● Eliminar una palabra del diccionario.
● Ver todas las palabras en el diccionario.
*/

unsigned int HashString(string clave) { // Cambiado a string en lugar de const string&
    unsigned int hash = 0;
    for (char c : clave) {
        hash += c;
    }
    return hash;
}

void menu(){
    cout << "\n----Diccionario----" << endl;
    cout << "1. Agregar palabra" << endl;
    cout << "2. Buscar significado" << endl;
    cout << "3. Eliminar palabra" << endl;
    cout << "4. Ver todas las palabras" << endl;
    cout << "0. Salir" << endl;
    cout << "Selecciona una opcion: " << endl;
}

int main() {
    unsigned tamanio = 11;
    HashMap<string, string> diccionario(tamanio, HashString);
    int opcion;
    string palabra, significado;

    do {

        menu();
        cin >> opcion;

        switch (opcion) {

            case 1:

                cout << "\nIngrese la palabra: " << endl;
                cin >> palabra;
                cout << "Ingrese el significado: " << endl;
                cin.ignore();
                getline(cin, significado);

                try {
                    diccionario.put(palabra, significado);
                    cout << "Palabra agregada" << endl;
                } catch (int e) {
                    cout << "Colision, intente nuevamente" << endl;
                }
                break;

            case 2:

                cout << "\nIngrese la palabra: " << endl;
                cin >> palabra;

                try {
                    cout << "Palabra: " << palabra << endl;
                    cout << "Significado: " << diccionario.get(palabra) << endl;
                } catch (int e) {
                    cout << "Palabra no encontrada" << endl;
                }
                break;

            case 3:

                cout << "\nIngrese la palabra a eliminar: " << endl;
                cin >> palabra;

                try {
                    diccionario.remove(palabra);
                    cout << "Palabra eliminada" << endl;
                } catch (int e) {
                    cout << "Palabra no encontrada" << endl;
                }
                break;

            case 4:

                diccionario.print();
                break;

            case 0:

                cout << "\nSaliendo..." << endl;
                break;

            default:

                cout << "\nOpcion invalida" << endl;
        }
    } while (opcion != 0);

    return 0;
}

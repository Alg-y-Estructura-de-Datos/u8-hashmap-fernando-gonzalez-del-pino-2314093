#include <iostream>
#include "HashMap/HashMap.h"
using namespace std;

/*Sistema de votaciones
Objetivo: Crear un sistema de votaciones donde cada votante tiene un número de
identificación y vota por un candidato.
La clave será el número de identificación del votante y el valor será el nombre del candidato
por el que ha votado.
Implementa funciones para:
● Registrar un voto.
● Verificar por quién votó una persona (buscando por su ID).
● Eliminar un voto si fue incorrecto.
● Imprimir todos los votos registrados.
Puntos clave:
● Prevenir que un votante registre más de un voto.
● Mostrar un error si se intenta eliminar un voto no existente*/

void menu(){
    cout << "\n----Sistema de votaciones----" << endl;
    cout << "1. Registrar voto" << endl;
    cout << "2. Verificar voto" << endl;
    cout << "3. Eliminar voto" << endl;
    cout << "4. Ver todos los votos" << endl;
    cout << "0. Salir" << endl;
    cout << "Selecciona una opcion: " << endl;
}

int main() {
    unsigned tamanio = 11;
    HashMap<int, string> votos(tamanio);
    int opcion, id;
    string candidato;

    do {

        menu();
        cin >> opcion;

        switch (opcion) {

            case 1:

                cout << "\nIngrese el ID del votante: " << endl;
                cin >> id;
                cout << "Ingrese el nombre del candidato: " << endl;
                cin.ignore();
                getline(cin, candidato);

                try {
                    votos.put(id, candidato);
                    cout << "Voto registrado" << endl;
                } catch (int e) {
                    cout << "El votante ya ha registrado un voto" << endl;
                }
                break;

            case 2:

                cout << "\nIngrese el ID del votante: " << endl;
                cin >> id;

                try {
                    cout << "Candidato: " << votos.get(id) << endl;
                } catch (int e) {
                    cout << "El votante no ha registrado un voto" << endl;
                }
                break;

            case 3:

                cout << "\nIngrese el ID del votante: " << endl;
                cin >> id;

                try {
                    votos.remove(id);
                    cout << "Voto eliminado" << endl;
                } catch (int e) {
                    cout << "El votante no ha registrado un voto" << endl;
                }
                break;

            case 4:

                votos.print();
                break;

            default:

                cout << "\nOpcion invalida" << endl;
                break;
        }

    } while (opcion != 0);

    return 0;
}
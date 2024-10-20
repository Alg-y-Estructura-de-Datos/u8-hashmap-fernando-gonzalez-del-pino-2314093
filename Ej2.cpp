#include <iostream>
#include "HashMap/HashMap.h"
using namespace std;

/*Sistema de gestión de empleados. Usar HashMap para almacenar y gestionar empleados por
su número de identificación (ID).
● La clave será el número de identificación del empleado y el valor será su nombre.
● Implementa un menú con opciones para:
● Agregar un nuevo empleado.
● Buscar un empleado por su número de identificación.
● Eliminar un empleado del sistema.
● Imprimir la lista completa de empleados.*/

void menu(){
    cout << "\n----Gestion de empleados----" << endl;
    cout << "1. Agregar empleado" << endl;
    cout << "2. Buscar empleado" << endl;
    cout << "3. Eliminar empleado" << endl;
    cout << "4. Ver todos los empleados" << endl;
    cout << "0. Salir" << endl;
    cout << "Selecciona una opcion: " << endl;
}

int main() {
    unsigned tamanio = 11;
    HashMap<int, string> empleados(tamanio);
    int opcion, id;
    string nombre;

    do {

        menu();
        cin >> opcion;

        switch (opcion) {

            case 1:

                cout << "\nIngrese el ID del empleado: " << endl;
                cin >> id;
                cout << "Ingrese el nombre del empleado: " << endl;
                cin.ignore();
                getline(cin, nombre);

                try {
                    empleados.put(id, nombre);
                    cout << "Empleado agregado" << endl;
                } catch (int e) {
                    cout << "Colision, intente nuevamente" << endl;
                }
                break;

            case 2:

                cout << "\nIngrese el ID del empleado: " << endl;
                cin >> id;

                try {
                    cout << "Nombre: " << empleados.get(id) << endl;
                } catch (int e) {
                    cout << "Empleado no encontrado" << endl;
                }
                break;

            case 3:

                cout << "\nIngrese el ID del empleado: " << endl;
                cin >> id;

                try {
                    empleados.remove(id);
                    cout << "Empleado eliminado" << endl;
                } catch (int e) {
                    cout << "Empleado no encontrado" << endl;
                }
                break;

            case 4:

                empleados.print();
                break;

            case 0:
                cout << "\nSaliendo..." << endl;
                break;

            default:
                cout << "\nOpcion no válida" << endl;
                break;
        }

    } while (opcion != 0);

    return 0;
}

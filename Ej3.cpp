#include <iostream>
#include "HashMap/HashMap.h"
using namespace std;

/*Registro de productos en una tienda. Almacenar productos de una tienda usando un código
único como clave y el nombre del producto como valor. Usa el HashMap para almacenar los
productos. El código de producto es la clave y el nombre es el valor.
Implementa opciones para:
● Añadir productos.
● Buscar productos por su código.
● Actualizar el nombre de un producto existente.
● Eliminar productos.
● Imprimir todos los productos registrados.
● Desafío adicional: Implementa el manejo de colisiones, y lanza excepciones cuando se
intenten agregar productos con códigos ya existentes o buscar productos no
registrados*/

void menu(){
    cout << "\n----Registro de productos----" << endl;
    cout << "1. Agregar producto" << endl;
    cout << "2. Buscar producto" << endl;
    cout << "3. Actualizar producto" << endl;
    cout << "4. Eliminar producto" << endl;
    cout << "5. Ver todos los productos" << endl;
    cout << "0. Salir" << endl;
    cout << "Selecciona una opcion: " << endl;
}

int main() {
    unsigned tamanio = 11;
    HashMap<int, string> productos(tamanio);
    int opcion, codigo;
    string nombre;

    do {

        menu();
        cin >> opcion;

        switch (opcion) {

            case 1:

                cout << "\nIngrese el codigo del producto: " << endl;
                cin >> codigo;
                cout << "Ingrese el nombre del producto: " << endl;
                cin.ignore();
                getline(cin, nombre);

                try {
                    productos.put(codigo, nombre);
                    cout << "Producto agregado" << endl;
                } catch (int e) {
                    cout << "Colision, intente nuevamente" << endl;
                }
                break;

            case 2:

                cout << "\nIngrese el codigo del producto: " << endl;
                cin >> codigo;

                try {
                    cout << "Nombre: " << productos.get(codigo) << endl;
                } catch (int e) {
                    cout << "Producto no encontrado" << endl;
                }
                break;

            case 3:

                cout << "\nIngrese el codigo del producto: " << endl;
                cin >> codigo;
                cout << "Ingrese el nuevo nombre del producto: " << endl;
                cin.ignore();
                getline(cin, nombre);

                try {
                    productos.remove(codigo);
                    productos.put(codigo, nombre);
                    cout << "Producto actualizado" << endl;
                } catch (int e) {
                    cout << "Producto no encontrado" << endl;
                }
                break;

            case 4:

                cout << "\nIngrese el codigo del producto: " << endl;
                cin >> codigo;

                try {
                    productos.remove(codigo);
                    cout << "Producto eliminado" << endl;
                } catch (int e) {
                    cout << "Producto no encontrado" << endl;
                }
                break;

            case 5:

                productos.print();
                break;

            case 0:

                cout << "\nSaliendo..." << endl;
                break;

            default:

                cout << "\nOpcion no valida" << endl;
                break;
        }

    } while (opcion != 0);

    return 0;
}

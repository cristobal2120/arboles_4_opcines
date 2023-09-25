// ultimo gordo y yo
// codigo hecho por kevin perez y fernando perez
//estudiantes de la uniagustiniana
#include <iostream>

class NodoArbol {
public:
    int dato;
    NodoArbol* izquierda;
    NodoArbol* derecha;

    NodoArbol(int valor) {
        dato = valor;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

class ArbolBinario {
private:
    NodoArbol* raiz;

public:
    ArbolBinario() {
        raiz = nullptr;
    }

    void insertar(int valor) {
        raiz = insertarRec(raiz, valor);
    }

    NodoArbol* insertarRec(NodoArbol* nodo, int valor) {
        if (nodo == nullptr) {
            return new NodoArbol(valor);
        }

        if (valor < nodo->dato) {
            nodo->izquierda = insertarRec(nodo->izquierda, valor);
        } else if (valor > nodo->dato) {
            nodo->derecha = insertarRec(nodo->derecha, valor);
        }

        return nodo;
    }

    void eliminar(int valor) {
        raiz = eliminarRec(raiz, valor);
    }

    NodoArbol* eliminarRec(NodoArbol* nodo, int valor) {
        if (nodo == nullptr) {
            return nodo;
        }

        if (valor < nodo->dato) {
            nodo->izquierda = eliminarRec(nodo->izquierda, valor);
        } else if (valor > nodo->dato) {
            nodo->derecha = eliminarRec(nodo->derecha, valor);
        } else {
            if (nodo->izquierda == nullptr) {
                NodoArbol* temp = nodo->derecha;
                delete nodo;
                return temp;
            } else if (nodo->derecha == nullptr) {
                NodoArbol* temp = nodo->izquierda;
                delete nodo;
                return temp;
            }

            NodoArbol* sucesor = encontrarMinimo(nodo->derecha);
            nodo->dato = sucesor->dato;
            nodo->derecha = eliminarRec(nodo->derecha, sucesor->dato);
        }

        return nodo;
    }

    NodoArbol* encontrarMinimo(NodoArbol* nodo) {
        while (nodo->izquierda != nullptr) {
            nodo = nodo->izquierda;
        }
        return nodo;
    }

    NodoArbol* buscar(int valor) {
        return buscarRec(raiz, valor);
    }

    NodoArbol* buscarRec(NodoArbol* nodo, int valor) {
        if (nodo == nullptr || nodo->dato == valor) {
            return nodo;
        }

        if (valor < nodo->dato) {
            return buscarRec(nodo->izquierda, valor);
        } else {
            return buscarRec(nodo->derecha, valor);
        }
    }

    void preordenTraversal(NodoArbol* nodo) {
        if (nodo != nullptr) {
            std::cout << nodo->dato << " ";
            preordenTraversal(nodo->izquierda);
            preordenTraversal(nodo->derecha);
        }
    }

    void inordenTraversal(NodoArbol* nodo) {
        if (nodo != nullptr) {
            inordenTraversal(nodo->izquierda);
            std::cout << nodo->dato << " ";
            inordenTraversal(nodo->derecha);
        }
    }

    void posordenTraversal(NodoArbol* nodo) {
        if (nodo != nullptr) {
            posordenTraversal(nodo->izquierda);
            posordenTraversal(nodo->derecha);
            std::cout << nodo->dato << " ";
        }
    }

    void imprimirRecorridos() {
        std::cout << "Recorrido en preorden: ";
        preordenTraversal(raiz);
        std::cout << std::endl;

        std::cout << "Recorrido en orden: ";
        inordenTraversal(raiz);
        std::cout << std::endl;

        std::cout << "Recorrido en posorden: ";
        posordenTraversal(raiz);
        std::cout << std::endl;
    }

    void mostrarMenu() {
        char opcion;
        do {
            std::cout << "Menú:" << std::endl;
            std::cout << "1. Insertar valor" << std::endl;
            std::cout << "2. Eliminar valor" << std::endl;
            std::cout << "3. Buscar valor" << std::endl;
            std::cout << "4. Imprimir recorridos" << std::endl;
            std::cout << "5. Salir" << std::endl;
            std::cout << "Elija una opción: ";
            std::cin >> opcion;

            switch (opcion) {
                case '1': {
                    int valor;
                    std::cout << "Ingrese un valor para insertar en el árbol: ";
                    std::cin >> valor;
                    insertar(valor);
                    break;
                }
                case '2': {
                    int valorAEliminar;
                    std::cout << "Ingrese el valor que desea eliminar del árbol: ";
                    std::cin >> valorAEliminar;
                    eliminar(valorAEliminar);
                    break;
                }
                case '3': {
                    int valorABuscar;
                    std::cout << "Ingrese el valor que desea buscar en el árbol: ";
                    std::cin >> valorABuscar;
                    NodoArbol* resultado = buscar(valorABuscar);
                    if (resultado != nullptr) {
                        std::cout << "El valor " << valorABuscar << " se encuentra en el árbol." << std::endl;
                    } else {
                        std::cout << "El valor " << valorABuscar << " no se encuentra en el árbol." << std::endl;
                    }
                    break;
                }
                case '4': {
                    imprimirRecorridos();
                    break;
                }
                case '5':
                    std::cout << "Saliendo del programa." << std::endl;
                    break;
                default:
                    std::cout << "Opción no válida. Intente de nuevo." << std::endl;
                    break;
            }
        } while (opcion != '5');
    }
};

int main() {
    ArbolBinario arbol;
    arbol.mostrarMenu();
    return 0;
}

// codigo hecho por kevin perez y fernando perez
//estudiantes de la uniagustiniana
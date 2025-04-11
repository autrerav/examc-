//lab3ex2
//Escriba un programa que inserte números enteros del 1 al 12 en la cola. Mostrar todos los elementos contenidos en la cola.
//Muestra la longitud de la cola utilizando el sizemétodo.
//Borrar 5 elementos de la cola. Muestra todos los elementos contenidos en la cola y su longitud.
//Complete el programa con una función que limite la longitud de la cola a un valor dado,
//por ejemplo 6, y elimine los elementos que excedan el límite. Si se supera el límite, 
//la función debe mostrar información de que la cola está llena y el elemento se ha borrado.
//Usando la función, agregue 4 elementos a la cola.




#include <iostream>
#include <queue>
using namespace std;


void rellenarCola(queue<int> &cola) {
    for (int i = 1; i <= 12; ++i) {
        cola.push(i);
    }
}

void mostrarCola(queue<int> cola) {
    cout << "Elementos en la cola: ";
    while (!cola.empty()) {
        cout << cola.front() << " ";
        cola.pop();
    }
    cout << "Cola mostrada..." << endl;
}


void borrarCola(queue<int> cola , int n ) {
    for (int i = 0; i < n && !cola.empty(); ++i) {
        cola.pop();
    }
}

void consultarliimite(queue<int> &cola, int limite) {

    while (cola.size() > limite) {
        cout << "La cola ha superado el límite. Se elimina el elemento: " << cola.front() << endl;
        cola.pop();
    }
}

void agregarelementos(queue<int> &cola){
    for (int i = 13; i <= 16; ++i) {
        cola.push(i);
        
    }
    
}

int main() {
    queue<int> cola;
    
    rellenarCola(cola);
    cout << "Cola hecha" << endl;

    mostrarCola(cola);
    cout << "Longitud de la cola: " << cola.size() << endl;
    
    borrarCola(cola, 5);
    cout << "Borrando los elementos" << endl;
    
    mostrarCola(cola);
    cout << "Longitud de la cola: " << cola.size() << endl;
    
    consultarliimite(cola, 6);
    cout << "consultando el limite la cola" << endl;
    
    agregarelementos(cola);
    cout << "agregando elementos a la cola" << endl;

    consultarliimite(cola, 6);
    cout << "consultando el limite la cola" << endl;

    mostrarCola(cola);
    cout << "Longitud final de la cola: " << cola.size() << endl;
    
    return 0;
}
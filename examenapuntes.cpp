 1. Herencia con clases y métodos sobrescritos
cpp
Copiar
Editar
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sonido() {
        cout << "Este animal hace un sonido genérico." << endl;
    }
};

class Perro : public Animal {
public:
    void sonido() override {
        cout << "Guau guau!" << endl;
    }
};

int main() {
    Animal* a = new Perro();
    a->sonido();  // Muestra: Guau guau!
    delete a;
    return 0;
}
🔸 Importante: uso de virtual y override.

✅ 2. Manejo de colas con clases personalizadas y control de límite
cpp
Copiar
Editar
#include <iostream>
#include <queue>
using namespace std;

class Cliente {
public:
    string nombre;
    Cliente(string n) : nombre(n) {}
};

void agregarCliente(queue<Cliente>& cola, const string& nombre, int limite) {
    if (cola.size() >= limite) {
        cout << "La cola está llena. No se puede agregar más clientes." << endl;
    } else {
        cola.push(Cliente(nombre));
        cout << "Cliente agregado: " << nombre << endl;
    }
}

int main() {
    queue<Cliente> cola;
    int limite = 3;
    agregarCliente(cola, "Juan", limite);
    agregarCliente(cola, "Ana", limite);
    agregarCliente(cola, "Luis", limite);
    agregarCliente(cola, "Pedro", limite);  // excede límite

    return 0;
}
✅ 3. Leer números desde archivo y obtener máximo y mínimo
cpp
Copiar
Editar
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream archivo("numeros.txt");
    int n, maximo = INT_MIN, minimo = INT_MAX;

    while (archivo >> n) {
        if (n > maximo) maximo = n;
        if (n < minimo) minimo = n;
    }

    cout << "Máximo: " << maximo << ", Mínimo: " << minimo << endl;
    archivo.close();
    return 0;
}
🔸 Suelen pedir máximo, mínimo, promedio, etc.

✅ 4. Hilos ejecutando tareas diferentes
cpp
Copiar
Editar
#include <iostream>
#include <thread>
using namespace std;

void tarea1() {
    cout << "Tarea 1 ejecutándose..." << endl;
}

void tarea2() {
    cout << "Tarea 2 ejecutándose..." << endl;
}

int main() {
    thread t1(tarea1);
    thread t2(tarea2);

    t1.join();
    t2.join();
    return 0;
}
✅ 5. Clase que gestiona promedio de notas de estudiantes
cpp
Copiar
Editar
#include <iostream>
#include <vector>
using namespace std;

class Estudiante {
public:
    string nombre;
    vector<int> notas;

    Estudiante(string n, vector<int> ns) : nombre(n), notas(ns) {}

    double promedio() {
        int suma = 0;
        for (int nota : notas) suma += nota;
        return double(suma) / notas.size();
    }
};

int main() {
    Estudiante e("Carlos", {80, 75, 90});
    cout << "Promedio de " << e.nombre << ": " << e.promedio() << endl;
    return 0;
}
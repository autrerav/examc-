#include <iostream>
#include <thread>
#include <array>
#include <mutex>

std::mutex mtx;
int sumaTotal = 0;

void sumar(int valor, int veces) {
    for (int i = 0; i < veces; ++i) {
        std::lock_guard<std::mutex> lock(mtx); 
        sumaTotal += valor;
    }
}

int main() {
    std::array<int, 3> numeros = {1, 2, 3};
    const int veces = 5;

    std::thread t1(sumar, numeros[0], veces);
    std::thread t2(sumar, numeros[1], veces);
    std::thread t3(sumar, numeros[2], veces);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Suma total: " << sumaTotal << std::endl;

    return 0;
}

#include <iostream>
#include <thread>

void imprimirNumeros() {
    for (int i = 1; i <= 5; ++i) {
        std::cout << "Número: " << i << std::endl;
    }
}

int main() {
    std::thread hilo(imprimirNumeros);
    hilo.join();
    return 0;
}

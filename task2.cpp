#include <iostream>
#include <thread>
#include <vector>

void msgy(const std::string& mensaje) {
    std::cout << "Mensaje: " << mensaje << std::endl;
}

int main() {
    std::vector<std::string> mensajes = {"Hola", "Mundo", "desde", "varios", "hilos"};
    std::vector<std::thread> hilos;

    for (const auto& msg : mensajes) {
        hilos.emplace_back(msgy, msg);
    }

    for (auto& hilo : hilos) {
        hilo.join(); // Esperar a que terminen todos los hilos
    }

    return 0;
}

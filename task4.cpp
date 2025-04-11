#include <iostream>
#include <thread>

void mostrarID(const std::string& nombre) {
    std::cout << "ID del hilo [" << nombre << "]: " << std::this_thread::get_id() << std::endl;
}

int main() {
    std::cout << "ID del hilo principal: " << std::this_thread::get_id() << std::endl;

    std::thread t1(mostrarID, "Hilo 1");
    std::thread t2(mostrarID, "Hilo 2");

    t1.join();
    t2.join();

    std::cout << "Número de hilos soportados: " << std::thread::hardware_concurrency() << std::endl;

    return 0;
}

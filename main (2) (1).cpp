#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("data_in.txt");
    std::ofstream outputFile("data_out.txt");

    if (!inputFile) {
        std::cerr << "Error al abrir data_in.txt" << std::endl;
        return 1;
    }
    if (!outputFile) {
        std::cerr << "Error al abrir data_out.txt" << std::endl;
        return 1;
    }

    float num, sum = 0;
    int count = 0;
    
    while (inputFile >> num && count < 5) {
        sum += num;
        count++;
    }

    if (count == 0) {
        std::cerr << "No se encontraron valores válidos en el archivo." << std::endl;
        return 1;
    }

    float average = sum / count;
    outputFile << "Suma," << sum << "\nPromedio," << average << std::endl;

    inputFile.close();
    outputFile.close();
    
    std::cout << "Proceso completado. Verifique data_out.txt" << std::endl;
    return 0;
}

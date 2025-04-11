#include <iostream>
#include <fstream>
#include <map>
#include <vector>

const std::string SUBSTITUTION_ORDER = "eaoidhnrstuycfglmwbkp qxz.";

int main() {
    std::string filename = "message.txt";  // Nombre del archivo de texto
    std::ifstream file(filename);
    std::ofstream outputFile("decodemessage.txt");

    if (!file) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
     if (!outputFile) {
        std::cerr << "Error al abrir data_out.txt" << std::endl;
        return 1;
    }

    std::vector<char> char_list; 

    std::map<char, int> freq;
    char ch;
    while (file.get(ch)) {  
        freq[ch]++;
    }
    
    file.close();
    
    std::cout << "Frecuencia de caracteres en " << filename << ":\n";
    for (const auto& pair : freq) {
        std::cout << "'" << pair.first << "': " << pair.second << std::endl;
        char_list.push_back(pair.first);

    }
    std::map<char, char> substitution_map;
    size_t size = std::min(char_list.size(), SUBSTITUTION_ORDER.size());
    for (size_t i = 0; i < size; ++i) {
        substitution_map[char_list[i]] = SUBSTITUTION_ORDER[i];
    }
     // Leer el archivo nuevamente para realizar la sustitución
    file.open(filename);
    while (file.get(ch)) {
        if (substitution_map.find(ch) != substitution_map.end()) {
            outputFile.put(substitution_map[ch]);
        } else {
            outputFile.put(ch);
        }
    }
    file.close();
    outputFile.close();

    std::cout << "Proceso completado. Mensaje decodificado guardado en decodemessage.txt" << std::endl;
    return 0;

}
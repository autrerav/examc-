#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void expandAndReverse(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    if (!inFile) {
        std::cerr << "Error al abrir " << inputFile << std::endl;
        return;
    }
    
    std::vector<std::string> lines;
    std::string line;
    
    while (std::getline(inFile, line)) {
        std::string expandedLine;
        for (char c : line) {
            expandedLine += c;
            expandedLine += ' '; 
        }
        lines.push_back(expandedLine);
    }
    
    inFile.close();
    
    std::reverse(lines.begin(), lines.end());
    
    std::ofstream outFile(outputFile);
    if (!outFile) {
        std::cerr << "Error al abrir " << outputFile << std::endl;
        return;
    }
    
    for (const auto& expandedLine : lines) {
        outFile << expandedLine << '\n';
    }
    
    outFile.close();
    std::cout << "Archivo " << outputFile << " creado con éxito." << std::endl;
}

int main() {
    expandAndReverse("bird_up.txt", "bird_usdown.txt");
    return 0;
}

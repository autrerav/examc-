//lab2_e1.cpp
//Modify the program to derive the CNC class from the Machine class.
//Create a new CNC object in main. Add a message in the constructor of Machine and CNC to display "In the Machine constructor", "In the CNC constructor". Display the results.
//Call the print_description method from the created CNC object. What is displayed?

#include <iostream>
#include <string>
using namespace std;

class Machine {
private:
    string name = "general machine";

public:
    string description = "An instance of Machine class";
    Machine(string);
    void print_description();
};

Machine::Machine(string machine_name) {
    this->name = machine_name;
    cout << "Creating an object of the class "
               "Machine, with name: " << endl
            << " " << this->name << endl
            << "Description: "<< endl
            << " " << description << endl;

}

void Machine::print_description() {
    cout << "Machine description: " << description << endl;
}

class CNC : public Machine {
public:
    string description = "A computerized numerical control (CNC) machine";
    CNC(string);
    void print_description();
    void print_base_description();
};

CNC::CNC(string cnc_name) : Machine(cnc_name) {
    cout << "In the CNC constructor" << endl;
}

void CNC::print_description() {
    cout << "CNC description: " << description << endl;
}

void CNC::print_base_description() {
    Machine::print_description();
}

int main() {
    Machine hammer("super hammer");
    hammer.print_description();
    CNC cncMachine("CNC Model X");
    cncMachine.print_description();
    cncMachine.print_base_description();
    
    return EXIT_SUCCESS;
}

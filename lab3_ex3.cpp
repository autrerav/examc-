//lab03t3.cpp
//1.-Añade una función que:
    //agrega un nuevo elemento a la cola
    //aumenta el número único de solicitantes en espera
//2.-Añade una función que:
    //eliminar el elemento más antiguo de la cola
    //muestra un mensaje sobre el número actual de solicitantes en espera (número de solicitantes = tamaño de la cola -1)
//3.-Añade una función que:
    //comprueba si el tamaño de la cola ha excedido un cierto número; En tal caso, 
    //la función debería suspender la posibilidad de que se agreguen más solicitantes.
    //Muestra un mensaje sobre el servicio suspendido si el tamaño de la cola ha excedido un cierto número


#include <iostream>
#include <queue>
using namespace std;

class Applicant {
public:
  int applicant_num = 0;
  int time;
};

void agregarelementos(queue<Applicant> &eit){
    Applicant i; 
    eit.push(i);
    i.applicant_num += 1;  

}

void borrarCola(queue<Applicant> &eit ) {
    eit.pop();
    cout << "Tiempo de espera: " << eit.size() << endl;

}

int main() {
  queue<Applicant> eit;
  /* creating an Applicant object */
    agregarelementos(eit);
    agregarelementos(eit);
    agregarelementos(eit);
    agregarelementos(eit);

  
  /* creating a temporary Applicant object, to assign to it a
     reference returned by the method `back` */
     
  Applicant temp = eit.back();
  
  cout << "last applicant number: " << temp.applicant_num
       << ", queue size: " << eit.size() << endl;
  
  // alternative
  cout << "last applicant number: " << eit.back().applicant_num
       << ", queue size: " << eit.size() << endl;

  cout << "applicants waiting for service:  " << eit.size() - 1 << endl;
}
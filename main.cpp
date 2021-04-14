#include <iostream>
#include <fstream>
#include <stdexcept>
#include "queue.h"
#include "type.h"
using namespace std;

int main() {
  Queue<T1> s; 
  T1 opcion, x;

  do {
  
    cout<<"\n\nIntroduzca un número del 1 al 5 para realizar una acción: \n1. Agregar \n2. Remover \n3. Mostrar la cola \n4. Limpiar la consola \n5. Salir del meú "<<endl;

    cin>>opcion;

    switch(opcion)
    {
    case 1:
        cout<<"\nAgregue un valor a la cola"<<endl;  
        cin>>x;
        s.add(x);
        break;
    case 2:
        s.remove();
        break;
    case 3:
        cout<<"La cola es: "<<endl;
        s.mostrarcola();
        break;
    case 4:
        system("clear");
        break;
    case 5:
      break;
    default:
         cout<<"Error, ingresa un numero entre el 1 al 4"<<endl;
        break;
    }

  }while(opcion != 5);
  cout<<"Ha sido un placer"<<endl;
  return 0;
}
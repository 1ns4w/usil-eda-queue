#include <iostream>
#include <fstream>
#include <stdexcept>
#include <stdlib.h> //clear
#include <climits> //lipiando errores
#include "queue.h"
#include "Type.h"
using namespace std;



int main() {
  queue<T1> b; //creamos un objeto 
  T1 option, value;

  //creamos un menu para el usuario
  do
  {
    cout<<"\n\nQue operacion quieres hacer? Elija una opcion. Si ingresas 0 sales del menu."<<endl;
    cout<<"1. add()"<<endl;
    cout<<"2. remove()"<<endl;
    cout<<"3. isEmpty()"<<endl;
    cout<<"4. isFull()"<<endl;
    cout<<"5. count()"<<endl;
    cout<<"6. display()"<<endl;
    cout<<"7. Clear Screen()"<<endl<<endl;

    cin>>option;

    switch(option)
    {
    case 0:
        break;
    case 1:
        cout<<"add operation \nIngrese un numero para agregar en el Queue"<<endl;  
        cin>>value;
        while(cin.fail()) //prevenimos que el compilador explote por el caso que el usuario digite letras
        {
          cin.clear();
          cin.ignore(INT_MAX, '\n');
          cout<<"Error, igrese numeros"<<endl;
        }
        b.add(value);
        break;
    case 2:
        cout<<"remove operation \nNumero eliminado: "<< b.remove() <<endl;
        break;
    case 3:
        if (b.isEmpty())
          cout<<"Queue esta vacio"<<endl;
        else
          cout<<"Queue no esta vacio"<<endl;
        break;
    case 4:
        if (b.isFull())
          cout<<"Queue esta lleno"<<endl;
        else
          cout<<"Queue no esta lleno"<<endl;
        break;
    case 5:
        cout<<"Contador \nContando los numeros del Queue: "<<b.count()<<endl;
        break;
    case 6:
        cout<<"Visualizando el Queue - "<<endl;
        b.display();
        break;
    case 7:
        system("clear");
        break;
    default:
        cout<<"Error, ingresa un numero entre el 1 al 7"<<endl;
        break;
    }
  } while(option != 0);
  cout<<"Programa cerrado"<<endl;

  return 0;
  
}
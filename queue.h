#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
using namespace std;
#include "Type.h"


template <typename T>
class queue
{
  private:
    T front; // head 
    T rear; // back 
    T arr[5]; //cantidad de elementos que podemos tener
    T trackCount;
  public:

    queue() //constructor
    {
      //inicializamos en -1 para que este vacio
      trackCount = 0;
      front = -1; 
      rear = -1; 
      for (T i =0; i <size(arr); i++)
      {
        arr[i]=0; //comienza desde 0
      }
    }
    bool isEmpty(); //vacio
    bool isFull(); //lleno
    void add(T &elem); //agregamos elementos
    T remove(); //eliminamos elementos
    T count(); //contamos los elementos que tenemos
    void display(); //nos muestra los elementos
};


template <typename T>
bool queue<T>::isEmpty()
  {
    if (front == -1 && rear == -1) //vacio ya que el arr comienza desde 0
        return true;
    else
        return false;
  }

template <typename T>
bool queue<T>::isFull()
  {
    if ((rear+1)%size(arr) == front) //esta lleno si tiene la misma cantidad que el arr/ size(arr) = 4
        return true;
    else
        return false;
  }

template <typename T>
void queue<T>::add(T &elem) 
  {
    if (isFull())
    {
    cout<<"It is full"<<endl;
    return;
    }
    else if (isEmpty())
    {
      //Primer numero agregado
      rear = 0; //no hay numeros entonces comienza desde el 0
      front = 0; //no hay numeros
      arr[rear]=elem; //rear o front funciona
      trackCount++;
    }
    else
    {
      //Desde dos o mas numeros implementados
      rear = (rear+1)%size(arr); //aumenta +1
      arr[rear]=elem;
      trackCount++;
    }
  }
template <typename T>
T queue<T>::remove()
  {
    T x;
    if(isEmpty())
    {
      cout<<"It is empty"<<endl;
      return 0;
    }
    else if (front == rear) //Pasa cuando tienes un elemento
    {
      x = arr[front];
      //Vacio totalmente
      front = -1;
      rear = -1;
      trackCount--;
      return x;
    }
    else 
    {
      //ocurre cuando ya eliminaste el primer elemento
      x = arr[front]; //eleminate el elemento
      arr[front]=0; 
      front = (front+1)%size(arr); // avanza a la siguiente posicion
      trackCount--;
      return x;
    }
  }

  template <typename T>
  T queue<T>::count()
  {
    return trackCount;
  }

  template <typename T>
  void queue<T>::display()
  {
    cout<<"Los elementos del Queue son: "<<endl;
    for(T i = 0; i < size(arr); i++)
    {
      cout<< arr[i]<< " ";
    }
  }
#endif
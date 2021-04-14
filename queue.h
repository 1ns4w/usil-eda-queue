#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
using namespace std;
#include "Type.h"

const T1 num=5;
template <typename T>
class Queue
{
  private:
    size_t m_front, m_rear; 
    T arr[num];
  public:
    Queue()
    { m_front = -1; 
      m_rear = -1; 
      for (T i =0; i <size(arr); i++) 
      {
        arr[i]=0;
      }
    }
    ~Queue(){}
    bool isEmpty(); //vacio
    void add(T &elem); //agregamos elementos
    T remove(); //eliminamos elementos
    void mostrarcola(); //nos muestra los elementos
};
template <typename T>
bool Queue<T>::isEmpty()
  {
    if (m_front == -1 && m_rear == -1)
        return true;
    else
        return false;
  }

template <typename T>
void Queue<T>::add(T &elem) 
  {
    if ((m_rear+1)%num==m_front)
    {
    throw out_of_range("La cola está llena");
    }
    else if (m_rear==num-1)
    {throw out_of_range("La cola está llena");}
    else if (isEmpty())
    {
      m_rear = 0; 
      m_front = 0; 
      arr[m_rear]=elem; }
    else
    {m_rear = (m_rear+1)%size(arr);
      arr[m_rear]=elem;}
  }
  
template <typename T>
T Queue<T>::remove()
  {
    if(isEmpty())
    {throw out_of_range("La cola está vacia");
      return 0;}
    else if (m_front == m_rear) 
    {
      m_front = m_rear = -1;
      return -1;
    }
    else 
    { arr[m_front]=0; 
      m_front = (m_front+1)%num; 
      return 0;}
  }

template <typename T>
  void Queue<T>::mostrarcola()
  {
    cout<<"Los elementos del Queue son: "<<endl;
    if (isEmpty()){
      cout<<"La cola está vacia"<<endl;}
    else {
      T i; 
      if (m_front<=m_rear){
        for (i=m_front; i<=m_rear; i++)
        cout<<arr[i]<<" ";
      } else {
        i=m_front;
        while (i<num){
          cout<<arr[i]<<" ";
          i++;
        }
        i=0;
        while(i<=m_rear){
          cout<<arr[i]<<" ";
        }
      }

    }
  }

#endif

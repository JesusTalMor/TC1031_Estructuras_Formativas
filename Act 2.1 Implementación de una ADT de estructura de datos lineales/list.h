/*
 * list.h
 * Creado el: 27/09/2020
 * Author: Jesus Talamantes Morales A01706335
 */

#ifndef LIST_H_
#define LIST_H_

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <class T> class List;

template <class T>
class Conector{
private:
  //Constructores
  Conector(T);
  Conector(T, Conector<T>*);

  //atributos
  T valor;
  Conector<T> *sigui;

  friend class List<T>;
};
//Contructores desarrollados
template <class T>
Conector <T>::Conector(T val) : valor(val), sigui(0){}

template <class T>
Conector<T>::Conector(T val, Conector* nxt) : valor(val), sigui(nxt){}

template <class T>
class List{
private:
  Conector<T> *princip;
  int tama;
public:
  //Constructor
  List();

  void addFirst(T);
  bool vacio();
  void add(T);
  void update(int,T);
  void remove(int);
  int find(T);
  std::string toString() const;
};

//Constructor desarrollado
template <class T>
List<T>::List() : princip(0), tama(0) {}

/*Función addFirst*/
template <class T>
void List<T>::addFirst(T val){
  Conector<T> *newConect;

  newConect = new Conector<T>(val);
  newConect->sigui = princip;
  princip = newConect;
  tama ++;
}

/*Funcion auxiliar vacio*/
template <class T>
bool List<T>::vacio(){
  return (princip == 0);
}

/*Funcion add completa*/
template <class T>
void List<T>::add(T val){
  Conector<T> *newConect, *aux;

  newConect = new Conector<T>(val);
  if(vacio()){
    addFirst(val);
    return;
  }

  aux = princip;
  while(aux->sigui != 0){
    aux = aux->sigui;
  }

  newConect->sigui = 0;
  aux->sigui = newConect;
  tama++;
}

/*Funcion update*/
template <class T>
void List<T>::update(int pos, T val){
  Conector<T> *aux;
  int busq = 0;
  aux = princip;
  while(busq != pos){
    aux = aux->sigui;
    busq++;
  }
  aux->valor = val;
}

/*Funcion remove*/
template <class T>
void List<T>::remove(int pos){
  Conector<T> *aux, *aux2;
  int busq = 0;
  aux = princip;
  aux2 = 0;

  if(pos == 0){
    princip = aux->sigui;
    delete aux;
    tama --;
    return;
  }

  while(busq != pos){
    aux2 = aux;
    aux = aux->sigui;
    busq++;
  }
  aux2->sigui = aux->sigui;
  tama --;

  delete aux;
}
/*Funcion find*/
template<class T>
int List<T>::find(T val){
  Conector<T> *aux;
  int pos =  0;

  aux = princip;
  while(aux->valor != val){
    if(aux->sigui != 0){
      aux = aux->sigui;
      pos ++;
    }
    else{
      return -1;
    }
  }
  return pos;
}

/*Funcion toString*/
template <class T>
std::string List<T>::toString() const {
  std::stringstream cadena;
  Conector<T> *aux;

  aux = princip;
  cadena << "[";
  while (aux != 0){
    cadena << aux->valor;
    if(aux->sigui != 0){
      cadena << ", ";
    }
    aux = aux->sigui;
  }
  cadena << "]";
  return cadena.str();
}


#endif /* LIST_H_ */

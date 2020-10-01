/*
 * dlist.h
 * Creado el: 29/09/2020
 * Autor: Jesus Talamantes Morales A01706335
 */

#ifndef DLIST_H_
#define DLIST_H_

#include <string>
#include <sstream>

using namespace std;

template <class T> class DList;

template <class T>
class DLink {
private:
  //Constructores
  DLink(T);
  DLink(T,DLink<T>*,DLink<T>*);

  T value;
  DLink<T> *previous;
  DLink<T> *next;

  friend class DList<T>;
};

//Constructor basico
template <class T>
DLink<T>::DLink(T val): value(val), previous(0), next(0) {}

//Constructor comun
template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink *nxt): value(val), previous(prev), next(nxt) {}

template <class T>
class DList {
private:
  DLink<T> *head;
  DLink<T> *tail;
  int size;

public:
  //Constructor
  DList();

  //Funciones principales de la clase
  void add(T);
  T find(T);
  void update(int,T);
  void remove(int);
  std::string toStringForward() const;
  std::string toStringBackward() const;

  //Funciones auxiliares de la clase
  bool empty() const;
  int get_size() {return size;}
};
//Constructor clase lista
template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}

/*Funcion empty()*/
template <class T>
bool DList<T>::empty() const{
  return (head == 0 && tail == 0);
}


/*Funcion add()*/
template <class T>
void DList<T>::add(T val){
  DLink<T> *newLink;
  newLink = new DLink<T>(val);

  if(empty()) {
    head = newLink;
    tail = newLink;
  } else {
    tail->next = newLink;
    newLink->previous = tail;
    tail = newLink;
  }
  size ++;
}

/*Funcion find()*/
template <class T>
T DList<T>::find(T val){
  DLink<T> *aux;
  int pos = 0;

  aux = head;
  while(aux->value != val){
    if(aux->next != 0){
      aux = aux->next;
      pos ++;
    }
    else{return -1;}
  }
  return pos;
}

/*Funcion update()*/
template <class T>
void DList<T>::update(int pos, T valor){
  DLink<T> *aux;
  int busq = 0;
  aux = head;
  if(pos >= size){
    return;
  }
  while(busq != pos){
    aux = aux->next;
    busq++;
  }

  aux->value =valor;
}

/*Funcion remove()*/
template <class T>
void DList<T>::remove(int pos){
  DLink<T> *aux;
  int busq = 0;
  aux = head;

  if(pos == 0){
    aux = head;
    head = aux->next;
    aux->next->previous = 0; //validacion para que no apunte a basura
    delete aux;
    size --;
    return;
  }

  if(pos == size - 1){
    aux = tail;
    tail = aux->previous;
    aux->previous->next = 0;
    delete aux;
    size --;
    return;
  }

  while(busq != pos){
    aux = aux->next;
    busq ++;
  }

  aux->next->previous = aux->previous;
  aux->previous->next = aux->next;
  delete aux;
  size --;
}

/*Funcion toStringForward()*/
template <class T>
std::string DList<T>::toStringForward() const {
  std::stringstream aux;
  DLink<T> *p;

  p = head;
  aux << "[";
  while (p != 0) {
    aux << p->value;
    if (p->next != 0) {
      aux << ", ";
    }
    p = p->next;
  }
  aux << "]";
  return aux.str();
}

/*Funcion toStringBackward*/
template <class T>
std::string DList<T>::toStringBackward() const {
  std::stringstream aux;
  DLink<T> *p;

  p = tail;
  aux << "[";
  while (p != 0) {
    aux << p->value;
    if (p->previous != 0) {
      aux << ", ";
    }
    p = p->previous;
  }
  aux << "]";
  return aux.str();
}



#endif /* LIST_H_ */

/*
 * minheap.h
 *  Created on: 15/10/2020
 *      Author: Jesus Talamantes Implementacion
 */

#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <sstream>
#include <iostream>

template <class T>
class Heap {
private:
  T *dato;
  unsigned int tamanio; //Unsigned es un int sin bit mas significativo
  unsigned int cuenta;
  unsigned int papa(unsigned int) const;
  unsigned int izq(unsigned int) const;
  unsigned int der(unsigned int) const; //No tengo idea
  void heapify(unsigned int); //Funcion para arreglar el heap
  void swap(unsigned int, unsigned int); //Funcion auxiliar
public:
  //Constructor principal
  Heap(unsigned int);
  bool empty() const; //Metodos de revision
  void push(T); //Añade un elemento al heap
  void pop(); //Quita el elemento menor
  unsigned int size(); //Puede const
  T top();
  std::string toString() const;
};

template <class T>
Heap<T>::Heap(unsigned int tama) {
  tamanio = tama;
  dato = new T[tamanio]; //arreglo de apuntadores
  cuenta = 0;
}

template <class T>
bool Heap<T>::empty() const {
  return (cuenta == 0);
}

template <class T>
unsigned int Heap<T>::size() {
  return cuenta;
}

template <class T>
T Heap<T>::top(){
  return (dato[0]);
}

template <class T>
unsigned int Heap<T>::papa(unsigned int pos) const{
  return (pos -1) / 2;
}

template <class T>
unsigned int Heap<T>::izq(unsigned int pos) const{
  return ((2 * pos) + 1);
}

template <class T>
unsigned int Heap<T>::der(unsigned int pos) const{
  return ((2 * pos) + 2);
}

template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
  T aux = dato[i];
  dato[i] = dato[j];
  dato[j] = aux;
}

template <class T>
void Heap<T>::heapify(unsigned int pos) {
  unsigned int iz = izq(pos);
	unsigned int de = der(pos);
	unsigned int min = pos;
	if (iz <= cuenta && dato[iz] < dato[min]) {
		min = iz;
	}
	if (de <= cuenta && dato[de] < dato[min]) {
		min = de;
	}
	if (min != pos) {
		swap(pos, min);
		heapify(min);
	}
}

template <class T>
void Heap<T>::push(T val) {
  unsigned int pos;

  pos = cuenta;
  cuenta++;
  while (pos > 0 && val < dato[papa(pos)]) {
    dato[pos] = dato[papa(pos)];
    pos = papa(pos);
  }
  dato[pos] = val;
}

template <class T>
void Heap<T>::pop() {
  dato[0] = dato[--cuenta]; //Ultimo dato agregado
  heapify(0);
}

template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;
	aux << "[";	for (unsigned int i = 0; i < cuenta; i++) {
		if (i != 0) {
			aux << " ";
		} aux << dato[i];
	} aux << "]";
	return aux.str();
}

#endif /*HEAP_H_*/

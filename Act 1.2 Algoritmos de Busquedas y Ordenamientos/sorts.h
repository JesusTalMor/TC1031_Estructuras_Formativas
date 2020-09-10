/*
 *  Act 1.2 Algoritmos de Busquedas y Ordenamientos
 *  Author: Jesus David Talamantes Morales
 *               A01706335
 *  Created on: 09/09/2020
 */

#ifndef SORTS_H_
#define SORTS_H_

#include <iostream>
#include <vector>
#include <list>

template <class T>
class Sorts {
private:
  void swap(std::vector<T>&, int, int);
  void prueba(std::vector<T>&);
  void separaMerge(std::vector<T>&, std::vector<T>&, int, int);
  void arregloMerge(std::vector<T>&, std::vector<T>&, int, int, int);
  void copiarArreglo(std::vector<T>&, std::vector<T>&, int, int);
public:
  void ordenaSeleccion(std::vector<T>&);
  void ordenaBurbuja(std::vector<T>&);
  void ordenaMerge(std::vector<T>&);
  int busqSecuencial(std::vector<T>&, T);
  int busqBinaria(std::vector<T>&, T);

};

//Funciones auxiliares
template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j){
  T aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}

template <class T>
void Sorts<T>::prueba(std::vector<T> &fuente){
  for(int x = 0; x < fuente.size() - 1; x++){
    std::cout << fuente[x] <<" ";
  }
  std::cout << std::endl;
}

template <class T>
void Sorts<T>::copiarArreglo(std::vector<T> &A, std::vector<T> &B, int low, int high){
  for(int i = low; i <= high; i++) {
    A[i] = B[i];
  }
}

template <class T>
void Sorts<T>::ordenaSeleccion(std::vector<T> &fuente) {
  int pos;

  for (int i = 0; i <= fuente.size() - 1; i ++){ //Contador para repara el arreglo
    pos = i;
    for(int j = i + 1; j <= fuente.size() - 1; j++){
      if(fuente[pos] > fuente[j]){
        pos = j;
      }
    }
      swap(fuente, i, pos);
  }
  prueba(fuente);
} //Terminado

template <class T>
void Sorts<T>::ordenaBurbuja(std::vector<T> &fuente){
  for(int i = fuente.size() - 1; i > 0; i--){
    for(int j = 0; j < i; j++){
      if(fuente[j] > fuente[j + 1]){
        swap(fuente, j, j + 1);
      }
    }
  }
  prueba(fuente);
} //Completado

template <class T>
void Sorts<T>::arregloMerge(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high){
  int i, j, k;
  i = low;
  j = mid + 1;
  k = low;

  while (i <= mid && j <= high) { //Evita que se pase a subpartes del arreglo
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) { //Aca se revisa que contador salio del rango y copia los
		for (; j <= high; j++) { //elementos restantes
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i]; //Primero realiza la opreción y luego suma
		}
	}
}

template<class T>
void Sorts<T>::separaMerge(std::vector<T> &A, std::vector<T> &B, int low, int high){
  int mid;

	//CASO BASE
	if ( (high - low) < 1 ) { //Cuando solo se tiene un elemento
		return;								  //comparando los indices cuando sean menor a 1 = 0
	}
	//Caso General Split
	mid = (high + low) / 2; //Da la mitad del array para partir redondea 3.5 a 3
	//Llamada recursiva
	//En lugar de generar un nuevo arreglo lo divide por medio de parametros
	separaMerge(A, B, low, mid); //Divide la rama izquierda del array
	separaMerge(A, B, mid + 1, high); //Divide la rama derecha del array
	arregloMerge(A, B, low, mid, high); //Arregla el array un merge cada 2 splits
	copiarArreglo(A, B, low, high);
}

template <class T>
void Sorts<T>::ordenaMerge(std::vector<T> &fuente){
  std::vector<T> temp(fuente.size());

  separaMerge(fuente, temp, 0, fuente.size() - 1);
  prueba(fuente);
}

template <class T>
int Sorts<T>::busqSecuencial(std::vector<T> &fuente, T valor){
  int confirm = 0;
  for(int i = 0; i < fuente.size(); i++){
    if(fuente[i] == valor){
      confirm = i;
    }
  }
  if(confirm != 0){
    return confirm;
  }
  else{
    return -1;
  }
}

template <class T>
int Sorts<T>::busqBinaria(std::vector<T> &fuente, T valor){
  int mid;
  int low = 0;
  int high = fuente.size() - 1;

  while (low < high){
    mid = (high + low) / 2;
    if (valor == fuente[mid]){
      return mid;
    } else if (valor < fuente[mid]){
      high = mid - 1;
    } else if (valor > fuente[mid]){
      low = mid + 1;
    }
  }
  return low;
}

#endif /* SORTS_H_ */

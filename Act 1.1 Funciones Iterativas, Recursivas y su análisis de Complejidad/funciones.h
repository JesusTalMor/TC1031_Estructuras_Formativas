/*
 *  Act. 1.1 Act 1.1 Funciones Iterativas, Recursivas y su análisis de Complejidad
 *  Author: Jesus David Talamantes Morales
 *               A01706335
 *  Created on: 27/08/2020
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include<iostream>

using namespace std;

class funciones{
  public:

    int sumaIterativa(int n){
      int suma_total = 0;
      for(int i=0; i<=n ; i++){
        suma_total = suma_total + i;
      }
      return suma_total;
    }

    int sumaRecursiva(int n){
      //Caso base
      if(n == 0) {
        return 0;
      }
      else{
        return n + sumaRecursiva(n-1);
      }
    }

    int sumaDirecta(int n){
      int resultado = 0;
      resultado = (n*(n + 1))/2;
      return resultado;
    }
};

#endif // FUNCIONES_H

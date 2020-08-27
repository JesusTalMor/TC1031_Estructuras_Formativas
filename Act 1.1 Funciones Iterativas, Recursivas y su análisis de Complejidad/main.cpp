/*
 * main.cpp
 *
 *  Created on: 26/08/2020
 *      Author: Jesus David Talamantes Morales
 */

#include <iostream>
#include "funciones.h"

using namespace std;

int main(int argc, char* argv[]) {
	funciones fun;
	int i = 20;

	/*	inician en el el renglon 20 para que el primer test 0 sea
	en el renglon 20 el test 1->21 y el n->20+n	*/

	cout << i++ << " " << ((36 == fun.sumaIterativa(8)) ? "success\n" : "fail\n");
	cout << i++ << " " << ((36 == fun.sumaRecursiva(8)) ? "success\n" : "fail\n");
	cout << i++ << " " << ((36 == fun.sumaDirecta(8)) ? "success\n" : "fail\n");
	cout << i++ << " " << ((0 == fun.sumaIterativa(0)) ? "success\n" : "fail\n");
	cout << i++ << " " << ((0 == fun.sumaRecursiva(0)) ? "success\n" : "fail\n");
	cout << i++ << " " << ((0 == fun.sumaDirecta(0)) ? "success\n" : "fail\n");
	cout << i++ << " " << ((1 == fun.sumaIterativa(1)) ? "success\n" : "fail\n");
	cout << i++ << " " << ((1 == fun.sumaRecursiva(1)) ? "success\n" : "fail\n");
	cout << i++ << " " << ((1 == fun.sumaDirecta(1)) ? "success\n" : "fail\n");
}

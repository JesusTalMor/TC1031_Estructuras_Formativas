# Análisis de Complejidad Asíntotica

*Suma Interativa*

Esta función presenta una complejidad lineal de O(n):
n es el número hasta el cual se quiere hacer las interaciones dentro de las cuales se entra en un ciclo igual al número de datos dando una complejidad de O(n) y dentro del ciclo se encuentran intrucciones independientes al numero de datos dando una complejidad de O(1) y al multiplicar ambas complejidades obtenemos que la mayor complejidad tomando el peor de los casos es O(n).

*Suma Recursiva*

Esta función al igual que la anterior presenta un complejidad de O(n):
n siendo el numero de pasos que realiza la función en la cual la función inicia con un número mayor a 0 y dentro de la función por medio de recusividad se realiza ciclos donde se realizan ciclos de n hasta llegar a 0 dando una complejidad de O(n).

*Suma directa*
Esta función presenta una complejidad de O(1) constante:
Ya que sin importar el numero de n la acción siempre se realiza en un paso debido a la fórmula de (n*(n-1)/2) dando el resultado directo en un número de pasos de 1, sin importar si el número es de 8 o 10000.

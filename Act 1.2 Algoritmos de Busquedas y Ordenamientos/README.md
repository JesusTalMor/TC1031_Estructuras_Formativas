# Act 1.2 Análisis de Complejidad Asintótica

## Ordenamiento de Arreglos

*Ordenar un arreglo por el método de selección (selectionSort)*

Esta función presenta una complejidad cuadrada de O(n^2):

Esto se demuestra de esta manera ya que la forma en la que opera es con un duó de ciclos for anidados los cuales funcionan en base al tamaño de n (donde n representa el número de elementos del arreglo). Entonces al estar dos ciclos for anidados se puede ver que se tiene una multiplicación de n*n lo cual da la complejidad de n^2 a la función.

Aunque un punto a recalcar dentro de la función es que en realidad se redondea a n^2, ya que la función en si va descartando los espacios en los cuales ya se ha acomodado el arreglo. Un ejemplo es que en un arreglo de 10 elementos se tiene el primer ciclo for inciado de 0 a 10 y el segundo de 1 a 10, pero al terminar la primera corrida y al acomodar el elemento de la posicion 0. El arreglo pasa ahora de 1 a 10 y el segundo de 2 a 10. Reduciendo la complejidad pero despues de todo se rendondea la complejidad a O(n^2).

*Ordenar un arreglo por el método de burbuja (bubbleSort)*

Esta función presenta una complejidad cuadrada de O(n^2):

Esto se demuestra de la misma manera que el caso de "selectionSort" por medio de 2 ciclos for anidados los cuales dependen del numero de elementos dentro del arreglo dado, dando una complejidad de n * n la cual da la complejidad de n^2.

Al igual que el caso particular anterior en esta función como tal su comportamiento se acerca mucho mas a n^2 aunque se trate de una función como en el caso anterior en la cual va disminuyendo el número de repeticiones conforme se ordena el arreglo, al igual que en el ejemplo anterior pero en este caso en lugar de iniciar como en el ejemplo de 0 a 10 y el segundo de 1 a 10, este se comporta restando los elementos acomodando primero los mayores dando el primer ciclo anidado después de acomodar el primer elemento de 0 a 9 y el segundo 0 a 8 sucesivamente.

*Ordenar un arreglo por el metodo de split y merge (mergeSort)*

Esta función presenta una complejidad de O(n*log(n)):

Esto se demuestra en la naturaleza de que es una función recursiva la cual se encarga una función en separar al arreglo en subarreglo que son la mitad del arreglo principal, y al hacer esto presenta una complejidad de O(n/2) que se convertirá en una complejidad de O(log(n)). Por último se encuentra la segunda parte de la función principal que es la parte de merge que se basa en convinar y acomodar los subarreglos formados por la función split dando como resultado que tenga una complejidad de O(n), por último al multiplicar ambas complejidades dando O(log(n)) * O(n) = O(n*log(n)).



## Busquedas dentro de Arreglos

*Busqueda secuencial*

Esta función presenta una complejidad de lineal O(n):

Esto se demuestra en la forma en la cual opera la función con tan solo un ciclo for que se basa en el número de elementos y el cual se detiene en el momento en el que encuentra el elemento o termina de recorrer el ciclo concluyendo que no existe el elemento que se quiere buscar. En general esta función no toma ramificaciones a diferencia de la busqueda binaria ya que, aunque cuenta con sentecias if() estas no crean ramificaciones como los son con el caso de usar if() y else if().

*Busqueda binaria*

Esta función presenta una complejidad de O(log(n)):

Esta función demuestra esta complejidad por la forma en la que opera, ya que genera arboles de ramificaciones las cuales le hacen realizar una cantidad excesiva menor de pasos que en el caso de la secuencial en la cual se debe el número de pasos es lineal al número de elementos del arreglo. La forma en la que funciona es que por medio del uso de la sentencia if() y else if() la función va descartando partes del arreglo para llegar a la solución en una menor cantidad de pasos ya que siempre empieza en la parte media del arreglo y dependiendo del si el valor es mayor o menor a la referencia central (o en el caso de que sea igual ahí se detiene la función), la función toma la mitad ya sea la mayor o la menor e ignora a la otra mitad logrando de esta manera eliminar pasos innecesarios y disminuir la complejidad de O(n) a O(log(n)). Ya que de manera matemática tenemos una O(n/2^k), ya que constantemente como se mencionó en el análisis se va partiendo a la mitad el arreglo.

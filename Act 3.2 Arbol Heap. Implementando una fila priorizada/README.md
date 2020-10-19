# Analisis Asintotico de Comlpejidad
## Función push()
La complejidad que presenta esta función es una complejidad media de O(log n), ya que la forma en la que funciona es que va revisando con la ayuda de la función auxiliar de papa() la cual retorna el padre relacionado con la posición en la que se quiere insertar el nuevo valor. El cual si el valor que se quiere insertar es menor que el papa, se realiza un pequeño swap para intercambiar al padre con el hijo y asi mantener la estructura mínima de la estructura heap. Y regresando a la complejidad como la función realiza salto de 2 ignorando la mitad de los elementos se mantiene con una complejidd de O(log n)

## Función pop()
La complejidad de esta función al igual que la función anterior es que presenta una complejidad de O(log n), debido a que la forma en la que opera es con el uso de la función auxiliar heapify() la cual organiza y mantiene la estructura minima del arbol heap, la complejidad en si sale de esta función la cual entre el padre y sus 2 hijos con cual debe realizar un swap para mantener la estructura, por lo que siempre sigue un camino que va dividiendo el arreglo entre 2 dando asi la complejidad de O(log n), en todos los casos posibles.

## Función top()
La complejidad que presenta esta función es una complejidad de O(1) o una complejidad constante, ya que se trata de una consulta de el dato que se encuentra al principio y solo se realiza en una operación de el dato que se encuentra en la primera posición del arreglo *dato[0]*.

## Función empty()
La complejidad que presenta esta función al igual que la anterior es de O(1) ya que se trata de una consulta inmediata de un atributo de la clase Heap() el cual es cuenta y solo se realiza la operación de *(Cuenta == 0)*, regresando de esta manera un valor booleano.

## Función size()
La complejidad que presenta esta función es exactamente igual que el anterior de O(1) ya que se consulta el valor que tiene el atributo de cuenta, dando en un paso el valor de cuenta.

# Analisis de Asintotico de Complejidad
## Función add()

Para esta función se divide en 2 casos el primero en el cual se quiera añadir un elemento cuando no existen ninguno en la lista en el cual se hara uso de la función secundaria addFirst(), la cual solo realiza una acción inicial la cual de da la complejidad de O(1). Pero ya que se esta tomando el peor de los casos en el cual ya se encuentran elementos en la lista, la función add recorrerá todos los elementos hasta llegar al final donde se aloja el nuevo objeto dando una complejidad de O(n) para el recorrido y O(1) para la creación del objeto y al multiplicarlos da como resultado una complejidad final de O(n).

## Funcion update()

Dentro de esta función se realiza en 2 etapas la primera que es buscar la posición seleccionada y la segunda remplazar el valor, al igual que en el caso anterior en el peor de los casos en el cual se quiera modificar el ultimo elemento del arreglo se tendrá una complejidad de O(n) y para el caso de reemplazar el valor este da una complejidad de O(1) en todos los casos dando una complejidad final de O(n).

## Función remove()

Esta función es parecida a la anterior solo que en este caso se tiene un condicional para cuando se quiera borrar el primer elemento del arreglo dando una complejidad para este caso de O(1) ya que no se recorre el arreglo y solo se borra el objeto en 1 paso, pero en el peor de los casos se tendra que recorrer todo el arreglo de n para conseguir ubicar la posicion y borrarla dando una complejidad conjunta de O(n).

## Función Find()
Para este función se aplica los casos similares anteriormente mencionados para las funciones remove() y update() dando una complejidad de O(n), en el peor de los casos en el cual recorra todo el arreglo para encontrar el valor que se busca.

## Función toString()
Esta función en el mejor y peor de los casos siempre presentará una complejidad de O(n), ya que para realizarla esta función debe leer todos los datos dentro del arreglo de objetos para obtener el valor e integrarlo a una cadena de caracteres.

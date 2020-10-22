# Análisis Asintotico de Complejidad
## Función add()
Inciando con la complejidad de esta función tenemos que analizar la forma en la que se comporta esta función lo que hace es que realiza un add de manera común como si fuese un bst común por lo cual comparte la misma complejidad que este, ya que no se puede estimar de ninguna manera que el arbol no se convierta en un arbol degenerado, la comlpejidad en el peor de los casos de la parte de add es de O(n), por otro lado tenemos la segunda función la cual es splay(), esta función siempre se realiza al finalizar alguna operación y consiste en realizar rotaciones entre el padre, y el abuelo y el hijo, hasta que el hijo llegue a ser la raíz. Por lo tanto se puede ver que en la primeras interaciones de esta funcíon se presentará un numero de n veces por lo tanto da una complejidad de O(n), pero ya que mientras mas veces se esten usando esta función y mas veces se esten usando la función splay, el arbol empezará a auto balancearse de esta forma presentando para ambas funciones una complejidad promedio de O(log n), la cual se queda de esta misma manera.

## Función remove()
Esta función se comporta de la misma manera que un find, donde primero busca en todo el arbol el objeto a borrar y guarda a su pariente para posteriormente usar el metodo Bottom-up para borrarlo y posteriormente realizar un splay en el padre del objeto que se borró, y como se mencionó anteriormente, la forma general en la que opera un SplayTree es con una complejidad inicial que es lineal O(n), pero debido a los splay se va realizando un auto balanceo del arbol manteniendo en este caso una complejidad de O(log n), para el borrado del objeto y O(log n) para el splay en el caso general, dejando la complejidad final como O(log n) , para esta función.

## Función find()
Para esta función se comporta de la misma manera que un BST común pero al final se realiza la función splay sobre el objeto encontrado para dejarlo como raíz, y como ya hemos discutido anteriormentre, la complejidad de una busqueda en un BST es de O(log n) porque va dividiendo el arbol por la mitad, y aparte de esto como ya hemos mencionado, es muy improbable que se presente el caso de un arbol degenerado, ya que la función splay de manera constante va modificando la estructura del arbol, y como se mencionó anteriormente al principio esta estructura puede verse como un arbol degenerado, pero despues de realizar multiples splays(), se mantiene en una forma normal de un BST. Por lo que la función en conjunto con la función splay dan una complejidad final de O(log n). 

## Función inorder()
Esta función presenta una complejidad lineal, ya que tiene que recorrer todos los objetos para poder imprmirlos en el orden correspondiente, dando de esta forma un complejidad de O(n).

## Función size()
Size() tiene una complejidad de O(1), ya que se trata de una consulta de un atributo de la clase.

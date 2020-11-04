# Analisis Asintotico de Complejidad
## Función visit()
Para esta primera función la cual es para generar una cadena de caracteres con las diferentes formas de presentar un BST que son: inorder, preorder, postorder, level. Para cada una de las funciones secundarias mencionadas todas presentan una complejidad de O(n), ya que que tiene que recorrer todo el BST para lograr imprimir todos los valores, pero ya que tenemos que son 4 procesos diferentes la complejidad final de la función es de O(4n) que al redondearse queda como una complejidad final de O(n).

## Función height()
Como tal esta función regresa el height o la cantidad máxima de niveles dentro de el BST, para lo que no tiene una salida corta, ya que tiene que recorrer todos los posibles caminos del BST para encontrar el nivel máximo dando esto una complejidad de O(n) en todos los casos.

## Función ancestors()
Para el caso de esta función se realiza una busqueda de tipo binaria ya que se ignorá la mitad de la estructura BST y constantemente se va ingnorando la mitad de los nodos presentando una complejidad en el mejor de los casos de O(log n), pero ya que existe el peor de los casos en un BST en el cual la estructura se convierta en un arbol degenerado en el cual sin importar el recorrido en el peor de los casos se mantendría la complejidad de O(n), y ya que se esta tomando el peor de los casos para este analisis tenemos que considerar la complejidad como O(n).

## Función whatlevelamI()
Esta función al igual que la anterior funciona con una busqueda binaria, para encontrar el valor del cual se quiere conocer el nivel y se van regresando los valores de los nodos que se consultaron a lo largo de la busqueda si es que se encuentra el valor al final, en el caso contrario no se imprime nada. Pero al igual que en el caso anterior si tuviesemos la garantia de que el BST no se  conviertiera en un arbol degenerado la complejidad seria de O(log n) pero ya que estamos contando con el peor de los casos en el cual el arbol se hace degenerado y la complejdiad pasa a ser de O(n) en el peor de los casos.

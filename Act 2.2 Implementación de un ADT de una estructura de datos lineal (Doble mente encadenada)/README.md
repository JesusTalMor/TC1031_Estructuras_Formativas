# Analisis Asintotico de Complejidad
## Función add()

Para este caso a comparación de la complejidad del ejercicio de una lista con solo un nodo, su complejidad cambia a ser en el peor de los casos un O(1), ya que para los 2 casos dejando de lado, el caso particular en el cual se quiera agregar un objeto a la lista en una posición determinada. Tenemos que para ambos casos en el cual se quiera poner el primer objeto o se quiera poner un objeto al principio tendremos una complejidad de O(1), ya que se sabe la posicion y tenemos el apuntador head para hacer el acomple. Ahora para el caso de add de manera común donde se quiere añadir un objeto al final de la cadena, para es caso ya que es una lista doblemente encadenada tenemos un apuntador tail el cual nos permite saber exactamente donde esta el final de la lista y usando este apuntador, nos ahorramos los pasos de recorrer todo el arreglo hasta llegar al final del mismo. En conclusión la compejidad de esta función de O(1)

## Funcion find()

Para este caso al igual que en el anterior, la complejidad se mantiene siendo esta un O(n) en el peor de los casos, ya que para encontrar algun elemento en el arreglo se tiene que recorrer todo el arreglo completo y en el peor de los casos en el cual el objeto que se esta buscando llegue a estar al final del arreglo tendremos una cantidad de n pasos. Dando como conclusión una complejidad de O(n).

## Función update()

Para esta función su complejidad se basa al igual que la anterior en 2 partes, la primera es recorrer el arreglo de objetos hasta llegar a la posicion deseada y de ahi rescribir el valor del objeto, dando en el peor de los casos en el cual se quiera el objeto de el final de la lista o que simplemente no se encuentre, se tendra para estos casos una cantidad de pasos de O(n).O(1) dando una complejidad final de O(n).

## Función remove()
Al igual que en el caso de update, para esta función su complejidad es de O(n). Ya que de igual manera que la anterior de update primero se busca la ubicación que se quiere modificar y despues en un paso se modifica el valor del objeto seleccionado. Dando en conclusión una complejidad de O(n) para el peor de los casos. Dando solo una complejidad de O(1) o constante en 2 casos particulares en los cuales se quiera eliminar el primer elemento o el ultimo elemento, ya que gracias a los apuntadores definidos de head y tail tenemos exactamente las direcciones de dichos objetos. Pero en general ya que se esta tomando el peor de los casos la complejidad final se mantiene en O(n).

## Función toStringForward y toStringBackward()
Para ambos casos de las funciones sin importar si este fuera el peor o mejor de los casos siempre se presentará una complejidad de O(n), ya que para escribir todos los elementos del arreglo en una cadena primero se tienen que leer todos los elementos del arreglo, dando siempre una complejidad lineal que es lineal a la cantidad de objetos en la lista.

/*
 * graph.h
 * creado en 11/11/2020
 * Autor: Jesus Talamantes Morales
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>

using namespace std;

class Graph {
	private:
		int nodos;
		vector<int> *adjList;
		int *adjMatrix;
		void addEdgeAdjList(string);
		void addEdgeAdjMatrix(string);
		void sortAdjList();
	public:
		Graph();
		void loadGraphMat(string, int, int);
		void loadGraphList(string, int, int);
		string printAdjList();
		string printAdjMat();
		string DFS(int, int);
		string BFS(int, int);
		void DFSHelper(int current, int goal, stack<int> &st, bool visited[], int paths[], vector<int> &visitedOrder);
		void BFSHelper(int current, int goal, queue<int> &qu, bool visited[], int paths[], vector<int> &visitedOrder);
		string printVisited(vector<int> &visitedOrder);
		string printPath(int path[], int inicio, int meta);

};

/*Constructor principal inicia la estructura*/
Graph::Graph(){
	nodos = 0;
}

/*loadGraphList carga el archivo de texto y usando la función auxiliar de  addEdgeAdjList()
 * inserta los valores del txt a un vector para su uso
 */
void Graph::loadGraphList(string file, int ver, int arc){
	nodos = ver;
	adjList = new vector<int>[nodos]; //Crea un vector donde guardara todos los nodos
	// Metodo para abrir y leer un archivo
	string linea;
	ifstream lee (file);
	if (lee.is_open()){
		while (getline(lee, linea)){
			addEdgeAdjList(linea); //Llama la función auxiliar para sacar los datos
		}
		lee.close(); // Cierra el archivo para evitar corrupcion
	} else {
		cout << "El archivo no pudo abrirse";
	}
}

/*Metodo para insertar los datos del txt al arreglo adyacente*/
void Graph::addEdgeAdjList(string linea){
	int u, v;
	// Toma los char en la posicion 1 y 4 que son los numeros y los guarda en V y U
	u = stoi(linea.substr(1,1));
	v = stoi(linea.substr(4,1));
	adjList[u].push_back(v); // Añade la conexion a v en la posicion u
	adjList[v].push_back(u); // Añade la conexion a u en la posicion v
	//Esto se realiza debido a que es una lista no direccionada
}

/*Aplicando el mismo proceso que en loadGraphList pero ahora para crear una matrix*/
void Graph::loadGraphMat(string file, int ver, int arc){
	nodos = ver;
	adjMatrix = new int[nodos*nodos]; // Crea una matrix del tamaño de nodo * nodo
	//De manera tecnica esto es un array gigante que se divide en la memoria
	//Otra forma de definir un array
	for (int i = 0; i < nodos*nodos; i++){
		adjMatrix[i] = 0; //LLena la matrix de ceros para su posterior modificacion
	}
	// Metodo para abrir y leer un archivo
	string linea;
	ifstream lee(file);

	if (lee.is_open()){
		while (getline(lee, linea)){
			addEdgeAdjMatrix(linea); //Usa la funcion auxiliar para conseguir los datos y
															//Guardarlos en la matrix
		}
		lee.close(); //Cierra el archivo para evitar corrupcion
	} else {
		cout << "El archivo no pudo abrirse";
	}

}

/*Metodo para insertar los datos del txt en una matrix de adyacencia*/
void Graph::addEdgeAdjMatrix(string linea){
	int u, v;
	// Toma los char en la posicion 1 y 4 que son los numeros y los guarda en V y U
	u = stoi(linea.substr(1,1));
	v = stoi(linea.substr(4,1));
	adjMatrix[u*nodos+v] = 1; //Declara un 1 en la interseccion entre U y V
	adjMatrix[v*nodos+u] = 1; //Declara un 1 en la interseccion entre V y U
}

/*Funcion para imprimir la lista de adyacencia*/
string Graph::printAdjList(){
	stringstream aux;
	sortAdjList(); //Utiliza una función auxiliar para arreglar y acomodar la lista
	for (int i = 0; i < nodos; i++){
		aux << "vertex " << i << " : "; //Imprime el vertice y el numero que este tiene
		for (int j = 0; j < adjList[i].size();j++){
			aux << adjList[i][j] << " ";
			//Imprime cada una de la conexiones del vertice anterior
		}
	}
	return aux.str();
}

/*Funcion auxiliar de vector la cual organiza en todo el vector*/
void Graph::sortAdjList(){
	for (int i = 0; i < nodos; i++){
		sort(adjList[i].begin(), adjList[i].end());
	}
}

/*Funcion para imprimir la matrix de adyacencia*/
string Graph::printAdjMat(){
	stringstream aux;
	for (int i = 0; i < nodos; i++){
		for (int j = 0; j < nodos; j++){
			aux << adjMatrix[i*nodos+j] << " ";
			//Imprime por completo todos los elementos de la matrix
		}
	}
	return aux.str();
}

/*Funcion DFS Depth First Search la cual en la documentacion cuenta con una complejidad
 * de O(V+E) donde V son los vertices y E son los numeros de arcos posibles
 */
string Graph::DFS(int inicio, int meta){
	stringstream aux;
	stack<int> st; //Usa un stack auxiliar para guardar los nodos aplicando FIFO
	bool visited[nodos]; //Creando un arreglo booleando para definir los nodos visitados
	vector<int> visitedOrder; //Para imprimir el orden utilizamos otro vector
	int path[nodos]; //Usando arreglo auxiliar para guardar el camino
	for (int i = 0; i < nodos; i++){
		visited[i] = false; //Define todos los nodos como no visitados
		path[i] = -1; // Define todos los padre como -1
	}
	st.push(inicio); //Añade el nodo del inicio a el array auxiliar st
	DFSHelper(inicio, meta, st, visited, path, visitedOrder); //Llama la funcion auxiliar DFSHelper
	aux << printVisited(visitedOrder) << printPath(path, inicio, meta);
	//Imprime los nodos visitados y el camino que tomo para el nodo meta
	return aux.str();
}

/*Funcion auxiliar DFSHelper recursiva que realiza el recorrido en el grafo*/
void Graph::DFSHelper(int current, int goal, stack<int> &st, bool visited[], int paths[], vector<int> &visitedOrder){
	if (current == goal){
		return;
		//Casp base cuando encuentra el valor del nodo meta
	} else if (st.empty()){
		cout << "Node not found"; //En el caso donde no se ecuentre el nodo meta
	} else {
		current = st.top(); //Current es el primer elemento en st
		st.pop(); //Saca el elemento del arreglo st
		visited[current] = true; //Declara el nodo como visitado
		visitedOrder.push_back(current); //Añade el nodo al orden de visitado
		//Realiza un chequeo de todos los nodos conectados a este nodo
		for (int i = 0; i < adjList[current].size(); i++){
			if (visited[adjList[current][i]] == false){
				st.push(adjList[current][i]);
				//Añade el nodo a path en caso de que no sea visitado
				paths[adjList[current][i]] = current;
			}
		}
		DFSHelper(current, goal, st, visited, paths, visitedOrder); //Funcion recursiva
	}
}

/*Esta funcion realiza un BFS Breadth first search o una busqueda por niveles para
 * encontrar el nodo meta
 */
string Graph::BFS(int inicio, int meta){
	stringstream aux;
	queue <int> qu; //Usa una queue para ubicar el siguiente elemento
	bool visited[nodos]; //Crea un arreglo boleano para revisar los nodos visitados
	vector<int> visitedOrder; //Usa un vector para guardar el orden de visita
	int path[nodos]; //Utilizamos un array para guardar el camino de cada nodo
	for (int i = 0; i < nodos; i++){
		visited[i] = false; //Define cada nodo como no visitado
		path[i] = -1; //Define cada padre como -1
	}
	qu.push(inicio); //añade el nodo raiz a la cola Qu
	BFSHelper(inicio, meta, qu, visited, path, visitedOrder); // Llama la funcion auxiliar
	aux << printVisited(visitedOrder) << printPath(path, inicio, meta);
	//Imprime los nodos visitados y el camino que se siguio para encontrar el nodo meta
	return aux.str();
}

/*Funcion auxiliar de BFS usando recursividad para recorrer todo el arreglo*/
void Graph::BFSHelper(int current, int goal, queue<int> &qu, bool visited[], int paths[], vector<int> &visitedOrder){
	if (current == goal){
		return;
		//Caso base se detiene cuando current es el valor
	} else if (qu.empty()){
		cout << "Node not found"; //En caso de que no se encuentre el nodo
	} else {
		current = qu.front(); // Define current como el primer elemento de qu
		qu.pop(); //Elimina el primer elemento en qu
		visited[current] = true; //Define el nodo current como visitado
		visitedOrder.push_back(current); // Añade el nodo current al vector visitedOrder
		//Checa todos los elementos conectados al nodo
		for (int i = 0; i < adjList[current].size(); i++){
			if (visited[adjList[current][i]] == false){
				qu.push(adjList[current][i]);
				//Empuja al queue cada nodo conectado si es que estos no han sido visitados
				if (paths[adjList[current][i]] == -1){
					paths[adjList[current][i]] = current;
					//Revisa si los nodos estan en posicion de -1 en path si es asi cambia el
					//valor por current
				}
			}
		}
		BFSHelper(current, goal, qu, visited, paths, visitedOrder); // Funcion recursiva
	}
}

/*Funcion auxiliar para imprimir los resultados en este caso el orden de visita*/
string Graph::printVisited(vector<int> &visitedOrder){
	stringstream aux;
	aux << "visited:";
	for (int i = 0; i < visitedOrder.size(); i++){
		aux << " " << visitedOrder[i]; //Imprime cada nodo visitado al string
	}
	return aux.str();
}

/*Funcion auxiliar para imprimir los resultado en este caso imprime el camino
 * que se siguió para el nodo meta
 */
string Graph::printPath(int path[], int inicio, int meta){
	stringstream aux;

	stack<int> reverse; //Crea un stack para imprimir el path en orden
	int nodo = meta; //Empieza con el valor de meta
	//El siguiente ciclo continua hasta que nodo llegue al valor de inicio
	while (nodo != inicio){
		reverse.push(nodo); //Añade el valor de nodo a el stack reverse
		nodo = path[nodo]; //Define el valor de nodo como el valor del padre en path
	}
	reverse.push(inicio); //Añade el valor de incio al stack reverse
	aux << " path:";
	//Imprime todo el stack hasta que este quede vacio
	while (!reverse.empty()) {
		aux << " " << reverse.top();
		reverse.pop();
	}
	return aux.str();
}

#endif

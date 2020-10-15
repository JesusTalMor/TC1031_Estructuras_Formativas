/*
 * bst.h
 * Creado en: 12/10/2020
 * Autor: Jesus Talamantes Morales
 */

#ifndef BST_H_
#define BST_H_

#include <string>
#include <sstream>
#include <iostream>

template <class T> class BST;

template <class T>
class Nodo {
private:
  T valor;
  Nodo *izq, *der;

  Nodo<T>* succesor();

public:
  Nodo(T);
  Nodo(T, Nodo<T>*, Nodo<T>*);
  void add(T); // Metodos recursivos
  bool find(T);
  int height() const;
  int whatlevelamI(T);
  void preorder(std::stringstream&) const;
  void inorder(std:: stringstream&) const;
  void postorder(std:: stringstream&) const;
  void porNivel(std:: stringstream&) const;
  void impNivel(std:: stringstream&, int) const;
  bool ancestors(std:: stringstream&, T) const;


  friend class BST<T>;
};

//Constructores
template <class T>
Nodo<T>::Nodo(T val) : valor(val), izq(0), der(0) {}

template <class T>
Nodo<T>::Nodo(T val, Nodo<T> *iz, Nodo<T> *de) : valor(val), izq(iz), der(de) {}

template <class T>
void Nodo<T>::add(T val){
  if(val < valor){
    if(izq != 0){
      izq->add(val);
    } else {
      izq = new Nodo<T>(val);
    }
  } else {
    if(der != 0){
      der->add(val);
    } else {
      der = new Nodo<T>(val);
    }
  }
}

template <class T>
bool Nodo<T>::find(T val){
  if(val == valor){
    return true;
  } else if (val < valor){
    return (izq != 0 && izq->find(val));
  } else if (val > valor){
    return (der != 0 && der->find(val));
  }
  return false;
}

template <class T>
int Nodo<T>::height() const{
  int iz = 1, de = 1;
  if(izq != 0){
    iz = izq->height() + 1;
  }
  if(der != 0){
    de = der->height() + 1;
  }
  if(iz > de){
    return iz;
  } else {
    return de;
  }
}

template <class T>
int Nodo<T>::whatlevelamI(T val){
  if(val == valor){
    return 1;
  } else if(val < valor){
    if(izq != 0){
      return izq->whatlevelamI(val) + 1;
    }
  } else if (val > valor){
    if(der != 0){
      return der->whatlevelamI(val) + 1;
    }
  }
  return -1;
}

template <class T>
void Nodo<T>::preorder(std::stringstream &aux) const {
  aux << valor;
  if(izq != 0){
    aux << " ";
    izq->preorder(aux);
  }
  if(der != 0){
    aux << " ";
    der->preorder(aux);
  }
}

template <class T>
void Nodo<T>::inorder(std::stringstream &aux) const {
  if (izq != 0) {
		izq->inorder(aux);
	}
	if (aux.tellp() != 1) {
		aux << " ";
	}
	aux << valor;
	if (der != 0) {
		der->inorder(aux);
	}
}

template <class T>
void Nodo<T>::postorder(std::stringstream &aux) const {
  if(izq != 0){
		izq->postorder(aux);
	}
	if (der != 0){
		der->postorder(aux);
	}
  if (aux.tellp() != 1){
		aux << " ";
  }
	aux << valor;
}

template <class T>
void Nodo<T>::porNivel(std::stringstream &aux) const {
  int nivel = height();
  impNivel(aux, nivel);
}

template<class T>
void Nodo<T>::impNivel(std::stringstream &aux, int niv) const{
  if(niv >= 0){
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << valor;
	}
  if (izq != 0) {
		izq->impNivel(aux, niv -1);
	}
	if (der != 0) {
		der->impNivel(aux, niv -1);
	}
}

template <class T>
bool Nodo<T>::ancestors(std::stringstream &aux,T val) const{
  //Funciona igual que la funcion find solo que va imprimiendo
  //su reccorido hasta el elemento que se busca
	if (val == valor) {
	  return true;
	} else if (val < valor) {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << valor;
		return (izq != 0 && izq->ancestors(aux,val));
	} else if (val > valor) {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << valor;
		return (der != 0 && der->ancestors(aux,val));
	}
	return false;
}

template <class T>
class BST {
private:
	Nodo<T> *raiz;

public:
	BST();
	bool empty() const;
	void add(T);
	bool find(T) const;
  int height();
  int whatlevelamI(T);
  std::string preorder() const;
	std::string inorder() const;
  std::string postorder() const;
  std::string porNivel() const;
  std::string visit() const;
  std::string ancestors(T) const;

};

template <class T>
BST<T>::BST() : raiz(0) {}

template <class T>
bool BST<T>::empty() const {
	return (raiz == 0);
}

template<class T>
void BST<T>::add(T val) {
	if (!empty()) { //Valida que el arbol tenga contenido
		if (!raiz->find(val)) {
			raiz->add(val);
		}
	} else {
		raiz = new Nodo<T>(val);
	}
}

template <class T>
bool BST<T>::find(T val) const {
	if (!empty()) {  //Valida que el arbol tenga algun elemento
		return raiz->find(val);
	} else {
		return false;
	}
}

template <class T>
int BST<T>::height(){
  if (!empty()) {  //Valida que el arbol tenga algun elemento
    return raiz->height();
  } else {
    return 0;
  }
}

template <class T>
int BST<T>::whatlevelamI(T val){
  if(!empty()){
    return raiz->whatlevelamI(val);
  } else {
    return -1;
  }
}

template <class T>
std::string BST<T>::preorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		raiz->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::inorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		raiz->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::postorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		raiz->postorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::porNivel() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		raiz->porNivel(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::visit() const {
  std::stringstream aux;
  aux << preorder() << "\n";
  aux << inorder() << "\n";
  aux << postorder() << "\n";
  aux << porNivel();

  return aux.str();
}

template <class T>
std::string BST<T>::ancestors(T val) const {
	std::stringstream aux;
	aux << "[";
	if (!empty()) {
		if(!raiz->ancestors(aux,val)){
			return "[]";
		}
	}
	aux << "]";
	return aux.str();
}

#endif /*BST_H_*/

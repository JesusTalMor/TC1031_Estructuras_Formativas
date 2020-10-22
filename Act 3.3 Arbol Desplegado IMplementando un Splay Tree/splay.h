/*
 * splay.h
 * Creado en 21/10/2020
 * Autor: Jesus Talamantes Morales A01706335
 */

#ifndef SPLAY_H_
#define SPLAY_H_

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <class T> class SplayTree;

template <class T>
class Nodo{
private:
  T value;
  Nodo<T> *left, *right, *parent;

  Nodo<T>* succesor();
  Nodo<T>* rot_right(Nodo<T>*);
  Nodo<T>* rot_left(Nodo<T>*);

public:
  Nodo(T);
  Nodo(T,Nodo<T>*,Nodo<T>*,Nodo<T>*);
  Nodo<T>*add(T);
  Nodo<T>*find(T);
  Nodo<T>*remove(T);
  void removeChilds();
	void inorder(std::stringstream&) const;
	void print_tree(std::stringstream&) const;
	void preorder(std::stringstream&) const;
	Nodo<T>* splay(Nodo<T>*,Nodo<T>*);

  friend class SplayTree<T>;
};

template <class T>
Nodo<T>::Nodo(T val): value(val),left(0),right(0),parent(0) {}

template <class T>
Nodo<T>::Nodo(T val,Nodo<T> *izq,Nodo<T> *der,Nodo<T> *pa)
: value(val),left(izq),right(der),parent(pa){}

template <class T>
Nodo<T>* Nodo<T>::add(T val){
	if(val < value){
		if(left != 0){
			return left->add(val);
		} else{
			left = new Nodo<T>(val);
			left->parent = this;
			return left;
		}
	}else{
		if(right != 0){
			return right->add(val);
		}else{
			right = new Nodo<T>(val);
			right->parent = this;
			return right;
		}
	}
}

template<class T>
Nodo<T>* Nodo<T>::find(T val){
	if(val == value){
		return this;
	}else if (val < value){
		if(left != 0)
			return left->find(val);
		else
			return this;
	}else if (val > value){
		if(right != 0)
			return right->find(val);
		else
			return this;
	}
	return 0;
}

/*No comprendo bien que sucede*/
template<class T>
Nodo<T>* Nodo<T>::succesor(){
	Nodo<T> *izq,*der;

	izq = left;
	der = right;

	if(right == 0){
		if(left != 0){
			left = 0;
		}
		if(izq)
			izq->parent = 0;
		return izq;
	}

	if(right->left == 0){
		right = right->right;
		if(right)
			right->parent = parent;
		if(der){
			der->right = 0;
			der->parent = 0;
		}
		return der;
	}

  Nodo<T> *p,*c;
  p = right;
  c = right->left;
  while(c->left !=0){
    p = c;
    c = c->left;
  }
  p->left=c->right;
  if(p->left !=0)
    p->left->parent = p;
  c->right = 0;
  return c;
}

template <class T>
Nodo<T>* Nodo<T>::remove(T val) {
Nodo<T> *succ, *old;
if (val < value) {
  if (left != 0) {
    if (left->value == val) {
      old = left;
      succ = left->succesor();
      if (succ != 0) {
        succ->left = old->left;
        succ->right = old->right;
        succ->parent = old->parent;
        if (succ->left)
          succ->left->parent = succ;
        if (succ->right)
          succ->right->parent = succ;
      }
      left = succ;
      delete old;
      return this;
    } else {
      return left->remove(val);
    }
  }
} else if (val > value) {
  if (right != 0) {
    if (right->value == val) {
      old = right;
      succ = right->succesor();
      if (succ != 0) {
        succ->left = old->left;
        succ->right = old->right;
        succ->parent = old->parent;
        if (succ->left)
          succ->left->parent = succ;
        if (succ->right)
          succ->right->parent = succ;
      }
      right = succ;
      delete old;
      return this;
  } else {
    return right->remove(val);
      }
    }
  }
  return 0;
}

template <class T>
Nodo<T>* Nodo<T>::rot_right(Nodo<T>* x){
  Nodo<T> *y = x->left;
  x->left = y->right;
  if(y->right)
    y->right->parent = x;
  y->right = x;
  // enlace de y con el padre de x
  y->parent = x->parent;
  x->parent = y;
  // enlace del padre de xx a y
  if (y->parent){
    if (y->parent->left && y->parent->left->value == x->value)
      y->parent->left = y;
    else
      y->parent->right = y;
  }
  return y;
}

template <class T>
Nodo<T>* Nodo<T>::rot_left(Nodo<T>* x){
  Nodo<T> *y = x->right;
  x->right = y->left;
  if(y->left)
    y->left->parent = x;
  y->left = x;
  // enlace de y con el padre de x
  y->parent = x->parent;
  x->parent = y;
  // enlace del padre de xx a y
  if (y->parent) {
    if (y->parent->left && y->parent->left->value == x->value)
      y->parent->left = y;
    else
      y->parent->right = y;
  }
  return y;
}

template <class T>
Nodo<T>* Nodo<T>::splay(Nodo<T>* root,Nodo<T>* x) {
  while (x->parent != 0){

    if(x->parent->value == root->value) {
      if(x->parent->left && x->parent->left->value == x->value){
        rot_right(x->parent);
      } else {
        rot_left(x->parent);
      }
	} else{
        Nodo<T>*p = x->parent; //padre
        Nodo<T>*g = p->parent; //abuelo

        if(p->left && g->left &&
		x->value == p->left->value && p->value == g->left->value){
		  rot_right(g);
          rot_right(p);
        } else if (p->right && g->right &&
		x->value == p->right->value && p->value == g->right->value){
		  rot_left(g);
          rot_left(p);
        } else if (p->left && g-> right &&
		x->value == p->left->value && p->value == g->right->value){
		  rot_right(p);
          rot_left(g);
        } else {
		  rot_left(p);
          rot_right(g);
        }
      }
    }
    return x;
}


template <class T>
void Nodo<T>::inorder(stringstream &aux) const {
  if (left != 0) {
    left->inorder(aux);
  }
  if (aux.tellp() != 1) {
    aux << " ";
  }
  aux << value;
  if (right != 0) {
    right->inorder(aux);
  }
}
template <class T>
void Nodo<T>::print_tree(stringstream &aux) const {
  if (parent != 0) {
    aux << "\n Nodo " << value;
    aux << " parent " << parent->value;
  } else
    aux << "\n root " << value;
  if (left != 0)
    aux << " left " << left->value;
  if (right != 0)
    aux << " right " << right->value;
  aux << "\n";

  if (left != 0) {
    left->print_tree(aux);
  }
  if (right != 0) {
    right->print_tree(aux);
  }
}

template <class T>
void Nodo<T>::preorder(stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

template <class T>
class SplayTree {

private:
  Nodo<T> *root;
  int size;

public:
  SplayTree();
  bool empty() const;
  void add(T);
  bool find (T);
  void remove (T);
  string inorder() const;
  string print_tree() const;
  string preorder() const;
  int size();
};

template <class T>
SplayTree<T>::SplayTree() : root(0) {}

template <class T>
bool SplayTree<T>::empty() const {
  return (root == 0);
}

template <class T>
void SplayTree<T>::add(T val) {
  if ( root != 0) {
    Nodo<T>* added = root->add(val);
    root = root->splay(root,added);
  }
  else {
    root = new Nodo<T>(val);
  }
  size ++;
}

template <class T>
void SplayTree<T>::remove(T val) {
  if (root != 0) {
    if (val == root->value) {
      Nodo<T> *succ = root->succesor();
      if (succ != 0) {
        succ->left = root->left;
        succ->right = root->right;
        succ->parent = 0;
        if (succ->left)
          succ->left->parent = succ;
        if (succ->right)
          succ->right->parent = succ;
      }
      delete root;
      root = succ;
    } else {
      Nodo<T>* p = root->remove(val);
      root = root->splay(root,p);
    }
  }
  size --;
}

template <class T>
bool SplayTree<T>::find(T val) {
  if (root != 0) {
    Nodo<T>* found = root->find(val);
    root = root->splay(root,found);
    return (root->value == val);
  } else {
    return false;
  }
}

template <class T>
string SplayTree<T>::inorder() const {
  stringstream aux;

  aux << "[";
  if (!empty()) {
    root->inorder(aux);
  }
  aux << "]";
  return aux.str();
}

template <class T>
string SplayTree<T>::print_tree() const {
  stringstream aux;

  aux << "\n ================================ ";
  if (!empty()) {
    root->print_tree(aux);
  }
  aux << " ================================== \n";
  return aux.str();
}

template <class T>
string SplayTree<T>::preorder() const {
  stringstream aux;

  aux << "[";
  if (!empty()) {
    root->preorder(aux);
  }
  aux << "]";
  return aux.str();
}

template <class T>
int SplayTree<T>::size(){
	return size;
}

#endif /*SPLAY_H_*/

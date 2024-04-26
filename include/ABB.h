#ifndef __ABB__
#define __ABB__

#include <iostream>
#include <queue>
#include <utility>

#include "AB.h"
#include "NodoBB.h"

template <class Key>
class ABB: public AB<Key>{

  public:
    ABB(void): AB<Key>(nullptr){}
    ABB(NodoB<Key>* raiz): AB<Key>(raiz){}
    ~ABB() {}

    bool insertar(const Key dato);
    bool insertarRama(NodoB<Key>*& nodo, const Key dato);

    bool buscar(const Key& X);
    bool buscarRama(NodoB<Key>* nodo, const Key& clave);
};

template <class Key>
bool ABB<Key>::buscar(const Key& clave) {
  return buscarRama(this->getRaiz(), clave);
}

template <class Key>
bool ABB<Key>::buscarRama(NodoB<Key>* nodo, const Key& clave) {
  int contador = 0;
  if (nodo == NULL) 
    return false;
  if (clave == nodo->getData()) 
    return true;
  if (clave < nodo->getData() )
  std::cout << "Contador: " << contador << std::endl;
    return buscarRama(nodo->getIzq(), clave);
    contador++;
  return buscarRama(nodo->getDer(), clave);
  
}

template <class Key>
bool ABB<Key>::insertar(const Key clave) {
  return insertarRama(this->getRaiz(), clave);
}

template <class Key>
bool ABB<Key>::insertarRama(NodoB<Key>*& nodo, const Key clave) {
  if (nodo == nullptr) {
    nodo = new NodoB<Key>(clave);
    return true;
  } else if (nodo->getData() == clave) {
    return false;
  } else if (clave < nodo->getData()) {
    insertarRama(nodo->getIzq(), clave);
  } else {
    insertarRama(nodo->getDer(), clave);
  }
}

#endif
#ifndef __NODOBB__
#define __NODOBB__

#include <iostream>

#include "NodoB.h"

template <class Key>
class NodoBB: public NodoB<Key> {
  public:
    NodoBB(Key data, Key clave, NodoBB<Key>* izq = nullptr, NodoBB<Key>* der = nullptr):
      clave(clave), NodoB<Key>(data, izq, der) {}
    ~NodoBB(void) {}

    Key getClave (void);

    void setClave(Key clave);

    NodoBB<Key>& operator=(const NodoBB<Key> &p);

  private:
    Key clave;
};

template <class Key>
Key NodoBB<Key>::getClave(void){
  return clave;
}

template <class Key>
void NodoBB<Key>::setClave(Key clave){
  this->clave = clave;
}

template <class Key>
NodoBB<Key>& NodoBB<Key>::operator=(const NodoBB<Key> &nodo) {
  if (this != &nodo) {
    this->data_  = nodo.getData();
    this->h_der_ = nodo.getDer();
    this->h_izq_ = nodo.getIzq();
    this->clave  = nodo.getClave();
  }
  return *this;
}

#endif
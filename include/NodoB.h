#ifndef __NODOB__
#define __NODOB__

#include <iostream>

template <class Key>
class NodoB{
  public:
    NodoB(void);
    NodoB(Key data, NodoB<Key>* izq = nullptr, NodoB<Key>* der = nullptr);
    ~NodoB(void);


    NodoB<Key>*& getIzq (void);
    NodoB<Key>*& getDer (void);
    Key         getData(void);

    void setIzq (NodoB<Key>* izq);
    void setDer (NodoB<Key>* der);    
    void setData(Key data);

    NodoB<Key>& operator=(const NodoB<Key> &p);

  protected:
    Key data_;
    Key clave_;
    NodoB<Key>* h_der_;
    NodoB<Key>* h_izq_;
};

template <class Key>
NodoB<Key>::NodoB(void){
  h_izq_ = nullptr;
  h_der_ = nullptr;
}

template <class Key>
NodoB<Key>::NodoB(Key data, NodoB<Key>* izq, NodoB<Key>* der){
  data_ = data;
  h_izq_ = izq;
  h_der_ = der;
}

// Destruye el nodo
template <class Key>
NodoB<Key>::~NodoB(void){
  if (!h_izq_) {delete h_izq_;}
  if (!h_der_) {delete h_der_;}
}

template <class Key>
NodoB<Key>*& NodoB<Key>::getIzq(void){
  return h_izq_;
}

template <class Key>
NodoB<Key>*& NodoB<Key>::getDer(void){
  return h_der_;
}

template <class Key>
Key NodoB<Key>::getData(void){
  return data_;
}

template <class Key>
void NodoB<Key>::setIzq(NodoB<Key>* izq){
  h_izq_ = izq;
}

template <class Key>
void NodoB<Key>::setDer(NodoB<Key>* der){
  h_der_ = der;
}

template <class Key>
void NodoB<Key>::setData(Key data){
  data_ = data;
}

template <class Key>
NodoB<Key>& NodoB<Key>::operator=(const NodoB<Key> &nodo) {
  if (this != &nodo) {
    this->data_  = nodo.getData();
    this->h_der_ = nodo.getDer();
    this->h_izq_ = nodo.getIzq();
  }
  return *this;
}

#endif
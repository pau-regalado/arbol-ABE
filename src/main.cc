#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <cstdlib>

//#include "../include/NodoB.h"
//#include "../include/AB.h"
//#include "../include/ABE.h"
#include "../include/simulator.h"
//#include "Nif.h"

const int MAX_INT = 100;
const int MIN_INT = -1000;
//typedef int Key;

int main (int argc, char* argv[]){
  std::cout << std::endl;
  AB<Key>* arb0 = nullptr;
  AB<Key>* arb1 = nullptr;
  arb0 = new ABE<Key>;
  arb1 = new ABB<Key>;
  
  const int MAX_INT = 100;
  const int MIN_INT = 0;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis(MIN_INT, MAX_INT);

  for (int i = 0; i < 100; ++i) {
    arb0->insertar(Key(dis(gen)));
    arb1->insertar(Key(dis(gen)));
  }
  //std::cout << *arb0 << std::endl;
  std::cout << "Introduzca un valor a buscar: ";
  int x;
  std::cin >> x;
  arb0->buscar(x);
  arb1->buscar(x);
}
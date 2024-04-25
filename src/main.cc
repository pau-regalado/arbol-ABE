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
  //ABE<Key> p;
  Simulator s;
  s.run(argc, argv);
  
}
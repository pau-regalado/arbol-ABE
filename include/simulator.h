#ifndef __SIMULATOR__
#define __SIMULATOR__

#include <iostream>
#include <fstream>
#include <string.h>

#include "AB.h"
#include "ABE.h"
#include "NodoB.h"
//#include "Nif.h"

//typedef int Key;

enum arbTypes { ABE, AB };
enum initTypes { MANUAL, RANDOM };

class Simulator {
  public:
    Simulator() {}
    void run(int argc, char* argv[]);
}; 

void Simulator::run(int argc, char* argv[]) { 
  bool arbCheck = false;
  bool initCheck = false;
  int size;
  ABE<int> p;
  AB<int>* arb = new AB<int>;
  initTypes initType = initTypes::RANDOM;
  std::string filename = "";
  arbTypes arbType = arbTypes::AB;

  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "-ab") == 0 && i + 1 < argc) {
      char* arbTypes = argv[++i];
      if (strcmp(arbTypes, "abe") == 0) {
        arbType = arbTypes::ABE;
        arbCheck = true;
      } else if (strcmp(arbTypes, "abb") == 0) {
        arbType = arbTypes::AB;
        arbCheck = true;
      } 

    } else if (strcmp(argv[i], "-init") == 0 && i + 1 < argc) {
      char* initializingType = argv[++i];
      if (strcmp(initializingType, "manual") == 0) {      
        initType = initTypes::MANUAL;
      } else if (strcmp(initializingType, "random") == 0) {
        initType = initTypes::RANDOM;
      } else if (strcmp(initializingType, "file") == 0) {
        filename = argv[++i];
      } 
    } 
  }

  if (!filename.empty()) {   
    switch (arbType) {
      case arbTypes::ABE: {      
        arb = new ABE<Key>();             
        break;
      };
      case arbTypes::AB: {
        arb = new AB<Key>();         
        break;
      };
      
    default:
        arb = new ABE<Key>();
      break;
    }
  } else if (initType == initTypes::MANUAL) {
    sequence = new StaticSequence<Key>(size);
    sequence->manualInitializing();
  } else if (initType == initTypes::RANDOM) {
    sequence = new StaticSequence<Key>(size);
    sequence->randomInitializing();
  } else {
    throw std::exception();
  }

  switch (arbType) {
    case arbTypes::ABE: {
      arb = new ABE<Key>();          
      break;
    };
    case arbTypes::AB: {
      arb = new AB<Key>();         
      break;
    };
  default:
      arb = new ABE<Key>();
    break;
  }

  //mostrar_v(*sequence);
  //ord->Sort();
  //ord->printSequence();
}
#endif
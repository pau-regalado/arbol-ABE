#ifndef __SIMULATOR__
#define __SIMULATOR__

#include <iostream>
#include <fstream>
#include <string.h>
#include <random>

#include "ABE.h"
#include "ABB.h"
#include "NodoBB.h"
#include "Nif.h"

typedef int Key;

enum initTypes { MANUAL, RANDOM };

class Simulator {
  public:
    Simulator() {}
    void run(int argc, char* argv[]);
    void show_menu(void);
    //void casesOp(void);
    //void randomInitializing();
    //void manualInitializing();
}; 

void Simulator::run(int argc, char* argv[]) { 
  bool arbCheck = false;
  bool initCheck = false;
  int size;
  initTypes initType = initTypes::RANDOM;
  std::string filename = "";
  AB<Key>* arb = nullptr;

  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "-ab") == 0 && i + 1 < argc) {
      char* arbTypes = argv[++i];
      if (strcmp(arbTypes, "abe") == 0) {
        arb = new ABE<Key>;
        arbCheck = true;
      } else if (strcmp(arbTypes, "abb") == 0) {
        arb = new ABB<Key>;
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

  /*if (!filename.empty()) {   
    switch (arbType) {
      case arbTypes::AABE: {      
        arb = new ABE<Key>();             
        break;
      };
      case arbTypes::AAB: {
        arb = new AB<Key>();         
        break;
      };
      
    default:
        arb = new ABE<Key>();
      break;
    }
  } else if (initType == initTypes::MANUAL) {
    manualInitializing();
  } else if (initType == initTypes::RANDOM) {
    randomInitializing();
  } else {
    throw std::exception();
  }*/

  //mostrar_v(*sequence);
  //ord->Sort();
  //ord->printSequence();


  char opcion;
  bool quit = false;
  while (!quit){
    show_menu();
    std::cin >> opcion;
    switch(opcion){
      case 'i': {
        int dato;
        std::cin >> dato;
        if (arb->insertar(dato)) {
          std::cout << dato << " insertado!" << std::endl;
        }else{
          std::cout << dato << " ya esta!" << std::endl;
        }
        break;
      }
      case 'b': {
        int x;
        std::cin >> x;
        if(arb->buscar(x)){
          std::cout << x << " encontrado" << std::endl;
        }else{
          std::cout << x << " no encontrado" << std::endl;
        }
        break;
      }
      case 'm':
        std::cout << *arb << std::endl;
        break;
      case 's': 
        quit = true;
        break;
      default: std::cout << "opcion no soportada" << std::endl;
        break;
    }    
  }
}

void Simulator::show_menu(void){
  std::cout << "OPCIONES: " << std::endl;
  std::cout << "[s] Salir" << std::endl;
  std::cout << "[i] Insertar" << std::endl;
  std::cout << "[b] Buscar" << std::endl;
  std::cout << "[m] Mostrar" << std::endl;
  
  std::cout << "Opción: ";
}
/*
void Simulator::casesOp(void) {
  char opcion;
  bool quit = false;
  while (!quit){
    show_menu();
    std::cin >> opcion;
    switch(opcion){
      case '1': {
        int dato;
        std::cin >> dato;
        if (arb.insertar(dato)) {
          std::cout << dato << " insertado!" << std::endl;
        }else{
          std::cout << dato << " ya esta!" << std::endl;
        }
        break;
      }
      case '2': {
        int x;
        std::cin >> x;
        if(p.buscar(x)){
          std::cout << x << " encontrado" << std::endl;
        }else{
          std::cout << x << " no encontrado" << std::endl;
        }
        break;
      }
      case '3':
        std::cout << p << std::endl;
        break;
      case '0': 
        quit = true;
        break;
      default: std::cout << "opcion no soportada" << std::endl;
        break;
    }    
  }
}*/
/*
void Simulator::randomInitializing() {
  const int MAX_INT = 99999999;
  const int MIN_INT = 0;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis(MIN_INT, MAX_INT);
  for (int i = 0; i < 10; i++) {
    arb.insertar(dis(gen)); // Para trabajar con nifs poner solo Key() para llamar a su constrructor aleatorio
  }
}

void Simulator::manualInitializing() {
  std::cout << "Elija numero a insertar: " << std::endl;
  int tam;
  std::cin >> tam;
  int value;
  for (int i = 0; i < tam; i++) {
    std::cout << "Inserte " << i << " elemento> ";
    std::cin >> value;
    arb.insertar(value);
  }
}
*/
#endif
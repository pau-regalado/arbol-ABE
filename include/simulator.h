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

  if (!filename.empty()) {   
    std::ifstream file("data/" + filename);

    if (!file.is_open()) {
      throw std::runtime_error("Error al abrir el archivo.");
    }       

    int kLines = 0;
    file >> kLines;
    for (int i = 0; i < kLines; ++i) {
      int line;
      file >> line;
      arb->insertar(Key(line));
    } 

  } else if (initType == initTypes::MANUAL) {
    int kLines = 0;
    std::cout << "Introduzca numero de elementos a insertar> ";
    std::cin >> kLines;
    if (kLines < 0) {
      throw std::runtime_error("Tamano incorrecto");
    }  
    for (int i = 0; i < kLines; ++i) {
      int line;
      std::cout << "Introduzca el elemento [" << i << "]> ";
      std::cin >> line;
      arb->insertar(Key(line));
    } 
  } else if (initType == initTypes::RANDOM) {
    int kLines = 5;
    std::cout << "Introduzca numero de elementos a insertar> ";
    std::cin >> kLines;
    if (kLines < 0) {
      throw std::runtime_error("Tamano incorrecto");
    }

    const int MAX_INT = 100;
    const int MIN_INT = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(MIN_INT, MAX_INT);

    for (int i = 0; i < kLines; ++i) {
      arb->insertar(Key(dis(gen)));
    }
  } else {
    throw std::exception();
  }

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

#endif
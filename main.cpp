//
//  main.cpp
//  Codificar
//
//  Programa para codificar archivos de texto.
//  Necesita llave.(password)
//  Evolución hacia codificación de cualquier tipo de archivos.
//
//  Created by Daniel on 22/02/15.
//  Copyright (c) 2015 Gotomo. All rights reserved.
//

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "IOpersonal.h"
#include "Transformar.h"


#define MIN 5

using namespace std;

int main(int argc, const char * argv[]) {
    list<char> *texto;
    
    string password, direccion;
    int * llave;
//    if(argc == 0){
//        password = argv[1];
//        direccion = IOpersonal::Cadena("Document");
//    }
//    else if(argc == 2){
//        password = argv[1];
//        direccion = argv[2];
//    }
//    else if(argc > 2){
//        cout << "To much arguments\n";
//        return 0;
//    }
//    else{
//        password = IOpersonal::Llave(5);
//        direccion = IOpersonal::Cadena("Document");
//    }
    
    direccion = "/Users/Daniel/Desktop/hola.txt";
    password = "32178";
//    password = "8321";
    
    
    llave = new int[password.size()];
    for(int i = 0; i < password.size(); ++i){
        llave[i] = password[i] - '0';
    }
    
    texto = IOpersonal::leerArchivo(direccion);
    
    texto = Transformar::encriptar(texto, llave, llave + password.size());
    IOpersonal::reescribir_archivo(direccion, texto);
    
    delete texto;
    return 0;
}
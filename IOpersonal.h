//
//  IOpersonal.h
//  
//
//  Created by Daniel on 28/02/15.
//
//

#ifndef ____IOpersonal__
#define ____IOpersonal__

#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

class IOpersonal {
public:
    static ostream & imprimir_buffer(ostream &, string);
    static void imprimir(string);
    static void imprimir(list<char>*);
    static void imprimir_error(string error, string recomendacion);
    static void imprimir_error(string error);
    static void reescribir_archivo(string direccion, list<char>* texto);
    static void escribir_inicio(string direccion, list<char>* texto);
    static void escribir_final(string direccion, list<char>* texto);
    
    static string Llave(int);
    static string Cadena(string, int);
    static string Cadena (string);
    static int número();
    
    static list<char>* leerArchivo(string);
    
    static bool verificar_string(string);
    static bool verificar_numeros(string);
};

#endif /* defined(____IOpersonal__) */

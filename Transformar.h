//
//  Transformar.h
//  Codificar
//
//  Created by Daniel on 22/02/15.
//  Copyright (c) 2015 Gotomo. All rights reserved.
//

#ifndef __Codificar__Transformar__
#define __Codificar__Transformar__

#include <iostream>
#include <list>
#include "IOpersonal.h"

using namespace std;

typedef list<char>* (*t_fase)(list<char>*, int);

class Transformar{
public:
    static list<char>* encriptar(list<char>*, int*, int*);
    
private:
    static list<char>* fase_uno(list<char>*, int);
    static list<char>* fase_dos(list<char>*, int);
    static list<char>* fase_tres(list<char>*, int);
    static list<char>* fase_cuatro(list<char>*, int);
    static list<char>* agregar_codigo(list<char>*, list<char>*);
};

#endif /* defined(__Codificar__Transformar__) */

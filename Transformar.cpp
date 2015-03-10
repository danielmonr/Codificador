//
//  Transformar.cpp
//  Codificar
//
//  Created by Daniel on 22/02/15.
//  Copyright (c) 2015 Gotomo. All rights reserved.
//

//  Encription: Se hace una encripcion en cuatro partes y se hace un ciclo de esas cuatro partes
//  Se intercambian las posiciones de caracteres (fase_uno, fase_dos)
//  Se añaden caracteres aleatorios (fase_dos)
//  Se modifican los caracteres (fase_tres)

#include "Transformar.h"

list<char>* Transformar::encriptar(list<char> * lista, int * codigo, int* final){
    
    cout << "Codificando...";
    const unsigned int N = 4;
    
    list<char> codigo_char;
    
    t_fase fase[N];
    fase[0] = fase_uno;
    fase[1] = fase_dos;
    fase[2] = fase_tres;
    fase[3] = fase_cuatro;
    
    int cont = 0;
    while(codigo < final){
        if(cont >= N){
            cont = 0;
        }
        cout << "\nCodigo: " << *codigo << "\ncont: " << cont << endl;
        
        codigo_char.push_back(*codigo);
        
        lista = fase[cont](lista, *codigo);
        codigo ++;
        cont++;
    }
    
    lista = agregar_codigo(lista, &codigo_char);
    
    cout << "\nTamano: " << lista->size() << endl;
    
    cout << "  Terminado.\n";
    return lista;
}

//  Intercambiar caracteres cada num caracter, intercambio hacia adelante
list<char>* Transformar::fase_uno(list<char> * lista, int num){
    int _cont = 0;
    list<char>::iterator it = (*lista).begin();
    
    // Si el tamaño es menor que el num no vale la pena continuar
    // no se hace ningun cambio.
    if (lista->size() >= num) {
        advance(it, num-1);
    }
    else{
        return lista;
    }
    char temp1 = *it;
    char temp2;
    
    // Se recorre la lista y si el carcater esta en la posición num(k), k > 1
    // se intercambia
    for(list<char>::iterator i = it; i != (*lista).end(); ++i){
        if(_cont == num){
            temp2 = *i;
            *i = temp1;
            temp1 = temp2;
            _cont = 1;
        }
        else{
            _cont++;
        }
    }
    
    // Finalmente se intercambia el caracter en la posicion num
    // por el ultimo caracter cambiado
    it = (*lista).begin();
    advance(it, num-1);
    *it = temp1;
    return lista;
}

//  Añadir caracteres random en el texto cada num posición
list<char>* Transformar::fase_dos(list<char> * lista, int num){
    int _cont = 0;
    srand((int)time(NULL));
    char _add;
    
    list<char>::iterator it = lista->begin();
    
    // Si el tamaño de la lista es menor que num
    // no vale la pena continuar
    if(lista->size() < num){
        return lista;
    }
    
    //Se recorre toda la lista y se añaden caracteres en las posiciones num(k), k > 0
    for (list<char>::iterator i = it; i != lista->end(); ++i){
        if(_cont == num){
            
            // Los caracteres que se añaden deben estar entre 32 y 126 (Código ASCII)
            _add = (rand() % 94) + 32;
            lista->insert(i, _add);
            _cont = 1;
        }
        else{
            _cont++;
        }
    }
    return lista;
}

// Se transforma el caracter, adelantando su codigo por num
list<char>* Transformar::fase_tres(list<char> * lista, int num){
    
    for(list<char>::iterator i = lista->begin(); i != lista->end(); ++i){
        // Si el código ASCII es superior a 126 no se le añade directamente
        // se hace un recorrido circular (se regresa al 32).
        if(*i > 126 - num){
            *i = 31 + num;
        }
        else{
            *i = *i + num;
        }
    }
    
    return lista;
}

// Intercambiar caracteres cada num caracter, intercambio hacia atrás
list<char>* Transformar::fase_cuatro(list<char> * lista, int num){
    
    // Ver documentación de Transformar::fase_uno
    
    int _cont = 0;
    char temp1, temp2;
    list<char>::iterator it = (*lista).begin();
    advance(it, num-1);
    temp1 = *it;
    it = lista->begin();
    advance(it, (lista->size() - ((lista->size() % num)))-1);
    
    for (list<char>::iterator i = it; i != lista->begin(); --i){
        if (_cont == 0){
            temp2 = *i;
            *i = temp1;
            temp1 = temp2;
            _cont = num-1;
        }
        else{
            _cont --;
        }
        
    }
    
    return lista;
}

list<char>* Transformar::agregar_codigo(list<char> * lista, list<char>* codigo){
    
    
    
    list<char>::iterator it = lista->end();
    lista->splice(it, *codigo);
    return lista;
}
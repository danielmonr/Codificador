//
//  IOpersonal.cpp
//  
//
//  Created by Daniel on 28/02/15.
//
//

#include "IOpersonal.h"

ostream& IOpersonal::imprimir_buffer(ostream & os, string s){
    os << s;
    os << '\n';
    return os;
}

void IOpersonal::imprimir(string s){
    cout << s << endl;
}

void IOpersonal::imprimir(list<char>* texto){
    for (auto item:*texto){
        cout << item;
    }
    cout << endl;
}

void IOpersonal::imprimir_error(string error, string recomendacion){
    cout << error << '(' << recomendacion << ')'<<endl;
}

void IOpersonal::imprimir_error(string error){
    cout << error << endl;
}

void IOpersonal::reescribir_archivo(string direccion, list<char> *texto){
    ofstream escribir(direccion);
    if(escribir.is_open()){
        for (auto item:(*texto)){
            escribir << item;
        }
        escribir.close();
    }
    else{
        imprimir_error("File not opened.", "Check the path of the file");
    }
}

void IOpersonal::escribir_final(string direccion, list<char> *texto){
    fstream fs;
    fs.open(direccion, fstream::out | fstream::app);
    if (fs.is_open()){
        for (auto item:(*texto)){
            fs << item;
        }
        fs.close();
    }
    else{
        imprimir_error("File not opened.", "Check the path of the file");
    }
}

void IOpersonal::escribir_inicio(string direccion, list<char> *texto){
    list<char>* temp = IOpersonal::leerArchivo(direccion);
    temp->splice(temp->begin(), (*texto));
    reescribir_archivo(direccion, temp);
}

string IOpersonal::Llave(int tamano){
    string _l;
    cout<< "Key: ";
    cin >> _l;
    
    if(_l.length() < tamano){
        cout << "Key incorrect. (size minimum is ";
        cout << tamano;
        cout << ")\n";
        
        
        
        return Llave(tamano);
    }
    
    if(!verificar_numeros(_l)){
        cout << "Key incorrect. (only numbers admitted)\n";
        return Llave(tamano);
    }
    
    return _l;
}

string IOpersonal::Cadena(string pedir, int tamano){
    string _c;
    cout << pedir << ": ";
    cin >> _c;
    
    if(_c.length() < tamano){
        cout << "Invalid entry. (size minimum " << tamano << ")";
        return Cadena(pedir, tamano);
        
    }
    
    if(!verificar_string(_c)){
        cout << "Invalid entry. (only letters)\n";
        return Cadena(pedir, tamano);
    }
    
    return _c;
}


string IOpersonal::Cadena(string pedir){
    string _c;
    cout << pedir << ": ";
    cin >> _c;
    
    return _c;
}

int IOpersonal::número(){
    int _n;
    cout << "Number: ";
    cin >>_n;
    return _n;
}

list<char> * IOpersonal::leerArchivo(string direccion){
    
    cout << "Leyendo archivo...";
    
    list<char> * _texto = new list<char>;
    char caracter;
    
    ifstream leer;
    leer.open(direccion);
    if (leer.is_open()){
        while(leer.get(caracter)){
            _texto->push_back(caracter);
        }
    }
    else{
        cout << "Direccion invalida.\n";
    }
    
    cout << " lectura terminada.\n";
    
    return _texto;
}


//  Función que verifica que el string s este compuesto únicamente por letras,
//  minúsculas y mayúsculas.
//  Si algún caracter es difernete de uno de estps tipos entonces se regresa el valor false.
bool IOpersonal::verificar_string(string s){
    for (int i = 0; i < s.length(); ++i){
        if(s[i] < 65 && s[i] > 91 && s[i] < 97 && s[i] > 122){
            return false;
        }
    }
    return true;
}

//  Función que verifica que el string s este compuesto únicamente por números.
//  Si algún caracter es difernete de uno de estps tipos entonces se regresa el valor false.
bool IOpersonal::verificar_numeros(string s){
    for (int i = 0; i < s.length(); ++i){
        if(s[i] < 48 && s[i] > 57){
            return false;
        }
    }
    return true;
}
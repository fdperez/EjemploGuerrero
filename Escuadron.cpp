#include "Escuadron.h"

Escuadron::Escuadron() : _nombre(""), _MAXguerreros(0), _guerreros(new Guerrero*[_MAXguerreros]) {
    for (int i = 0; i<this->_MAXguerreros; i++) {
        this->_guerreros[i] = nullptr;
    }
}

Guerrero** Escuadron::getGuerreros() const {
    return _guerreros;
}

int Escuadron::getNumGuerrerosActual() const {
    return _numGuerrerosActual;
}

int Escuadron::getMAXguerreros() const {
    return _MAXguerreros;
}

void Escuadron::setNombre(string _nombre) {
    this->_nombre = _nombre;
}

string Escuadron::getNombre() const {
    return _nombre;
}

Escuadron::Escuadron(string _nombre, int _MAXguerreros) : _nombre(_nombre), _MAXguerreros(_MAXguerreros), _guerreros(new Guerrero*[_MAXguerreros]) {
    for (int i = 0; i<this->_MAXguerreros; i++) {
        this->_guerreros[i] = nullptr;
    }
}

Escuadron::Escuadron(const Escuadron& orig) : _nombre(orig._nombre), _numGuerrerosActual(orig._numGuerrerosActual) {
    if (this->_MAXguerreros != orig._MAXguerreros) { //Si son de diferente tamaño, libero la memoria y reservo de nuevo con el nuevo tamaño
        for (int i = 0; i<this->_MAXguerreros; i++) {
            this->_guerreros[i] = nullptr;
        }
        delete []this->_guerreros;


        this->_MAXguerreros = orig._MAXguerreros;
        this->_guerreros = new Guerrero*[this->_MAXguerreros];
    }

    for (int i = 0; i<this->_MAXguerreros; i++) {
        if (orig._guerreros[i] != nullptr) {
            this->_guerreros[i] = new Guerrero(*orig._guerreros[i]);
        } else {
            this->_guerreros[i] = nullptr;
        }
    }
}

Escuadron::~Escuadron() {
    for (int i = 0; i<this->_MAXguerreros; i++) {
        _guerreros[i] = nullptr;
    }
    delete []this->_guerreros;
}

void Escuadron::anadirGuerrero(Guerrero* g) {
    if (g == nullptr) {
        throw string("No hay ningún guerrero que añadir");
    }
    if (this->_numGuerrerosActual >= this->_MAXguerreros) {
        throw string("No se pueden añadir más guerreros");
    }
    this->_guerreros[_numGuerrerosActual] = g;
    this->_numGuerrerosActual++;
}

Guerrero* Escuadron::eliminarGuerrero(int pos) {
    if (this->_guerreros[pos] == nullptr || pos >= this->_numGuerrerosActual) {
        throw string("no hay ningún guerrero en esta posición");
    }
    Guerrero *g = this->_guerreros[pos];
    this->_guerreros[pos] = nullptr;
    this->_numGuerrerosActual--; //Al decrementar antes, no hay que comparar con (_numGuerrerosActual-1) en las siguientes líneas
    if (pos<this->_numGuerrerosActual) { //Si no sacamos el último elemento con datos, reordenamos para que no existan espacios
        this->_guerreros[pos] = this->_guerreros[this->_numGuerrerosActual]; //Movemos el último que había a la posición eliminada 
        this->_guerreros[this->_numGuerrerosActual] = nullptr;
    }
    return g;
}



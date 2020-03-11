#include "Ejercito.h"

Ejercito::Ejercito() : _nombreLider(""), _region(""), _numEscuadronesActual(0), _MAXescuadrones(1), _escuadrones(new Escuadron*[_MAXescuadrones]) {
    this->_escuadrones[0] = nullptr;
}

Escuadron** Ejercito::getEscuadrones() const {
    return _escuadrones;
}

Escuadron* Ejercito::getEscuadron(int pos) {
    if (this->_escuadrones[pos] == nullptr || pos>this->_MAXescuadrones) {
        throw string("no hay ningún guerrero en esta posición");
    }
    return _escuadrones[pos];
}


int Ejercito::getNumEscuadronesActual() const {
    return _numEscuadronesActual;
}

void Ejercito::setNombreLider(string _nombreLider) {
    this->_nombreLider = _nombreLider;
}

string Ejercito::getNombreLider() const {
    return _nombreLider;
}

void Ejercito::setRegion(string _region) {
    this->_region = _region;
}

string Ejercito::getRegion() const {
    return _region;
}

Ejercito::Ejercito(string _region, string _nombre) : _region(_region), _nombreLider(_nombre), _numEscuadronesActual(0), _MAXescuadrones(1), _escuadrones(new Escuadron*[_MAXescuadrones]) {
    this->_escuadrones[0] = nullptr;
}

Ejercito::Ejercito(string _region, string _nombreL, string _nombreEsc, int _maxGuerrerosEsc) : _region(_region), _nombreLider(_nombreL), _numEscuadronesActual(1), _MAXescuadrones(1), _escuadrones(new Escuadron*[_MAXescuadrones]) {
    this->_escuadrones[0] = new Escuadron(_nombreEsc, _maxGuerrerosEsc);
}

Ejercito::Ejercito(const Ejercito& orig) : _region(orig._region), _nombreLider(orig._nombreLider), _numEscuadronesActual(orig._numEscuadronesActual) {
    if (this->_MAXescuadrones != orig._MAXescuadrones) { //Si son de diferente tamaño, libero la memoria y reservo de nuevo con el nuevo tamaño
        for (int i = 0; i<this->_MAXescuadrones; i++) {
            delete this->_escuadrones[i];
            this->_escuadrones[i] = nullptr;
        }
        delete []this->_escuadrones;

        this->_MAXescuadrones = orig._MAXescuadrones;
        this->_escuadrones = new Escuadron*[this->_MAXescuadrones];
    }

    for (int i = 0; i<this->_MAXescuadrones; i++) {
        if (orig._escuadrones[i] != nullptr) {
            this->_escuadrones[i] = new Escuadron(*orig._escuadrones[i]);
        } else {
            this->_escuadrones[i] = nullptr;
        }
    }
}

Ejercito::~Ejercito() {
    for (int i = 0; i<this->_MAXescuadrones; i++) {
        delete this->_escuadrones[i];
        this->_escuadrones[i] = nullptr;
    }
    delete []this->_escuadrones;
}

void Ejercito::anadirEscuadron(string _nombre, int _tam) {
    Escuadron *e = new Escuadron(_nombre, _tam);
    if (this->_numEscuadronesActual<this->_MAXescuadrones) {
        this->_escuadrones[this->_numEscuadronesActual] = e;
        this->_numEscuadronesActual++;
    } else {
        ampliarArray(); //Amplio la zona reservada para el array
        this->_escuadrones[this->_numEscuadronesActual] = e;
        this->_numEscuadronesActual++;
    }
}

void Ejercito::eliminarEscuadron(int pos) {
    if (this->_escuadrones[pos] == nullptr || pos>=this->_numEscuadronesActual) {
        throw string("no hay ningún escuadron en esta posición");
    }
    delete this->_escuadrones[pos];
    this->_escuadrones[pos] = nullptr;
    this->_numEscuadronesActual--;
    if (pos<this->_numEscuadronesActual) { //Si no sacamos el último elemento con datos, reordenamos para que no existan espacios
        this->_escuadrones[pos]=this->_escuadrones[this->_numEscuadronesActual]; //Movemos el último que había a la posición eliminada 
        this->_escuadrones[this->_numEscuadronesActual]=nullptr;
    }
}

int Ejercito::getMAXescuadrones() const {
    return _MAXescuadrones;
}

void Ejercito::ampliarArray() {
    this->_MAXescuadrones *= 2; //Doblo el tamaño que le teniamos asignado al array
    Escuadron **aux = new Escuadron*[this->_MAXescuadrones]; //Creo uno auxiliar
    for (int i = 0; i < _MAXescuadrones; i++) { //Copio todos los elementos del array actual en el auxiliar y los nuevos huecos los inicializo a nullptr
        if (i<this->_numEscuadronesActual) {
            aux[i] = this->_escuadrones[i];
        } else {
            aux[i] = nullptr;
        }
    }

    delete []this->_escuadrones; //Libero el espacio que le tenía reservado al antiguo array.
    this->_escuadrones = aux; //Hago que apunte al auxiliar que he creado.
}



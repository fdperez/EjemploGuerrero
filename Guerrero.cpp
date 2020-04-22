
#include <sstream>

#include "Guerrero.h"

Guerrero::~Guerrero() {
    for (int i = 0; i < _numArmas; i++) {
        this->_armas[i] = nullptr;
    }
}

Guerrero::Guerrero(string _nombre, float _fuerza, float _resistencia, float _salud) : _nombre(_nombre), _fuerza(_fuerza), _resistencia(_resistencia), _salud(_salud), _numArmasActual(0) {
    for (int i = 0; i < _numArmas; i++) {
        this->_armas[i] = nullptr;
    }
}

Guerrero::Guerrero() : _nombre(""), _fuerza(0), _resistencia(0), _salud(0), _numArmasActual(0) {
    for (int i = 0; i < _numArmas; i++) {
        this->_armas[i] = nullptr;
    }
}

Arma* Guerrero::GetArma(int pos) {
    if (this->_armas[pos] = nullptr) {
        throw string("no hay ningún arma en esta posición");
    }
    return this->_armas[pos];
}

int Guerrero::GetNumArmasActual() const {
    return _numArmasActual;
}

Guerrero::Guerrero(const Guerrero& orig) : _nombre(orig._nombre), _fuerza(orig._fuerza), _resistencia(orig._resistencia), _salud(orig._salud), _numArmasActual(orig._numArmasActual) {
    for (int i = 0; i < _numArmas; i++) { //Siempre tienen el mismo tamaño los arrays
        if (orig._armas[i] != nullptr) {
            this->_armas[i] = orig._armas[i];
        } else {
            this->_armas[i] = nullptr;
        }
    }
}

void Guerrero::SetSalud(float _salud) {
    this->_salud = _salud;
}

float Guerrero::GetSalud() const {
    return _salud;
}

void Guerrero::SetResistencia(float _resistencia) {
    this->_resistencia = _resistencia;
}

float Guerrero::GetResistencia() const {
    return _resistencia;
}

void Guerrero::SetFuerza(float _fuerza) {
    this->_fuerza = _fuerza;
}

float Guerrero::GetFuerza() const {
    return _fuerza;
}

void Guerrero::SetNombre(string _nombre) {
    this->_nombre = _nombre;
}

string Guerrero::GetNombre() const {
    return _nombre;
}

void Guerrero::anadirArma(Arma* a) {
    if (a==nullptr){
        throw string("No hay ningún arma");
    }
    if (this->_numArmasActual >= _numArmas) {
        throw string("No se pueden añadir más armas");
    }
    this->_armas[this->_numArmasActual] = a;
    this->_numArmasActual++;
}

Arma** Guerrero::desarmar() {
    Arma** la = new Arma*[_numArmasActual];
    for (int i = _numArmasActual-1; i >= 0; i--) { //Para empezar a sacar por el último y no tener que reordenar
        la[i] = soltarArma(i);
    }
    return la;
}

Arma* Guerrero::soltarArma(int pos) {
    if (this->_armas[pos] == nullptr || pos>=this->_numArmasActual) {
        throw string("no hay ningún arma en esta posición");
    }
    Arma *a = this->_armas[pos];
    this->_armas[pos] = nullptr;
    this->_numArmasActual--; //Al decrementar antes, no hay que comparar con (_numArmasActual-1) en las siguientes líneas
    if (pos<this->_numArmasActual) { //Si no sacamos el último elemento con datos, reordenamos para que no existan espacios
        this->_armas[pos] = this->_armas[_numArmasActual]; //Movemos el último que había a la posición eliminada 
        this->_armas[_numArmasActual] = nullptr;
    }
    return a;
}

bool Guerrero::operator<=(const Guerrero& g) {
    return this->_fuerza<=g._fuerza;
}

string Guerrero::toCSV() {
    stringstream ss;
    ss<<this->_nombre<<";"<<this->_fuerza<<";"<<this->_resistencia<<";"<<this->_salud<<";"<<this->_numArmasActual;
    return ss.str();
}

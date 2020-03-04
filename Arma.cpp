#include "Arma.h"

Arma::~Arma() {
}

void Arma::SetDuracion(int _duracion) {
    this->_duracion = _duracion;
}

int Arma::GetDuracion() const {
    return _duracion;
}

void Arma::SetPoder(float _poder) {
    this->_poder = _poder;
}

float Arma::GetPoder() const {
    return _poder;
}

void Arma::SetNombre(string _nombre) {
    this->_nombre = _nombre;
}

string Arma::GetNombre() const {
    return _nombre;
}


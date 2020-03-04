
#include "Armero.h"

Armero::~Armero() {
}

void Armero::SetLimitePoder(float _limitePoder) {
    this->_limitePoder = _limitePoder;
}

float Armero::GetLimitePoder() const {
    return _limitePoder;
}

void Armero::SetNombre(string _nombre) {
    this->_nombre = _nombre;
}

string Armero::GetNombre() const {
    return _nombre;
}


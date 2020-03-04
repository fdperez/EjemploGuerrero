
#include "Guerrero.h"

Guerrero::~Guerrero() {
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


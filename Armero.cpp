
#include "Armero.h"

Armero::~Armero() {
}

Armero::Armero(string _nombre, float _limitePoder):_nombre(_nombre), _limitePoder(_limitePoder) {

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

Arma* Armero::crearArma(string _nombre, float _poder) {
    if(_poder<0 || _poder>this->_limitePoder){
        throw out_of_range("El poder del arma está fuera de rango");
    }
    return new Arma(_nombre,_poder,50);
}

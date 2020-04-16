#include "Lancero.h"

Lancero::Lancero(const Lancero& orig) : Guerrero(orig), _rangoAtaque(_rangoAtaque) {

}

Lancero::Lancero(string _nombre, float _fuerza, float _resistencia, float _salud, int _rangoAtaque) : Guerrero(_nombre, _fuerza, _resistencia, _salud), _rangoAtaque(_rangoAtaque) {

}

Lancero::~Lancero() {

}

void Lancero::SetRangoAtaque(int rangoAtaque) {
    this->_rangoAtaque = rangoAtaque;
}

int Lancero::GetRangoAtaque() const {
    return this->_rangoAtaque;
}

string Lancero::toCSV() {
    stringstream ss;
    ss << Guerrero::toCSV() << ";" << this->_rangoAtaque;
    return ss.str();
}

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
    ss << this->_rangoAtaque << ";" /*<< Guerrero::toCSV()*/;
    return ss.str();
}

/**
 * 
 * @pre El formato de la cadena debe ser el siguiente: rangoAtaque;nombre;fuerza;resistencia;salud
 */
void Lancero::fromCSV(string cadena) {
    stringstream ss(cadena);
    ss>>this->_rangoAtaque;
    ss.ignore(1);
    string aux;
    getline(ss, aux);
    Guerrero::fromCSV(aux);
}

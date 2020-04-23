#include <sstream>

#include "Arquero.h"

Arquero::Arquero(const Arquero& orig) : Guerrero(orig), flechas(orig.flechas) {
}

Arquero::~Arquero() {
}

void Arquero::SetFlechas(bool flechas) {
    this->flechas = flechas;
}

bool Arquero::IsFlechas() const {
    return flechas;
}

string Arquero::toCSV() {
    stringstream ss;
    ss << this->flechas << ";" << Guerrero::toCSV();
    return ss.str();
}

/**
 * 
 * @pre El formato de la cadena debe ser el siguiente: rangoAtaque;nombre;fuerza;resistencia;salud
 */
void Arquero::fromCSV(string cadena) {
    stringstream ss(cadena);
    ss>>this->flechas;
    ss.ignore(1);
    string aux;
    getline(ss, aux);
    Guerrero::fromCSV(aux);
}

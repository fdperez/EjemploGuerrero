#include <sstream>

#include "Arquero.h"

Arquero::Arquero(const Arquero& orig):Guerrero(orig), flechas(orig.flechas) {
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
    ss<<Guerrero::toCSV()<<";"<<this->flechas;
    return ss.str();
}

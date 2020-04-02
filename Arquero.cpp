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
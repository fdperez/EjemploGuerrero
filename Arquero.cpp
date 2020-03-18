/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arquero.cpp
 * Author: Daniel
 * 
 * Created on 18 de marzo de 2020, 11:24
 */

#include "Arquero.h"

Arquero::Arquero() {
}

Arquero::Arquero(const Arquero& orig) {
}

Arquero::~Arquero() {
}

void Arquero::SetFlechas(bool flechas) {
    this->flechas = flechas;
}

bool Arquero::IsFlechas() const {
    return flechas;
}
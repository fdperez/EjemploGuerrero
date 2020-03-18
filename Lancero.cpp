/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lancero.cpp
 * Author: Daniel
 * 
 * Created on 18 de marzo de 2020, 11:23
 */

#include "Lancero.h"

Lancero::Lancero(const Lancero& orig) {
}

Lancero::~Lancero() {
}

void Lancero::SetRangoAtaque(int rangoAtaque) {
    this->rangoAtaque = rangoAtaque;
}

int Lancero::GetRangoAtaque() const {
    return rangoAtaque;
}


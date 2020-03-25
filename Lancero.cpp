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

Lancero::Lancero(string _nombre, float _fuerza, float _resistencia, float _salud, int _rangoAtaque):Guerrero(_nombre, _fuerza, _resistencia, _salud), _rangoAtaque(_rangoAtaque) {
}


Lancero::Lancero(const Lancero& orig):Guerrero(orig), _rangoAtaque(orig._rangoAtaque) {
}

Lancero::~Lancero() {
}

void Lancero::SetRangoAtaque(int rangoAtaque) {
    this->_rangoAtaque = rangoAtaque;
}

int Lancero::GetRangoAtaque() const {
    return _rangoAtaque;
}

string Lancero::GetNombre() const {
    return "Este método ha sido redefinido";
}
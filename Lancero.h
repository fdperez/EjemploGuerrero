/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lancero.h
 * Author: Daniel
 *
 * Created on 18 de marzo de 2020, 11:23
 */

#ifndef LANCERO_H
#define LANCERO_H

#include "Guerrero.h"
#include <string>
using namespace std;

class Lancero:public Guerrero {
public:
    Lancero() = default;
    Lancero(string _nombre, float _fuerza, float _resistencia, float _salud, int _rangoAtaque);
    Lancero(const Lancero& orig);
    virtual ~Lancero();
    void SetRangoAtaque(int rangoAtaque);
    int GetRangoAtaque() const;
    string GetNombre() const;

private:
    int _rangoAtaque = 0;
};

#endif /* LANCERO_H */


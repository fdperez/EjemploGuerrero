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

class Lancero:public Guerrero {
public:
    Lancero() = default;
    Lancero(const Lancero& orig);
    virtual ~Lancero();
    void SetRangoAtaque(int rangoAtaque);
    int GetRangoAtaque() const;

private:
    int rangoAtaque = 0;
};

#endif /* LANCERO_H */


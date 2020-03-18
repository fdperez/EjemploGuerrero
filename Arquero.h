/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arquero.h
 * Author: Daniel
 *
 * Created on 18 de marzo de 2020, 11:24
 */

#ifndef ARQUERO_H
#define ARQUERO_H

class Arquero {
public:
    Arquero();
    Arquero(const Arquero& orig);
    virtual ~Arquero();
    void SetFlechas(bool flechas);
    bool IsFlechas() const;

private:
    bool flechas = false;
};

#endif /* ARQUERO_H */


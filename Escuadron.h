/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escuadron.h
 * Author: Juan
 *
 * Created on 11 de marzo de 2020, 11:37
 */

#ifndef ESCUADRON_H
#define ESCUADRON_H

#include <iostream>
#include "Guerrero.h"
using namespace std;

class Escuadron {
public:
    Escuadron();
    Escuadron(string _nombre, int _MAXguerreros);
    Escuadron(const Escuadron& orig);
    virtual ~Escuadron();
    int getMAXguerreros() const;
    void setNombre(string _nombre);
    string getNombre() const;
    int getNumGuerrerosActual() const;
    void anadirGuerrero(Guerrero *g);
    Guerrero* eliminarGuerrero(int pos);
    Guerrero** getGuerreros() const;

private:
    string _nombre;
    int _MAXguerreros;
    int _numGuerrerosActual;
    Guerrero **_guerreros;
};

#endif /* ESCUADRON_H */


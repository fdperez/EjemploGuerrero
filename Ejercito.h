#ifndef EJERCITO_H
#define EJERCITO_H

#include <iostream>
#include "Escuadron.h"
using namespace std;

class Ejercito {
public:
    Ejercito();
    Ejercito(string _region, string _nombre);
    Ejercito(string _region, string _nombreL, string _nombreEsc, int _maxGuerrerosEsc); //Recibe los datos necarios para poder generar un escuadrón al crear el ejército
    Ejercito(const Ejercito& orig);
    Escuadron** getEscuadrones() const;
    Escuadron *getEscuadron(int pos);
    int getNumEscuadronesActual() const;
    void setNombreLider(string _nombreLider);
    string getNombreLider() const;
    void setRegion(string _region);
    string getRegion() const;
    int getMAXescuadrones() const;
    virtual ~Ejercito();
    void anadirEscuadron(string _nombre, int _tam);
    void eliminarEscuadron(int pos);

private:
    string _region;
    string _nombreLider;
    int _MAXescuadrones; //Por defecto siempre va a valer 1 ya que vamos a ir aumentando el tamaño
    // según la necesidad que tengamos a la hora de crear escuadrones
    int _numEscuadronesActual;
    Escuadron **_escuadrones;
    
    void ampliarArray();
};

#endif /* EJERCITO_H */


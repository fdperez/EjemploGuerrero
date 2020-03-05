#include <string>
#include "Arma.h"
using namespace std;

#ifndef GUERRERO_H
#define GUERRERO_H

class Guerrero {
public:
    Guerrero()=default;
    Guerrero(string _nombre, float _fuerza, float _resistencia, float _salud);
    Guerrero(const Guerrero& orig)=default;
    virtual ~Guerrero();
    void SetSalud(float _salud);
    float GetSalud() const;
    void SetResistencia(float _resistencia);
    float GetResistencia() const;
    void SetFuerza(float _fuerza);
    float GetFuerza() const;
    void SetNombre(string _nombre);
    string GetNombre() const;
    
private:
    string _nombre="";
    float _fuerza=0;
    float _resistencia=0;
    float _salud=0;
    int _tam=10;
    Arma* armas[10];
};

#endif /* GUERRERO_H */


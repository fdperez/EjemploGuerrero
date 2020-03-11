#include <string>
#include "Arma.h"
using namespace std;

#ifndef GUERRERO_H
#define GUERRERO_H

class Guerrero {
public:
    Guerrero();
    Guerrero(string _nombre, float _fuerza, float _resistencia, float _salud);
    Guerrero(const Guerrero& orig);
    virtual ~Guerrero();
    void SetSalud(float _salud);
    float GetSalud() const;
    void SetResistencia(float _resistencia);
    float GetResistencia() const;
    void SetFuerza(float _fuerza);
    float GetFuerza() const;
    void SetNombre(string _nombre);
    string GetNombre() const;
    int GetNumArmasActual() const;
    Arma* GetArma(int pos);
    void anadirArma(Arma *a);
    Arma* soltarArma(int pos);
    Arma** desarmar();

    static const int _numArmas = 3;
private:
    string _nombre = "";
    float _fuerza = 0;
    float _resistencia = 0;
    float _salud = 0;
    int _numArmasActual = 0;
    Arma* _armas[_numArmas];
};

#endif /* GUERRERO_H */


#include <string>
#include "Arma.h"
#include "ItemCSV.h"
using namespace std;

#ifndef GUERRERO_H
#define GUERRERO_H

class Guerrero: public ItemCSV {
public:
    //Los constructores no son necesarios en una clase abstracta ya que nunca se van a crear objetos pero nos permiten reutilizar la implementación
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
    bool operator<=(const Guerrero &g);
    
    //Método virtual puro (=0) Al tener uno, ya se considera una clase abstracta
    virtual string toCSV()=0;
    virtual void fromCSV(string cadena)=0;

    
    static const int _numArmas = 3;
protected:
    string _nombre = "";
    float _fuerza = 0;
    float _resistencia = 0;
    float _salud = 0;
    int _numArmasActual = 0;
    Arma* _armas[_numArmas];
};

#endif /* GUERRERO_H */


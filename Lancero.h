#ifndef LANCERO_H
#define LANCERO_H

#include "Guerrero.h"
#include <string>
using namespace std;

template<typename T=int, typename Y=bool> //tipos por defecto
class Lancero : public Guerrero {
public:
    Lancero(string _nombre, float _fuerza, float _resistencia, float _salud, T _rangoAtaque, Y _salto);
    Lancero(const Lancero<T,Y> &orig);
    virtual ~Lancero();
    void SetRangoAtaque(T rangoAtaque);
    T GetRangoAtaque() const;
    void SetSalto(Y _salto);
    Y GetSalto() const;

    //string GetNombre() const; //Declaración del método redefinido

private:
    T _rangoAtaque;
    Y _salto;
};

//Se implementan aquí (.H) porque el compilador instancia y compila una copia diferente cuando necesite 

template<typename T, typename Y>
Lancero<T, Y>::Lancero(string _nombre, float _fuerza, float _resistencia, float _salud, T _rangoAtaque, Y _salto) : Guerrero(_nombre, _fuerza, _resistencia, _salud), _rangoAtaque(_rangoAtaque), _salto(_salto) {
}

template<typename T, typename Y>
Lancero<T, Y>::Lancero(const Lancero<T, Y> &orig) : Guerrero(orig), _rangoAtaque(orig._rangoAtaque), _salto(orig._salto) {
}

template<typename T, typename Y>
Lancero<T, Y>::~Lancero() {
}

template<typename T, typename Y>
void Lancero<T, Y>::SetRangoAtaque(T rangoAtaque) {
    this->_rangoAtaque = rangoAtaque;
}

template<typename T, typename Y>
T Lancero<T, Y>::GetRangoAtaque() const {
    return _rangoAtaque;
}

template<typename T, typename Y>
void Lancero<T, Y>::SetSalto(Y _salto) {
    this->_salto = _salto;
}

template<typename T, typename Y>
Y Lancero<T, Y>::GetSalto() const {
    return _salto;
}

#endif /* LANCERO_H */


#ifndef LANCERO_H
#define LANCERO_H

#include "Guerrero.h"
#include <string>
#include <sstream>
using namespace std;

class Lancero : public Guerrero {
public:
    Lancero() = default;
    Lancero(string _nombre, float _fuerza, float _resistencia, float _salud, int _rangoAtaque);
    Lancero(const Lancero& orig);
    virtual ~Lancero();
    void SetRangoAtaque(int rangoAtaque);
    int GetRangoAtaque() const;
    virtual string toCSV() override;
    
private:
    int _rangoAtaque = 0;
};

#endif /* LANCERO_H */


#ifndef ARQUERO_H
#define ARQUERO_H

#include "Guerrero.h"

class Arquero:public Guerrero{
public:
    Arquero()=default;
    Arquero(const Arquero& orig);
    virtual ~Arquero();
    void SetFlechas(bool flechas);
    bool IsFlechas() const;

private:
    bool flechas = false;
};

#endif /* ARQUERO_H */


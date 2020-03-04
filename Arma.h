#include <string>
using namespace std;

#ifndef ARMA_H
#define ARMA_H

class Arma {
public:
    Arma()=default;
    Arma(const Arma& orig)=default;
    virtual ~Arma();
    void SetDuracion(int _duracion);
    int GetDuracion() const;
    void SetPoder(float _poder);
    float GetPoder() const;
    void SetNombre(string _nombre);
    string GetNombre() const;
    
private:
    string _nombre="";
    float _poder=0;
    int _duracion=0;
};

#endif /* ARMA_H */


#include <string>
using namespace std;

#ifndef ARMERO_H
#define ARMERO_H

class Armero {
public:
    Armero()=default;
    Armero(const Armero& orig)=default;
    virtual ~Armero();
    void SetLimitePoder(float _limitePoder);
    float GetLimitePoder() const;
    void SetNombre(string _nombre);
    string GetNombre() const;
    
private:
    string _nombre="";
    float _limitePoder=0;
};

#endif /* ARMERO_H */


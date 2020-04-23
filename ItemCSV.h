#ifndef ITEMCSV_H
#define ITEMCSV_H

#include <string>

class ItemCSV {
public:
    virtual std::string toCSV()=0;
    virtual void fromCSV(std::string cadena)=0;
    virtual ~ItemCSV(){};
};

#endif /* ITEMCSV_H */


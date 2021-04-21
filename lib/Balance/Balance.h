#ifndef BALANCE_H
#define BALANCE_H

#include "Capteur.h"

class Balance
{
private:

Capteur un;
Capteur deux;
Capteur trois;
Capteur quatre;

public:

    Balance();
    void mesurer_poids();
    
};


#endif // BALANCE_H

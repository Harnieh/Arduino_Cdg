#ifndef PLATEAU_H
#define PLATEAU_H

#include "Axe.h"

class Plateau
{
private:
    
    Axe axeX;   
    Axe axeY;
    Axe palpeur;

    short increment;

public:

    Plateau();


    void setupPlateau();
    void deplacerPlateau();

    void Increment1() { increment = 1; }
    void Increment10() { increment = 10; }
    void Increment100() { increment = 100;}
    void Increment1000() { increment = 1000; }


// Plateau::Plateau(/* args */)
// {
// }
};





#endif // PLATEAU_H

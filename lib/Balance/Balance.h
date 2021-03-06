#ifndef BALANCE_H
#define BALANCE_H

#include "Capteur.h"

class Balance
{
private:

float poidsPlateau=0;   //float plateau_poids;

Capteur un;
Capteur deux;
Capteur trois;
Capteur quatre;

float mesure_poids;

public:

    Balance();
    void tareZero();   // tare  pour déterminer à zéro
    void tareConnue(); //mesure du poids avec tare connue pour déterminer le facteur d'écchelle
    void mesurerPoidsPlateauAVide();
    float mesurer_poids();
};


#endif // BALANCE_H

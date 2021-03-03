#ifndef SERVOMOTEUR_H
#define SERVOMOTEUR_H

#include <stdint.h>

class Servomoteur
{
    private:
    uint8_t pinStep;    //Pin défini step 
    uint8_t PinDirection;   //Pin défini direction
    long position_pas;   //Position sur l'axe en pas (long ?_position_pas)
    float position_mm;    //Position sur l'axe en mm (float ?_position_mm)
    float facteurDeConversion;    //Facteur de conversion en mm par pas pour l'axe (float ?_facteur)
    long limiteMin;     //Limite minimale de l'axe en ?? (long ?_min)
    long limiteMax;     //Limite maximale de l'axe (long ?_max)

    public:

    Servomoteur(uint8_t pinStep, uint8_t pinDirection);  //Constructeur par défaut
};

#endif // SERVOMOTEUR_H
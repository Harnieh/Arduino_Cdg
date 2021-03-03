#include "Servomoteur.h"

Servomoteur::Servomoteur(uint8_t pinDuPas, uint8_t pinDeDirection)  //Constructeur par défaut 
{
    uint8_t pinStep = pinDuPas;
    uint8_t pinDirection = pinDeDirection;
    long position_pas;   //Position sur l'axe en pas (long ?_position_pas)
    float position_mm;    //Position sur l'axe en mm (float ?_position_mm)
    float facteurDeConversion;    //Facteur de conversion en mm par pas pour l'axe (float ?_facteur)
    long limiteMin;     //Limite minimale de l'axe en ?? (long ?_min)
    long limiteMax;     //Limite maximale de l'axe en ?? (long ?_max)
}
#include "Servomoteur.h"

Servomoteur::Servomoteur()  //Constructeur par défaut 
{
    long position_pas=0;   //Position sur l'axe en pas (long ?_position_pas)
    float position_mm=0;    //Position sur l'axe en mm (float ?_position_mm)
    float facteurDeConversion=0;    //Facteur de conversion en mm par pas pour l'axe (float ?_facteur)
    long limiteMin;     //Limite minimale de l'axe en ?? (long ?_min)
    long limiteMax;     //Limite maximale de l'axe en ?? (long ?_max)
}
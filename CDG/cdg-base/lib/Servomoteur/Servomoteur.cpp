#include "Servomoteur.h"
#include "Arduino.h"

Servomoteur::Servomoteur(uint8_t pinDuPas, uint8_t pinDeDirection, long positionPas, float positionMm, float facteur, long min, long max)  //Constructeur du moteur
{  
    pinStep = pinDuPas;
    pinDirection = pinDeDirection;
    position_pas = positionPas;   //Position sur l'axe en pas (long ?_position_pas)
    position_mm = positionMm;    //Position sur l'axe en mm (float ?_position_mm)
    facteurDeConversion = facteur;    //Facteur de conversion en mm par pas pour l'axe (float ?_facteur)
    limiteMin = min;     //Limite minimale de l'axe en ?? (long ?_min)
    limiteMax = max;     //Limite maximale de l'axe en ?? (long ?_max)
}

void Servomoteur::setup()
{
    AccelStepper servo(AccelStepper::DRIVER, pinStep, pinDirection);

}
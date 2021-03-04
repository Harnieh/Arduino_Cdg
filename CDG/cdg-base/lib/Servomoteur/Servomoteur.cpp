#include "Servomoteur.h"
#include "Arduino.h"

Servomoteur::Servomoteur(uint8_t pinDuPas, uint8_t pinDeDirection, float facteur, int vitessemax, int acceleration)  //Constructeur du moteur
{  
    pinStep = pinDuPas;
    pinDirection = pinDeDirection;

    servoVitesseMaxPas = vitessemax;
    servoAccelerationPas = acceleration;

    facteurDeConversion = facteur;    //Facteur de conversion en mm par pas pour l'axe (float ?_facteur)


//AXE   axePosition_pas = positionPas;   //Position sur l'axe en pas (long ?_position_pas)
//AXE   axePosition_mm = positionMm;    //Position sur l'axe en mm (float ?_position_mm)
//AXE   axeLimiteMin = min;     //Limite minimale de l'axe en ?? (long ?_min)
//AXE   axeLimiteMax = max;     //Limite maximale de l'axe en ?? (long ?_max)
}

void Servomoteur::setup()
{
    AccelStepper servo(AccelStepper::DRIVER, pinStep, pinDirection); // création objet AccelStepper pour piloter les moteurs pas à pas
    digitalWrite(pinDirection, 0);
    servo.setMaxSpeed(servoVitesseMaxPas);
    servo.setAcceleration(servoAccelerationPas);
}

void Servomoteur::run(AccelStepper choixMoteur)
{
    choixMoteur.runSpeed();
}




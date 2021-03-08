#include "Servomoteur.h"
#include "Arduino.h"

Servomoteur::Servomoteur(uint8_t pinDuPas, uint8_t pinDeDirection, float facteur, int vitessemax, int acceleration)  //Constructeur du moteur
{  
     Serial.println("Constru servo");

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
    Serial.println("entree setup servo");
    AccelStepper servo(AccelStepper::DRIVER, pinStep, pinDirection); // création objet AccelStepper pour piloter les moteurs pas à pas
    Serial.println("setup servo: creation de l accelstepper");
 
    digitalWrite(pinDirection, 1);
    Serial.println("setup servo: digital write");
 
    servo.setMaxSpeed(servoVitesseMaxPas);
    Serial.println("setup servo: setMaxSpeed");
 
    servo.setAcceleration(servoAccelerationPas);
    Serial.println("setup servo: setAcceleration");
  
    servo.setCurrentPosition(0);
    Serial.println("setup servo: setcurrentpos");
}

void Servomoteur::run()
{  
Serial.println("MARCHE servo");
Serial.print("pinStep:");
Serial.println(pinStep);
Serial.print("pindirection:");
Serial.println(pinDirection);
servo.runToNewPosition(100);
}




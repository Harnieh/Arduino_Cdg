#include "Servomoteur.h"
#include "Arduino.h"


Servomoteur::Servomoteur(uint8_t pinDuPas, uint8_t pinDeDirection, float facteur, int vitessemax, int acceleration)  //Constructeur du moteur
{  
#define pinsensmoteur2
#define pinenable

     Serial.println("Constru servo");

    pinStep = pinDuPas;
    pinDirection = pinDeDirection;

    piloteVitesseMaxPas = vitessemax;
    piloteAccelerationPas = acceleration;

    facteurDeConversion = facteur;    //Facteur de conversion en mm par pas pour l'axe (float ?_facteur)

 
//AXE   axePosition_pas = positionPas;   //Position sur l'axe en pas (long ?_position_pas)
//AXE   axePosition_mm = positionMm;    //Position sur l'axe en mm (float ?_position_mm)
//AXE   axeLimiteMin = min;     //Limite minimale de l'axe en ?? (long ?_min)
//AXE   axeLimiteMax = max;     //Limite maximale de l'axe en ?? (long ?_max)
}

void Servomoteur::setup()
{
    Serial.println("entree setup pilote");
    AccelStepper pilote(AccelStepper::DRIVER, pinStep, pinDirection); // création objet AccelStepper pour piloter les moteurs pas à pas
    Serial.println("setup pilote: creation de l accelstepper");
 
 //   pinMode(PIN_SENS_MOTEUR2, OUTPUT); // sortie digitale contrôle de direction du moteur 2 de l'axe X (le nombre de pas est dupliqué du moteur 1 sur la carte)
 //   digitalWrite(PIN_SENS_MOTEUR2, 0);
 //   pinMode(PIN_ENABLE, OUTPUT); // sortie digitale contrôle de direction du moteur 2 de l'axe X (le nombre de pas est dupliqué du moteur 1 sur la carte)
 //   digitalWrite(PIN_ENABLE, 0);

    Serial.println("setup pilote: digital write");
 
    pilote.setMaxSpeed(piloteVitesseMaxPas);
    Serial.println("setup pilote: setMaxSpeed");
 
    pilote.setAcceleration(piloteAccelerationPas);
    Serial.println("setup pilote: setAcceleration");
  
   // pilote.setCurrentPosition(0);    
   // Serial.println("setup pilote: setcurrentpos");
}

void Servomoteur::run()
{  
Serial.println("MARCHE pilote");
Serial.print("pinStep:");
Serial.println(pinStep);    // Retour serial des pins
Serial.print("pindirection:");
Serial.println(pinDirection);   // Retour serial des pins
//servo.runToNewPosition(10); //Vas a la position 10
}




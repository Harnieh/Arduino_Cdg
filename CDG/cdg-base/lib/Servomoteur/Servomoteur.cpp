#include "Servomoteur.h"
#include "Arduino.h"
//#define pinsensmoteur2 9
//#define pinenable 8

Servomoteur::Servomoteur(uint8_t pinDuPas, uint8_t pinDeDirection, /*float facteur,*/ int vitessemax, int acceleration): AccelStepper(AccelStepper::DRIVER,pinDuPas, pinDeDirection)  //Constructeur du moteur
{  

   Serial.println("Constru servo");

   pinStep = pinDuPas;
   pinDirection = pinDeDirection;
   //facteurDeConversion = facteur;    //Facteur de conversion en mm par pas pour l'axe (float ?_facteur)
   piloteVitesseMaxPas = vitessemax;
   piloteAccelerationPas = acceleration;


  //a pinMode(pinsensmoteur2, OUTPUT); // sortie digitale contrôle de direction du moteur 2 de l'axe X (le nombre de pas est dupliqué du moteur 1 sur la carte)
  //A digitalWrite(pinsensmoteur2, 0);
   //a pinMode(pinenable, OUTPUT); // sortie digitale contrôle de direction du moteur 2 de l'axe X (le nombre de pas est dupliqué du moteur 1 sur la carte)
   //a digitalWrite(pinenable, 0);  
//a Serial.println("setup pilote: digital write");
//AXE   axePosition_pas = positionPas;   //Position sur l'axe en pas (long ?_position_pas)
//AXE   axePosition_mm = positionMm;    //Position sur l'axe en mm (float ?_position_mm)
//AXE   axeLimiteMin = min;     //Limite minimale de l'axe en ?? (long ?_min)
//AXE   axeLimiteMax = max;     //Limite maximale de l'axe en ?? (long ?_max)
}

void Servomoteur::setup()
{
   Serial.println("entree setup");
 //  AccelStepper* pilote(AccelStepper::DRIVER, pinStep, pinDirection); // création objet AccelStepper pour piloter les moteurs pas à pas
// Serial.println("setup pilote: creation de l accelstepper");
 
   //   pinMode(PIN_SENS_MOTEUR2, OUTPUT); // sortie digitale contrôle de direction du moteur 2 de l'axe X (le nombre de pas est dupliqué du moteur 1 sur la carte)
   //   digitalWrite(PIN_SENS_MOTEUR2, 0);
   //   pinMode(PIN_ENABLE, OUTPUT); // sortie digitale contrôle de direction du moteur 2 de l'axe X (le nombre de pas est dupliqué du moteur 1 sur la carte)
   //   digitalWrite(PIN_ENABLE, 0);
 
   setMaxSpeed(piloteVitesseMaxPas);
   Serial.println("setMaxSpeed");

   setAcceleration(piloteAccelerationPas);
   Serial.println("setAcceleration");
  
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

   runToNewPosition(-100); //Vas a la position 10
}
#include "Servomoteur.h"
#include "Arduino.h"
#define pinsensmoteur2 9
#define pinenable 8

Servomoteur::Servomoteur(int pinDuPas, int pinDeDirection, /*float facteur,*/ int vitessemax, int acceleration) : AccelStepper(AccelStepper::DRIVER, pinDuPas, pinDeDirection) //Constructeur du moteur
{
   AccelStepper xaxis(AccelStepper::DRIVER, pinDuPas, pinDeDirection);

   pinStep = pinDuPas;    //Pin défini step 
   pinDirection = pinDeDirection;   //Pin défini direction
   piloteVitesseMaxPas = vitessemax;    //Vitesse en pas par seconde
   piloteAccelerationPas = acceleration;

   positionPas = 0;
   position_mm = 0; //position sur l'axe x en mm
}

void Servomoteur::setup()
{
   

   pinMode(pinenable, OUTPUT);
   pinMode(pinsensmoteur2, OUTPUT);
   digitalWrite(pinsensmoteur2,1);//1 negatif 0 positif
   digitalWrite(pinenable,0);
}

void Servomoteur::deplacer(long dist_mm) //procédure de déplacement sur une position ABSOLUE en pas
{
   AccelStepper xaxis(AccelStepper::DRIVER, pinStep, pinDirection);
   xaxis.setCurrentPosition(0);
   Serial.println("setcurrentpos");

   xaxis.setMaxSpeed(500);
   Serial.println("setMaxSpeed");

   xaxis.setAcceleration(200);
   Serial.println("setAcceleration");
   if (dist_mm > 0)
   {
      digitalWrite(pinsensmoteur2, 0); //le moteur 2 de l'axe X tourne en sens inverse du moteur 1
     
      Serial.println("digitalwritesens 0");
   }
   else
   {
      digitalWrite(pinsensmoteur2, 1); //le moteur 2 de l'axe X tourne en sens inverse du moteur 1
     
      Serial.println("digitalwritesens 1");
   }
   if (dist_mm != 0)
   {
      xaxis.runToNewPosition(dist_mm);
      positionPas = dist_mm;
      position_mm = positionPas * facteur;
     // envoie_donnees(1, position_mm); //envoie la nouvelle position en x pour affichage case 1
     
      Serial.println(positionPas);
   }
} //fin de la procédure de déplacement

/**/
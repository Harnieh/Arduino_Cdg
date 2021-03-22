#include "MoteurPasAPaS.h"
#include "Arduino.h"
#define pinsensmoteur2 9
#define pinenable 8

MoteurPasAPas::MoteurPasAPas(int pinDuPas, int pinDeDirection, /*float facteur,*/ int vitessemax, int acceleration) : AccelStepper(AccelStepper::DRIVER, pinDuPas, pinDeDirection) //Constructeur du moteur
{
   AccelStepper xaxis(AccelStepper::DRIVER, pinDuPas, pinDeDirection);

   pinStep = pinDuPas;    //Pin défini step 
   pinDirection = pinDeDirection;   //Pin défini direction
   piloteVitesseMaxPas = vitessemax;    //Vitesse en pas par seconde
   piloteAccelerationPas = acceleration;

   positionPas = 0;
   position_mm = 0; //position sur l'axe x en mm
}

void MoteurPasAPas::setup()
{
   pinMode(pinenable, OUTPUT);
   pinMode(pinsensmoteur2, OUTPUT);
   digitalWrite(pinsensmoteur2,1);//1 negatif 0 positif
   digitalWrite(pinenable,0);
}

void MoteurPasAPas::deplacer(long dist_mm) //procédure de déplacement sur une position ABSOLUE en pas
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
      
   }
} //fin de la procédure de déplacement

void MoteurPasAPas::debug() {
   Serial.print("piloteAccelerationPas");
   Serial.println(piloteAccelerationPas);

   Serial.print("piloteVitesseMaxPas=");
   Serial.println(piloteVitesseMaxPas);

   Serial.print("pinDirection=");
   Serial.println(pinDirection);

   Serial.print("pinStep=");
   Serial.println(pinStep);
   
   Serial.print("facteur=");
   Serial.println(facteur);

   Serial.print("positionPas=");
   Serial.println(positionPas);

   Serial.print("position_mm=");
   Serial.println(positionPas);
}

/**/
#include "MoteurPasAPaS.h"
#include "Arduino.h"
#include "SensMoteur.h"
#define pinsensmoteur2 9
#define pinenable 8

MoteurPasAPas::MoteurPasAPas(int pinDuPas, int pinDeDirection, /*float facteur,*/ int vitessemax, int acceleration) : AccelStepper(AccelStepper::DRIVER, pinDuPas, pinDeDirection) //Constructeur du moteur
{
   AccelStepper axis(AccelStepper::DRIVER, pinDuPas, pinDeDirection);

   pinStep = pinDuPas;    //Pin défini step 
   pinDirection = pinDeDirection;   //Pin défini direction
   piloteVitesseMaxPas = vitessemax;   //Vitesse en pas par seconde
   piloteAccelerationPas = acceleration;

   positionPas = 0;
   position_mm = 0; //position sur l'axe x en mm
}

void MoteurPasAPas::setup()
{
   pinMode(pinenable, OUTPUT);
   pinMode(pinsensmoteur2, OUTPUT);
   digitalWrite(pinsensmoteur2,negatif);
   digitalWrite(pinenable,0);
}

void MoteurPasAPas::deplacer(long dist_mm) //procédure de déplacement sur une position ABSOLUE en pas
{
   AccelStepper axis(AccelStepper::DRIVER, pinStep, pinDirection);
   axis.setCurrentPosition(0);
   Serial.println("setcurrentpos");

   axis.setMaxSpeed(500);  //test de passer valeur constru
   Serial.println("setMaxSpeed");

   axis.setAcceleration(200);    //test de passer valeur constru
   Serial.println("setAcceleration");

   if (dist_mm > 0)     //RAJOUTER CONDITION
   {
      digitalWrite(pinsensmoteur2, positif); //le moteur 2 de l'axe X tourne en sens inverse du moteur 1
      Serial.println("digitalwritesens positif");
   }
   else
   {
      digitalWrite(pinsensmoteur2, negatif); //le moteur 2 de l'axe X tourne en sens inverse du moteur 1  
      Serial.println("digitalwritesens negatif");
   }
   if (dist_mm != 0)
   {
      axis.runToNewPosition(dist_mm);
      positionPas = dist_mm;
      position_mm = positionPas * facteur;
     // envoie_donnees(1, position_mm); //envoie la nouvelle position en x pour affichage case 1
      
   }
} //fin de la procédure de déplacement


void MoteurPasAPas::debug() 
{
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
#include "Plateau.h"
#include "Arduino.h"
#include "SensMoteur.h"
#define pinsensmoteur2 9
#define pinenable 8

Plateau::Plateau(int pinDuPas, int pinDeDirection, int vitessemax, int acceleration) //Constructeur du moteur
{
   pinStep = pinDuPas;    //Pin défini step 
   pinDirection = pinDeDirection;   //Pin défini direction
   piloteVitesseMaxPas = vitessemax;   //Vitesse en pas par seconde
   piloteAccelerationPas = acceleration;

   positionPas = 0;
   position_mm = 0; //position sur l'axe x en mm
}

void Plateau::setup()
{
   pinMode(pinenable, OUTPUT);   //Pinenable obligatoire pour avancement des moteurs 
   pinMode(pinsensmoteur2, OUTPUT);    // Nécessaire pour le 2nd moteur de X
   digitalWrite(pinsensmoteur2,negatif);
   digitalWrite(pinenable,0);
}

void Plateau::deplacerY(long dist_mm) //procédure de déplacement sur une position ABSOLUE en pas
{
   AccelStepper axis(AccelStepper::DRIVER, pinStep, pinDirection);
   axis.setCurrentPosition(0);
   Serial.println("setcurrentpos");

   axis.setMaxSpeed(piloteVitesseMaxPas);  //test de passer valeur constru
   Serial.println("setMaxSpeed");

   axis.setAcceleration(piloteAccelerationPas);    //test de passer valeur constru
   Serial.println("setAcceleration");

   axis.runToNewPosition(dist_mm);
   positionPas = dist_mm;
   position_mm = positionPas * facteur;
     // envoie_donnees(1, position_mm); //envoie la nouvelle position en x pour affichage case 1
      
   
} //fin de la procédure de déplacement



void Plateau::deplacerX(long dist_mm) //procédure de déplacement sur une position ABSOLUE en pas
{
   AccelStepper axis(AccelStepper::DRIVER, pinStep, pinDirection);
   axis.setCurrentPosition(0);
   Serial.println("setcurrentpos");

   axis.setMaxSpeed(piloteVitesseMaxPas);  //test de passer valeur constru
   Serial.println("setMaxSpeed");

   axis.setAcceleration(piloteAccelerationPas);    //test de passer valeur constru
   Serial.println("setAcceleration");

   if (dist_mm > 0)     //RAJOUTER CONDITION
   {
      digitalWrite(pinsensmoteur2, positif); //definir le sens du moteur 2 de l'axe X tourne en sens inverse du moteur 1
      Serial.println("digitalwritesens positif");
   }
   else
   {
      digitalWrite(pinsensmoteur2, negatif); //definir le sens due moteur 2 de l'axe X tourne en sens inverse du moteur 1  
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

void Plateau::debug() 
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
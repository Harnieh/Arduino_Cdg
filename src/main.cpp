#include <Arduino.h>      //inclusion des fonctions arduino pour platformio
#include <Hx711.h>        //librairie de la carte de mesure en pont de wheatstone Hx711 attention librairie perso base sur première librairie
#include <stdint.h>
#include <AccelStepper.h> //librairie de pilotage de moteurs pas à pas
#include "Axe.h"
#include "Plateau.h"
#include "Capteur.h"
#include "Balance.h"

#define PIN_SENS_MOTEUR2 9 // controle moteur 2
#define PIN_ENABLE 8

#define X_COURROIE_PAS 2       //pas de la courroie de l'axe x
#define Y_COURROIE_PAS 2       //pas de la courroie de l'axe y

#define X_VITESSE_MAX 500      //pas par seconde
#define X_ACCELERATION_MAX 200 //pas par seconde² ATTENTION à calculer en fonction de la masse, du couple moteur et de la transmission

#define Y_VITESSE_MAX 500   //pas par seconde
#define Y_ACCELERATION_MAX 200 //pas par seconde² ATTENTION à calculer en fonction de la masse, du couple moteur et de la transmission


// axe X moteur 1  pin 2 = step, pin 5 = direction
// axe X moteur 2  step dupliqué physiquement sur la carte de commande, pin 13 = direction
// axe Y moteur 3 pin 3 = step, pin 6 = direction
// axe Z moteur 4 pin 4 = step, pin 7 = direction


//AccelStepper xaxis(AccelStepper::DRIVER, 2, 5); 
//AccelStepper yaxis(AccelStepper::DRIVER, 3, 6); 
//moteur axe X POO
// Axe X(2,5,X_VITESSE_MAX,X_ACCELERATION_MAX);   // DONNER STRUCTURE AXE
// Axe Y(3,6,Y_VITESSE_MAX,Y_ACCELERATION_MAX);  
// Axe Z(4,7,Y_VITESSE_MAX,Y_ACCELERATION_MAX);


Plateau plateauBanc;  
Balance balanceBanc;


//Capteur un(10,A0,-60,-87.5);

// float capteur1_valeur=0;
// float capteur1_offset=0;
// float capteur1_fact=1;

bool first = true;

void setup()
{
  Serial.begin(9600);
  delay(1000);
  
  
  // X.setup(); //POO
  //Y.setup();
  //Z.setup();
  // pinMode(PIN_ENABLE, OUTPUT);
  // pinMode(PIN_SENS_MOTEUR2, OUTPUT);
  // digitalWrite(PIN_SENS_MOTEUR2,1);
  // digitalWrite(PIN_ENABLE,0);
  
  plateauBanc.setupPlateau();

  Serial.println("setup main");
}

void loop()
{
  if (first)
  {  
    plateauBanc.Increment1();
    plateauBanc.deplacerPlateau();
    plateauBanc.Increment10();
    plateauBanc.deplacerPlateau();
    plateauBanc.Increment100();
    plateauBanc.deplacerPlateau();
    plateauBanc.Increment1000();
    plateauBanc.deplacerPlateau();

    balanceBanc.mesurerPoidsPlateauAVide();
    balanceBanc.tareZero();
    balanceBanc.mesurer_poids();

    
    //un.mesurer_le_poids();
    //un.envoie_donnees(1,10);
    plateauBanc.deplacerPlateau();
    first=false;
  }
}


//------------------------------------------------------------------------------------//
/*Servomoteur X(2,5,500,200);
    X.setup(); //POO
    Serial.println("X.deplacer(20);");

    X.deplacer(150);

    first=false;
    Serial.println("findeplacer");
 //----------------------Fonctionne----------------------------------------------//   
  pinMode(PIN_ENABLE, OUTPUT);
  pinMode(PIN_SENS_MOTEUR2, OUTPUT);
  digitalWrite(PIN_SENS_MOTEUR2,1);
  digitalWrite(PIN_ENABLE,0);

  AccelStepper xaxis(AccelStepper::DRIVER, 2, 5);
  xaxis.setCurrentPosition(0);
  Serial.println("setcurrentpos");

  xaxis.setMaxSpeed(500);
  Serial.println("setMaxSpeed");

  xaxis.setAcceleration(200);
  Serial.println("setAcceleration");

  xaxis.runToNewPosition(-150);
  first=false;*/


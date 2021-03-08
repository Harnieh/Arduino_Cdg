#include <Arduino.h>      //inclusion des fonctions arduino pour platformio
#include <Hx711.h>        //librairie de la carte de mesure en pont de wheatstone Hx711 attention librairie perso base sur première librairie
#include <stdint.h>
#include "Capteur.h"
#include "Servomoteur.h"
#include "Piece.h"

#define PIN_SENS_MOTEUR2 9 //test
#define PIN_ENABLE 8

#define X_VITESSE_MAX 500      //pas par seconde
#define X_ACCELERATION_MAX 200 //pas par seconde² ATTENTION à calculer en fonction de la masse, du couple moteur et de la transmission

AccelStepper xaxis(AccelStepper::DRIVER, 2, 5);


void setup()
{
    Serial.begin(9600);
    Serial.println("setup main");
    pinMode(PIN_SENS_MOTEUR2, OUTPUT); // sortie digitale contrôle de direction du moteur 2 de l'axe X (le nombre de pas est dupliqué du moteur 1 sur la carte)
  digitalWrite(PIN_SENS_MOTEUR2, 0);
  pinMode(PIN_ENABLE, OUTPUT); // sortie digitale contrôle de direction du moteur 2 de l'axe X (le nombre de pas est dupliqué du moteur 1 sur la carte)
  digitalWrite(PIN_ENABLE, 0);
  xaxis.setMaxSpeed(X_VITESSE_MAX);
  xaxis.setAcceleration(X_ACCELERATION_MAX);

}

void loop()
{
    Serial.println("loop");
    xaxis.runToNewPosition(10);
    // Servomoteur test(3,6,1,200,100);//moteur axe X
    //     test.setup();
    //     test.run();
    
}

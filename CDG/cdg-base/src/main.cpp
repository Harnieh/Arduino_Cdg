#include <Arduino.h>      //inclusion des fonctions arduino pour platformio
#include <Hx711.h>        //librairie de la carte de mesure en pont de wheatstone Hx711 attention librairie perso base sur première librairie
#include <stdint.h>
#include "Capteur.h"
#include "Servomoteur.h"
#include "Piece.h"

void setup()
{
 Servomoteur test(2,5,1,200,100);//moteur axe X
}

void loop()
{

}

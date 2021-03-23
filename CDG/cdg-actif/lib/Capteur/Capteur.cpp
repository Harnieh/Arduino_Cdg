#include "Arduino.h"
#include "Capteur.h"

Capteur::Capteur(int PinCapteurNum, uint8_t pinCapteurAlpha)
{
    Serial.println("CONSTRU CAPTEUR");
    Serial.println(PinCapteurNum);
    Serial.println(pinCapteurAlpha);

    pinUn = PinCapteurNum;
    pinDeux = pinCapteurAlpha;
    Hx711 Moncapteur(int pinUn, uint8_t pinDeux);

    Serial.println(pinUn);
    Serial.println(pinDeux);


    capteurValeur=0.0;//VALEUR (float capteur?_valeur)
    capteurPoidsAVide=0.0;//POIDS A VIDE (float capteur?_offset)
    capteurFacteurEchelle=0.0;//FACTEUR D ECHELLE (float capteur?_fact)
    capteurTareConnue= (1.43 + 20) / 4;//POIDS DE LA TARE DU CAPTEUR EN NEWTON(float capteur?_tare_connue)
    capteurPositionX=0.0;//POSITION DU CAPTEUR EN MM (float capteur?_x)
    capteurPositionY=0.0;//(float capteur?_y)
}

float Capteur::mesurer_le_poids()
{
    Serial.println("MESURER LE POIDS");
    //capteurValeur=
}


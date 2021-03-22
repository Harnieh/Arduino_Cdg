#ifndef CAPTEUR_H
#define CAPTEUR_H
#include <Hx711.h>

class Capteur

{
private:
int pinUn;
uint8_t pinDeux;

Hx711 MonCapteur(int pinUn,uint8_t pinDeux);

float capteurValeur;//VALEUR (float capteur?_valeur)
float capteurPoidsAVide;//POIDS A VIDE (float capteur?_offset)
float capteurFacteurEchelle;//FACTEUR D ECHELLE (float capteur?_fact)
float capteurTareConnue;//POIDS DE LA TARE DU CAPTEUR EN NEWTON(float capteur?_tare_connue)
float capteurPositionX;//POSITION DU CAPTEUR EN X EN MM (float capteur?_x)
float capteurPositionY;//POSITION DU CAPTEUR EN Y EN MM(float capteur?_y)

public:

Capteur(int,const uint8_t); //Constructeur par défaut > Initialisation à 0 de tous les attributs


float mesurer_le_poids();
};

#endif // CAPTEUR_H

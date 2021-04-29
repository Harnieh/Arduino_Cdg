#ifndef CAPTEUR_H
#define CAPTEUR_H
#include <Hx711.h>

class Capteur

{
private:
int pinUn;
uint8_t pinDeux;


float capteurValeur=0;//VALEUR (float capteur?_valeur)
float capteurPoidsAVide=0;//POIDS A VIDE (float capteur?_offset)
float capteurFacteurEchelle=0;//FACTEUR D ECHELLE (float capteur?_fact)
float capteurTareConnue_Newton=(1.43+20)/4;//POIDS DE LA TARE DU CAPTEUR EN NEWTON(float capteur?_tare_connue)
float capteurPositionX_mm;//POSITION DU CAPTEUR EN X EN MM (float capteur?_x)
float capteurPositionY_mm;//POSITION DU CAPTEUR EN Y EN MM(float capteur?_y)

Hx711 pressioncaptor;

public:

Capteur(int pinUn,const uint8_t pinDeux,float positionX_mm,float positionY_mm); //Constructeur

void tarer_a_zero();
void tarer_connue(float poidsPlateau);
float mesurer_le_poids(int grandeurEnvoi);
void envoie_donnees(byte grandeur,float valeur);    //mettre autre part?

float getCapteurValeur() const 
{
    return capteurValeur; 
}



};

#endif // CAPTEUR_H

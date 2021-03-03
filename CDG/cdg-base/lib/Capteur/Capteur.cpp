#include "Capteur.h"

Capteur::Capteur()      //Constructeur par défaut > Initialisation à 0 excepté Tare connue
{
    capteurValeur=0.0;//VALEUR (float capteur?_valeur)
    capteurPoidsAVide=0.0;//POIDS A VIDE (float capteur?_offset)
    capteurFacteurEchelle=0.0;//FACTEUR D ECHELLE (float capteur?_fact)
    capteurTareConnue= (1.43 + 20) / 4;//POIDS DE LA TARE DU CAPTEUR EN NEWTON(float capteur?_tare_connue)
    capteurPositionX=0.0;//POSITION DU CAPTEUR EN MM (float capteur?_x)
    capteurPositionY=0.0;//(float capteur?_y)
}

Capteur::Capteur(float x,float y)      //Constructeur x y
{
    capteurValeur=0.0;//VALEUR (float capteur?_valeur)
    capteurPoidsAVide=0.0;//POIDS A VIDE (float capteur?_offset)
    capteurFacteurEchelle=0.0;//FACTEUR D ECHELLE (float capteur?_fact)
    capteurTareConnue=0.0;//POIDS DE LA TARE DU CAPTEUR EN NEWTON(float capteur?_tare_connue)
    capteurPositionX= x;//POSITION DU CAPTEUR EN X EN MM (float capteur?_x)
    capteurPositionY= y;//POSITION DU CAPTEUR EN Y EN MM(float capteur?_y)
}
#pragma once
class Capteur

{

float capteurValeur;//VALEUR (float capteur?_valeur)
float capteurPoidsAVide;//POIDS A VIDE (float capteur?_offset)
float capteurFacteurEchelle;//FACTEUR D ECHELLE (float capteur?_fact)
float capteurTareConnue;//POIDS DE LA TARE DU CAPTEUR EN NEWTON(float capteur?_tare_connue)
float capteurPositionX;//POSITION DU CAPTEUR EN X EN MM (float capteur?_x)
float capteurPositionY;//POSITTION DU CAPTEUR EN Y EN MM(float capteur?_y)

public:

Capteur(); //Constructeur par défaut > Initialisation à 0 de tous les attributs
Capteur(float, float); //Constructeur avec choix de X et Y

};

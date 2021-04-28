#include "balance.h"

Balance::Balance(): un(10,A0,-60,-87.5),deux(11,A1,60,-87.5),trois(12,A2,60,87.5),quatre(13,A3,-60,87.5)
{
    Serial.println("Constru balance");
}

void Balance::tareZero() 
{
    un.tarer_a_zero();
    deux.tarer_a_zero();
    trois.tarer_a_zero();
    quatre.tarer_a_zero();

    this->mesurer_poids();
}

void Balance::mesurerPoidsPlateauAVide() 
    {
        poidsPlateau=this->mesurer_poids();
        un.envoie_donnees(10,poidsPlateau); //utilisation du capteur un, pas forcement utile > passage par un capteur ou une nouvelle classe pour les envois?
    }

void Balance::tareConnue()
{
    un.tarer_connue();
    deux.tarer_connue();
    trois.tarer_connue();
    quatre.tarer_connue();

    this->mesurer_poids();
}

float Balance::mesurer_poids() 
{
    un.mesurer_le_poids(6);
    deux.mesurer_le_poids(7);
    trois.mesurer_le_poids(8);
    quatre.mesurer_le_poids(9);
    mesure_poids=un.getCapteurValeur()+deux.getCapteurValeur()+trois.getCapteurValeur()+quatre.getCapteurValeur();
    return(mesure_poids);
}


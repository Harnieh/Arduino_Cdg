#include "Arduino.h"
#include "Capteur.h"
#define NB_MESURES 30

Capteur::Capteur(int _pinUn, uint8_t _pinDeux,float _capteurPositionX_mm,float _capteurPositionY_mm):pinUn(_pinUn),pinDeux(_pinDeux),capteurPositionX_mm(_capteurPositionX_mm)
                                                                                                    ,capteurPositionY_mm(_capteurPositionY_mm),pressioncaptor(Hx711(pinUn,pinDeux))
{
    Serial.println("constru capteur");
}

void Capteur::tarer_a_zero()
{ 
  capteurPoidsAVide=pressioncaptor.averageValue(NB_MESURES);
}

void Capteur::tarer_connue(float poidsPlateau)
{
  capteurFacteurEchelle=(pressioncaptor.averageValue(NB_MESURES)-capteurPoidsAVide)/(capteurTareConnue_Newton+poidsPlateau);
}

float Capteur::mesurer_le_poids(int grandeurEnvoi)
{
  //  Serial.println(capteurValeur);
    capteurValeur=(pressioncaptor.averageValue(NB_MESURES)-capteurPoidsAVide)/capteurFacteurEchelle;
  //  Serial.println(capteurValeur);
  this->envoie_donnees(grandeurEnvoi,capteurValeur);
}

void Capteur::envoie_donnees(byte grandeur,float valeur)
{
  //Serial.println("Envoi");
  byte byte1;
  byte byte2;      
   valeur=valeur*10; //x10 pour avoir une précision de 0,1
   valeur=valeur+32768; //prise en compte des valeurs négatives
   if (valeur<0)
     {
      valeur=0;
     }
   if (valeur>65535)
     {
      valeur=65535;
     }
   byte2 = byte(valeur/256);
   byte1 = byte(valeur-256*byte2);
   Serial.write(grandeur);
   Serial.write(byte1);
   Serial.write(byte2);
   delay(200);
}


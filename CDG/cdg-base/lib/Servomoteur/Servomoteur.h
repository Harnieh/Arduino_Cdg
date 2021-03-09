#ifndef SERVOMOTEUR_H
#define SERVOMOTEUR_H
#include <AccelStepper.h> //librairie de pilotage de moteurs pas à pas
#include <stdint.h>

class Servomoteur
{
    private:
    AccelStepper pilote;
    uint8_t pinStep;    //Pin défini step 
    uint8_t pinDirection;   //Pin défini direction

    int piloteVitesseMaxPas;    //Vitesse en pas par seconde
    int piloteAccelerationPas;  //Acceleration du servo en pas par seconde^2 ATTENTION à calculer en fonction de la masse, du couple moteur et de la transmission 

    float facteurDeConversion;    //Facteur de conversion en mm par pas pour l'axe (float ?_facteur)

//AXE    long position_pas;   //Position sur l'axe en pas (long ?_position_pas)
//AXE    float position_mm;    //Position sur l'axe en mm (float ?_position_mm)
//AXE    long limiteMin;     //Limite minimale de l'axe en ?? (long ?_min)
//AXE    long limiteMax;     //Limite maximale de l'axe (long ?_max)

    public:

    Servomoteur(uint8_t pinDuPas, uint8_t pinDeDirection, float facteur, int vitessemax, int acceleration);  //Constructeur par défaut
    
    void setup();
    void run();
};

#endif // SERVOMOTEUR_H
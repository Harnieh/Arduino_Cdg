#ifndef AXE_H
#define AXE_H

#include <AccelStepper.h> //librairie de pilotage de moteurs pas à pas
#include <stdint.h>

class Axe
{
    private:
    
    int pinStep;    //Pin défini step 
    int pinDirection;   //Pin défini direction
    int piloteVitesseMaxPas;    //Vitesse en pas par seconde
    int piloteAccelerationPas;  //Acceleration du servo en pas par seconde^2 ATTENTION à calculer en fonction de la masse, du couple moteur et de la transmission

    AccelStepper moteur;

    float facteurConversionMmPas; //facteur de conversion mm/pas
    long positionPas;
    float position_mm; //position sur l'axe x en mm

    //AXE    long limiteMin;     //Limite minimale de l'axe en ?? (long ?_min)
    //AXE    long limiteMax;     //Limite maximale de l'axe (long ?_max)

    public:

    Axe(int pinDuPas, int pinDeDirection, /*float facteur,*/ int vitessemax, int acceleration);  //Constructeur par défaut
    void setup();

    void deplacer(long dist_mm); //procédure de déplacement sur une position ABSOLUE en pas

    void debug();
};

#endif // AXE_H

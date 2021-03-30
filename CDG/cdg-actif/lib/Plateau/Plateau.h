#include <AccelStepper.h> //librairie de pilotage de moteurs pas à pas
#include <stdint.h>

class Plateau : public AccelStepper
{
    private:
    
    
    int pinStep;    //Pin défini step 
    int pinDirection;   //Pin défini direction
    int piloteVitesseMaxPas;    //Vitesse en pas par seconde
    int piloteAccelerationPas;  //Acceleration du servo en pas par seconde^2 ATTENTION à calculer en fonction de la masse, du couple moteur et de la transmission
    AccelStepper axeY;
    
    float facteurConversionMmPas; //facteur de conversion mm/pas
    long positionPas;
    float position_mm; //position sur l'axe x en mm

    
    
    
//    float facteurDeConversion;    //Facteur de conversion en mm par pas pour l'axe (float ?_facteur)

//AXE    long position_pas;   //Position sur l'axe en pas (long ?_position_pas)
//AXE    float position_mm;    //Position sur l'axe en mm (float ?_position_mm)
//AXE    long limiteMin;     //Limite minimale de l'axe en ?? (long ?_min)
//AXE    long limiteMax;     //Limite maximale de l'axe (long ?_max)
    public:

    Plateau(int pinDuPas, int pinDeDirection, /*float facteur,*/ int vitessemax, int acceleration);  //Constructeur par défaut
    void setup();

    void deplacer(long dist_mm); //procédure de déplacement sur une position ABSOLUE en pas

    void debug();
};

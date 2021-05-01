#include "Plateau.h"

Plateau::Plateau(): axeX(2,5,500,200),axeY(3,6,500,200),palpeur(4,7,500,200)    
{ 
    Serial.println("Constru plateau");
}

void Plateau::setupPlateau()
{
    Serial.println("setup");  

    axeX.setup();
    axeY.setup();
    palpeur.setup();
}

void Plateau::deplacerPlateau() 
{
    Serial.println("Deplacement");  
    Serial.println(increment); 
    // axeX.deplacer(increment);
    // axeY.deplacer(increment);
    palpeur.deplacer(increment);       
}




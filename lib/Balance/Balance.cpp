#include "balance.h"



Balance::Balance(): un(10,A0,-60,-87.5),deux(11,A1,60,-87.5),trois(12,A2,60,87.5),quatre(13,A3,-60,87.5)
{
    Serial.println("Constru balance");
}

void Balance::mesurer_poids() 
{
    un.mesurer_le_poids();
    deux.mesurer_le_poids();
    trois.mesurer_le_poids();
    quatre.mesurer_le_poids();
}
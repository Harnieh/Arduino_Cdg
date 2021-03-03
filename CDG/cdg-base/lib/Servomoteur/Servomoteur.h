#pragma once
class Servomoteur


{
    long x_position_pas=0;   //Position sur l'axe X en pas (long x_position_pas)
    long y_position_pas=0;   //Position sur l'axe Y en pas (long y_position_pas)
    long z_position_pas=0;   //Position sur l'axe Z en pas (long z_position_pas)

    float x_position_mm=0;    //Position sur l'axe X en mm (float x_position_mm)
    float y_position_mm=0;    //Position sur l'axe Y en mm (float y_position_mm)
    float z_position_mm=0;    //Position sur l'axe Z en mm (float z_position_mm)

    float x_facteurDeConversion=0;    //Facteur de conversion en mm par pas pour l'axe X (float x_facteur)
    float y_facteurDeConversion=0;    //Facteur de conversion en mm par pas pour l'axe Y (float y_facteur)
    float z_facteurDeConversion=0;    //Facteur de conversion en mm par pas pour l'axe Z (float z_facteur)

    long x_limiteMin;     //Limite minimale de l'axe X en ?? (long x_min)
    long y_limiteMin;     //Limite minimale de l'axe Y  (long y_min)
    long z_limiteMin;     //Limite minimale de l'axe Z (long z_min)

    long x_limiteMax;     //Limite maximale de l'axe X (long x_max)
    long y_limiteMax;     //Limite maximale de l'axe Y (long y_max)
    long z_limiteMax;     //Limite maximale de l'axe Z (long z_max)

    public:
    Servomoteur();  //Constructeur par défaut
};
#ifndef PIECE_H
#define PIECE_H

class Piece
{
    float piece_poids;  //Poids de la pièce en Newton (float piece_poids)

    float piece_xg_mm;  //Position de la pièce en mm sur l'axe X (float piece_xg_mm)
    float piece_yg_mm;  //Position de la pièce en mm sur l'axe Y (float piece_yg_mm)

    float piece_xg_pas; //Position de la pièce en pas sur l'axe X (float piece_xg_pas)
    float piece_yg_pas; //Position de la pièce en pas sur l'axe Y (float piece_yg_pas)

    public:

    Piece();            //Constructeur par défaut de Piece
};
#endif // PIECE_H

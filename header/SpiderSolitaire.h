//
// Created by nicacio on 5/16/18.
//

#ifndef SOLITAIRESPIDER_SOLITAIREGAME_H
#define SOLITAIRESPIDER_SOLITAIREGAME_H

#include "Card.h"
#include "Deck.h"

/*
 * TOTAL DE CARTAS: 104
 * TOTAL DE CARTAS POR TIPO: 13
 * TOTAL DE PILHAS 10:
 * TOTAL DE PILHAS COMPLETAS: 8
 */
class SpiderSolitaire {

private:
    Deck piles[10];
    Deck completedPiles[8];


public:
    SpiderSolitaire();
    void printPiles();
    void printCompletedPiles();


};

#endif //SOLITAIRESPIDER_SOLITAIREGAME_H

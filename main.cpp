#include <iostream>
#include <cstdlib>
#include "header/Card.h"
#include "header/Deck.h"

using namespace std;


int main() {
    Deck piles[8];
    for (int i = 0; i < 8; ++i) {
        piles[i].fillPerSuit(1, SPADES);
    }

    piles[0].moveCardTo(piles[0].getCard(0), &piles[7]);


    for (int j = 0; j < 8; ++j) {
        cout << endl;
        piles[j].printCards();
    }



    return 0;
}
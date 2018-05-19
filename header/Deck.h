//
// Created by nicacio on 16/05/18.
//

#ifndef SOLITAIRESPIDER_DECK_H
#define SOLITAIRESPIDER_DECK_H



#include "Card.h"

// maximo de cartas: 52;

class Deck {

private:
    Card * head;
    Card * tail;
    int size;

public:
    Deck();

    //set
    void setHead(Card * _head);
    void setTail(Card * _tail);
    void incrementSize();
    void decrementSize();


    //get
    void handOutCardsTo(int quantity, Deck * to);
    int getSize();
    void addFrenchSuit(Suit _suit); // pq estamos usando o naipe frances de 52 cartas e 13 catras cada naipe
    void fillPerSuit(int number_of_suits, Suit _suit);
    void moveCardTo(Card * c, Deck * to);
    void shuffle();
    void addCard(Card *c);
    void removeCard(Card *c);
    void removeTail();
    bool checkCardsOrder();
    bool checkCardsOrder(Card c);
    void printCards();
    CardValue getNumberOfValue(int _i);


    Card *getCard(int _i);
};

#endif //SOLITAIRESPIDER_DECK_H
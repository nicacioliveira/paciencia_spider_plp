//
// Created by nicacio on 16/05/18.
//
#ifndef SOLITAIRESPIDER_CARD_H
#define SOLITAIRESPIDER_CARD_H

#include <string>

enum CardValue {
    Ace=1, Two=2, Three=3, Four=4, Five=5, Six=6, Seven=7, Eight=8, Nine=9, Ten=10, Jack=11, Queen=12, King=13
};

enum Suit {
    CUPS=1, COINS=2, CLUBS=3, SPADES=4
};

class Card {

private:
    int id;
    Suit suit;
    CardValue value;
    bool turned;
    Card *next;
    Card *prev;

public:
    Card();
    Card(Suit _suit, CardValue _value, bool _turned, int _id);

    //set
    void setId(int _id);
    void setSuit(Suit _suit);
    void setCardValue(CardValue _value);
    void setTurned(bool _turned);
    void setNext(Card *_next);
    void setPrev(Card * _prev);


    //get
    int getId();
    Suit getSuit();
    CardValue getValue();
    bool getTurned();
    Card *getNext();
    Card *getPrev();

    //func
    std::string getStringValue();
    std::string getStringSuit();

};

#endif //SOLITAIRESPIDER_CARD_H

//
// Created by nicacio on 16/05/18.
//
#include "../header/Card.h"

Card::Card() {

}

void Card::setId(int _id) {
    id = _id;
}

int Card::getId() {
    return id;
}

void Card::setSuit(Suit _suit) {
    suit = _suit;
}

void Card::setCardValue(CardValue _value) {
    value = _value;
}

void Card::setTurned(bool _turned) {
    turned = _turned;
}

void Card::setNext(Card *_next) {
    next = _next;
}

void Card::setPrev(Card *_prev) {
    prev = _prev;
}

Suit Card::getSuit() {
    return suit;
}

CardValue Card::getValue() {
    return value;
}

bool Card::getTurned() {
    return turned;
}

Card *Card::getNext() {
    return next;
}

Card *Card::getPrev() {
    return prev;
}


Card::Card(Suit _suit, CardValue _value, bool _turned, int _id) {
    suit = _suit;
    value = _value;
    turned = _turned;
    next = NULL;
    prev = NULL;
    id = _id;
}


std::string Card::getStringValue() {
    std::string resp;
    if (turned) {
        return "--";
    } else {
        switch (value) {
            case Ace:
                resp = "Ace";
                break;
            case Two:
                resp = "2";
                break;
            case Three:
                resp = "3";
                break;
            case Four:
                resp = "4";
                break;
            case Five:
                resp = "5";
                break;
            case Six:
                resp = "6";
                break;
            case Seven:
                resp = "7";
                break;
            case Eight:
                resp = "8";
                break;
            case Nine:
                resp = "9";
                break;
            case Ten:
                resp = "10";
                break;
            case Jack:
                resp = "Jack";
                break;
            case Queen:
                resp = "Queen";
                break;
            case King:
                resp = "King";
                break;
        }
        return resp;
    }
}

std::string Card::getStringSuit() {
    std::string resp;
    switch (suit) {
        case CUPS:
            resp = "Cups";
            break;
        case COINS:
            resp = "Coins";
            break;
        case CLUBS:
            resp = "Clubs";
            break;
        case SPADES:
            resp = "Spades";
            break;
    }
    return resp;
}
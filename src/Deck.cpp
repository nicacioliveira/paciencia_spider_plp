//
// Created by nicacio on 5/17/18.
//

#include "../header/Deck.h"
#include <iostream>
#include "../header/Card.h"
#define frenchSuitNumber 13

int indexCounter = 0;

Deck::Deck() {
    head = NULL;
    tail = NULL;
    size = 0;
}

void Deck::addFrenchSuit(Suit _suit) {

    for (int i = 0; i < frenchSuitNumber; ++i) {
        addCard(new Card(_suit, getNumberOfValue(i+1), false, indexCounter++));
    }
    
}

void Deck::fillPerSuit(int number_of_suits, Suit _suit) {
    for (int i = 0; i < number_of_suits; ++i) {
        addFrenchSuit(_suit);
    }
}

void Deck::shuffle() {

}

void Deck::handOutCardsTo(int quantity, Deck *to) {
    while (quantity > 0 && size > 0) {
        if (to->tail == NULL) {
            to->head = to->tail = tail;
        } else {
            to->tail->setNext(tail);
            to->tail->setPrev(tail);
            to->tail = tail;
        }
        removeTail();
        quantity--;
    }
}

void Deck::moveCardTo(Card * _card, Deck * to) {
    if (_card != NULL && to != NULL) {

        // desconect
        if (_card->getPrev() == NULL && _card->getNext() != NULL) {
            head = tail = NULL;
        }
        else if (_card->getPrev() != NULL && _card->getNext() == NULL) {
            Card * tail_prev = tail->getPrev();
            tail_prev->setNext(NULL);
            tail = tail_prev;
        }
        else if (_card->getPrev() != NULL && _card->getNext() != NULL) {
            Card * card_prev = _card->getPrev();
            card_prev->setNext(NULL);
            tail = card_prev;
        }
        else {

        }

        //conect
        if (to->tail == NULL) {
            to->head = to->head = _card;
        } else {
            _card->setPrev(to->tail);
            to->tail->setNext(_card);
            Card *aux = _card;
            while (aux->getNext() != NULL) aux = aux->getNext();
            tail = aux;
        }

        //std::cout << "TO -> HEAD: " << to->head->getStringValue() << " TAIL: " << to->tail->getStringValue() << std::endl;
    }

}

Card * Deck::getCard(int _index) {
    Card * resp = head;
    while (resp != NULL) {
        if (resp->getId() == _index)
            break;
        else
            resp = resp->getNext();
    }
    return resp;
}

void Deck::addCard(Card *c) {
    if (tail == NULL) {
        head = tail = c;
    } else {
        tail->setNext(c);
        c->setPrev(tail);
        tail = c;
    }
    size++;
}

void Deck::removeTail() {
    if (size == 1) {
        tail = head = NULL;
        size--;
    } else if (size > 1) {
        tail = tail->getPrev();
        tail->setNext(NULL);
        size--;
    }

}

void Deck::removeCard(Card *c) {

}

bool Deck::checkCardsOrder() {
    return false;
}

bool Deck::checkCardsOrder(Card c) {
    return false;
}


void Deck::setHead(Card *_head) {
    head = _head;
}

void Deck::setTail(Card *_tail) {
    tail = _tail;
}

void Deck::incrementSize() {
    size++;
}

void Deck::decrementSize() {
    size--;
}

int Deck::getSize() {
    return size;
}


CardValue Deck::getNumberOfValue(int _i) {
    CardValue resp;
    switch (_i) {
        case 1:
            resp = Ace;
            break;
        case 2:
            resp = Two;
            break;
        case 3:
            resp = Three;
            break;
        case 4:
            resp = Four;
            break;
        case 5:
            resp = Five;
            break;
        case 6:
            resp = Six;
            break;
        case 7:
            resp = Seven;
            break;
        case 8:
            resp = Eight;
            break;
        case 9:
            resp = Nine;
            break;
        case 10:
            resp = Ten;
            break;
        case 11:
            resp = Jack;
            break;
        case 12:
            resp = Queen;
            break;
        case 13:
            resp = King;
            break;
    }
    return resp;
}

void Deck::printCards() {
    Card *temp = head;
    while (temp != NULL) {
        std::cout << "Id: " << temp->getId() << " " << temp->getStringSuit() << " " << temp->getStringValue() << " " << std::endl;
        temp = temp->getNext();
    }
}

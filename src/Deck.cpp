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

    Card * _card = tail;
    while (_card != NULL && --quantity > 0) {
        _card = _card->getPrev();
    };

    moveCardTo(_card, to);


}

void Deck::moveCardTo(Card * _card, Deck * to) {
    if (_card != NULL && to != NULL) {
        if (_card == head){

            if (to->head == NULL) {
                to->head = _card;
                to->tail = tail;
                to->size = size;
                //
                size = 0;
                head = tail = NULL;
            } else {
                _card->setPrev(to->tail);
                to->tail->setNext(_card);
                to->tail = tail;
                to->size += size;
                //
                size = 0;
                head = tail = NULL;
            }

        } else if (_card == tail) {

            if (to->head == NULL) {
                _card->getPrev()->setNext(NULL);
                tail = _card->getPrev();
                _card->setPrev(NULL);
                size--;
                //
                to->size++;
                to->head = to->tail = _card;
            } else {
                int newSize = 0;
                Card * aux = _card;
                while (aux != NULL){
                    aux = aux->getNext();
                    newSize++;
                }
                size -=newSize;
                to->size += newSize;
                tail->getPrev()->setNext(NULL);
                tail = tail->getPrev();

                //
                to->tail->setNext(_card);
                _card->setPrev(to->tail);
                _card->setNext(NULL);
                to->tail = _card;

            }

        } else {

            if (to->head == NULL) {
                int newSize = 0;
                Card * aux = _card;
                while (aux != NULL){
                    aux = aux->getNext();
                    newSize++;
                }

                to->head = _card;
                to->tail = tail;
                size -= newSize;
                to->size += newSize;
                //
                tail = _card->getPrev();
                _card->getPrev()->setNext(NULL);
            } else {
                int newSize = 0;
                Card * aux = _card;
                while (aux != NULL){
                    aux = aux->getNext();
                    newSize++;
                }

                Card * thisTail = _card->getPrev();
                to->tail->setNext(_card);
                _card->setPrev(to->tail);
                to->tail = tail;
                to->size += newSize;
                size -= newSize;
                thisTail->setNext(NULL);
                tail = thisTail;


            }

        }
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

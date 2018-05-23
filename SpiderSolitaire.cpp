//
// Created by nicacioods on 22/05/18.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int frenchSuitNumber = 13;
const int numberOfSuits = 8;
const int qtdPiles = 10;
const int _false = 0;

struct Card {
    int value;
    int turned;
};

string getStringValue(Card c) {
    string resp;
    if (!c.turned) {
        return "|-----|";
    } else {
        switch (c.value) {
            case 1: //|queen|
                resp += "| Ace |";
                break;
            case 2:
                resp = "|  2  |";
                break;
            case 3:
                resp = "|  3  |";
                break;
            case 4:
                resp = "|  4  |";
                break;
            case 5:
                resp = "|  5  |";
                break;
            case 6:
                resp = "|  6  |";
                break;
            case 7:
                resp = "|  7  |";
                break;
            case 8:
                resp = "|  8  |";
                break;
            case 9:
                resp = "|  9  |";
                break;
            case 10:
                resp = "|  10 |";
                break;
            case 11:
                resp = "| Jack|";
                break;
            case 12:
                resp = "|Queen|";
                break;
            case 13:
                resp = "| King|";
                break;
        }
        return resp;
    }
}

void printPiles(vector<vector<Card>> piles) {
    //nicacio
    try {
        string response = "";
        string header = "";
        int i, j = 0;

        cout << header << endl;

        for (i = 0; i < piles.size(); ++i) {
            response = "";
            for (j = 0; j < piles[i].size(); ++j) {
                response += "       " + getStringValue(piles[j][i]) + "";
            }
            cout << response << endl;
        }
    } catch (int e) {
        cout << e << endl;
    }
}

//Adiciona as cartas do deck a pilha
void handOutCardsTo(vector<Card> deck, int quantity, vector<Card> PileTo) {
    //damiao
    for(int i = 0; i < quantity; i++) {
        PileTo.push_back(deck.back());
        deck.pop_back();
    }
}

Card newCard(int i){
    Card oneCard;
    oneCard.value = i + 1;
    oneCard.turned = _false;
    return oneCard;
}

void addFrenchSuit(vector<Card> deck) {
    for(int i = 0; i < frenchSuitNumber; i++) {
        deck.push_back(newCard(i));
    }
}

void fillDeck(vector<Card> deck) {
    //Daniele
    for(int i = 0; i < numberOfSuits; i++) {
        addFrenchSuit(deck);
    }
}

int checkOrder(vector<Card> deck, int id) {
    //kelvin
}

int checkCompletedPile(vector<Card> pilha, vector<vector<Card>> completedPiles) {
    //kelvin
}
void moveCardsTo(vector<Card> from, vector<Card> to) {
    //nicacio
}

void shuffle(vector<Card> deck) {
    //Lucas
}

int start(vector<Card> deck,  vector<vector<Card>> piles) {
    fillDeck(deck);
    shuffle(deck);
    handOutCardsTo(deck, 5, piles[0]);
    handOutCardsTo(deck, 5, piles[1]);
    handOutCardsTo(deck, 5, piles[2]);
    handOutCardsTo(deck, 5, piles[3]);
    handOutCardsTo(deck, 4, piles[4]);
    handOutCardsTo(deck, 4, piles[5]);
    handOutCardsTo(deck, 4, piles[6]);
    handOutCardsTo(deck, 4, piles[7]);
    handOutCardsTo(deck, 4, piles[8]);
    handOutCardsTo(deck, 4, piles[9]);
}

//Distribui uma carta para cada pilha, caso todas as pilhas contenha uma ou mais cartas
int deal(vector<Card> deck, vector<vector<Card>> piles) {
    //damiao
    int check = 1;

    for(int i = 0; i < qtdPiles; i++) {
        if (piles[i].size() < 1){
            check = 0;
            break;
        }
    }
    if (check > 0 && deck.size() > 0) {
        for (int i = 0; i < qtdPiles; i++) {
            handOutCardsTo(deck, 1, piles[i]);
        }
    }

}

int main() {
    vector<Card> deck;
    vector<vector<Card>> piles[qtdPiles];
    vector<vector<Card>> completedPiles[10];
    int option = 1;
    return EXIT_SUCCESS;
}
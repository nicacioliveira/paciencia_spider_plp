//
// Created by nicacioods on 22/05/18.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

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

void handOutCardsTo(vector<Card> deck, int quantity, vector<Card> PileTo) {
    //damiao
}

void fillDeck(vector<Card>) {
    //Daniele
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

int deal(vector<Card> deck, int quantity, vector<Card> PileTo) {
    //damiao
}

int main() {
    vector<Card> deck[104];
    vector<vector<Card>> piles[10];
    vector<vector<Card>> completedPiles[10];
    int option = 1;

    return 0;
}
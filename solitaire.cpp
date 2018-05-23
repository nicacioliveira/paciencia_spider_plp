//
// Created by nicacioods on 22/05/18.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Card {
    int value;
    int turned;
};

string getStringValue(Card c);
void printPiles(vector<vector<Card>> piles);
void handOutCardsTo(vector<Card> &deck, int quantity, vector<Card> &PileTo);
void fillDeck(vector<Card> & deck);
int checkOrder(vector<Card> deck, int id);
int checkCompletedPile(vector<Card> pilha, vector<vector<Card>> completedPiles);
int moveCardsTo(vector<Card> &from, int value, vector<Card> &to);
void shuffle(vector<Card> deck);
int start(vector<Card> &deck, vector<vector<Card>> &piles);
int deal(vector<Card> deck, int quantity, vector<Card> PileTo);
void printDeck(vector<Card> deck);
int contains(vector<Card> deck, int value);

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
    string response = "";
    string header = "";
    Card c;

    int maxIndex = 0;

    for (int i = 0; i < piles.size(); ++i) {
        if (piles[maxIndex].size() < piles[i].size()) maxIndex = i;
        header += "          " + to_string(i) + "   ";
    }
    cout << header << endl;

    string card_value = "";

    for (int i = 0; i < piles[maxIndex].size(); ++i) {
        response = "";
        for (int j = 0; j < piles.size(); ++j) {
            if (i >= piles[j].size())
                card_value = "       ";
            else
                card_value = getStringValue(piles[j][i]);
            response += "       " + card_value + "";
        }
        cout << response << endl;
    }
}

void handOutCardsTo(vector<Card> &deck, int quantity, vector<Card> &PileTo) {
    //damiao
}

void fillDeck(vector<Card> & deck) {
    //daniela
}

int checkOrder(vector<Card> deck, int id) {
    //kelvin
}

int checkCompletedPile(vector<Card> pilha, vector<vector<Card>> completedPiles) {
    //kelvin
}

int contains(vector<Card> deck, int value) {
    int resp = 0;
    for (Card c : deck) {
        if (c.value == value) {
            resp = 1;
            break;
        }
    }
    return resp;
}

int moveCardsTo(vector<Card> &from, int value, vector<Card> &to) {
    //nicacio
    int response = 0;
    int isValidMoviment;
    if (to.size() == 0)
        isValidMoviment = 1;
    else if (value < to.back().value)
        isValidMoviment = 1;
    else
        isValidMoviment = 0;

    if (contains(from, value) && checkOrder(from, value) && isValidMoviment) {
        vector<Card> stack;
        for (int i = from.size() - 1; i >= 0; ++i) {
            if (from[i].value == value) {
                stack.push_back(from.back());
                from.pop_back();
                break;
            }
            stack.push_back(from.back());
            from.pop_back();
        }

        from.back().turned = 1;

        for (int i = 0; i < stack.size(); ++i)  {
            to.push_back(stack.back());
            stack.pop_back();
        }
    }
    return response;
}

void deck_shuffle(vector<Card> &deck) {
    //Lucas
}

int start(vector<Card> &deck, vector<vector<Card>> &piles) {
    fillDeck(deck);
    deck_shuffle(deck);
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
    vector<Card> deck(104);
    vector<vector<Card>> piles(10);
    vector<vector<Card>> completedPiles(10);

    return 0;
}
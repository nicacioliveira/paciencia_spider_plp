//
// Created by nicacioods on 22/05/18.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

const int frenchSuitNumber = 13;
const int numberOfSuits = 8;
const int qtdPiles = 10;
const int _false = 0;

struct Card {
    int value;
    int turned;
};

string getStringValue(Card c);
void printPiles(vector<vector<Card> > piles);
void handOutCardsTo(vector<Card> &deck, int quantity, vector<Card> &PileTo);
void fillDeck(vector<Card> & deck);
int checkOrder(vector<Card> deck, int id);
int checkCompletedPile(vector<Card> pilha, vector<vector<Card> > completedPiles);
int moveCardsTo(vector<Card> &from, int value, vector<Card> &to);
void shuffle(vector<Card> deck);
int start(vector<Card> &deck, vector<vector<Card> > &piles);
int deal(vector<Card> deck, int quantity, vector<Card> PileTo);
void printDeck(vector<Card> deck);
int contains(vector<Card> deck, int value);

//OK
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

//OK
void printPiles(vector<vector<Card> > piles) {
    //nicacio
    string response = "";
    string header = "";
    Card c;

    int maxIndex = 0;

    for (int i = 0; i < piles.size(); ++i) {
        ostringstream index;
        if (piles[maxIndex].size() < piles[i].size()) maxIndex = i;
        index << i;
        header += "          " + index.str() + "   ";
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

//OK
//Distribui as cartas do deck para a pilha
void handOutCardsTo(vector<Card> &deck, int quantity, vector<Card> &PileTo) {
    //damiao

    Card c;
    if (quantity <= deck.size() && quantity > 0) {
        //remove do deck e passa para a pilha
        for (int i = 0; i < quantity - 1; ++i) {
            c = deck.back();
            deck.pop_back();
            PileTo.push_back(c);
        }
        //torna a ultima carta da pilha visivel
        c = deck.back();
        deck.pop_back();
        c.turned = 1;
        PileTo.push_back(c);
    }
}

//OK
Card newCard(int i){
    Card oneCard;
    oneCard.value = i + 1;
    oneCard.turned = _false;
    return oneCard;
}

//OK
void addFrenchSuit(vector<Card> &deck) {
    for(int i = 0; i < frenchSuitNumber; i++) {
        deck.push_back(newCard(i));
    }
}

//OK
void fillDeck(vector<Card> &deck) {
    //Daniele
    for(int i = 0; i < numberOfSuits; i++) {
        addFrenchSuit(deck);
    }
}

int checkOrder(vector<Card> deck, int id) {
    //kelvin

    //provisorio
    int isValid = 1;
    if (deck.back().value != id) {
        for (int i = deck.size() - 1; i > 0; ++i) {
            if ((deck[i - 1].value + 1) != deck[i].value) {
                isValid = 0;
                break;
            }
        }
    }
    return isValid;
}

int checkCompletedPile(vector<Card> pilha, vector<vector<Card> > completedPiles) {
    //kelvin
}

//OK
int contains(vector<Card> deck, int value) {
    int resp = 0;
    for (int i = 0; i < deck.size(); ++i) {
        if (deck[i].value == value) {
            resp = 1;
            break;
        }
    }
    return resp;
}

//OK
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
        for (int i = from.size() - 1; i >= 0; --i) {
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

//OK
void deck_shuffle(vector<Card> &deck) {
    //Lucas
    for(int i = 0; i < deck.size(); i++) {
	      	int valueGenerated = rand() % deck.size();
	      	Card temporaryCard = deck[i];
		deck[i] = deck[valueGenerated];
	  	deck[valueGenerated] = temporaryCard;
	}

}

//OK
int start(vector<Card> &deck, vector<vector<Card> > &piles) {
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

//Distribui uma carta para cada pilha, caso todas as pilhas contenha uma ou mais cartas
int deal(vector<Card> &deck, vector<vector<Card> > &piles) {
    //damiao
    int check = 1;

    for (int i = 0; i < qtdPiles; i++) {
        if (piles[i].size() < 1) {
            check = 0;
            break;
        }
    }

    for (int i = 0; i < qtdPiles; i++) {
        if (check > 0 && deck.size() > 0) {
            handOutCardsTo(deck, 1, piles[i]);
        }
    }
}

int getFirstValuePossible(vector<Card> pile) {
    int value = pile.back().value;
    for (int i = pile.size() - 1; i > 0; --i) {
        if ((pile[i].value+1) != pile[i-1].value && !pile[i-1].turned) break;
        value = pile[i-1].value;
    }
    return value;
}

void hint(vector<Card> deck, vector<vector<Card> > piles) {
    Card c;
    c.value = -1;
    c.turned = 1;
    string response = "--------------HINT-------------\n";

    for (int i = 0; i < piles.size(); ++i) {

        if (piles[i].size() > 0) {

            c.value = getFirstValuePossible(piles[i]);

            for (int j = 0; j < piles.size(); ++j) {

                if ((piles[j].back().value-1) == c.value) {
                    response += "Card: " + getStringValue(c) + " -- ";
                    ostringstream indexI;
                    indexI << i;
                    response += "Pile: " + indexI.str() + " --> ";
                    ostringstream indexJ;
                    indexJ << j;
                    response += "" + indexJ.str() + "; ";
                    response += "\n";
                    break;
                }
            }

        }

    }

    if (c.value == -1 && deck.size() >= 10) {
        cout << "No hint at the moment. But you can deal a new card into each tableau at the column." << endl;
    } else if (deck.size() < 10) {
        cout << "No hint at the moment." << endl;
    } else {
        cout << response;
    }
}

int main() {
    vector<Card> deck;//104
    vector<vector<Card> > piles(10);
    vector<vector<Card> > completedPiles(10);

    start(deck, piles);
    printPiles(piles);
    hint(deck, piles);


    return EXIT_SUCCESS;
}

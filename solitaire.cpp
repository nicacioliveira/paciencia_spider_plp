//
// Created by Nicacio, Damião, Daniela, Lucas and Kelvin on 05/20/18 for the discipline of PLP.
// UFCG - Campina Grande - PB
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

/**
 * This function returns string value of the value in card.
 * But if the value of the card is true, it returns | ----- |.
 * @param Card
 * @return equivalent string value of card value
 */
string getStringValue(Card c);

/**
 * Prints the piles in column format
 * @param piles
 */
void printPiles(vector<vector<Card> > piles);

/**
 * Distributes a specific number of cards to the pile.
 * Obs: Sets the last card to face up
 * @param deck
 * @param quantity
 * @param pile
 */
void handOutCardsTo(vector<Card> &deck, int quantity, vector<Card> &pile);

/**
 *
 * @param value of card
 * @return Card
 */
Card newCard(int i);

/**
 * Adds a French suit to the deck
 * Franch suit: 13 cards 1(Ace) to 13(King)
 * @param deck
 */
void addFrenchSuit(vector<Card> &deck);

/**
 * Fills in the deck with a specific number of french suits
 * @param deck
 */
void fillDeck(vector<Card> & deck);

/**
 * Checks if the order of the cards is correct starting from a certain card
 * @param deck
 * @param card value
 * @return 1: valid; 0: not valid
 */
int checkOrder(vector<Card> deck, int id);

/**
 * Checks
 * @param deck
 * @param completedPiles
 * @return 1: is true; 0: is not true
 */
int checkCompletedPile(vector<Card> deck, vector<vector<Card> > completedPiles);

/**
 * Checks whether a card is contained in a stack
 * @param deck
 * @param value
 * @return 1: contains; 0: not contains
 */
int contains(vector<Card> deck, int value);

/**
 * Move cards from one stack to another
 * @param (pile)from
 * @param Card value
 * @param (pile)to
 * @return 1: movement was possible; 0: movement was not possible
 */
int moveCardsTo(vector<Card> &from, int value, vector<Card> &to);

/**
 * Shuffles the deck...
 * @param deck
 */
void deck_shuffle(vector<Card> &deck);

/**
 * Starts the game by filling the main deck with 104 cards
 * of French suits, shuffles and distribute some cards to
 * each stack (column) of the game.
 *
 * @param main deck
 * @param piles(matrix)
 */
void start(vector<Card> &deck, vector<vector<Card> > &piles);

/**
 * Distributes one card to each pile if possible
 * @param main deck
 * @param piles
 * @return 1: deal is possible; 0: deal is not possible
 */
int deal(vector<Card> &deck, vector<vector<Card> > &piles);

// ---------------------------------------------------------------------------------------------------------------------

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

void printPiles(vector<vector<Card> > piles) {
    //implemented by nicacio
    string response = "";
    string header = "";
    Card c;

    // index of the biggest pile
    int maxIndex = 0;

    // Search biggest Pile
    for (int i = 0; i < piles.size(); ++i) {
        ostringstream index;
        if (piles[maxIndex].size() < piles[i].size()) maxIndex = i;
        index << i;
        header += "          " + index.str() + "   ";
    }

    //Header of the piles
    cout << header << endl;

    string card_value = "";

    // Transpose
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

void handOutCardsTo(vector<Card> &deck, int quantity, vector<Card> &pile) {
    //implemented by Damiao
    Card c;
    if (quantity <= deck.size() && quantity > 0) {
        for (int i = 0; i < quantity - 1; ++i) {
            c = deck.back();
            deck.pop_back();
            pile.push_back(c);
        }
        //Sets the last card to face up
        c = deck.back();
        deck.pop_back();
        c.turned = 1;
        pile.push_back(c);
    }
}

Card newCard(int value){
    //Implemented by Daniele
    Card oneCard;
    oneCard.value = value + 1;
    oneCard.turned = _false;
    return oneCard;
}

void addFrenchSuit(vector<Card> &deck) {
    //Implemented by Daniele
    for(int i = 0; i < frenchSuitNumber; i++) {
        deck.push_back(newCard(i));
    }
}

void fillDeck(vector<Card> &deck) {
    //Implemented by Daniele
    for(int i = 0; i < numberOfSuits; i++) {
        addFrenchSuit(deck);
    }
}

int checkOrder(vector<Card> deck, int cardValue) {
    //Implemented by Kelvin

    //provisorio
    int isValid = 1;
    if (deck.back().value != cardValue) {
        for (int i = deck.size() - 1; i > 0; ++i) {
            if ((deck[i - 1].value + 1) != deck[i].value) {
                isValid = 0;
                break;
            }
        }
    }
    return isValid;
}

int checkCompletedPile(vector<Card> deck, vector<vector<Card> > completedPiles) {
    //kelvin
}

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

int moveCardsTo(vector<Card> &from, int value, vector<Card> &to) {
    //Implemented by Nicacio
    int response = 0;

    // verifies if is a possible movement for:
    //      1. size of (to) is 0;
    //      2. value of the card is not greater than the value of the end of the pile;
    int isValidMoviment;
    if (to.size() == 0)
        isValidMoviment = 1;
    else if (value < to.back().value)
        isValidMoviment = 1;
    else
        isValidMoviment = 0;

    if (contains(from, value) && checkOrder(from, value) && isValidMoviment) {
        vector<Card> stack;
        // removes cards of (from), set last value of (from) to turned and passes the values ​​to (to)
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
        response = 1;
    }
    return response;
}

void deck_shuffle(vector<Card> &deck) {
    //Implemented by Lucas
    for(int i = 0; i < deck.size(); i++) {
	      	int valueGenerated = rand() % deck.size();
	      	Card temporaryCard = deck[i];
		deck[i] = deck[valueGenerated];
	  	deck[valueGenerated] = temporaryCard;
	}

}

void start(vector<Card> &deck, vector<vector<Card> > &piles) {
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

int deal(vector<Card> &deck, vector<vector<Card> > &piles) {
    //Implemented by Damiao
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

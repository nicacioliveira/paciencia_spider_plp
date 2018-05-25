//
// Created by Nicacio, Damião, Daniela, Lucas and Kelvin on 05/20/18 for the discipline of PLP.
// UFCG - Campina Grande - PB
//

#include <iostream>
#include <stdio.h>
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
void printPiles(vector<Card> deck, vector<vector<Card> > piles);

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

int checkOrder(int elem, int cardValue);

/**
 * Checks if the order of the cards is correct starting from a certain card
 * @param deck
 * @param card value
 * @return 1: valid; 0: not valid
 */
int isValidMov(vector<Card> deck, int id);

/**
 * Checks
 * @param deck
 * @param completedPiles
 * @return 1: is true; 0: is not true
 */
int checkCompletedPile(vector<Card> &pile);

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
void deal(vector<Card> &deck, vector<vector<Card> > &piles);

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

void printPiles(vector<Card> deck, vector<vector<Card> > piles) {
    //implemented by nicacio
    if (deck.empty()) {
        cout << "The game has not started." << endl;
    } else {
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
            header += "      " + index.str() + "   ";
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
                response += "   " + card_value + "";
            }
            cout << response << endl;
        }
        cout << endl;
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


int checkOrder(int elem, int cardValue) {
    int result = 0;
    if((elem - cardValue) == 1) {
        result = 1;
    }
    return result;
}

int isValidMov(vector<Card> pile, int cardValue) {
    //Implemented by Kelvin
    int isPossible = 0;
    int lastIndex = pile.size() - 1;
    if(lastIndex < 0) {
        isPossible = 1;
    }
    else{
        int lastElem = pile[lastIndex].value - 1;

        if(checkOrder(lastElem, cardValue) == 1) {
            isPossible = 1;
        }
    }

    return isPossible;
}

int checkCompletedPile(vector<Card> &pile) {
    //kelvin

    int completed = 0;
    int lastPos = pile.size() - 1;
    int ace = 2;
    int king = 13;
    int cont = 0;
    if(lastPos >= 0) {
        int elem = pile[lastPos].value - 1;
        if(elem == ace) {
            while(lastPos - 1 >= 0 && checkOrder(pile[lastPos - 1].value - 1, elem) == 1) {
                cont++;
                elem = piles[lastPos - 1].value - 1;
                lastPos--;
            }
        }
    }
    if(cont == 11 && pile[lastPos].value - 1 == 13 ) {
        completed = 1;
    }
    return completed;
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
    // feat. Kelvin
    int response = 0;

    // verifies if is a possible movement for:
    //      1. size of (to) is 0;
    //      2. value of the card is not greater than (neither equal) the value of the end of the pile;


    if (contains(from, value) && isValidMov(to, value)) {
        vector<Card> stack;
        // removes cards of (from), set last value of (from) to turned and passes the values ​​to (to)
        for (int i = from.size() - 1; i >= 0; --i) {
            if (from[i].value == value) {
                stack.push_back(from.back());
                from.pop_back();
                break;
            }
            cout << from.back().value + " " << endl;
            stack.push_back(from.back());
            from.pop_back();
        }

        from.back().turned = 1;
        int stackSize = stack.size();
        for (int i = 0; i < stackSize; ++i)  {
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
    if (!deck.empty())
        cout << "The game has already started." << endl;
    else {
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
}

void deal(vector<Card> &deck, vector<vector<Card> > &piles) {
    //Implemented by Damiao
    if (deck.empty())
        cout << "The game has not started." << endl;
    else {

        int check = 1;

        for (int i = 0; i < qtdPiles; i++) {
            if (piles[i].size() < 1) {
                check = 0;
                break;
            }
        }
        if (check == 0)
            cout << "All stacks must contain at least one card." << endl;
        else {
            for (int i = 0; i < qtdPiles; i++) {
                if (check > 0 && deck.size() > 0) {
                    handOutCardsTo(deck, 1, piles[i]);
                }
            }
            printPiles(deck, piles);
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

void help() {
    string cmd = "";
    cmd += "   |---------------------------------HELP--------------------------------|\n";
    cmd += "   |Start:         start                                                 |\n";
    cmd += "   |Quit Game:     quit                                                  |\n";
    cmd += "   |Reset Game:    reset                                                 |\n";
    cmd += "   |Help:          help                                                  |\n";
    cmd += "   |Hint:          hint                                                  |\n";
    cmd += "   |print piles:   print                                                 |\n";
    cmd += "   |deal:          deal                                                  |\n";
    cmd += "   |_____________________________________________________________________|\n";
    cmd += "   |Move cards:    move (press Enter)                                    |\n";
    cmd += "   |               <card value> <output pile number> <input pile number> |\n";
    cmd += "   |---------------------------------------------------------------------|\n";

    cout << cmd << endl;
}


void spiderLogo() {
    string logo = "";
    logo += " _______  _______  ___      ___   _______  _______  ___   ______    _______ \n";
    logo += "|       ||       ||   |    |   | |       ||   _   ||   | |    _ |  |       |\n";
    logo += "|  _____||   _   ||   |    |   | |_     _||  |_|  ||   | |   | ||  |    ___|\n";
    logo += "| |_____ |  | |  ||   |    |   |   |   |  |       ||   | |   |_||_ |   |___ \n";
    logo += "|_____  ||  |_|  ||   |___ |   |   |   |  |       ||   | |    __  ||    ___|\n";
    logo += " _____| ||       ||       ||   |   |   |  |   _   ||   | |   |  | ||   |___ \n";
    logo += "|_______||_______||_______||___|   |___|  |__| |__||___| |___|  |_||_______|\n";
    logo += "                                                                            \n";
    logo += "                                   /      \\                                \n";
    logo += "                                \\  \\  ,,  /  /                            \n";
    logo += "                                 '-.`\\()/`.-'                              \n";
    logo += "                                .--_'(  )'_--.                              \n";
    logo += "                               / /` /`''`\\ `\\ \\                          \n";
    logo += "                                |  |  ><  |  |                              \n";
    logo += "                                \\  \\      /  /                            \n";
    logo += "                                    '.__.'                                  \n";
    cout << logo << endl;
}

void bye() {
    string bye = "";
    cout << endl;
    bye += "                    ____             _ _                        \n";
    bye += "                   |  _ \\           | | |                      \n";
    bye += "                   | |_) |_   _  ___| | |      / _ \\           \n";
    bye += "                   |  _ <| | | |/ _ \\ | |    \\_\\(_)/_/       \n";
    bye += "                   | |_) | |_| |  __/_|_|    \\_//\"\\\\_       \n";
    bye += "                   |____/ \\__, |\\___(_|_)      /   \\         \n";
    bye += "                          __/ |                                 \n";
    bye += "                         |___/                                  \n";
    cout << bye << endl;
}

int getOption() {
    string opt = "";
    int response = -1;
    while (response == -1) {
        cout << "Command? ";
        cin >> opt;

        if (opt == "start")      response = 1;
        else if (opt == "quit")  response = 0;
        else if (opt == "reset") response = 2;
        else if (opt == "help")  response = 3;
        else if (opt == "hint")  response = 4;
        else if (opt == "move")  response = 5;
        else if (opt == "print") response = 6;
        else if (opt == "deal")  response = 7;
        else response = -1;

        if (response == -1) cout << "Invalid Command!!!" << endl;

    }
    return response;
}

void move(vector<Card> &deck, vector<vector<Card> > &piles) {
    int value, from, to;
    scanf("%d %d %d", &value, &from, &to);

    if ((value <= 13 && value >= 1) && (from >= 0 && from <= 9) && (to >= 0 && to <= 9)) {
        if (moveCardsTo(piles[from], value, piles[to]))
            printPiles(deck, piles);
        else
            cout << "Impossible move!!!" << endl;
    }
}

int main() {
    Card c1 = newCard(13);
    Card c2 = newCard(12);
    Card c3 = newCard(11);
    Card c4 = newCard(10);
    Card c5 = newCard(9);
    Card c6 = newCard(8);
    Card c7 = newCard(7);
    Card c8 = newCard(6);
    Card c9 = newCard(5);
    Card c10 = newCard(4);
    Card c11 = newCard(3);
    Card c12 = newCard(2);
    Card c22 = newCard(5);
    vector<Card> piles = {c22, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12};
    int lastPos = piles.size() - 1;
    int ace = 2;
    int king = 13;
    int cont = 0;
    if(lastPos >= 0) {
        int elem = piles[lastPos].value - 1;
        if(elem == ace) {
            while(lastPos - 1 >= 0 && checkOrder(piles[lastPos - 1].value - 1, elem) == 1) {
                cout << "Inicio\n";
                cout << "\n------Elemento anterior: " << piles[lastPos - 1].value - 1;
                cout <<"\nElemento:"  << elem;
                cont++;
                elem = piles[lastPos - 1].value - 1;
                cout << "\nUltima pos: " << lastPos-1;
                cout << "\nUltima pos: " << lastPos;
                lastPos--;
                cout << "\nFim\n";


            }
        }


    }







    return EXIT_SUCCESS;
}

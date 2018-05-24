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
int checkCompletedPile(vector<Card> deck, vector<Card> pile);

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

int checkOrder(vector<Card> deck, int cardValue) {
    //Implemented by Kelvin

    //provisorio
    int isValid = 1;
    if (deck.back().value != cardValue) {
        for (int i = deck.size() - 1; i > 0; --i) {
            if (deck[i-1].turned == 0) break;
            if (deck[i].value == cardValue) break;
            if ((deck[i].value+1) != deck[i-1].value) {
                isValid = 0;
                break;
            }
        }
    }
    return isValid;
}

int checkCompletedSuit(vector<Card> deck, int cardValue) {
    //Implemented by Kelvin

    //provisorio
    int isValid = 1;
    if (deck.back().value != cardValue) {
        for (int i = deck.size() - 1; i > 0; --i) {
            if (deck[i-1].turned == 0) {
                isValid = 0;
                break;
            }
            if (deck[i].value == cardValue) break;
            if ((deck[i].value+1) != deck[i-1].value) {
                isValid = 0;
                break;
            }
        }
    }
    return isValid;
}

void congrats() {
    string congrats;
    congrats += "You Won!!";
    cout << congrats << endl;
}

void removeCompletedPile(vector<Card> &pile) {

    while (true) {
        if (pile.back().value == 13 || pile.empty() == 1) {
            pile.pop_back();
            break;
        }
        pile.pop_back();
    }

}

int checkCompletedPile(vector<vector<Card> > &piles) {
    int completedPilesNumber = 0;
    //13 is king
    for (int i = 0; i < piles.size(); ++i) {
        if (checkCompletedSuit(piles[i], 13) == 1) {
            removeCompletedPile(piles[i]);
            completedPilesNumber++;
            cout << "One Suit completed in pile " << i << endl;
        }
    }

    return completedPilesNumber;
}

int checkWon(vector<Card> &deck, vector<vector<Card> > &piles, int &completedPilesCounter) {
    int response = 1;

    completedPilesCounter += checkCompletedPile(piles);

    if (deck.size() != 0 || completedPilesCounter > numberOfSuits)
        response = 0;

    if (response == 1) congrats();

    return response;
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

void deal(vector<Card> &deck, vector<vector<Card> > &piles) {
    //Implemented by Damiao
    if (deck.empty())
        cout << "The game has not started." << endl;
    else {

        int check = 1;

        for (int i = 0; i < piles.size(); i++) {
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
        if (pile[i-1].turned == 0) break;
        //if (pile[i].value == cardValue) break;
        if ((pile[i].value+1) != pile[i-1].value) {
            break;
        }
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
        c.value = getFirstValuePossible(piles[i]);
        for (int j = 0; j < piles.size(); ++j) {
            if ( j != i && (piles[j].back().value-1) == c.value) {
                ostringstream indexI;
                ostringstream indexJ;
                indexI << i;
                indexJ << j;
                response += "Card: " + getStringValue(c) + " -- ";
                response += "Pile: " + indexI.str() + " --> ";
                response += "" + indexJ.str() + "; ";
                response += "\n";

            }
        }

    }

    if (c.value == -1 && deck.size() >= 10) {
        cout << "No hint at the moment. But you can deal a new card into each tableau at the column." << endl;
    } else if (c.value == -1 && deck.size() < 10) {
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
    vector<Card> deck;//104
    vector<vector<Card> > piles(10);
    vector<vector<Card> > completedPiles(10);

    int completedPilesCounter = 0;
    int opt; // [0: quit]; [1: start]; [2: reset]; [3: help] ; [4:hint]; [5:move]; []
    spiderLogo();
    help();
    opt = getOption();
    while (true) {
        if (opt == 0) {
            bye();
            break;
        }
        else if (opt == 1) {
            //start
            start(deck, piles);
            printPiles(deck, piles);
        }
        else if (opt == 2) {
            deck.clear();
            piles[0].clear();
            piles[1].clear();
            piles[2].clear();
            piles[3].clear();
            piles[4].clear();
            piles[5].clear();
            piles[6].clear();
            piles[7].clear();
            piles[8].clear();
            piles[9].clear();
            completedPiles.clear();
            start(deck, piles);
            printPiles(deck, piles);
            //reset
        }
        else if (opt == 3) {
            help();
        }
        else if (opt == 4) {
            hint(deck, piles);
        }
        else if (opt == 5) {
            move(deck, piles);
            if (checkWon(deck,piles, completedPilesCounter)) {
                completedPilesCounter = 0;
                deck.clear();
                piles[0].clear();sta
                piles[1].clear();
                piles[2].clear();
                piles[3].clear();
                piles[4].clear();
                piles[5].clear();
                piles[6].clear();
                piles[7].clear();
                piles[8].clear();
                piles[9].clear();
                completedPiles.clear();
                start(deck, piles);
                printPiles(deck, piles);
            }
        }
        else if (opt == 6){
            printPiles(deck, piles);
        }
        else if (opt == 7) {
            deal(deck, piles);
        }

        // test winner

        opt = getOption();
    }

    /*FOR TESTS
    start(deck, piles);
    checkWon(deck, piles, completedPilesCounter);
    moveCardsTo(piles[8], 2, piles[7]);
    deal(deck, piles);
    moveCardsTo(piles[7], 3, piles[4]);
    moveCardsTo(piles[1], 7, piles[0]);
    moveCardsTo(piles[0], 8, piles[1]);
    printPiles(deck, piles);
    hint(deck, piles);
    checkWon(deck, piles, completedPilesCounter);
    moveCardsTo(piles[5], 11, piles[0]);
    moveCardsTo(piles[6], 10, piles[0]);
    moveCardsTo(piles[1], 9, piles[0]);
    moveCardsTo(piles[4], 4, piles[1]);
    moveCardsTo(piles[6], 1, piles[3]);
    printPiles(deck, piles);
    hint(deck, piles);
    checkWon(deck, piles, completedPilesCounter);
    moveCardsTo(piles[1], 5, piles[6]);
    moveCardsTo(piles[6], 6, piles[0]);
    deal(deck, piles);
    moveCardsTo(piles[0], 9, piles[1]);
    moveCardsTo(piles[0], 12, piles[9]);
    printPiles(deck, piles);
    hint(deck, piles);
    printPiles(deck, piles);
    checkWon(deck, piles, completedPilesCounter);
    printPiles(deck, piles);*/

    return EXIT_SUCCESS;
}

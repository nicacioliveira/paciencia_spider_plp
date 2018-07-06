//
// Created by Nicacio, Damiao, Daniela, Lucas and Kelvin on 05/20/18 for the discipline of PLP.
// UFCG - Campina Grande - PB
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <ctime>

using namespace std;

const int frenchSuitNumber = 13;
const int numberOfSuits = 8;
const int qtdPiles = 10;
const int _false = 0;
int contMovements = 0;

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
 * This function returns int value of the card value.
 * @param string card value
 * @return int card value
 */
int getIntValue(string card);

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
 * checks if there is any completed suit in any of the stacks
 * @param deck
 * @param completedPiles
 * @return 1: is true; 0: is not true
 */
int checkCompletedSuit(vector<vector<Card> > &piles);

/**
 * Check if pile contais one completed suit
 * @param pile
 * @return
 */
int checkCompletedSuit(vector<Card> pile);

/**
 * removes a completed suit from a pile
 * @param pile
 */
void removeCompletedSuit(vector<Card> &pile);

/**
 * Check winner
 *
 * @param deck
 * @param piles
 * @param completedPilesCounter
 * @return
 */
int checkWon(vector<Card> &deck, vector<vector<Card> > &piles, int &completedPilesCounter);

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
void deal(vector<Card> &deck, vector<vector<Card> > &piles, int isStarded);

/**
 * Takes the first value that can be moved in a stack
 * @param pile
 * @return
 */
int getFirstValuePossible(vector<Card> pile);

/**
 * Gameplay hints
 * @param deck
 * @param piles
 */
void hint(vector<Card> deck, vector<vector<Card> > piles);

/**
 * Prints the number of card movements performed
 */
void printContMovements();

/**
 * Help options
 */
void help();

void congrats();

/**
 * Get options in game
 * @return
 */
int getOption();

// -------------------------------------------------Basic Functions-----------------------------------------------------

string getStringValue(Card c) {
    string resp;
    if (!c.turned) {
        resp = "|-----|";
    }
    else if (c.value == 1)
        resp = "| Ace |";
    else if (c.value == 2)
        resp = "|  2  |";
    else if (c.value == 3)
        resp = "|  3  |";
    else if (c.value == 4)
        resp = "|  4  |";
    else if (c.value == 5)
        resp = "|  5  |";
    else if (c.value == 6)
        resp = "|  6  |";
    else if (c.value == 7)
        resp = "|  7  |";
    else if (c.value == 8)
        resp = "|  8  |";
    else if (c.value == 9)
        resp = "|  9  |";
    else if (c.value == 10)
        resp = "| 10  |";
    else if (c.value == 11)
        resp = "| Jack|";
    else if (c.value == 12)
        resp = "|Queen|";
    else if (c.value == 13)
        resp = "| King|";
    else {
        resp = "       ";
    }
    return resp;
}

int getIntValue(string card) {
    transform(card.begin(), card.end(), card.begin(), ::tolower);
    int resp;
    if (card == "ace" || card == "1")
        resp = 1;
    else if (card == "2")
        resp = 2;
    else if (card == "3")
        resp = 3;
    else if (card == "4")
        resp = 4;
    else if (card == "5")
        resp = 5;
    else if (card == "6")
        resp = 6;
    else if (card == "7")
        resp = 7;
    else if (card == "8")
        resp = 8;
    else if (card == "9")
        resp = 9;
    else if (card == "10")
        resp = 10;
    else if (card == "jack" || card == "11")
        resp = 11;
    else if (card == "queen"|| card == "12")
        resp = 12;
    else if (card == "king" || card == "13")
        resp = 13;
    else
        resp = -1;

    return resp;
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
        header += "   |\\_" + index.str() + "_/|";
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

int checkCompletedSuit(vector<Card> pile) {
    //Implemented by Nicacio

    int count = 1;
    int isValid = 0;
    if (!pile.empty() && pile.back().value == 1) {
        Card next = pile.back();
        pile.pop_back();
        while (count <= 13) {

            if (count == 13 && next.value == 13){
                isValid = 1;
                break;
            } else if (!pile.empty() && (pile.back().value) == next.value + 1) {
                count++;
                next = pile.back();
                pile.pop_back();
            } else {
                isValid = 0;
                break;
            }
        }
    }
    return isValid;
}

void removeCompletedSuit(vector<Card> &pile) {
    //Implemented by Nicacio
    while (true) {
        if (pile.back().value == 13 || pile.empty() == 1) {
            pile.pop_back();
            if (!pile.empty()) pile.back().turned = 1;
            break;
        }
        pile.pop_back();
    }

}

int checkCompletedSuit(vector<vector<Card> > &piles) {
    // Implemented by Nicacio
    int completedPilesNumber = 0;
    //13 is king
    for (int i = 0; i < piles.size(); ++i) {
        if (checkCompletedSuit(piles[i]) == 1) {
            removeCompletedSuit(piles[i]);
            completedPilesNumber++;
            printPiles(piles);
            cout << "One Suit completed in pile " << i << endl;
        }
    }

    return completedPilesNumber;
}

int checkWon(vector<Card> &deck, vector<vector<Card> > &piles, int &completedPilesCounter) {
    // Implemented by Nicacio
    int response = 0;

    completedPilesCounter += checkCompletedSuit(piles);

    if (completedPilesCounter == numberOfSuits)
        response = 1;

    if (response == 1) congrats();

    return response;
}

int contains(vector<Card> deck, int value) {
    //Implemented by Nicacio
    int resp = 0;
    for (int i = 0; i < deck.size(); ++i) {
        if (deck[i].value == value && deck[i].turned) {
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
    else if (value + 1 == to.back().value)
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

        if (!from.empty()) from.back().turned = 1;

        while (!stack.empty()) {
            to.push_back(stack.back());
            stack.pop_back();
        }
        response = 1;
    }
    return response;
}

void deck_shuffle(vector<Card> &deck) {
    //Implemented by Lucas
    srand(time(0));
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

void deal(vector<Card> &deck, vector<vector<Card> > &piles, int isStarted) {
    //Implemented by Damiao
    if (deck.empty())
        cout << "You did not have any more cards to hand out!" << endl;
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
            printPiles(piles);
        }
    }
}

int getFirstValuePossible(vector<Card> pile) {
    int value = -1;
    if (!pile.empty()) {
        value = pile.back().value;

        for (int i = pile.size() - 1; i > 0; --i) {
            if (pile[i - 1].turned == 0) break;
            //if (pile[i].value == cardValue) break;
            if ((pile[i].value + 1) != pile[i - 1].value) {
                break;
            }
            value = pile[i - 1].value;
        }
    }
    return value;
}

// ---------------------------------------------Jogability functions----------------------------------------------------

//aux function for generate hint string
string makeHintString(int indexPileFrom, int indexPileTo, Card c) {
    string response;
    ostringstream indexI;
    ostringstream indexJ;
    indexI << indexPileFrom;
    indexJ << indexPileTo;
    response += "Card: " + getStringValue(c) + " -- ";
    response += "Pile: " + indexI.str() + " --> ";
    response += "" + indexJ.str() + "; ";
    response += "\n";
    return response;
}

void hint(vector<Card> deck, vector<vector<Card> > piles) {
    Card card;
    card.value = -1;
    card.turned = 1;
    string header = "--------------HINT-------------\n";
    string response = "";
    string footer = "-------------------------------\n";

    for (int indexPileFrom = 0; indexPileFrom < piles.size(); ++indexPileFrom) {

        card.value = getFirstValuePossible(piles[indexPileFrom]);

        if (card.value != -1) {

            for (int indexPileTo = 0; indexPileTo < piles.size(); ++indexPileTo) {
                if (piles[indexPileTo].empty())
                    response += makeHintString(indexPileFrom, indexPileTo, card);
                else if (indexPileTo != indexPileFrom && (piles[indexPileTo].back().value - 1) == card.value)
                    response += makeHintString(indexPileFrom, indexPileTo, card);
            }
        }
    }

    if (response.size() <= 0 && deck.size() >= 10) {
        cout << "No hint at the moment. But you can deal a new card into each tableau at the column." << endl;
    } else if (response.size() <= 0) {
        cout << "No hint at the moment." << endl;
    } else if (card.value == -1) {
        cout << "No hint at the moment." << endl;
    } else {
        cout << header + response + footer << endl;
    }
}

void help() {
    string cmd = "";
    cmd += "   |---------------------------------HELP--------------------------------|\n";
    cmd += "   |Start:            start                                              |\n";
    cmd += "   |Quit Game:        quit                                               |\n";
    cmd += "   |Reset Game:       reset                                              |\n";
    cmd += "   |Help:             help                                               |\n";
    cmd += "   |Hint:             hint                                               |\n";
    cmd += "   |print piles:      print                                              |\n";
    cmd += "   |deal:             deal                                               |\n";
    cmd += "   |Completed Suits:  suits                                              |\n";
    cmd += "   |_____________________________________________________________________|\n";
    cmd += "   |Move cards:    move (press Enter)                                    |\n";
    cmd += "   |               <card value> <output pile number> <input pile number> |\n";
    cmd += "   |Cards:         Ace(1) 2 3 4 5 6 7 8 9 10 Jack(11) Queen(12) King(13) |\n";
    cmd += "   |---------------------------------------------------------------------|\n";

    cout << cmd << endl;
}

// auxiliary function
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

// auxiliary function
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

// auxiliary function
void congrats() {
    string congrats;
    congrats += " __     __          __          ___       _        \n";
    congrats += " \\ \\   / /          \\ \\        / (_)     | |   \n";
    congrats += "  \\ \\_/ /__  _   _   \\ \\  /\\  / / _ _ __ | |  \n";
    congrats += "   \\   / _ \\| | | |   \\ \\/  \\/ / | | '_ \\| | \n";
    congrats += "    | | (_) | |_| |    \\  /\\  /  | | | | |_|     \n";
    congrats += "    |_|\\___/ \\__,_|     \\/  \\/   |_|_| |_(_)   \n";
    congrats += "                                                   \n";
    congrats += "\n";
    congrats += "   _____                            _         _       _   _                 _          \n";
    congrats += "  / ____|                          | |       | |     | | (_)               | |         \n";
    congrats += " | |     ___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_ _  ___  _ __  ___| |         \n";
    congrats += " | |    / _ \\| '_ \\ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \\| '_ \\/ __| |     \n";
    congrats += " | |___| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \\__ \\_|       \n";
    congrats += "  \\_____\\___/|_| |_|\\__, |_|  \\__,_|\\__|\\__,_|_|\\__,_|\\__|_|\\___/|_| |_|___(_)\n";
    congrats += "                     __/ |                                                             \n";
    congrats += "                    |___/                                                              \n";
    cout << congrats << endl;
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
        else if (opt == "suits") response = 8;
        else response = -1;

        if (response == -1) cout << "Invalid Command!!!" << endl;

    }
    return response;
}

//auxiliary move cards function
void move(vector<Card> &deck, vector<vector<Card> > &piles) {
    char cardIn[5];
    int value, from, to;
    scanf("%s %d %d", cardIn, &from, &to);
    string card(cardIn);
    value = getIntValue(card);

    if ((value <= 13 && value >= 1) && (from >= 0 && from <= 9) && (to >= 0 && to <= 9)) {
        if (moveCardsTo(piles[from], value, piles[to])) {
            printPiles(piles);
            contMovements++;
            printContMovements();
        } else
            cout << "Impossible move!!!" << endl;
    }

}

// auxiliary function
int checkIsStarted(int isStarted) {
    if (isStarted == 0) {
        cout << "The game has not been started!" << endl;
        return 0;
    }
    return 1;
}

// auxiliary function
void resetPiles(vector<vector<Card> > &piles) {
    for (int i = 0; i < piles.size(); ++i) {
        piles[i].clear();
    }
}

// auxiliary function
void viewCompletedPilesNumber(int completedPilesCounter) {
    cout << "Complete suits: " << completedPilesCounter << endl;
}

// auxiliary function
void printContMovements(){
    cout << "\n\nMade movements: " << contMovements << "\n" << endl;
}

int main() {
    vector<Card> deck;//104
    vector<vector<Card> > piles(10);

    int completedPilesCounter = 0;
    int opt; // [0: quit]; [1: start]; [2: reset]; [3: help] ; [4:hint]; [5:move]; [6:print]; [7:deal]; [8:suits]
    int isStarted = 0;
    int started = 1;
    spiderLogo();
    help();
    opt = getOption();
    while (true) {
        if (opt == 0) {
            //QUIT
            bye();
            deck.clear();
            resetPiles(piles);
            break;
        }
        else if (opt == 1 && checkIsStarted(started)) {
            //START
            start(deck, piles);
            isStarted = 1;
            started = 0;
            printPiles(piles);
            printContMovements();
        }
        else if (opt == 2 && checkIsStarted(isStarted)) {
            //RESET
            deck.clear();
            resetPiles(piles);
            start(deck, piles);
            printPiles(piles);
            contMovements = 0;
            printContMovements();
        }
        else if (opt == 3) {
            //HELP MENU
            help();
        }
        else if (opt == 4 && checkIsStarted(isStarted)) {
            //HINT
            hint(deck, piles);
        }
        else if (opt == 5 && checkIsStarted(isStarted)) {
            //MOVE CARD
            move(deck, piles);
            // CHECK WON and CHECK COMPLETED PILES
            if (checkWon(deck, piles, completedPilesCounter)) {
                completedPilesCounter = 0;
                isStarted = 0;
                started = 1;
                deck.clear();
                resetPiles(piles);
                contMovements = 0;
                printContMovements();
            }
        }
        else if (opt == 6 && checkIsStarted(isStarted)){
            //PRINT PILES
            printPiles(piles);
            printContMovements();
        }
        else if (opt == 7 && checkIsStarted(isStarted)) {
            // HANDOUT CARDS
            deal(deck, piles, isStarted);
        }
        else if (opt == 8 && checkIsStarted(isStarted)){
            // SUITS NUMBER
            viewCompletedPilesNumber(completedPilesCounter);
        }

        opt = getOption();
    }


    return EXIT_SUCCESS;
}

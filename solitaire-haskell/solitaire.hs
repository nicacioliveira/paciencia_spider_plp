---------------------------------------------------------------------------------------------------
--                                     Spider Solitaire                                           |
-- Created by Nicacio, Damiao, Daniela, Lucas and Kelvin on 05/20/18 for the discipline of PLP.   |
-- UFCG - Campina Grande - PB                                                                     |
---------------------------------------------------------------------------------------------------

import Data.List

-- Formatting of the suits:
-- empty: |-----|
-- Cards: | Ace |
--        |  2  |
--        |  3  |
--        |  4  |
--        |  5  |
--        |  6  |
--        |  7  |
--        |  8  |
--        |  9  |
--        | 10  |
--        |Jack |
--        |Queen|
--        | King|

data Card = Card {
    number :: Int,
    value :: String,
    turned :: Bool
} deriving (Show)

cardNumber :: Card -> Int
cardNumber (Card n v t) = n

cardValue :: Card -> String
cardValue (Card n v t) = v

cardIsTurned :: Card -> Bool
cardIsTurned (Card n v t) = t

frenchSuit = [Card 1  "| King|" True,
        Card 2  "|Queen|" True,
        Card 3  "| Jack|" True,
        Card 4  "| 10  |" True,
        Card 5  "|  9  |" True,
        Card 6  "|  8  |" True,
        Card 7  "|  7  |" True,
        Card 8  "|  6  |" True,
        Card 9  "|  5  |" True,
        Card 10 "|  4  |" True,
        Card 11 "|  3  |" True,
        Card 12 "|  2  |" True,
        Card 12 "| Ace |" True
        ]

createCard :: Int -> String -> Bool -> Card
createCard n v t = Card {number = n, value = v, turned = t}

--- SHOW PILES
formatLine :: [Card] -> String
formatLine [] = ""
formatLine s = (cardValue $ head s) ++ "  " ++ (formatLine $ tail s)

formatPiles :: [[Card]] -> String
formatPiles [] = ""
formatPiles s = (formatLine $ head s) ++ "\n" ++ (formatPiles $ tail s)

printPiles :: [[Card]] -> IO()
printPiles piles = do
    putStrLn "| --- |  | --- |  | --- |  | --- |  | --- |  | --- |  | --- |  | --- |  | --- |  | --- |  | --- |  | --- |  | --- |"
    putStrLn $ formatPiles $ transpose piles


--- HANDOUTCARDSTO
--- deck, quantity, pile to
--- returns modified pile
handOutCardsTo :: [Card] -> Int -> [Card] -> [Card]
handOutCardsTo deck quantity pile = []

--- filldeck or create
fillDeck :: [Card] -> [Card]
fillDeck deck = []

---checkOrder
checkOrder :: [Card] -> Int -> Bool
checkOrder pile cardValue = False

---checkCompletedSuit
checkCompletedSuit :: [Card] -> Bool
checkCompletedSuit pile = False

removeCompletedSuit :: [Card] -> Bool
removeCompletedSuit piles = False

checkWon :: [Card] -> [[Card]] -> Int -> Bool
checkWon deck piles completedPilesNumber = False

contains :: [Card] -> Bool
contains pile = False

-- moveCardsTo ????

-- deck_shuffle ???

-- start ????

deal :: [Card] -> [[Card]] -> [[Card]]
deal deck piles = [[]]

hint :: [Card] -> [[Card]] -> IO()
hint deck piles = do
    putStrLn "not implemented"

help :: String
help = 
    "\n"
    ++"  |---------------------------------HELP--------------------------------|\n"
    ++"  |Start:            start                                              |\n"
    ++"  |Quit Game:        quit                                               |\n"
    ++"  |Reset Game:       reset                                              |\n"
    ++"  |Help:             help                                               |\n"
    ++"  |Hint:             hint                                               |\n"
    ++"  |print piles:      print                                              |\n"
    ++"  |deal:             deal                                               |\n"
    ++"  |Completed Suits:  suits                                              |\n"
    ++"  |_____________________________________________________________________|\n"
    ++"  |Move cards:    move (press Enter)                                    |\n"
    ++"  |               <card value> <output pile number> <input pile number> |\n"
    ++"  |Cards:         Ace(1) 2 3 4 5 6 7 8 9 10 Jack(11) Queen(12) King(13) |\n"
    ++"  |---------------------------------------------------------------------|\n"

spiderLogo :: String
spiderLogo =
        "\n"
        ++" _______  _______  ___      ___   _______  _______  ___   ______    _______ \n"
        ++"|       ||       ||   |    |   | |       ||   _   ||   | |    _ |  |       |\n"
        ++"|  _____||   _   ||   |    |   | |_     _||  |_|  ||   | |   | ||  |    ___|\n"
        ++"| |_____ |  | |  ||   |    |   |   |   |  |       ||   | |   |_||_ |   |___ \n"
        ++"|_____  ||  |_|  ||   |___ |   |   |   |  |       ||   | |    __  ||    ___|\n"
        ++" _____| ||       ||       ||   |   |   |  |   _   ||   | |   |  | ||   |___ \n"
        ++"|_______||_______||_______||___|   |___|  |__| |__||___| |___|  |_||_______|\n"
        ++"                                                                            \n"
        ++"                                   /      \\                                \n"
        ++"                                \\  \\  ,,  /  /                            \n"
        ++"                                 '-.`\\()/`.-'                              \n"
        ++"                                .--_'(  )'_--.                              \n"
        ++"                               / /` /`''`\\ `\\ \\                          \n"
        ++"                                |  |  ><  |  |                              \n"
        ++"                                \\  \\      /  /                            \n"
        ++"                                    '.__.'                                  \n"

bye :: String
bye = 
    "\n"
    ++"                    ____             _ _                        \n"
    ++"                   |  _ \\           | | |                      \n"
    ++"                   | |_) |_   _  ___| | |      / _ \\           \n"
    ++"                   |  _ <| | | |/ _ \\ | |    \\_\\(_)/_/       \n"
    ++"                   | |_) | |_| |  __/_|_|    \\_//\"\\\\_       \n"
    ++"                   |____/ \\__, |\\___(_|_)      /   \\         \n"
    ++"                          __/ |                                 \n"
    ++"                         |___/                                  \n"

congrats :: String
congrats = 
        "\n"
        ++" __     __          __          ___       _        \n"
        ++" \\ \\   / /          \\ \\        / (_)     | |   \n"
        ++"  \\ \\_/ /__  _   _   \\ \\  /\\  / / _ _ __ | |  \n"
        ++"   \\   / _ \\| | | |   \\ \\/  \\/ / | | '_ \\| | \n"
        ++"    | | (_) | |_| |    \\  /\\  /  | | | | |_|     \n"
        ++"    |_|\\___/ \\__,_|     \\/  \\/   |_|_| |_(_)   \n"
        ++"                                                   \n"
        ++"\n"
        ++"   _____                            _         _       _   _                 _          \n"
        ++"  / ____|                          | |       | |     | | (_)               | |         \n"
        ++" | |     ___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_ _  ___  _ __  ___| |         \n"
        ++" | |    / _ \\| '_ \\ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \\| '_ \\/ __| |     \n"
        ++" | |___| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \\__ \\_|       \n"
        ++"  \\_____\\___/|_| |_|\\__, |_|  \\__,_|\\__|\\__,_|_|\\__,_|\\__|_|\\___/|_| |_|___(_)\n"
        ++"                     __/ |                                                             \n"
        ++"                    |___/                                                              \n"
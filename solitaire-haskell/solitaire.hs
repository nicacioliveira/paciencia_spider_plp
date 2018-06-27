---------------------------------------------------------------------------------------------------
--                                     Spider Solitaire                                           |
-- Created by Nicacio, Damiao, Daniela, Lucas and Kelvin on 05/20/18 for the discipline of PLP.   |
-- UFCG - Campina Grande - PB                                                                     |
---------------------------------------------------------------------------------------------------
module Main where

import StackFunctions
import Card
import DeckFunctions


isNotStarted :: Bool -> Bool
isNotStarted started = started == False

isStarted :: Bool -> Bool
isStarted started = started == True

getOption :: IO String
getOption = 
    do
        putStrLn "command?? "
        opt <- getLine
        return opt


main :: IO()
main =  
    do  
        putStrLn spiderLogo
        putStrLn help
        run "" False [] [[]]


run :: String -> Bool -> [Card] -> [[Card]] -> IO()
run opt started deck piles  
                            | opt == "quit" =
                                do
                                    putStrLn bye

                            | opt == "start" && isNotStarted started =
                                do
                                    let d_p = createPiles 4 5 (newDeck 8) []
                                    let deck = fst d_p
                                    let piles = snd d_p
                                    let d_p = createPiles 6 4 deck piles
                                    let deck = fst d_p
                                    let piles = snd d_p
                                    
                                    printPiles piles

                                    run "" True deck piles

                            | opt == "start" && isStarted started = 
                                do
                                    putStrLn "Is Started!!!"
                                    run "" True deck piles

                            | opt == "reset" && isStarted started =
                                do
                                    let d_p = createPiles 4 5 (newDeck 8) []
                                    let deck = fst d_p
                                    let piles = snd d_p
                                    let d_p = createPiles 6 4 deck piles
                                    let deck = fst d_p
                                    let piles = snd d_p
                                    
                                    printPiles piles

                                    run "" True deck piles

                            | opt == "reset" && isNotStarted started =
                                do
                                    putStrLn "Is not Started!!!"

                                    run "" False deck piles

                            | opt == "help"=
                                do
                                    putStrLn help
                                    run "" started deck piles

                            | opt == "hint" && isStarted started =
                                do
                                    putStrLn "Not Implemented!!!"
                                    run "" started deck piles

                            | opt == "hint" && isNotStarted started =
                                do
                                    putStrLn "is not Started!!!"
                                    run "" started deck piles

                            | opt == "move" && isStarted started =
                                do
                                    putStrLn "Not Implemented!!!"
                                    run "" started deck piles

                            | opt == "move" && isNotStarted started =
                                do
                                    putStrLn "is not Started!!!"
                                    run "" started deck piles


                            | opt == "deal" && isStarted started =
                                do
                                    putStrLn "Not Implemented!!!"
                                    run "" started deck piles

                            | opt == "deal" && isNotStarted started =
                                do
                                    putStrLn "is not Started!!!"
                                    run "" started deck piles

                            | opt == "suits" && isStarted started =
                                do
                                    putStrLn "Not Implemented!!!"
                                    run "" started deck piles

                            | opt == "suits" && isNotStarted started =
                                do
                                    putStrLn "is not Started!!!"
                                    run "" started deck piles

                            | opt == "print" && isStarted started = 
                                do
                                    printPiles piles
                                    run "" True deck piles

                            | opt == "print" && isNotStarted started = 
                                do
                                    putStrLn "Is not Started!!!"
                                    run "" False deck piles

                            | otherwise =
                                do
                                    opt <- getOption
                                    run opt started deck piles


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
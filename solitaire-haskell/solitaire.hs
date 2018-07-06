---------------------------------------------------------------------------------------------------
--                                     Spider Solitaire                                           |
-- Created by Nicacio                                                                             |
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
        putStrLn ""
        return opt


main :: IO()
main =  
    do  
        putStrLn spiderLogo
        putStrLn help
        run 0 0 "" False [] [[]]


-- 
run :: Int -> Int -> String -> Bool -> [Card] -> [[Card]] -> IO()
run numberOfPlays completedSuits opt started deck piles
                            --The player wins when:
                            | completedSuits == 8 =
                                do
                                    putStrLn "8 completed suits"
                                    putStrLn congrats
                                    run 0 0 "help" False [] [[]]

                            | opt == "quit" =
                                do
                                    putStrLn bye

                            | opt == "start" && isNotStarted started =
                                do
                                    let d_p = createPiles 4 5 (shuffle $ newDeck 8) []
                                    let deck = fst d_p
                                    let piles = snd d_p
                                    let d_p = createPiles 6 4 deck piles
                                    let deck = fst d_p
                                    let piles = snd d_p

                                    run numberOfPlays completedSuits "print" True deck piles

                            | opt == "start" && isStarted started = 
                                do
                                    putStrLn "Is Started!!!"
                                    run numberOfPlays completedSuits "" True deck piles

                            | opt == "reset" && isStarted started =
                                do
                                    let d_p = createPiles 4 5 (shuffle $ newDeck 8) []
                                    let deck = fst d_p
                                    let piles = snd d_p
                                    let d_p = createPiles 6 4 deck piles
                                    let deck = fst d_p
                                    let piles = snd d_p

                                    run 0 0 "print" True deck piles

                            | opt == "reset" && isNotStarted started =
                                do
                                    putStrLn "Is not Started!!!"

                                    run numberOfPlays completedSuits "" False deck piles

                            | opt == "help"=
                                do
                                    putStrLn help
                                    run numberOfPlays completedSuits "" started deck piles

                            | opt == "hint" && isStarted started =
                                do
                                    let hintResponse = hint piles

                                    if thereAreEmptyPiles piles then 
                                        putStrLn "There are empty piles that can be used in moves."
                                    else
                                        putStr ""

                                    if hintResponse == "" && length deck >= 10 then
                                            putStrLn "No hint at the moment. But you can deal a new card into each tableau at the column."
                                    else
                                        if hintResponse == "" then
                                            putStrLn "No hint at the moment."
                                        else
                                            do
                                                putStrLn "--------------HINT-------------"
                                                putStrLn hintResponse
                                                putStrLn "-------------------------------"

                                    run numberOfPlays completedSuits "" started deck piles

                            | opt == "hint" && isNotStarted started =
                                do
                                    putStrLn "is not Started!!!"
                                    run numberOfPlays completedSuits "" started deck piles

                            | opt == "move" && isStarted started =
                                do
                                    putStr "Card? "
                                    card    <- getLine
                                    putStr "From? "
                                    from    <- getLine
                                    putStr "To? "
                                    to      <- getLine

                                    if (isNumber card && isNumber from && isNumber to) then
                                        do
                                            let movement        = (move ( read from) ( read to) ( read card) piles)
                                            let isValidMovement = fst movement
                                            let pileFrom        = fst $ snd movement
                                            let pileTo          = snd $ snd movement

                                            if (isValidMovement) then
                                                do
                                                    let p1 = replaceValueAtPos ( read from) pileFrom piles
                                                    let p2 = replaceValueAtPos ( read to) pileTo p1
                                                    let checkWon = checkCompletedPiles completedSuits p2

                                                    let completedSuits = fst checkWon
                                                    let p3 = snd checkWon

                                                    run (numberOfPlays+1) completedSuits "print" started deck p3
                                            else
                                                do
                                                    putStrLn "Invalid movement!"
                                                    run numberOfPlays completedSuits "" started deck piles                                        
                                    else
                                        do
                                            putStrLn "Invalid Input!"
                                            run numberOfPlays completedSuits "" started deck piles  

                            | opt == "move" && isNotStarted started =
                                do
                                    putStrLn "is not Started!!!"
                                    run numberOfPlays completedSuits "" started deck piles

                            | opt == "deal" && isStarted started =
                                do

                                    if (oneCardPerPile piles) == False then
                                        do
                                            putStrLn "All stacks must contain at least one card."
                                            run numberOfPlays completedSuits "" started deck piles
                                    else
                                        if length deck < 10 then
                                            do
                                                putStrLn "You did not have any more cards to hand out!"
                                                run numberOfPlays completedSuits "" started deck piles
                                        else
                                            do
                                                let d_p = deal deck piles
                                                let deck = fst d_p
                                                let piles = snd d_p

                                                run numberOfPlays completedSuits "print" started deck piles

                            | opt == "deal" && isNotStarted started =
                                do
                                    putStrLn "is not Started!!!"
                                    run numberOfPlays completedSuits "" started deck piles

                            | opt == "suits" && isStarted started =
                                do
                                    putStrLn "-------------------------------------------------------------------------------"
                                    putStrLn ("Completed Suits: " ++ show completedSuits)
                                    putStrLn "-------------------------------------------------------------------------------"
                                    run numberOfPlays completedSuits "" started deck piles

                            | opt == "suits" && isNotStarted started =
                                do
                                    putStrLn "is not Started!!!"
                                    run numberOfPlays completedSuits "" started deck piles

                            | opt == "print" && isStarted started = 
                                do
                                    putStrLn "-------------------------------------------------------------------------------"
                                    putStrLn ("Number of Plays: " ++ show numberOfPlays)
                                    putStrLn ("Completed Suits: " ++ show completedSuits)
                                    putStrLn "-------------------------------------------------------------------------------"
                                    printPiles piles
                                    run numberOfPlays completedSuits "" True deck piles

                            | opt == "print" && isNotStarted started = 
                                do
                                    putStrLn "Is not Started!!!"
                                    run numberOfPlays completedSuits "" False deck piles

                            | otherwise =
                                do
                                    opt <- getOption
                                    run numberOfPlays completedSuits opt started deck piles



-- used in move function
isNumber :: String -> Bool
isNumber s =    case reads s :: [(Integer, String)] of
                    [(_, "")] -> True
                    _         -> False

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
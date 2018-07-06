---------------------------------------------------------------------------------------------------
-- Created by Nicacio                                                                             |
-- UFCG - Campina Grande - PB                                                                     |
---------------------------------------------------------------------------------------------------
module DeckFunctions where

import Data.List -- for transpose matrix
import Card
import StackFunctions
import System.Random -- for shuffle
import System.IO.Unsafe -- for shuffle random int

------------------------------------------------------------------------------------------------------------------------------------

{-
    This implementation tried, to the maximum, 
    not to make use of monads and the like so 
    that it was possible to study to the maximum 
    the basic structures of Hask language
-}


-- PRINTPILES ------------------------------------------------------------------------------------------------------------------------------------

{-
    Methods to format and print piles of cards.
-}

printPiles :: [[Card]] -> IO()
printPiles piles =
    do
        let str = formatPiles $ transpose $ toStringPiles (maxLenthInPiles piles) piles
        putStrLn "|[[0]]| |[[1]]| |[[2]]| |[[3]]| |[[4]]| |[[5]]| |[[6]]| |[[7]]| |[[8]]| |[[9]]|"
        putStrLn "|=====| |=====| |=====| |=====| |=====| |=====| |=====| |=====| |=====| |=====|"
        putStrLn str

formatPiles :: [[String]] -> String
formatPiles [] = ""
formatPiles (x:xs) = formatPile x ++ "\n" ++ formatPiles xs

maxLenthInPiles :: [[Card]] -> Int
maxLenthInPiles piles = maximum $ map length piles

addString :: String -> Int -> [String] -> [String]
addString _ 0 l = l
addString s n l = addString s (n-1) (push s l)

formatPile :: [String] -> String
formatPile [] = ""
formatPile (x:xs) = x ++ " " ++ formatPile xs


--[[Card, Card],[Card, Card]] -> [["value", "value"], ["value", "value"]]
toStringPiles :: Int -> [[Card]] -> [[String]]
toStringPiles _ [] = []
toStringPiles n (x:xs) = (addString "       " (n - (length x))(map toString x)):toStringPiles n xs

--SUITs, DECK and PILES ----------------------------------------------------------------------------------------------------------------------------------

{-
    The French suit, used here, contains: 13 cards : Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack , Queen, King
    The French Deck, used here, contains: 104 Cards or 8 French Suits
-}

newSuit :: [Card]
--FORTESTS--newSuit = [newCard 13 True, newCard 12 True, newCard 11 True, newCard 10 True, newCard 9 True, newCard 8 True, newCard 7 True, newCard 6 True, newCard 5 True, newCard 4 True, newCard 3 True, newCard 2 True, newCard 1 True]
newSuit = [newCard 13 False, newCard 12 False, newCard 11 False, newCard 10 False, newCard 9 False, newCard 8 False, newCard 7 False, newCard 6 False, newCard 5 False, newCard 4 False, newCard 3 False, newCard 2 False, newCard 1 False]

-- qtt suits -> deck
newDeck :: Int -> [Card]
newDeck 0 = []
newDeck n = newSuit ++ newDeck (n-1)

-- qtt, from, to -> from to
handOutCards :: Int -> [Card] -> [Card] -> ([Card], [Card])
handOutCards n from to =	if n == 1 then
                            	(resultantFrom, push (setCardTurned headFrom) to )
                        	else
                                handOutCards (n-1) resultantFrom (push headFrom to)
                            where
                            	resultantFrom = init from
                            	headFrom = last from


-- qtt deck -> deck pile
createPile :: Int -> [Card] -> ([Card], [Card])
createPile n deck = handOutCards n deck []

-- qtd nCards deck piles
createPiles :: Int -> Int -> [Card] -> [[Card]] -> ([Card], [[Card]])
createPiles n qtd deck piles =
                    if (n == 0) then 
                        (deck, piles)
                    else
                        createPiles (n-1) qtd newDeck (push newPile piles)
                    where
                        d_p = createPile qtd deck
                        newDeck = fst d_p
                        newPile = snd d_p

-- MOVE CARDS ----------------------------------------------------------------------------------------------------------------

-- push_back a list elements in another list
pushBackCards :: [Card] -> [Card] -> [Card]
pushBackCards [] p2 =   p2
pushBackCards p1 p2 =   pushBackCards px1 (push c p2) 
                        where 
                            c = last p1
                            px1 = init p1

-- set that the last card in a list has turned
setLastTurned :: [Card] -> [Card]
setLastTurned [] = []
setLastTurned pile = push (setCardTurned c) p
                                            where
                                                c = last pile
                                                p = init pile


-- mover one card in pile A for pile B
-- Whereas, if possible, the cards below that letter should be moved
moveCardPileToPile :: Card -> [Card] -> [Card] -> [Card] -> ([Card], [Card])
moveCardPileToPile card pFrom pTo paux =
                                    if cardEquals card c1 then
                                        (setLastTurned (pop pFrom), (pushBackCards (push (c1) paux) pTo))
                                    else
                                        moveCardPileToPile card px1 pTo (push c1 paux)
                                    where
                                        c1 = if length pFrom == 0 then invalidCard else last pFrom
                                        px1 = init pFrom


-- checks if one card is smaller than another card
-- Card(2) - 1 == CardNext(1)
isValidOrder :: Card -> Card -> Bool
isValidOrder (Card v t) (Card vnext t2) = ((v-1) == vnext) && (t && t2)

-- check if the order of the cards below a card is correct
checkOrder :: Card -> [Card] -> Bool
checkOrder card [c] = if card == c && isTurned card then True else False
checkOrder card pile =  if card == lastcardp && isTurned card then
                            True
                        else
                            if isValidOrder cardp lastcardp then
                                checkOrder card lastpile
                            else
                                False
                        where
                            lastcardp = last pile
                            lastpile = init pile
                            cardp = last lastpile



-- aux
replaceValueAtPos :: Int -> a -> [a] -> [a]
replaceValueAtPos pos val (x:xs)
                                | pos < 0 || pos >= length (x:xs) = error "Invalid position!!!"
                                | pos == 0    = val:xs
                                | otherwise = x:replaceValueAtPos (pos-1) val xs
-- aux
isValidInterval :: Int -> Int -> [[Card]] -> Bool
isValidInterval n1 n2 piles = (n1 >= 0 && n2 >= 0) && (n1 < l && n1 < l) where l = length piles

-- searches from the bottom up (by the rules of the game)
getCardInPile :: Int -> [Card] -> Card
getCardInPile _ [] = newCard (-1) False
getCardInPile v pile =  if (v == getValue value) && (isTurned value) then 
                            value
                        else 
                            getCardInPile v resultantPile
                        where
                            value = last pile
                            resultantPile = init pile


-- main function to move the cards
-- posPileFrom -> posPileTo -> cardValue -> Piles -> (opValid, (modificated pileFrom, modificated pileTo))
move :: Int -> Int -> Int -> [[Card]] -> (Bool, ([Card], [Card]))
move from to cvalue piles = if (from >= 0 && from <= 13 && to >= 0 && to <= 13 && to /= from) then

                                if (checkOrder card pileFrom) && (length pileTo == 0) then
                                    (True, moveCardPileToPile card pileFrom [] [])
                                else 
                                    if (checkOrder card pileFrom) && (isValidOrder cardTo card)then
                                        (True, moveCardPileToPile card pileFrom pileTo [])
                                    else
                                        (False, ([card], []))

                            else
                                (False, ([], []))
                            where
                                pileFrom = piles !! from
                                pileTo = piles !! to
                                card = getCardInPile cvalue pileFrom
                                cardTo = if length pileTo == 0 then invalidCard else last pileTo

------------------------------------------------------------------------------------------------------------------

-- push_back one card to each pile
pushCardInPileOfPiles :: Int -> Card -> [[Card]] -> [[Card]]
pushCardInPileOfPiles pos card piles = replaceValueAtPos pos newPile piles
                                    where
                                        p = piles !! pos
                                        newPile = push (setCardTurned card) p

-- aux
auxDeal :: Int -> [Card] -> [[Card]] -> ([Card], [[Card]])
auxDeal _ [] piles     = ([], piles)
auxDeal (-1) deck piles   = (deck, piles)
auxDeal n deck piles   = auxDeal (n-1) resultantDeck (pushCardInPileOfPiles n card piles)
                        where
                            card = last deck
                            resultantDeck = init deck

-- deal cards in piles
deal :: [Card] -> [[Card]] -> ([Card], [[Card]])
deal deck piles = auxDeal 9 deck piles


-- checks if there is at least one card in each stack
-- used in main
oneCardPerPile :: [[Card]] -> Bool
oneCardPerPile [] = True
oneCardPerPile (pile:piles) =   if (length pile) == 0 then
                                    False
                                else
                                    oneCardPerPile piles

-- WON ----------------------------------------------------------------------------------------------------------------

-- Checks if the piles contain a full suit
containsCompletedSuit :: Int -> [Card] -> Bool
containsCompletedSuit 14 _ = True
containsCompletedSuit _ [] = False
containsCompletedSuit n pile =  if (getValue value == n) && (isTurned value) && (n <= 13) then
                                    containsCompletedSuit (n+1) resultantPile
                                else 
                                    False
                                where
                                    resultantPile = init pile
                                    value = last pile



-- aux value for next function
king = newCard 13 True

-- removes an completed suit on pile
removeCompletedSuit :: [Card] -> [Card]
removeCompletedSuit [] = []
removeCompletedSuit pile =  if cardEquals card king then
                                (setLastTurned resultantPile)
                            else
                                removeCompletedSuit resultantPile
                            where
                                card = last pile
                                resultantPile = init pile

-- aux 
auxCheckCompletedPiles :: Int -> [[Card]] -> [[Card]] -> (Int, [[Card]])
auxCheckCompletedPiles n [] resultant = (n, resultant)
auxCheckCompletedPiles n (pile:piles) resultant =    
    if (containsCompletedSuit 1 pile) then
        auxCheckCompletedPiles (n+1) piles (resultant ++ [removeCompletedSuit pile])
    else
        auxCheckCompletedPiles n piles (resultant ++ [pile])


-- aux
checkCompletedPiles :: Int -> [[Card]] -> (Int, [[Card]])
checkCompletedPiles n piles = auxCheckCompletedPiles n piles []

-- SHUFFLE ----------------------------------------------------------------------------------------------------------------

-- Swap element of list in position a for b
swapElementsAt :: Int -> Int -> [a] -> [a]
swapElementsAt a b list = list1 ++ [list !! b] ++ list2 ++ [list !! a] ++ list3
    where   list1 = take a list;
            list2 = drop (succ a) (take b list);
            list3 = drop (succ b) list


shuffle :: [Card] -> [Card]
shuffle deck = auxShuffle ((length deck)-1) deck

--Note: this method uses a unsafePerformIO(IO Int -> Int). But this method not contains side effect.
auxShuffle :: Int -> [Card] -> [Card]
auxShuffle 0 deck = deck
auxShuffle n deck = auxShuffle (n-1) (swapElementsAt randomN n deck )
                    where
                        randomN = ((unsafePerformIO $ randomRIO(0,n)) `mod` n)


-- HINT ----------------------------------------------------------------------------------------------------------------


-- used in main
thereAreEmptyPiles :: [[Card]] -> Bool
thereAreEmptyPiles [] = False
thereAreEmptyPiles (pile:piles) = if length pile == 0 then True else thereAreEmptyPiles piles


-- looks for a possible letter to give hint
getPossibleCard :: [Card] -> Card
getPossibleCard [] = newCard (-1) False
getPossibleCard [c] = c
getPossibleCard pile =  if (isValidOrder nextc c) && (isTurned nextc) && (isTurned c) then
                            getPossibleCard resultantPile
                        else
                            c
                        where
                            c = last pile
                            resultantPile = init pile
                            nextc = last resultantPile

-- aux
genHintOfCard :: Int -> Int -> Card -> Card -> String
genHintOfCard nCard nLastCard card lastCard =   if isValidOrder lastCard card then
                                                    "Card: " ++ (toString card) ++ " -- Pile: " ++ (show nCard) ++ " --> " ++ (show nLastCard) ++ "\n"
                                                else
                                                    ""
-- aux
genHintPerPile :: Card -> Int -> [Card] -> Int -> [[Card]] -> String
genHintPerPile _ _ _ _ [] = ""
genHintPerPile card nCard pileCard pilesCounter (pile:piles) = 
    if isValidCard card then
        if nCard /= pilesCounter then
            (genHintOfCard nCard pilesCounter card lastCard) ++ genHintPerPile card nCard pileCard (pilesCounter+1) piles
        else
            genHintPerPile card nCard pileCard (pilesCounter+1) piles
    else
        ""
    where
        lastCard = if length pile == 0 then invalidCard else last pile

-- aux
auxHint :: Int -> [[Card]] -> [[Card]] -> String
auxHint _ [] _ = ""
auxHint nCard (pileCard:ps) piles = (genHintPerPile card nCard pileCard 0 piles) ++ (auxHint (nCard+1) ps piles)
                        where
                            card = getPossibleCard pileCard

hint :: [[Card]] -> String
hint piles = auxHint 0 piles piles

------------------------------------------------------------------------------------------------------------------
-- FOR TESTS
{-
completedPile = [newCard 13 True, newCard 12 True, newCard 11 True, newCard 10 True, newCard 9 True, newCard 8 True, newCard 7 True, newCard 6 True, newCard 5 True, newCard 4 True, newCard 3 True, newCard 2 True, newCard 1 True]

pile0 = [newCard 1 False,  newCard 3 False,  newCard 5 False,  newCard 7 False,  newCard 9 True]
pile1 = [newCard 11 False, newCard 12 False, newCard 2 False,  newCard 4 False,  newCard 6 True]
pile2 = [newCard 8 False,  newCard 10 False, newCard 13 False, newCard 1 False,  newCard 3 True, newCard 12 True, newCard 11 True]
pile3 = [newCard 5 False,  newCard 7 False,  newCard 9 False,  newCard 11 False, newCard 13 True]
pile4 = [newCard 2 False,  newCard 4 False,  newCard 6 False,  newCard 8 True]
pile5 = [newCard 10 False, newCard 12 False, newCard 1 False,  newCard 3 True]
pile6 = [newCard 5 False,  newCard 7 False,  newCard 9 False,  newCard 11 True]
pile7 = [newCard 13 False, newCard 2 False,  newCard 4 False,  newCard 6 True]
pile8 = [newCard 8 False,  newCard 10 False, newCard 12 False, newCard 1 True]
pile9 = [newCard 3 False,  newCard 5 False,  newCard 7 False,  newCard 9 True]

piles = [completedPile, pile1, pile2, completedPile, pile4, pile5, pile6, pile7, pile8, completedPile]

{-str = transpose $ toStringPiles piles
formated = formatPiles str-}
-}

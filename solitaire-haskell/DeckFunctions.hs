module DeckFunctions where

import Data.List
import Card
import StackFunctions


printPiles :: [[Card]] -> IO()
printPiles piles =
	do
		let str = formatPiles $ transpose $ toStringPiles piles
		putStrLn "|  -  | |  -  | |  -  | |  -  | |  -  | |  -  | |  -  | |  -  | |  -  | |  -  |"
		putStrLn str


formatPiles :: [[String]] -> String
formatPiles [] = ""
formatPiles (x:xs) = formatPile x ++ "\n" ++ formatPiles xs

formatPile :: [String] -> String
formatPile [] = ""
formatPile (x:xs) = x ++ " " ++ formatPile xs


--[[Card, Card],[Card, Card]] -> [["value", "value"], ["value", "value"]]
toStringPiles :: [[Card]] -> [[String]]
toStringPiles [] = []
toStringPiles (x:xs) = (map toString x):toStringPiles xs

--One suit of 13 cards
newSuit :: [Card]
newSuit = [newCard 13 True, newCard 12 True, newCard 11 True, newCard 10 True, newCard 9 True, newCard 8 True, newCard 7 True, newCard 6 True, newCard 5 True, newCard 4 True, newCard 3 True, newCard 2 True, newCard 1 True]

--french deck contains 104 cards or 8 suits of 13 cards
newDeck :: Int -> [Card]
newDeck 0 = []
newDeck n = newSuit ++ newDeck (n-1)

-- qtt, from, to -> from to
handOutCards :: Int -> [Card] -> [Card] -> ([Card], [Card])
handOutCards n from to =	if n == 1 then
                            	(resultantFrom, push (headFrom) to )
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

------------------------------------------------------------------------------------------------------------------


-- FOR TESTS

pile0 = [newCard 1 False, newCard 2 False, newCard 3 False, newCard 4 False, newCard 5 False]
pile1 = [newCard 1 False, newCard 2 False, newCard 3 False, newCard 4 False, newCard 5 True]
pile2 = [newCard 1 False, newCard 2 False, newCard 3 False, newCard 4 False, newCard 5 True]
pile3 = [newCard 1 False, newCard 2 False, newCard 3 False, newCard 4 False, newCard 5 True]
pile4 = [newCard 1 False, newCard 2 False, newCard 3 False, newCard 4 True]
pile5 = [newCard 1 False, newCard 2 False, newCard 3 False, newCard 4 True]
pile6 = [newCard 1 False, newCard 2 False, newCard 3 False, newCard 4 True]
pile7 = [newCard 1 False, newCard 2 False, newCard 3 False, newCard 4 True]
pile8 = [newCard 1 False, newCard 2 False, newCard 3 False, newCard 4 True]
pile9 = [newCard 1 False, newCard 2 False, newCard 3 False, newCard 4 True]

piles = [pile0, pile1, pile2, pile3, pile4, pile5, pile6, pile7, pile8, pile9]

str = transpose $ toStringPiles piles
formated = formatPiles str

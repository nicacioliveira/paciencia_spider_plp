:-initialization(main).

% --------------------- DECK, PILES AND CARDS

card(Value, Turned, [Value, Turned]).

createSuit(S) :-card(ace    , true, Ace),
                card( 2     , true, Two),
                card( 3     , true, Three),
                card( 4     , true, Four),
                card( 5     , true, Five),
                card( 6     , true, Six),
                card( 7     , true, Seven),
                card( 8     , true, Eight),
                card( 9     , true, Nine),
                card(10     , true, Ten),
                card(queen  , true, Jack),
                card(jack   , true, Queen),
                card(queen  , true, King),
                append([Ace], [Two], X1),
	            append(X1, [Three], X3),
	            append(X3, [Four], X4),
	            append(X4, [Five], X5),
	            append(X5, [Six], X6),
	            append(X6, [Seven], X7),
                append(X7, [Eight], X8),
                append(X8, [Nine], X9),
	            append(X9, [Ten], X10),
                append(X10, [Jack], X11),
                append(X11, [Queen], X12),
	            append(X12, [King], S).

createDeck(D) :-createSuit(S1), createSuit(S2), createSuit(S3), createSuit(S4), createSuit(S5), createSuit(S6), createSuit(S7), createSuit(S8),
                append(S1, S2, X1),
                append(X1, S3, X2),
                append(X2, S4, X3),
                append(X3, S5, X4),
                append(X4, S6, X5),
                append(X5, S7, X6),
                append(X6, S8, X7),
                random_permutation(X7, D).


insertInHead(NewHead, Tail, [NewHead|Tail]).

head([H|T], H).
tail([H|T], T).

take(0, _, []) :- !.
take(N, [H|TA], [H|TB]) :- N > 0, N2 is N - 1, take(N2, TA, TB).

drop(0,LastElements,LastElements) :- !.
drop(N,[_|Tail],LastElements) :- N > 0, N1 is N  - 1, drop(N1,Tail,LastElements).

transferElements(N, A, B, NA, NB) :- take(N, A, Elems), append(Elems, B, NB), drop(N, A, NA).

createPiles(Deck, Piles, NewDeck) :-
                                    transferElements(5, Deck, [], NDeck1, NewPile1),
                                    transferElements(5, NDeck1, [], NDeck2, NewPile2),
                                    transferElements(5, NDeck2, [], NDeck3, NewPile3),
                                    transferElements(5, NDeck3, [], NDeck4, NewPile4),
                                    transferElements(4, NDeck4, [], NDeck5, NewPile5),
                                    transferElements(4, NDeck5, [], NDeck6, NewPile6),
                                    transferElements(4, NDeck6, [], NDeck7, NewPile7),
                                    transferElements(4, NDeck7, [], NDeck8, NewPile8),
                                    transferElements(4, NDeck8, [], NDeck9, NewPile9),
                                    transferElements(4, NDeck9, [], NDeck10, NewPile10),
                                    append([NewPile1], [NewPile2], P1),
                                    append(P1, [NewPile3], P2),
                                    append(P2, [NewPile4], P3),
                                    append(P3, [NewPile5], P4),
                                    append(P4, [NewPile6], P5),
                                    append(P5, [NewPile7], P6),
                                    append(P6, [NewPile8], P7),
                                    append(P7, [NewPile9], P8),
                                    append(P8, [NewPile10],P9),
                                    Piles = P9, NewDeck = NDeck10.


%----------------------------------------------------------------------------------------------------------------------



main:-
    run([],[], false).
	%spiderLogo(), helpGame(), congrats(), bye(), halt(0).


    %nao testado
readInput(X) :-
                read_line_to_codes(user_input, X3),
                string_to_atom(X3,X2),
                atom_number(X2,X).

% os metodos start, reset, help, hint, print, deal, suits, exit e exception nao foram implementados
run(Deck, Piles, Started) :-
    write("Command?? "),
    readInput(X),
    (X =:= 1 -> start(Deck, Piles, Started); true),
    (X =:= 2 -> reset(Deck, Piles, Started); true),
    (X =:= 3 -> help(Started); true),
    (X =:= 4 -> hint(Deck, Piles, Started); true),
    (X =:= 5 -> print(Deck, Piles, NewDeck, NewPiles); true),
    (X =:= 6 -> deal(Deck, Piles, NewDeck, NewPiles); true),
    (X =:= 7 -> suits(Deck, Piles, NewDeck, NewPiles); true),
    (X =:= 8 -> exit(); true),
    (X > 8   -> run(Deck, Piles, Started); true),
    (X < 1   -> run(Deck, Piles, Started); true).



start(Deck, Piles, false) :-
    spiderLogo,
    createDeck(D),
    createPiles(D, NewPiles, NewDeck),
    %print(Piles),
    run(NewDeck, NewPiles, true).

start(Deck, Piles, true):-
    writeln("Is Started!!!"),
    run(Deck, Piles, true).

reset(Deck, Piles, true) :-
    createDeck(D),
    createPiles(D, NewPiles, NewDeck),
    run(NewDeck, NewPiles,true).

reset(Deck, Piles, false) :-
    writeln("Is not Started!!!"),
    run(Deck, Piles, false).

help(Started) :-
    helpGame,
    run(Deck, Piles, Started).

hint(Deck, Piles, true) :-
      thereAreEmptyPiles(Piles) -> writeln("There are empty piles that can be used in moves."),
      run(Deck, Piles, true).
hint(Deck, Piles, false):-
    writeln("Is not Started!!!"),
    run(Deck, Piles, false).

print(Deck, Piles, NewDeck, NewPiles) :-
    run(Deck, Piles).

deal(Deck, Piles, NewDeck, NewPiles) :-
    run(Deck, Piles).

suits(Deck, Piles, NewDeck, NewPiles) :-
    run(Deck, Piles).

exit() :-
    bye.


%--------------------------------------------------------------------------


spiderLogo :-
nl,writeln(" _______  _______  ___      ___   _______  _______  ___   ______    _______ "),
   writeln("|       ||       ||   |    |   | |       ||   _   ||   | |    _ |  |       |"),
   writeln("|  _____||   _   ||   |    |   | |_     _||  |_|  ||   | |   | ||  |    ___|"),
   writeln("| |_____ |  | |  ||   |    |   |   |   |  |       ||   | |   |_||_ |   |___ "),
   writeln("|_____  ||  |_|  ||   |___ |   |   |   |  |       ||   | |    __  ||    ___|"),
   writeln(" _____| ||       ||       ||   |   |   |  |   _   ||   | |   |  | ||   |___ "),
   writeln("|_______||_______||_______||___|   |___|  |__| |__||___| |___|  |_||_______|"),
   writeln("                                                                            "),
   writeln("                              ////      \\\\\\\\                                "),
   writeln("                              \\\\\\\\  ,,  ////                                "),
   writeln("                               \\\\\\\\ ()  ////                                 "),
   writeln("                              ....(    )....                                "),
   writeln("		             ////(  X	)\\\\\\\\                              "),
   writeln("                            //// ||||||| ////                               "),
   writeln("                            \\\\\\\\         ////                               "),
   writeln("                             \\\\\\\\       ////                                ").





helpGame :-
nl, writeln("  |---------------------------------HELP--------------------------------|"),
    writeln("  |Start:            start (1)                                             |"),
    writeln("  |Reset Game:       reset (2)                                             |"),
    writeln("  |Help:             help (3)                                              |"),
    writeln("  |Hint:             hint (4)                                              |"),
    writeln("  |print piles:      print (5)                                             |"),
    writeln("  |deal:             deal (6)                                              |"),
    writeln("  |Completed Suits:  suits (7)                                             |"),
    writeln("  |Quit Game:        quit (8)                                              |"),
    writeln("  |_____________________________________________________________________|"),
    writeln("  |Move cards:    move (press Enter)                                    |"),
    writeln("  |               <card value> <output pile number> <input pile number> |"),
    writeln("  |Cards:         Ace(1) 2 3 4 5 6 7 8 9 10 Jack(11) Queen(12) King(13) |"),
    writeln("  |---------------------------------------------------------------------|").





congrats :-
nl, writeln(" __     __          __          ___       _        "),
	writeln(" \\ \\   / /          \\ \\        / (_)     | |   "),
	writeln("  \\ \\_/ /__  _   _   \\ \\  /\\  / / _ _ __ | |  "),
	writeln("   \\   / _ \\| | | |   \\ \\/  \\/ / | | '_ \\| | "),
	writeln("    | | (_) | |_| |    \\  /\\  /  | | | | |_|     "),
	writeln("    |_|\\___/ \\__,_|     \\/  \\/   |_|_| |_(_)   "),
	writeln("   _____                            _         _       _   _                 _          "),
	writeln("  / ____|                          | |       | |     | | (_)               | |         "),
	writeln(" | |     ___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_ _  ___  _ __  ___| |         "),
	writeln(" | |    / _ \\| '_ \\ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \\| '_ \\/ __| |     "),
	writeln(" | |___| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \\__ \\_|       "),
	writeln("  \\_____\\___/|_| |_|\\__, |_|  \\__,_|\\__|\\__,_|_|\\__,_|\\__|_|\\___/|_| |_|___(_)"),
	writeln("                     __/ |                                                             "),
	writeln("                    |___/                                                              ").





bye :-
nl, writeln("                    ____             _ _                        "),
	writeln("                   |  _ \\           | | |                      "),
	writeln("                   | |_) |_   _  ___| | |      / _ \\           "),
	writeln("                   |  _ <| | | |/ _ \\ | |    \\_\\(_)/_/       "),
	writeln("                   | |_) | |_| |  __/_|_|    \\_//\"\\\\_       "),
	writeln("                   |____/ \\__, |\\___(_|_)      /   \\         "),
	writeln("                   |____/ \\__, |\\___(_|_)      /   \\                            "),
	writeln("                         |___/                                  ").

%-- HINT ----------------------------------------------------------------------------------------------------------------


% used in run
thereAreEmptyPiles([]):- false.
thereAreEmptyPiles([Pile|Piles]):- length(Pile, L), L == 0 -> true; thereAreEmptyPiles(Piles).



%-- HINT ----------------------------------------------------------------------------------------------------------------

:-initialization(main).

% --------------------- DECK, PILES AND CARDS

card(Value, Turned, [Value, Turned]).

createSuit(S) :-card( 1    , true, Ace),
                card( 2     , true, Two),
                card( 3     , true, Three),
                card( 4     , true, Four),
                card( 5     , true, Five),
                card( 6     , true, Six),
                card( 7     , true, Seven),
                card( 8     , true, Eight),
                card( 9     , true, Nine),
                card(10     , true, Ten),
                card(11  , true, Jack),
                card(12   , true, Queen),
                card(13  , true, King),
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

encontraeElem(0, [H|_], H):- !.
encontraeElem(I, [_|T], E):- X is I - 1, encontraeElem(X, T, E).

% Tamanho de uma Lista
tamL([_], 1):- !.
tamL([_|L], T):- tamL(L, X), T is X + 1.

printar_pilha(I,Pilha) :-
    tamL(Pilha, Tamanho),
    ( I >= Tamanho , write('     ');
    I < Tamanho , encontraeElem(I,Pilha,T1),
                                            (
                                            
                                            T1 =:= 1, write(' | ace  | ');
                                            T1 > 1, T1 < 10, write(' |--0') ,print(T1),write('--| ');
                                            T1 =:= 10, write(' |--') ,print(T1),write('--| ');
                                            T1 =:= 11, write(' | jack | ');
                                            T1 =:= 12, write(' | queen| ');
                                            T1 =:= 13, write(' | king | '))).
                                            
                                            

print_p2(I,Pilha) :-
	encontraeElem(I,Pilha,Pilha1),
	printar_pilha(0,Pilha1).
	

printar_p(I,Pilha, 0):- !.
printar_p(I,Pilha, X) :-
    encontraeElem(0,Pilha,Pilha1),
    encontraeElem(1,Pilha,Pilha2),
    encontraeElem(2,Pilha,Pilha3),
    encontraeElem(3,Pilha,Pilha4),
    encontraeElem(4,Pilha,Pilha5),
    encontraeElem(5,Pilha,Pilha6),
    encontraeElem(6,Pilha,Pilha7),
    encontraeElem(7,Pilha,Pilha8),
    encontraeElem(8,Pilha,Pilha9),
    encontraeElem(9,Pilha,Pilha10),
    
	tamL(Pilha1, Tamanho1),
	tamL(Pilha2, Tamanho2),
	tamL(Pilha3, Tamanho3),
	tamL(Pilha4, Tamanho4),
	tamL(Pilha5, Tamanho5),
	tamL(Pilha6, Tamanho6),
	tamL(Pilha7, Tamanho7),
	tamL(Pilha8, Tamanho8),
	tamL(Pilha9, Tamanho9),
	tamL(Pilha10, Tamanho10),
    
    ( I >= Tamanho1 , write('     ');
    I < Tamanho1 , print_p2(I,Pilha1)),
    
    ( I >= Tamanho2 , write('     ');
    I < Tamanho2 , print_p2(I,Pilha2)),
    
    ( I >= Tamanho3 , write('     ');
    I < Tamanho3 , print_p2(I,Pilha3)),
    
    ( I >= Tamanho4 , write('     ');
    I < Tamanho4 , print_p2(I,Pilha4)),
    
    ( I >= Tamanho5 , write('     ');
    I < Tamanho5 , print_p2(I,Pilha5)),
    
    ( I >= Tamanho6 , write('     ');
    I < Tamanho6 , print_p2(I,Pilha6)),
    
    ( I >= Tamanho7 , write('     ');
    I < Tamanho7 , print_p2(I,Pilha7)),
    
    ( I >= Tamanho8 , write('     ');
    I < Tamanho8 , print_p2(I,Pilha8)),
    
    ( I >= Tamanho9 , write('     ');
    I < Tamanho9 , print_p2(I,Pilha9)),
    
    ( I >= Tamanho10 , write('     ');
    I < Tamanho10 , print_p2(I,Pilha10)),
 
    write('\n'),
	H is I + 1,X1 is X - 1, printar_p(H, Pilha,X1).
	

%----------------------------------------------------------------------------------------------------------------------

main:-
    run([],[]).
	%spiderLogo(), helpGame(), congrats(), bye(), halt(0).


    %nao testado		
userInput(X) :-
                read_line_to_codes(user_input, X3),
                string_to_atom(X3,X2),
                atom_number(X2,X).
     
% os metodos start, reset, help, hint, print, deal, suits, exit e exception nao foram implementados    
run(Deck, Piles) :-
    read(X),
    X =:= 1 -> start();
    X =:= 2 -> reset();
    X =:= 3 -> help();
    X =:= 4 -> hint(Deck, Piles, NewDeck, NewPiles);
    X =:= 5 -> print(Deck, Piles, NewDeck, NewPiles);
    X =:= 6 -> deal(Deck, Piles, NewDeck, NewPiles);
    X =:= 7 -> suits(Deck, Piles, NewDeck, NewPiles);
    X =:= 8 -> exit();
    X > 8   -> run(Deck, Piles);
    X < 1   -> run(Deck, Piles).



start() :-
    spiderLogo,
    createDeck(D),
    createPiles(D, Piles, Deck),
    %print(Piles),
    run(Deck, Piles)
    write('\n \n \n \n \n'),
    printar_p(0,Piles,10).

reset() :-
    createDeck(D),
    createPiles(D, Piles, Deck),
    run(Deck, Piles).

help() :-
    help,
    run(Deck, Piles).

hint(Deck, Piles, NewDeck, NewPiles) :-
        run(Deck, Piles).

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




       

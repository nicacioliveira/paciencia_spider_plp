:-initialization(main).



main:-
	spiderLogo(), helpGame(), congrats(), bye(), halt(0).




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
	

   
		

%nao testado		
userInput :-
    read_line_to_codes(user_input, X3),
    string_to_atom(X3,X2),
    atom_number(X2,X),
    processInput(X).
 
% os metodos start, reset, help, hint, print, deal, suits, exit e exception nao foram implementados    
processInput(X) :-   
	X ==:== 1 -> start();
	X ==:== 2 -> reset();
	X ==:== 3 -> help();
	X ==:== 4 -> hint();
	X ==:== 5 -> print();
	X ==:== 6 -> deal();
	X ==:== 7 -> suits();
        X ==:== 8 -> exit();
        X > 8 -> exception().



       

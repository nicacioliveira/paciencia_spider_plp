cmake_minimum_required(VERSION 3.10)
project(SolitaireSpider)

set(CMAKE_CXX_STANDARD 11)

add_executable(SolitaireSpider main.cpp header/Card.h src/Card.cpp header/Deck.h header/SpiderSolitaire.h src/Deck.cpp)
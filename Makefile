all: testcards game
testcards: cards.o testcards.o
	g++ cards.cpp testcards.cpp -o testcards
game: main.o cards.o
	g++ main.cpp cards.cpp -o game
main.o: main.cpp
	g++ main.cpp -c 
cards.o: cards.cpp
	g++ cards.cpp -c
testcards.o: testcards.cpp
	g++ testcards.cpp -c
clean:
	rm testcards game main.o cards.o testcards.o

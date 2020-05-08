//cards.h
//Authors: Nick Ryan
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H
#include <iostream>
#include <string>

using namespace std;

class Card {
public:
	Card(char suit, char num);
	bool operator== (const Card& other) const;
	friend std::ostream& operator<< (std::ostream& os, const Card& random);
	char getSuit() const;
	void setSuit(char suit);
	char getNum() const;
	void setNum(char num);
	Card* getNext() const;
	void setNext(Card* next);
private:
	char suit;
        char num;
        Card* next;
};

class CardList {
public:
	CardList();
	~CardList();
	Card* getFirst() const;
	void append(char suit, char num);
	void remove(char suit, char num);
	Card* find(char suit, char num) const;
	friend std::ostream& operator<< (std::ostream& os, const CardList& random);
private:
	Card* first;
};

class Player {
public:
	Player(string name, CardList* hand);
	string getName() const;
	Card* takeTurn();
	bool findRemoveCard(Card* card);
	friend std::ostream& operator<< (std::ostream& os, const Player& random);
private:
	string name;
	Card* currentCard;
	CardList* hand;
};
// Use this file to define all your classes and public functions
// You should design your program with OOP prinicples using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Node inf your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.

#endif

//cards.cpp
//Author: Nick Ryan
//Implementation of the classes defined in cards.h

#include "cards.h"

using namespace std;

// Card class functions
Card::Card(char suit, char num) {
	this->suit = suit;
	this->num = num;
	this->next = NULL;
}
bool Card::operator== (const Card& other) const {
	if ((this->suit == other.suit) && (this->num == other.num)) {return true;}
	return false;
}
std::ostream& operator<< (std::ostream& os, const Card& random) {
	os << random.suit << " " << random.num << endl;
	return os;
}
char Card::getSuit() const {
	return this->suit;
}
void Card::setSuit(char suit) {
	this->suit = suit;
}
char Card::getNum() const {
	return this->num;
}
void Card::setNum(char num) {
	this->num = num;
}
Card* Card::getNext() const {
	return this->next;
}
void Card::setNext(Card* other) {
	this->next = other;
}


// CardList class fucntions
CardList::CardList() {
	first = NULL;
	
}
CardList::~CardList() {
	Card* current = this->first;
	while(current) {
		Card* n = current;
		current = current->getNext();
		delete n;
	}
}
Card* CardList::getFirst() const {
	return first;
}
std::ostream& operator<< (std::ostream& os, const CardList& random) { 
	Card* n = random.first; 
	while(n) {
		os << *n;
		n = n->getNext();
	}
	return os;
 }
void CardList::append(char suit, char num) {
	if (first == NULL) {
		first = new Card(suit, num);
	}
	else {
		Card* n = first;
		while(n->getNext()) {n = n->getNext();}
		n->setNext(new Card(suit, num));
	}
}
void CardList::remove(char suit, char num) {
	if(!this->first) { return; }
	Card target(suit, num);
	Card* prev = this->first;
	Card* current = this->first->getNext();
	if(*prev == target) { 
		//first card in cardlist
		first = current;
		delete prev;
		return;
	}
        while (current) {
                if(*current == target) {
			if(current->getNext() == NULL) {
				// last card in list
				prev->setNext(NULL);
				delete current;
				return;
			}
			else{ 
				// middle card
				prev->setNext(current->getNext());
				delete current;
				return;
			}
		}
                prev = prev->getNext();
		current = current->getNext();
        }
}
Card* CardList::find(char suit, char num) const {
	Card target(suit, num);
	Card* current = this->first;
	while (current) {
		if(*current == target) {return current;}
		current = current->getNext();
	}
	return NULL;
}

//player class functions
Player::Player(string name, CardList* hand) {
	this->name = name;
	this->hand = hand;
	if(this->hand) {
		currentCard = this->hand->getFirst();
	}
}
string Player::getName() const {
	return this->name;
}
std::ostream& operator<< (std::ostream& os, const Player& random) {
	os << random.name << "'s cards:" <<  endl;
	os << *random.hand << endl;
	return os;
}
Card* Player::takeTurn() {
	Card* n = currentCard;
	if(n) {currentCard = n->getNext();};
	return n;
}
bool Player::findRemoveCard(Card* card) {
	if (!hand) {return false;}
	Card* n = this->hand->find(card->getSuit(), card->getNum());
	if(n) {
		if(currentCard && (*n == *currentCard)) {
			currentCard = currentCard->getNext();
		}
                this->hand->remove(n->getSuit(), n->getNum());
		return true;
	}
	return false;
}

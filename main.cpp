#include <iostream>
#include <fstream>
#include <string>

#include "cards.h"

using namespace std;

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // Create two objects of the class you defined 
  // to contain two sets of cards in two input files
  CardList list1, list2;

  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
  	list1.append(line[0], line[2]);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
  	list2.append(line[0], line[2]);
  }
  cardFile2.close();

  // Start the game
  Player player1("Alice", &list1);
  Player player2("Bob", &list2);

  // Run the game
  Player* currentTurnPlayer = &player1;
  Player* otherPlayer = &player2;
  Card* currentCard = currentTurnPlayer->takeTurn();

  while(currentCard) {
	  if(otherPlayer->findRemoveCard(currentCard)) {
		cout << currentTurnPlayer->getName() << " picked matching card " << *currentCard;
		currentTurnPlayer->findRemoveCard(currentCard);
		Player* n = currentTurnPlayer;
		currentTurnPlayer = otherPlayer;
		otherPlayer = n;
	 }

	 currentCard = currentTurnPlayer->takeTurn();
  }

  cout << endl << player1;
  cout << player2;

  return 0;
}


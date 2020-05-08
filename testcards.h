// testcards.h
//Authors: Your Partner's Name and Your Name
//All test declarations go here

// This is not exhaustive list of tests. You can remove / edit tests if it doesn't suit your design but you should definitelty add more
// You should test all possible cornere cases of your public functions

#ifndef TESTCARDS_H
#define TESTCARDS_H

#include <iostream>
#include "cards.h"

using namespace std;

void runAll();

void test_card();
void test_card_suit_getset();
void test_card_num_getset();
void test_card_next_getset();
void test_card_operator_equalsequals();

void test_cardlist();
void test_cardlist_first_get();
void test_cardlist_append();
void test_cardlist_remove();
void test_cardlist_find();

void test_player();
void test_player_name_get();
void test_player_taketurn();
void test_player_findremovecard();

void START_TEST(string testname){
  cout<<"Start "<<testname<<endl;
}

void END_TEST(string testname) {
  cout<<"End "<<testname<<endl<<endl;
}

void assertEquals(string expected, string actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(char expected, char actual, string testDescription){
   if (expected == actual) {
     cout<<"PASSED " << endl;
   } else {
     cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
   }
 }

void assertEquals(int expected, int actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(const Card& expected, const Card& actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

 void assertIsNull(Card* card, string testDescription){
   if (!card) {
     cout<<"PASSED " << endl;
   } else {
     cout<< "  FAILED: "<< testDescription << endl <<"   Expected: NULL  Actual: Not NULL"  << endl;
   }
 }

  void assertIsNotNull(Card* card, string testDescription){
     if (card) {
       cout<<"PASSED " << endl;
     } else {
       cout<< "  FAILED: "<< testDescription << endl <<"   Expected: Not NULL  Actual: NULL" << endl;
     }
   }

void assertEquals(bool expected, bool actual, string testDescription){
	if(expected == actual) {
		cout << "PASSED " << endl;
	} else {
		cout<< "  FAILED: " << testDescription << endl << "   Expected: " << expected << " Actual: " << actual << endl;
	}
}


#endif

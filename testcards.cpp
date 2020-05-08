// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
  runAll();
  return 0;
}

void runAll(){
	test_card();
	test_cardlist();
	test_player();
}

void test_card(){
  START_TEST("test_card");
  test_card_suit_getset();
  test_card_num_getset();
  test_card_next_getset();
  test_card_operator_equalsequals();
  END_TEST("test_card");
}

void test_cardlist(){
  START_TEST("test_cardlist");
  test_cardlist_first_get();
  test_cardlist_append();
  test_cardlist_remove();
  test_cardlist_find();
  END_TEST("test_cardlist");
}

void test_player(){
  START_TEST("test_player");
  test_player_name_get();
  test_player_taketurn();
  test_player_findremovecard();
  END_TEST("test_player");
}

void test_card_suit_getset() {
	const string testName = "test_card_suit_getset";
	START_TEST(testName);
	Card n('h', '3');
	assertEquals('h', n.getSuit(), "get");
	n.setSuit('c');
	assertEquals('c', n.getSuit(), "set");
	END_TEST(testName);
}

void test_card_num_getset() {
       const string testName = "test_card_num_getset";
       START_TEST(testName);
       Card n('h', '3');
       assertEquals('3', n.getNum(), "get");
       n.setNum('5');
       assertEquals('5', n.getNum(), "set");
       END_TEST(testName);
 }

void test_card_next_getset() {
	const string testName = "test_card_next_getset";
	START_TEST(testName);
	Card i('c', '2');
        Card n('h', '3');
	n.setNext(&i);
        assertEquals(i, *n.getNext(), "set_get");
        END_TEST(testName);
  }

void test_card_operator_equalsequals() {
	const string testName = "test_card_operator_equalequals";
	START_TEST(testName);
	Card a('s','4');
	assertEquals(true, a == a, "equals - true");
	Card b('h','j');
	assertEquals(false, a == b, "equals - false");
	END_TEST(testName);
}

  void test_cardlist_first_get() {
          const string testName = "test_cardlist_first_get";
          START_TEST(testName);
	  CardList list;
	  assertIsNull(list.getFirst(), "empty list");
	  list.append('h', 'k');
	  list.append('s', '5');
	  assertEquals(Card('h', 'k'), *list.getFirst(), "expected");
          END_TEST(testName);
   }

  void test_cardlist_append() {
          const string testName = "test_cardlist_append";
          START_TEST(testName);
          CardList list;           
          list.append('h', 'k');    
          list.append('s', '5');
          assertIsNotNull(list.find('s', '5'), "failed to append");
          assertIsNotNull(list.find('h', 'k'), "failed to append");
	  END_TEST(testName);
   }

  void test_cardlist_remove() {
          const string testName = "test_cardlist_remove";
          START_TEST(testName);
          CardList list;
	  list.remove('c','2');
	  assertIsNull(list.find('c', '2'), "empty list");
	  list.append('h', 'k');
	  list.append('s', '5');
	  assertIsNotNull(list.find('s', '5'), "should find");
	  assertIsNotNull(list.find('h', 'k'), "should find");
	  list.remove('s', '5');
	  assertIsNull(list.find('s', '5'), "should not find");
	  list.remove('h', 'k');
	  assertIsNull(list.find('h', 'k'), "should find");
	  END_TEST(testName);
   }

void test_cardlist_find() {
          const string testName = "test_cardlist_find";
          START_TEST(testName);
	  CardList list;
	  assertIsNull(list.find('c', '2'), "empty list");
 	  list.append('h', 'k');
	  list.append('s', '5');
	  assertIsNull(list.find('c', '2'), "should not find");
	  assertIsNotNull(list.find('s', '5'), "should find");
	  assertIsNotNull(list.find('h', 'k'), "should find");
          END_TEST(testName);
   }

   void test_player_name_get() {
           const string testName = "test_player_name_get";
           START_TEST(testName);
	   Player player("Joe", NULL);
	   assertEquals("Joe", player.getName(), "expected");
           END_TEST(testName);
    }
 
 void test_player_taketurn() {
            const string testName = "test_player_taketurn";
            START_TEST(testName);
	    CardList hand;
	    Player nick("Nick", &hand);
	    assertIsNull(nick.takeTurn(), "should be empty list");
	    CardList list;
	    list.append('s', '3');
	    list.append('h', '0');
	    list.append('c', 'k');
	    Player player("Player", &list);
	    assertEquals(new Card('s', '3'), player.takeTurn(), "should return first appended");
	    assertEquals(new Card('h', '0'), player.takeTurn(), "should return second appended");
	    assertEquals(new Card('c', 'k'), player.takeTurn(), "should return third appended");
	    assertIsNull(player.takeTurn(), "should return NULL");
            END_TEST(testName);
     }

  void test_player_findremovecard() {
             const string testName = "test_player_findremovecard";
             START_TEST(testName);
	     CardList list;
	     Player player("Player", &list);
	     assertEquals(false, player.findRemoveCard(new Card('s', '2')), "should return NULL");
	     CardList hand;
	     hand.append('s', '3');
             hand.append('h', '0');
             hand.append('c', 'k');
             Player nick("Nick", &hand);
             assertEquals(true, nick.findRemoveCard(new Card('s', '3')), "should find first card");
	     assertEquals(true, nick.findRemoveCard(new Card('h', '0')), "should find second card");
	     assertEquals(true, nick.findRemoveCard(new Card('c', 'k')), "should find third(last) card");
	     assertEquals(false, nick.findRemoveCard(new Card('c', 'k')), "should find nothing");
             END_TEST(testName);
      }

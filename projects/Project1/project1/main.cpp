// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

#include <iostream>
#include "piece.h"
#include "pawn.h"
#include "person.h"
#include "data_structures.h"


using namespace std;
const int SIZE = 6;

int main()
{
  CLL cll = CLL();
  ALL all = ALL(SIZE);
  Node card = Node();
  Node c1 = Node();
  Node c2 = Node();
  Node c3 = Node();
  Node c4 = Node();
  Node c5 = Node();
  Node c6 = Node();
  Node c7 = Node();
  Node c8 = Node();
  Node c9 = Node();
  Node c10 = Node();
  Node c11 = Node();
  Node c12 = Node();
  
/*
  // empty draw should display empty list to konsole
  if (card.has_next())
    cout << "Valid" << endl;
  else
    cout << "Empty list" << endl;
  */
  cll.build_deck();
  //int check = cll.display();
  //cout << "Card count: " << check << endl;
  cll.draw_card(c1);
  cll.draw_card(c2);
  cll.draw_card(c3);
  cll.draw_card(c4);
  cll.draw_card(c5);
  cll.draw_card(c6);
  cll.draw_card(c7);
  cll.draw_card(c8);
  cll.draw_card(c9);
  cll.draw_card(c10);
  cll.draw_card(c11);
  cll.draw_card(c12);

  all.insert(c1);
  all.insert(c2);
  all.insert(c3);
  all.insert(c4);
  all.insert(c5);
  all.insert(c6);
  all.insert(c7);
  all.insert(c8);
  all.insert(c9);
  all.insert(c10);
  all.insert(c11);
  all.insert(c12);

  all.display_all();
  all.display_current_hand();
  cout << endl;
  //card.display();
  cout << endl;
  //int check = cll.display();
  //cout << "Card count: " << check << endl;
  cout << endl;

  /*
  Person p1 = Person();
  p1.display();
  Person p2 = Person(p1);
  p2.display();

  Dice d1 = Dice();
  int roll = d1.roll();
  d1.display();
  roll = d1.roll();
  d1.display();
  roll = d1.roll();
  roll = d1.roll();
  d1.display();

  Card card = Card(0, 0);
  card.display();
  Card c1 = Card();
  c1.display();

  Pawn pawn1 = Pawn();
  pawn1.display();

  Dice dice1 = Dice();
  dice1.display();

  Player play1 = Player();
  play1.display();


  Piece p1 = Piece();
  Piece p2 = Piece(false, true);
  p1.display();
  p2.display();

  if (p2.is_individual())
    cout << "individual" << endl;

  if (p2.is_community())
    cout << "community" << endl;
    */

  return 0;
}




// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

#include <iostream>
#include "piece.h"
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
  
  cll.draw_card(card);
  // empty draw should display empty list to konsole
  if (card.has_next())
    cout << "Valid" << endl;
  else
    cout << "Empty list" << endl;
  cll.build_deck();
  int check = cll.display();
  cout << "Card count: " << check << endl;
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
  card.display();
  cout << endl;
  check = cll.display();
  cout << "Card count: " << check << endl;
  cout << endl;

  cout << "PLAYER AND PERSON TEST" << endl;
  Player play1 = Player();
  play1.display();
  Player play2 = Player(play1);
  play2.display();
  cout << endl;

  cout << "ROLLING DICE TEST" << endl;
  cout << endl;
  Dice d1 = Dice();
  int roll = d1.roll();
  cout << "Rolled: " << roll << endl;
  roll = d1.roll();
  cout << "Rolled: " << roll << endl;
  roll = d1.roll();
  cout << "Rolled: " << roll << endl;
  roll = d1.roll();
  cout << "Rolled: " << roll << endl;

  Pawn pawn1 = Pawn();
  pawn1.display();


  if (pawn1.is_individual())
    cout << "individual" << endl;

  if (pawn1.is_community())
    cout << "community" << endl;
  return 0;
}




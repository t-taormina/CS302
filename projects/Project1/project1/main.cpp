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

int main()
{
  CLL cll = CLL();
  Node card = Node();
  cll.draw_card(card);
  if (card.has_next())
    cout << "Valid" << endl;
  else
    cout << "Empty list" << endl;

  cll.build_deck();
  int check = cll.display();
  cout << "Card count: " << check << endl;
  cll.draw_card(card);
  cout << endl;
  card.display();
  cout << endl;
  check = cll.display();
  cout << "Card count: " << check << endl;

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




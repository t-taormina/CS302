// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1
#include <iostream>
#include "piece.h"
#include "card.h"
using namespace std;

int main()
{

  Card c1 = Card();
  Card c2 = Card(0,0);
  c1.display();
  c2.display();


  /*
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
/*
            for (int i = 0; i < 4; i++)
              for (int j = 0; j < 13; j++)
                Card card = Card(i, j)
                deck.add(card)
*/

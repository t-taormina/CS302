// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

#include "piece.h"
#include <iostream>
using namespace std;

Piece::Piece(): individual(false), community(false){}

Piece::Piece(bool ind, bool comm): individual(ind), community(comm){}

/*
Piece::Piece(Piece& source)
{
  individual = source.individual;
  community = source.community;
}
*/

Piece::~Piece(){}

void Piece::display() const
{
  if (individual)
    cout << "Individual piece" << endl;
  else if (community)
    cout << "Community piece" << endl;
  else 
    cout << "Piece is not in use" << endl;
}

bool Piece::is_individual()
{
  return individual;
}

bool Piece::is_community()
{
  return community;
}

int Piece::copy_piece(Piece& source)
{
  individual = source.individual;
  community = source.community;
  return 0;
}

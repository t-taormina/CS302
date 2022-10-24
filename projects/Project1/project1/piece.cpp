// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1 CS302

#include "piece.h"
#include <iostream>
using namespace std;

// Default Constructor.
Piece::Piece(): individual(false), community(false){}

// Parameterized Constructor.
Piece::Piece(bool ind, bool comm): individual(ind), community(comm){}

// Deconstructor.
Piece::~Piece(){}

// @Dev - Displays member data.
// Args -> None.
// Returns -> None.
void Piece::display() const
{
  if (individual)
    cout << "Individual piece" << endl;
  else if (community)
    cout << "Community piece" << endl;
  else 
    cout << "Piece is not in use" << endl;
}

// @Dev - Confirms if a piece is an individual piece.
// Args -> None.
// Returns -> Boolean.
bool Piece::is_individual()
{
  return individual;
}

// @Dev - Confirms if a piece is a community piece.
// Args -> None.
// Returns -> Boolean.
bool Piece::is_community()
{
  return community;
}

// @Dev - Takes a piece object and replicates its data members.
// Args -> Piece object by reference.
// Returns -> Integer success.
int Piece::copy_piece(Piece& source)
{
  individual = source.individual;
  community = source.community;
  return 0;
}


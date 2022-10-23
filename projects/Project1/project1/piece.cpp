// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

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

// @Dev - .
// Args -> .
// Returns -> .
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

// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

#include "pawn.h"
#include <iostream>
using namespace std;


// Default Constructor.
Pawn::Pawn(): Piece(), position(0){}

// Parameterized Constructor.
Pawn::Pawn(int arg_position): position(arg_position){}

// Deconstructor.
Pawn::~Pawn(){}

// @Dev - Displays member data for "position".
// Args -> None.
// Returns -> None.
void Pawn::display_position()
{
  cout << "Position: " << position << endl;
  Piece::display();
}

// @Dev - Sets member value "position" to provided argument.
// Args -> Integer.
// Returns -> Integer success.
void Pawn::change_position(int arg)
{
  if (arg < 7 && arg > 0)
  {
    position = arg;
    return 1;
  }
  cout << "Position cannot be changed to an out of bounds value. No change has been made." << endl;
  return 0;
}

// @Dev - Confirms if pawn has a certain "position" value.
// Args -> Integer.
// Returns -> Boolean confirmation.
bool Pawn::is_position(int arg)
{
  return (position == arg);
}


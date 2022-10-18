// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

#include "pawn.h"
#include <iostream>
using namespace std;


Pawn::Pawn(): Piece(), position(0){}

Pawn::Pawn(int arg_position): position(arg_position){}

Pawn::~Pawn(){}

void Pawn::display_position()
{
  cout << "Position: " << position << endl;
  Piece::display();
}

void Pawn::change_position(int arg)
{
  if (arg > 6 || arg < 1)
  {
    cout << "Position cannot be changed to an out of bounds value. No change has been made." << endl;
    return;
  }
  position = arg;
}

bool Pawn::is_position(int arg)
{
  return (position == arg);
}


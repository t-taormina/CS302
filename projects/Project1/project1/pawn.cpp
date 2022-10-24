// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1 CS302

#include "piece.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

//CONTAINS PAWN AND DICE IMPLEMENTATION.
//DICE class starts line 66


//Pawn Class 
//=============================================================

// Default Constructor.
Pawn::Pawn(): Piece(), position(INVALID){}

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
}

// @Dev - Displays all member data.
// Args -> None.
// Returns -> None.
void Pawn::display()
{
  cout << "Position: " << position << endl;
  Piece::display();
}

// @Dev - Sets member value "position" to provided argument.
// Args -> Integer.
// Returns -> Integer success.
int Pawn::change_position(int arg)
{
  if (arg < 7 && arg > 0)
  {
    position = arg - 1;
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

// Dice Class
//=============================================================

// Default Constructor.
Dice::Dice():  Piece(false, true), value(0) 
{
  srand(time(NULL)); // seeds random num gen with current time
}

// Deconstructor
Dice::~Dice(){}

// @Dev - Displays member data.
// Args -> None.
// Returns -> None.
void Dice::display() const
{
  cout << "Value: " << value << endl;
}

// @Dev - Generates random number from 1-6.
// Args -> None.
// Returns -> Random integer from 1-6 and sets member value to the generated integer.
int Dice::roll()
{
  int result = rand() % 6;
  result += 1;
  value = result;
  return result;
}


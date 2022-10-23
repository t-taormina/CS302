// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

#include "pawn.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

// Default Constructor.
Dice::Dice():  Piece(false, true), value(0) 
{
  srand(time(NULL));
  // seeds random num gen with current time
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




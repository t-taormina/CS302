// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

#include "pawn.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

Dice::Dice():  Piece(false, true), value(0) 
{
  srand(time(NULL));
  // seeds random num gen with current time
}

Dice::~Dice(){}

void Dice::display() const
{
  cout << "Value: " << value << endl;
}

int Dice::roll()
{
  int result = rand() % 6;
  result += 1;
  value = result;
  return result;
}




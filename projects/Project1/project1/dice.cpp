// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1
#include "pawn.h"
#include <iostream>
using namespace std;

Dice::Dice(): value(0) {}

Dice::~Dice(){}

void Dice::display() const
{
  cout << "Value: " << value << endl;
}

int Dice::roll()
{
  // return random number from 1-6
  // need some guidance on how to implement
  return 1;
}




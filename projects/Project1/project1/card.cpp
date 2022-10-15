// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1
#include "card.h"
#include <iostream>
using namespace std;


Card::Card(): value(card_value::two), suit(card_suit::hearts), position(0) {}

Card::Card(card_value arg_val, card_suit arg_suit): value(arg_val), suit(arg_suit), position(0){}

Card::~Card(){}

bool Card::is_position(int arg)
{
  if (arg == position)
    return true;
  return false;
}

int Card::point_conversion()
{
  if (value == card_value::ace)
    return 3;
  else if (value == card_value::king || value == card_value::queen || value == card_value::jack)
    return 2;
  else
    return 1;
}

void Card::display() const
{
  switch(value)
  {
    case card_value::two:
      cout << "2 ";
      break;
    
    case card_value::three:
      cout << "3 ";
      break;

    case card_value::four:
      cout << "4 ";
      break;
    
    case card_value::five:
      cout << "5 ";
      break;

    case card_value::six:
      cout << "6 ";
      break;
    
    case card_value::seven:
      cout << "7 ";
      break;

    case card_value::eight:
      cout << "8 ";
      break;
    
    case card_value::nine:
      cout << "9 ";
      break;

    case card_value::ten:
      cout << "10 ";
      break;
    
    case card_value::jack:
      cout << "Jack ";
      break;

    case card_value::queen:
      cout << "Queen ";
      break;
    
    case card_value::king:
      cout << "King ";
      break;

    case card_value::ace:
      cout << "Ace ";
      break;
  }

  cout << "of ";

  switch(suit)
  {
    case card_suit::hearts:
      cout << "hearts" << endl;
      break;
    
    case card_suit::diamonds:
      cout << "diamonds" << endl;
      break;

    case card_suit::clubs:
      cout << "clubs" << endl;
      break;

    case card_suit::spades:
      cout << "spades" << endl;
      break;
  }
}


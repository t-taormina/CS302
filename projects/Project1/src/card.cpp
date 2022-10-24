// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1 CS302

#include "piece.h"
#include <iostream>
using namespace std;


// Default constructor
Card::Card(): Piece(), value(card_value::invalid_value), suit(card_suit::invalid_suit), position(0) {}

// Paramterized constructor
Card::Card(int arg_value, int arg_suit): Piece(false, true)
{
  value = (card_value) arg_value;
  suit = (card_suit) arg_suit;
  position = INVALID;
}
  
// Deconstructor
Card::~Card(){}

// @Dev - Sets member data value for "position" to argument provided integer.
// Args -> Integer representing position to set.
// Returns -> Integer for success or failure.
int Card::set_position(int arg)
{
  if (arg < 6 || arg >= 0)
    position = arg;
  else 
    position = INVALID;
  return position;
}

// @Dev - Checks to determine if the argument matches the position member value.
// Args -> Integer representing position to check.
// Returns -> Boolean for success or failure.
bool Card::is_position(int arg)
{
  if (arg == position)
    return true;
  return false;
}

// @Dev - Takes a card object and replicates its data members.
// Args -> Card object by reference.
// Returns -> Integer for success.
int Card::copy_card(Card& source)
{
  value = source.value;
  suit = source.suit;
  position = source.position;
  return 1;
}

// @Dev - Uses the card value to determine points awarded to a player.
// Args -> None.
// Returns -> 3 points if card value is an Ace.
//            2 points if card value is a face card.
//            1 points if card value is a number card.
//            0 points if card value is invalid.
int Card::point_conversion()
{
  if (value == card_value::invalid_value)
    return 0;
  else if (value == card_value::ace)
    return 3;
  else if (value == card_value::king || value == card_value::queen || value == card_value::jack)
    return 2;
  else
    return 1;
}

// @Dev - Determines if a card has a valid suit and value assigned.
// Args -> None.
// Returns -> Boolean.
bool Card::is_valid()
{
  bool success = true;
  if (value == card_value::invalid_value || suit == card_suit::invalid_suit)
    success = false;
  return success;
}

// @Dev - Displays data members for object.
// Args -> None.
// Returns -> None.
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

    case card_value::invalid_value:
      cout << "invalid card value ";
      break;
  }

  cout << "of ";

  switch(suit)
  {
    case card_suit::hearts:
      cout << "hearts ";
      break;
    
    case card_suit::diamonds:
      cout << "diamonds ";
      break;

    case card_suit::clubs:
      cout << "clubs ";
      break;

    case card_suit::spades:
      cout << "spades ";
      break;

    case card_suit::invalid_suit:
      cout << "invalid card suit ";
      break;
  }
  cout << "at position: " << position << endl;
}


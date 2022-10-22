// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

#include "pawn.h"
#include <iostream>
using namespace std;


// Default constructor
Card::Card(): Piece(), value(card_value::two), suit(card_suit::hearts), position(0) {}

// Paramterized constructor
Card::Card(int arg_value, int arg_suit): Piece(false, true)
{
  value = (card_value) arg_value;
  suit = (card_suit) arg_suit;
}
  
// Deconstructor
Card::~Card(){}

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
int Card::point_conversion()
{
  if (value == card_value::ace)
    return 3;
  else if (value == card_value::king || value == card_value::queen || value == card_value::jack)
    return 2;
  else
    return 1;
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


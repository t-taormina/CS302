// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

#include "person.h"
#include <iostream>
using namespace std;


// Default constructor
Player::Player(): Person(), points(0){}

// Deconstructor
Player::~Player(): ~Person()
{
  if (username)
  {
    delete [] username;
    username = nullptr;
  }
}

// Copy Constructor.
Player::Player(const Player& to_copy): Person(to_copy), points(to_copy.points)
{
  username = new char[strlen(to_copy.username) + 1];
  strcpy(username, to_copy.username);
}

// @Dev - Displays member data.
// Args -> None.
// Returns -> None.
void Player::display() const
{
  cout << "Points: " << points << endl;
  Person::display();
}

// @Dev - Adds points to member data field "points".
// Args -> Integer.
// Returns -> 0 if argument is negative (End game in this situation, its been hacked)
//            value stored in argument otherwise.
void Player::add_points(int add_points)
{
  if (add_points < 0)
    return 0;
  points += add_points;
  return add_points;
}

// @Dev - Displays data currently stored in member value.
// Args -> None.
// Returns -> None.
void Player::display_points()
{
  cout << "Points: " << points << endl;
}

// @Dev - Determines which player has a higher score.
// Args -> Player object by reference.
// Returns -> Bool.
bool Player::is_winner(const Player& opponent)
{
  if (points > opponent_points)
    return true;
  else 
    return false;
}

// @Dev - Resets data in member for "points" to zero.
// Args -> None.
// Returns -> Integer for success.
int Player::reset_points()
{
  points = 0;
  if (points == 0)
    return 1;
  else 
    return 0;
}


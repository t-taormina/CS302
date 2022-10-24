// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1 CS302

#include "person.h"
#include <iostream>
#include <cstring>
using namespace std;
const int SIZE = 100;

// CONTAINS BOTH PERSON AND PLAYER CLASS
// PLAYER class starts at line 111

// Person Class
//=============================================================

// Default Constructor.
Person::Person(): first_name(nullptr), last_name(nullptr), wins(0), losses(0)
{
  first_name = new char[SIZE];
  last_name = new char[SIZE];
  cout << "Please provide your first name: ";
  std::cin.get(first_name, SIZE, '\n');
  std::cin.ignore(SIZE, '\n');
  cout << "Please provide your last name: ";
  std::cin.get(last_name, SIZE, '\n');
  std::cin.ignore(SIZE, '\n');
}

// Copy Constructor.
Person::Person(const Person& to_copy) 
{
  first_name = new char[strlen(to_copy.first_name) + 1];
  strcpy(first_name, to_copy.first_name);

  last_name = new char[strlen(to_copy.last_name) + 1];
  strcpy(last_name, to_copy.last_name);
  
  wins = to_copy.wins;
  losses = to_copy.losses;
}

// Deconstructor.
Person::~Person()
{
  if (first_name)
  {
    delete[] first_name;
    first_name = nullptr;
  }
  if (last_name)
  {
    delete[] last_name;
    last_name = nullptr;
  }
}

// Assignment Operator.
Person& Person::operator=(const Person& arg)
{
  if (this == arg)
    return *this;
  if (first_name)
    delete [] first_name;
  if (last_name)
    delete [] last_name;
  first_name = new char [strlen(arg.first_name) + 1];
  last_name = new char [strlen(arg.last_name) + 1];
  strcpy(first_name, arg.first_name);
  strcpy(last_name, arg.last_name);
  wins = arg.wins;
  losses = arg.losses;
  return *this;
}

// @Dev - Displays member data for object.
// Args -> None.
// Returns -> None.
void Person::display() const
{
  if (first_name)
    cout << "First name: " << first_name << endl;
  if (last_name)
    cout << "Last name: " << last_name << endl;
  cout << "Wins: " << wins << endl;
  cout << "Losses: " << losses << endl;
}

// @Dev - Edit member data.
// Args -> Character array.
// Returns -> Integer success.
int Person::edit_first_name(char* edit)
{
  if (!edit)
    return 0;

  if (first_name)
  {
    delete [] first_name;
    first_name = nullptr;
  }

  first_name = new char[strlen(edit)+1];
  strcpy(first_name,edit);
  return 1;
}

// @Dev - Edit member data.
// Args -> Character array.
// Returns -> Integer success.
int Person::edit_last_name(char* edit)
{
  if (!edit)
    return 0;

  if (last_name)
  {
    delete [] last_name;
    last_name = nullptr;
  }

  last_name = new char[strlen(edit)+1];
  strcpy(last_name,edit);
  return 1;
}


// Player Class
//=============================================================

// Default constructor
Player::Player(): Person(), points(0), username(nullptr)
{ 
  username = new char[SIZE];
  cout << "Please provide your desired username: ";
  std::cin.get(username, SIZE, '\n');
  std::cin.ignore(SIZE, '\n');
}

// Deconstructor
Player::~Player() 
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

// Assignment Operator.
Player& Player::operator=(const Player& arg)
{
  if (this == arg)
    return *this;
  if (username)
    delete [] username;
  username = new char [strlen(arg.username) + 1];
  strcpy(username, arg.username);
  points = arg.points;
  return *this;
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
int Player::add_points(int add_points)
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
  cout << points << endl;
}

// @Dev - Determines which player has a higher score.
// Args -> Player object by reference.
// Returns -> Bool.
bool Player::is_winner(const Player& opponent)
{
  if (points > opponent.points)
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

// @Dev - Increments "wins" data member by one.
// Args -> None.
// Returns -> Integer for success.
int Player::add_win()
{
  wins += 1;
  return 0;
}

// @Dev - Increments "losses" data member by one.
// Args -> None.
// Returns -> Integer for success.
int Player::add_loss()
{
  losses += 1;
  return 0;
}

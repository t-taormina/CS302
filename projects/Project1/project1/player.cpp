// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

#include "person.h"
#include <iostream>
using namespace std;


// Default constructor
Player::Player(): Person(), points(0){}

// Parameterized constructor
Player::Player(char* usrname, char* f_name, char* l_name): Person(f_name, l_name), username(usrname), points(0){}

Player::~Player(): ~Person()
{
  if (username)
  {
    delete [] username;
    username = nullptr;
  }
}

Player::Player(const Player& to_copy)
{
  // implement later, have questions
}

void Player::display() const
{
  cout << "Points: " << points << endl;
  Person::display();
}

void Player::add_points(int add_points)
{
  if (add_points < 0)
    return;
  points += add_points;
}

void Player::display_points()
{
  cout << "Points: " << points << endl;
}

bool Player::is_winner(int& opponent_points)
{
  if (points > opponent_points)
    return true;
  else 
    return false;
}

int Player::reset_points()
{
  points = 0;
  if (points == 0)
    return 1;
  else 
    return 0;
}


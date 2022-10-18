// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1
#include "person.h"
#include <iostream>
using namespace std;


Player::Player(): Person(), points(0){}

Player::~Player(){}

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

void Player::reset_points()
{
  points = 0;
}


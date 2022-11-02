// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

// Contains Activity, Skiing, ... classes.
// Skiing-> line number 118

#include "activity.h"



// ACTIVITY CLASS
// =================================================================
Activity::Activity(): season(nullptr), level(0)
{
  season = new char[SIZE];
  cout << "Please enter the best season(s) for this activity: ";
  std::cin.get(season, SIZE, '\n');
  std::cin.ignore(SIZE, '\n');
}

Activity::Activity(int arg_level)
{
  season = new char[SIZE];
  cout << "Please enter the best season(s) for this activity: ";
  std::cin.get(season, SIZE, '\n');
  std::cin.ignore(SIZE, '\n');
  level = arg_level;
}

Activity::Activity(const Activity& arg)
{
  season = new char [strlen(arg.season) + 1];
  strcpy(season, arg.season);
  level = arg.level;
}

Activity::~Activity()
{
  if (season)
  {
    delete [] season;
    season = nullptr;
  }
}

Activity& Activity::operator=(const Activity& arg)
{
  if (*this == arg)
    return *this; 
  if (season)
    delete [] season;
  season = new char [strlen(arg.season) + 1];
  strcpy(season, arg.season);
  level = arg.level;
  return *this;
}

Activity Activity::operator++()
{
  if (level < 3)
    level = level + 1;
  return *this;
}

bool Activity::operator == (const Activity& arg) const
{
  bool success = true;
  if (strcmp(arg.season, season) != 0 || arg.level != level)
    success = false;
  return success;
}

ostream & operator << (ostream & out, const Activity& arg)
{
  out << "Season: " << arg.season << "\t" << "Level: " << arg.level;
  return out;
}

istream & operator >> (istream & in, Activity& arg)
{
  if (arg.season)
    delete [] arg.season;
  arg.season = new char[SIZE];
  cout << "Enter the season: ";
  in.get(arg.season, SIZE, '\n');
  in.ignore(SIZE, '\n');
  cout << "Enter the level of difficulty of the sport: ";
  in >> arg.level;
  return in;
}
int Activity::edit_season(char* new_season)
{
  if (season)
    delete [] season;
  season = new char [strlen(new_season) + 1];
  strcpy(season, new_season);
  return 0;
}

int Activity::display()
{
  cout << *this << endl;
  return 0;
}


// SKI CLASS
// =================================================================
Skiing::Skiing(): Activity(1), location(nullptr), day_cost(0), rental_cost(0) {}

Skiing::Skiing(char* arg_location, float arg_dcost, float arg_lcost, int arg_level): Activity(arg_level)
{
  if (arg_location)
  {
    location = new char[strlen(arg_location) + 1];
    strcpy(location, arg_location);
  }
  else 
    location = nullptr;
  day_cost = arg_dcost;
  rental_cost = arg_lcost;
}

Skiing::Skiing(const Skiing& to_copy): Activity(to_copy) 
{
  location = new char[strlen(to_copy.location) + 1];
  strcpy(location, to_copy.location);
  day_cost = to_copy.day_cost;
  rental_cost = to_copy.rental_cost;
  for (auto iter = to_copy.reviews.begin(); iter < to_copy.reviews.end(); iter++)
    reviews.push_front(iter);
}

Skiing::~Skiing() 
{
  if (location)
  {
    delete [] location;
    location = nullptr;
  }
}

Skiing& Skiing::operator=(const Skiing& arg)
{
  if (*this == arg)
    return *this;
  if (location)
    delete [] location;
  location = new char[strlen(arg.location) + 1];
  strcpy(location, arg.location);
  day_cost = arg.day_cost;
  rental_cost = arg.rental_cost;
  rating = arg.rating;
  for (auto iter = arg.reviews.begin(); iter < arg.reviews.end(); iter++)
    reviews.push_front(iter);
  return *this;
}

Skiing Skiing::operator + (const Skiing& op2) const
{
}

bool Skiing::operator == (const Skiing& arg) const
{
  bool success = true;
  success = Activity::operator==(arg);
  if (strcmp(location, arg.location) != 0)
    success = false;
  return success;
}

/*
  char* location;
    float day_cost;
    float rental_cost;
    string review; 
*/


//bool operator != (const Skiing& arg) const;
ostream & operator << (ostream & out, const Skiing& arg)
{
  out << "Location: " << arg.location << endl;
  out << "Day cost: " << arg.day_cost << endl;
  out << "Rental cost: " << arg.rental_cost << endl;
  return out;
}

istream & operator >> (istream & in, const Skiing& arg)
{
}

int operator<(const Skiing& l_ski, const Skiing& r_ski)
{
}

int operator<=(const Skiing&, const Skiing&)
{
}

int operator>(const Skiing&, const Skiing&)
{
}

int operator>=(const Skiing&, const Skiing&)
{
}

int Skiing::display()
{
  Activity::display();
  cout << *this << endl;
}

int Skiing::display_reviews()
{
  int count = 1;
  cout << "Reviews: " << endl;
  for (auto iter = reviews.begin(); iter < reviews.end(); iter++)
  {
    cout << count << ": " << iter << endl;
    count++;
  }
  return count - 1;
}

int Skiing::add_reviews()
{

}

int Skiing::calculate_max_cost()
{
}

int Skiing::calculate_min_cost()
{
}
// =================================================================


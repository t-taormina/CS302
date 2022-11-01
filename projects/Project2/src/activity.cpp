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

Activity::Activity(char* arg_season, int arg_level)
{
  if (arg_season)
  {
    season = new char[strlen(arg_season) + 1];
    strcpy(season, arg_season);
  }
  else
    season = nullptr;
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

/*
  char* location;
    float day_cost;
    float rental_cost;
    string review; 
*/

// SKI CLASS
// =================================================================
Skiing::Skiing(): Activity(), location(nullptr), day_cost(0), rental_cost(0), review("") {}

Skiing::Skiing(char* arg_location, float arg_dcost, float arg_lcost)
{
}

Skiing::Skiing(const Skiing&)
{
}

Skiing~Skiing()
{
}

Skiing& operator=(const Skiing& arg);
Skiing operator + (const Skiing& op2) const;
bool operator == (const Skiing& arg) const;
bool operator != (const Skiing& arg) const;
friend ostream & operator << (ostream & out, const Skiing& arg);
friend istream & operator >> (istream & in, const Skiing& arg);
friend int operator<(const Skiing&, const Skiing&); 
friend int operator<=(const Skiing&, const Skiing&); 
friend int operator>(const Skiing&, const Skiing&); 
friend int operator>=(const Skiing&, const Skiing&);

int display();
int calculate_max_cost();
int calculate_min_cost();
// =================================================================


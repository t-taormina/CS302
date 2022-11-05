// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

// Contains Activity, Skiing, ... classes.
// Skiing-> line number 135

#include "activity.h"


// ACTIVITY CLASS
// =================================================================
Activity::Activity(): season(nullptr), location(""), level(0) {}

Activity::Activity(string arg_loc): level(0)
{
  char temp[7] = "Winter";
  season = new char[strlen(temp) + 1];
  strcpy(season, temp);
  location = arg_loc;
}

Activity::Activity(const Activity& arg)
{
  season = new char [strlen(arg.season) + 1];
  strcpy(season, arg.season);
  location = arg.location;
  level = arg.level;
  for (auto iter = arg.ratings.begin(); iter < arg.ratings.end(); iter++)
    ratings.push_back(*iter);
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
  location = arg.location;
  level = arg.level;
  for (auto iter = arg.ratings.begin(); iter < arg.ratings.end(); iter++)
    ratings.push_back(*iter);
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
  if (strcmp(arg.season, season) != 0 || arg.location != location)
    success = false;
  return success;
}

ostream & operator << (ostream & out, Activity& arg)
{
  int rating = arg.avg_rating();
  out << "Season: " << arg.season << "\n" << "Location: " << arg.location << "\n" << "Level: " << arg.level <<  "\n" << "Average rating: " << rating;
  return out;
}

istream & operator >> (istream & in, Activity& arg)
{
  arg.add_rating();
  return in;
}

int Activity::display()
{
  cout << *this << endl;
  return 0;
}

int Activity::avg_rating()
{
  int count = 0;
  int sum = 0;
  for (auto iter = ratings.begin(); iter < ratings.end(); iter++)
  {
    sum += *iter;
    count++;
  }
  if (count == 0) 
    return 0;
  return sum / count;
}

int Activity::add_rating(int arg)
{
  if (arg < 1 || arg > 5)
  {
    cout << "Invalid rating. Please try again." << endl;
    return 0;
  }
  ratings.push_back(arg);
}

int Activity::rate()
{
  int flag = 0;
  int rating;
  while (flag == 0)
  {
    cout << "Please enter a rating from 1-5: ";
    cin >> rating;
    if (rating < 1 || rating > 5)
      cout << "Invalid rating." << endl; 
    else 
      flag = 1;
  }
  ratings.push_back(rating);
}
// =================================================================


// SKI CLASS
// =================================================================
Skiing::Skiing(): Activity("",1), review(nullptr), lift_cost(0), rental_cost(0), easy_runs(0), hard_runs(0) {}

Skiing::Skiing(char* arg_review, float l_cost, float r_cost, int e_runs, int h_runs, string arg_loc): location(arg_loc)
{
  if (arg_review)
  {
    review = new char[strlen(arg_review) + 1];
    strcpy(review, arg_review);
  }
  else 
    review = nullptr;
  lift_cost = l_cost;
  rental_cost = r_cost;
  easy_runs = e_runs;
  hard_runs = h_runs;
}

Skiing::Skiing(const Skiing& to_copy): Activity(to_copy) 
{
  review = new char[strlen(to_copy.review) + 1];
  strcpy(review, to_copy.review);
  lift_cost = to_copy.lift_cost;
  rental_cost = to_copy.rental_cost;
  easy_runs = to_copy.easy_runs;
  hard_runs = to_copy.hard_runs;
}

Skiing::~Skiing() 
{
  if (review)
  {
    delete [] review;
    review = nullptr;
  }
}

Skiing& Skiing::operator=(const Skiing& arg)
{
  if (*this == arg)
    return *this;
  Activity::operator=(arg);
  if (review)
    delete [] review;
  review = new char[strlen(arg.review) + 1];
  strcpy(review, arg.review);
  lift_cost = arg.lift_cost;
  rental_cost = arg.rental_cost;
  easy_runs = arg.easy_runs;
  hard_runs = arg.hard_runs;
  return *this;
}

Skiing Skiing::operator + (const int& op2) const
{
  lift_cost += op2;
  return *this;
}

bool Skiing::operator == (const Skiing& arg) const
{
  bool success = Activity::operator==(arg);
  return success;
}

//bool operator != (const Skiing& arg) const;
ostream & operator << (ostream & out, const Skiing& arg)
{
  out << "Review: " << arg.review << endl;
  out << "Lift cost: " << arg.lift_cost << endl;
  out << "Rental cost: " << arg.rental_cost << endl;
  out << "Easy runs: " << arg.easy_runs << endl;
  out << "Hard runs: " << arg.hard_runs << endl;
  return out;
}

istream & operator >> (istream & in, const Skiing& arg)
{
  return in;
}

int operator<(Skiing& l_ski, Skiing& r_ski)
{
  int flag = 0;
  if (l_ski.calculate_max_cost() < r_ski.calculate_max_cost())
    flag = 1;
  return flag;
}

int operator<=(Skiing& l_ski, Skiing& r_ski)
{
  int flag = 0;
  if (l_ski.calculate_max_cost() <= r_ski.calculate_max_cost())
    flag = 1;
  return flag;

}

int operator>(Skiing& l_ski, Skiing& r_ski)
{
  int flag = 0;
  if (l_ski.calculate_max_cost() > r_ski.calculate_max_cost())
    flag = 1;
  return flag;

}

int operator>=(Skiing& l_ski, Skiing& r_ski)
{
  int flag = 0;
  if (l_ski.calculate_max_cost() >= r_ski.calculate_max_cost())
    flag = 1;
  return flag;

}

int Skiing::display()
{
  Activity::display();
  cout << *this << endl;
  return 0;
}
int Skiing::calculate_max_cost()
{
  return lift_cost + rental_cost;
}

int Skiing::calculate_min_cost()
{
  return lift_cost;
}
// =================================================================


// Snow Shoe Class
// =================================================================
Snowshoe::Snowshoe(){}
Snowshoe::Snowshoe(float, int, string){}
Snowshoe::Snowshoe(char* arg_location, float arg_dcost, float arg_lcost){}
Snowshoe::Snowshoe(const Snowshoe&){}
Snowshoe::~Snowshoe(){}

Snowshoe& Snowshoe::operator=(const Snowshoe& arg){}
Snowshoe Snowshoe::operator + (const Snowshoe& op2) const{}
bool Snowshoe::operator == (const Snowshoe& arg) const{}
bool Snowshoe::operator != (const Snowshoe& arg) const{}
ostream & operator << (ostream & out, const Snowshoe& arg){}
istream & operator >> (istream & in, const Snowshoe& arg){}
int operator<(const Snowshoe&, const Snowshoe&){}
int operator<=(const Snowshoe&, const Snowshoe&){} 
int operator>(const Snowshoe&, const Snowshoe&){} 
int operator>=(const Snowshoe&, const Snowshoe&){}

int display(){}

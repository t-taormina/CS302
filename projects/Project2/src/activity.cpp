// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

// Contains Activity, Skiing, Snowshoe, and Skating classes.
// Skiing: line number 135
// Snowshoe: line number 281
// Skating: line number 404

#include "activity.h"


// ACTIVITY CLASS
// =================================================================
Activity::Activity(): season(nullptr), location(""), level(DEFAULT) {}

Activity::Activity(string arg_loc): level(DEFAULT)
{
  char temp[7] = "Winter";
  season = new char[strlen(temp) + 1];
  strcpy(season, temp);
  location = arg_loc;
}

Activity::Activity(string arg_loc, int arg_level)
{
  char temp[7] = "Winter";
  season = new char[strlen(temp) + 1];
  strcpy(season, temp);
  location = arg_loc;
  level = arg_level;
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

bool Activity::operator != (const Activity& arg) const
{
  bool success = false;
  if (strcmp(arg.season, season) != 0 || arg.location != location)
    success = true;
  return success;
}

ostream & operator << (ostream & out, const Activity& arg) 
{
  int rating = arg.avg_rating();
  out << "Season: " << arg.season << "\n" << "Location: " << arg.location << "\n" << "Level: " << arg.level <<  "\n" << "Average rating: " << rating;
  return out;
}

int Activity::display() const
{
  cout << *this << endl;
  return 0;
}

int Activity::avg_rating() const
{
  if (ratings.empty())
    return 0;
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
  return 0;
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
  return rating;
}
// =================================================================


// SKI CLASS
// =================================================================
Skiing::Skiing(): Activity("",INTERMEDIATE), review(nullptr), lift_cost(0), rental_cost(0), easy_runs(0), hard_runs(0) {}

Skiing::Skiing(float l_cost, float r_cost, int e_runs, int h_runs, string arg_loc): Activity(arg_loc, INTERMEDIATE), review(nullptr)
{
  lift_cost = l_cost;
  rental_cost = r_cost;
  easy_runs = e_runs;
  hard_runs = h_runs;
}

Skiing::Skiing(const Skiing& obj): Activity(obj) 
{
  if (obj.review)
  {
    review = new char[strlen(obj.review) + 1];
    strcpy(review, obj.review);
  }
  else 
    review = nullptr;
  lift_cost = obj.lift_cost;
  rental_cost = obj.rental_cost;
  easy_runs = obj.easy_runs;
  hard_runs = obj.hard_runs;
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
  if (arg.review)
  {
    if (review)
      delete [] review;
    review = new char[strlen(arg.review) + 1];
    strcpy(review, arg.review);
  }
  else review = nullptr;
  lift_cost = arg.lift_cost;
  rental_cost = arg.rental_cost;
  easy_runs = arg.easy_runs;
  hard_runs = arg.hard_runs;
  return *this;
}

Skiing Skiing::operator + (const int& op2)
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
  out << "Lift cost: " << arg.lift_cost << endl;
  out << "Rental cost: " << arg.rental_cost << endl;
  out << "Easy runs: " << arg.easy_runs << endl;
  out << "Hard runs: " << arg.hard_runs;
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

void Skiing::add_rating(int arg)
{
  Activity::add_rating(arg);
}

void Skiing::rate()
{
  Activity::rate();
}

int Skiing::display() const
{
  Activity::display();
  cout << *this << endl;
  if (review)
    cout << "Review: " << review << endl;
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
Snowshoe::Snowshoe(): Activity("", BEGINNER), distance(0), difficulty(0), trail_name("") {}

Snowshoe::Snowshoe(float dist, int diff, string name, string loc): Activity(loc, BEGINNER)  
{
  distance = dist;
  difficulty = diff;
  trail_name = name;
}

Snowshoe::Snowshoe(const Snowshoe& obj): Activity(obj)
{
  distance = obj.distance;
  difficulty = obj.difficulty;
  trail_name = obj.trail_name;
}

Snowshoe::~Snowshoe(){}

Snowshoe& Snowshoe::operator=(const Snowshoe& obj)
{
  if (*this == obj)
    return *this;
  Activity::operator=(obj);
  distance = obj.distance;
  difficulty = obj.difficulty;
  trail_name = obj.trail_name;
  return *this;
}

Snowshoe Snowshoe::operator + (const Snowshoe& op2) const
{
  return *this;
}

bool Snowshoe::operator == (const Snowshoe& arg) const
{
  bool success = false;
  if (trail_name == arg.trail_name && Activity::operator==(arg))
    success = true;
  return success;
}

bool Snowshoe::operator != (const Snowshoe& arg) const
{
  bool success = true;
  if (trail_name == arg.trail_name && Activity::operator==(arg))
    success = false;
  return success;
}

ostream & operator << (ostream & out, const Snowshoe& arg)
{
  out << "Trail Name: " << arg.trail_name << endl;
  out << "Difficulty: " << arg.difficulty << endl;
  out << "Distance: " << arg.distance << endl;
  return out;
}

istream & operator >> (istream & in, const Snowshoe& arg)
{
  return in;
}

int operator<(const Snowshoe& l_arg, const Snowshoe& r_arg)
{
  int flag = 0;
  if (l_arg.difficulty < r_arg.difficulty)
    flag = 1;
  return flag;
}

int operator<=(const Snowshoe& l_arg, const Snowshoe& r_arg)
{
  int flag = 0;
  if (l_arg.difficulty <= r_arg.difficulty)
    flag = 1;
  return flag;
} 

int operator>(const Snowshoe& l_arg, const Snowshoe& r_arg)
{
  int flag = 0;
  if (l_arg.difficulty > r_arg.difficulty)
    flag = 1;
  return flag;
} 

int operator>=(const Snowshoe& l_arg, const Snowshoe& r_arg)
{
  int flag = 0;
  if (l_arg.difficulty >= r_arg.difficulty)
    flag = 1;
  return flag;
}

int Snowshoe::display() const
{
  Activity::display();
  cout << *this << endl;
  return 0;
}

void Snowshoe::rate()
{
  Activity::rate();
}

void Snowshoe::add_rating(int arg)
{
  Activity::add_rating(arg);
}
// =================================================================


// Skating Class
// =================================================================
Skating::Skating():Activity("", BEGINNER), week_cost(0), weekend_cost(0), events(false), name("") {}

Skating::Skating(float arg_wcost, float arg_wkndcost, bool arg_events, string arg_name, string arg_location): Activity(arg_location, BEGINNER)
{
  week_cost = arg_wcost;
  weekend_cost = arg_wkndcost;
  events = arg_events;
  name = arg_name;
}

Skating::Skating(const Skating& obj): Activity(obj)
{
  week_cost = obj.week_cost;
  weekend_cost = obj.weekend_cost;
  events = obj.events;
  name = obj.name;
}

Skating::~Skating(){}

Skating& Skating::operator=(const Skating& obj)
{
  if (*this == obj)
    return *this;
  Activity::operator=(obj);
  week_cost = obj.week_cost;
  weekend_cost = obj.weekend_cost;
  events = obj.events;
  name = obj.name;
  return *this;
}

bool Skating::operator == (const Skating& arg) const
{
  bool success = false;
  if (name == arg.name && Activity::operator==(arg))
    success = true;
  return success;
}

bool Skating::operator != (const Skating& arg) const
{
  bool success = true;
  if (name == arg.name && Activity::operator==(arg))
    success = false;
  return success;
}

ostream & operator << (ostream & out, const Skating& arg)
{
  out << "Name: " << arg.name << endl;
  out << "Week day cost: " << arg.week_cost << endl;
  out << "Weekend cost: " << arg.weekend_cost << endl;
  if (arg.events)
    out << "This venue holds other events. Please ensure there is no scheduled events before visiting."<< endl;
  else 
    out << "This venue rarely holds events. It is advised that you still visit their website to ensure availability." << endl;
  return out;
}

istream & operator >> (istream & in, const Skating& arg)
{
  return in;
}

int operator<(const Skating& l_arg, const Skating& r_arg)
{
  int flag = 0;
  if (l_arg.weekend_cost < r_arg.weekend_cost )
    flag = 1;
  return flag;
}

int operator<=(const Skating& l_arg, const Skating& r_arg)
{
  int flag = 0;
  if (l_arg.weekend_cost <= r_arg.weekend_cost )
    flag = 1;
  return flag;
}

int operator>(const Skating& l_arg, const Skating& r_arg)
{
  int flag = 0;
  if (l_arg.weekend_cost > r_arg.weekend_cost )
    flag = 1;
  return flag;
}

int operator>=(const Skating& l_arg, const Skating& r_arg)
{
  int flag = 0;
  if (l_arg.weekend_cost >= r_arg.weekend_cost )
    flag = 1;
  return flag;
}

int Skating::display() const
{
  Activity::display();
  cout << *this << endl;
  return 0;
}

void Skating::rate()
{
  Activity::rate();
}

void Skating::add_rating(int arg)
{
  Activity::add_rating(arg);
}



// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

// Contains Activity, Skiing, Snowshoe, and Skating classes.
// Skiing: line number 135
// Snowshoe: line number 281
// Skating: line number 404

// This file contains the implementation of the activity.h file. The hierarchy contains
// 4 classes with activity as the root. The ski, snowshoe, and skating class all inherit 
// publicly from the activity class. 

#include "activity.h"


// ACTIVITY CLASS
// =================================================================
// Default constructor.
Activity::Activity(): season(nullptr), location(""), level(DEFAULT) {}

// Parameterized constructor with default level.
Activity::Activity(string arg_loc): level(DEFAULT)
{
  char temp[7] = "Winter";
  season = new char[strlen(temp) + 1];
  strcpy(season, temp);
  location = arg_loc;
}

// Parameterized constructor with argument level.
Activity::Activity(string arg_loc, int arg_level)
{
  char temp[7] = "Winter";
  season = new char[strlen(temp) + 1];
  strcpy(season, temp);
  location = arg_loc;
  level = arg_level;
}

// Copy constructor.
Activity::Activity(const Activity& arg)
{
  season = new char [strlen(arg.season) + 1];
  strcpy(season, arg.season);
  location = arg.location;
  level = arg.level;
  for (auto iter = arg.ratings.begin(); iter < arg.ratings.end(); iter++)
    ratings.push_back(*iter);
}

// Deconstructor.
Activity::~Activity()
{
  if (season)
  {
    delete [] season;
    season = nullptr;
  }
}

// @Dev - Overloaded equal sign operator assigns all member values.
// Args - Object by reference.
// Returns - Pointer to lvalue.
Activity& Activity::operator=(const Activity& arg)
  i(*thi== arg)
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

// @Dev - Overloaded ++ operator increments the level data member.
// Args - None.
// Returns - Pointer to lvalue.
Activity Activity::operator++()
{
  if (level < 3)
    level = level + 1;
  return *this;
}

// @Dev - Overloaded == operator determines of two objects have the same location and season.
// Args - Object by reference.
// Returns - Boolean true for match and false otherwise.
bool Activity::operator == (const Activity& arg) const
{
  bool success = true;
  if (strcmp(arg.season, season) != 0 || arg.location != location)
    success = false;
  return success;
}

// @Dev - Overloaded != operator determines of two objects have different location or season.
// Args - Object by reference.
// Returns - Boolean true for mismatch and false otherwise.
bool Activity::operator != (const Activity& arg) const
{
  bool success = false;
  if (strcmp(arg.season, season) != 0 || arg.location != location)
    success = true;
  return success;
}

// @Dev - Overloaded << operator outputs the object to the console.
// Args - Ostream and Object by reference.
// Returns - Ostream.
ostream & operator << (ostream & out, const Activity& arg) 
{
  int rating = arg.avg_rating();
  out << "Season: " << arg.season << "\n" << "Location: " << arg.location << "\n" << "Level: " << arg.level <<  "\n" << "Average rating: " << rating;
  return out;
}

// @Dev - Overloaded << operator outputs the object to the console.
// Args - Ostream and Object by reference.
// Returns - Ostream.
int Activity::display() const
{
  cout << *this << endl;
  return 0;
}

// @Dev - Computes average rating of an object. Not currently in use(need more time).
// Args - None.
// Returns - Integer determined by formula for an average that rounds down.
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

// @Dev - Adds rating to the rating vector member. Not currently in use(need more time).
// Args - Integer to be added to the vector.
// Returns - Integer success.
int Activity::add_rating(int arg)
{
  if (arg < 1 || arg > 5)
  {
    cout << "Invalid rating. Please try again." << endl;
    return 0;
  }
  ratings.push_back(arg);
  return 1;
}

// @Dev - Allows client to prompt for user inputs without providing any arguments. Not currently in use(need more time).
// Args - None.
// Returns - Integer rating.
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
// Default constructor.
Skiing::Skiing(): Activity("",INTERMEDIATE), review(nullptr), lift_cost(0), rental_cost(0), easy_runs(0), hard_runs(0) {}

// Parameterized constructor.
Skiing::Skiing(float l_cost, float r_cost, int e_runs, int h_runs, string arg_loc): Activity(arg_loc, INTERMEDIATE), review(nullptr)
{
  lift_cost = l_cost;
  rental_cost = r_cost;
  easy_runs = e_runs;
  hard_runs = h_runs;
}

// Copy constructor.
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

// Deconstructor.
Skiing::~Skiing() 
{
  if (review)
  {
    delete [] review;
    review = nullptr;
  }
}

// @Dev - Overloaded equal sign operator assigns all member values.
// Args - Object by reference.
// Return- Pointer to lvalue.
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

// @Dev - Overloaded + operator increases the lift cost member by integer provided.
// Args - Integer to add to lift cost.
// Return - Pointer to lvalue.
Skiing Skiing::operator + (const int& op2)
{
  lift_cost += op2;
  return *this;
}

// @Dev - Overloaded == operator to compare objects.
// Args - Object to compare.
// Return - Boolean.
bool Skiing::operator == (const Skiing& arg) const
{
  bool success = Activity::operator==(arg);
  return success;
}

// @Dev - Overloaded != operator to compare objects.
// Args - Object to compare.
// Return - Boolean.
bool Skiing::operator != (const Skiing& arg) const
{
  bool success = Activity::operator!=(arg);
  return success;
}

// @Dev - Overloaded << operator to output objects to the console.
// Args - Ostrem and Object by reference.
// Return - Ostream.
ostream & operator << (ostream & out, const Skiing& arg)
{
  out << "Lift cost: " << arg.lift_cost << endl;
  out << "Rental cost: " << arg.rental_cost << endl;
  out << "Easy runs: " << arg.easy_runs << endl;
  out << "Hard runs: " << arg.hard_runs << endl;
  return out;
}

// @Dev - Overloaded < operator to compare max cost of objects.
// Args - lvalue and rvalue objects by reference.
// Return - Integer flag 0 for false and 1 for true.
int operator<(const Skiing& l_ski, const Skiing& r_ski)
{
  int flag = 0;
  if (l_ski.calculate_max_cost() < r_ski.calculate_max_cost())
    flag = 1;
  return flag;
}

// @Dev - Overloaded <= operator to compare max cost of objects.
// Args - lvalue and rvalue objects by reference.
// Return - Integer flag 0 for false and 1 for true.
int operator<=(const Skiing& l_ski, const Skiing& r_ski)
{
  int flag = 0;
  if (l_ski.calculate_max_cost() <= r_ski.calculate_max_cost())
    flag = 1;
  return flag;
}

// @Dev - Overloaded > operator to compare max cost of objects.
// Args - lvalue and rvalue objects by reference.
// Return - Integer flag 0 for false and 1 for true.
int operator>(const Skiing& l_ski, const Skiing& r_ski)
{
  int flag = 0;
  if (l_ski.calculate_max_cost() > r_ski.calculate_max_cost())
    flag = 1;
  return flag;
}

// @Dev - Overloaded >= operator to compare max cost of objects.
// Args - lvalue and rvalue objects by reference.
// Return - Integer flag 0 for false and 1 for true.
int operator>=(const Skiing& l_ski, const Skiing& r_ski)
{
  int flag = 0;
  if (l_ski.calculate_max_cost() >= r_ski.calculate_max_cost())
    flag = 1;
  return flag;
}

// @Dev - Outputs parent and current object to console.
// Args - None.
// Return - Integer success.
int Skiing::display() const
{
  Activity::display();
  cout << *this << endl;
  if (review)
    cout << "Review: " << review << endl;
  return 0;
}

// @Dev - Calculates max cost based on current member values.
// Args - None.
// Return - Integer representing cost.
int Skiing::calculate_max_cost() const
{
  return lift_cost + rental_cost;
}

// @Dev - Calculates min cost based on current member values.
// Args - None.
// Return - Integer representing cost.
int Skiing::calculate_min_cost() const
{
  return lift_cost;
}

// @Dev - Adds rating to rating vector. Not currently in use(need more time).
// Args - Integer argument to add to rating vector.
// Return - None.
void Skiing::add_rating(int arg)
{
  Activity::add_rating(arg);
}

// @Dev - Calls parent rate() that prompts user for input to add to rating vector. Not currently in use(need more time).
// Args - None.
// Return - None.
void Skiing::rate()
{
  Activity::rate();
}
// =================================================================


// Snow Shoe Class
// =================================================================
// Default constructor.
Snowshoe::Snowshoe(): Activity("", BEGINNER), distance(0), difficulty(0), trail_name("") {}

// Parameterized constructor.
Snowshoe::Snowshoe(float dist, int diff, string name, string loc): Activity(loc, BEGINNER)  
{
  distance = dist;
  difficulty = diff;
  trail_name = name;
}

// Copy constructor.
Snowshoe::Snowshoe(const Snowshoe& obj): Activity(obj)
{
  distance = obj.distance;
  difficulty = obj.difficulty;
  trail_name = obj.trail_name;
}

// Deconstructor.
Snowshoe::~Snowshoe(){}

// @Dev - Overloaded equal sign operator assigns all member values.
// Args - Object by reference.
// Return- Pointer to lvalue.
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

// @Dev - Overloaded + operator increases the lift cost member by integer provided.
// Args - Integer to add to lift cost.
// Return - Pointer to lvalue.
Snowshoe Snowshoe::operator + (const Snowshoe& op2) const
{
  difficulty += op2;
  return *this;
}

// @Dev - Overloaded == operator to compare objects.
// Args - Object to compare.
// Return - Boolean.
bool Snowshoe::operator == (const Snowshoe& arg) const
{
  bool success = false;
  if (trail_name == arg.trail_name && Activity::operator==(arg))
    success = true;
  return success;
}

// @Dev - Overloaded != operator to compare objects.
// Args - Object to compare.
// Return - Boolean.
bool Snowshoe::operator != (const Snowshoe& arg) const
{
  bool success = true;
  if (trail_name == arg.trail_name && Activity::operator==(arg))
    success = false;
  return success;
}

// @Dev - Overloaded << operator to output objects to the console.
// Args - Ostrem and Object by reference.
// Return - Ostream.
ostream & operator << (ostream & out, const Snowshoe& arg)
{
  out << "Trail Name: " << arg.trail_name << endl;
  out << "Difficulty: " << arg.difficulty << endl;
  out << "Distance: " << arg.distance << endl;
  return out;
}

// @Dev - Overloaded < operator to compare max cost of objects.
// Args - lvalue and rvalue objects by reference.
// Return - Integer flag 0 for false and 1 for true.
int operator<(const Snowshoe& l_arg, const Snowshoe& r_arg)
{
  int flag = 0;
  if (l_arg.difficulty < r_arg.difficulty)
    flag = 1;
  return flag;
}

// @Dev - Overloaded <= operator to compare max cost of objects.
// Args - lvalue and rvalue objects by reference.
// Return - Integer flag 0 for false and 1 for true.
int operator<=(const Snowshoe& l_arg, const Snowshoe& r_arg)
{
  int flag = 0;
  if (l_arg.difficulty <= r_arg.difficulty)
    flag = 1;
  return flag;
} 

// @Dev - Overloaded > operator to compare max cost of objects.
// Args - lvalue and rvalue objects by reference.
// Return - Integer flag 0 for false and 1 for true.
int operator>(const Snowshoe& l_arg, const Snowshoe& r_arg)
{
  int flag = 0;
  if (l_arg.difficulty > r_arg.difficulty)
    flag = 1;
  return flag;
} 

// @Dev - Overloaded >= operator to compare max cost of objects.
// Args - lvalue and rvalue objects by reference.
// Return - Integer flag 0 for false and 1 for true.
int operator>=(const Snowshoe& l_arg, const Snowshoe& r_arg)
{
  int flag = 0;
  if (l_arg.difficulty >= r_arg.difficulty)
    flag = 1;
  return flag;
}

// @Dev - Outputs parent and current object to console.
// Args - None.
// Return - Integer success.
int Snowshoe::display() const
{
  Activity::display();
  cout << *this << endl;
  return 0;
}

// @Dev - Calls parent rate() that prompts user for input to add to rating vector. Not currently in use(need more time).
// Args - None.
// Return - None.
void Snowshoe::rate()
{
  Activity::rate();
}

// @Dev - Adds rating to rating vector. Not currently in use(need more time).
// Args - Integer argument to add to rating vector.
// Return - None.
void Snowshoe::add_rating(int arg)
{
  Activity::add_rating(arg);
}
// =================================================================


// Skating Class
// =================================================================
// Default constructor.
Skating::Skating():Activity("", BEGINNER), week_cost(0), weekend_cost(0), events(false), name("") {}

// Parameterized constructor.
Skating::Skating(float arg_wcost, float arg_wkndcost, bool arg_events, string arg_name, string arg_location): Activity(arg_location, BEGINNER)
{
  week_cost = arg_wcost;
  weekend_cost = arg_wkndcost;
  events = arg_events;
  name = arg_name;
}

// Copy constructor.
Skating::Skating(const Skating& obj): Activity(obj)
{
  week_cost = obj.week_cost;
  weekend_cost = obj.weekend_cost;
  events = obj.events;
  name = obj.name;
}

// Deconstructor.
Skating::~Skating(){}

// @Dev - Overloaded equal sign operator assigns all member values.
// Args - Object by reference.
// Return- Pointer to lvalue.
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

// @Dev - Overloaded == operator to compare objects.
// Args - Object to compare.
// Return - Boolean.
bool Skating::operator == (const Skating& arg) const
{
  bool success = false;
  if (name == arg.name && Activity::operator==(arg))
    success = true;
  return success;
}

// @Dev - Overloaded != operator to compare objects.
// Args - Object to compare.
// Return - Boolean.
bool Skating::operator != (const Skating& arg) const
{
  bool success = true;
  if (name == arg.name && Activity::operator==(arg))
    success = false;
  return success;
}

// @Dev - Overloaded << operator to output objects to the console.
// Args - Ostrem and Object by reference.
// Return - Ostream.
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

// @Dev - Overloaded < operator to compare max cost of objects.
// Args - lvalue and rvalue objects by reference.
// Return - Integer flag 0 for false and 1 for true.
int operator<(const Skating& l_arg, const Skating& r_arg)
{
  int flag = 0;
  if (l_arg.weekend_cost < r_arg.weekend_cost )
    flag = 1;
  return flag;
}

// @Dev - Overloaded <= operator to compare max cost of objects.
// Args - lvalue and rvalue objects by reference.
// Return - Integer flag 0 for false and 1 for true.
int operator<=(const Skating& l_arg, const Skating& r_arg)
{
  int flag = 0;
  if (l_arg.weekend_cost <= r_arg.weekend_cost )
    flag = 1;
  return flag;
}

// @Dev - Overloaded > operator to compare max cost of objects.
// Args - lvalue and rvalue objects by reference.
// Return - Integer flag 0 for false and 1 for true.
int operator>(const Skating& l_arg, const Skating& r_arg)
{
  int flag = 0;
  if (l_arg.weekend_cost > r_arg.weekend_cost )
    flag = 1;
  return flag;
}

// @Dev - Overloaded >= operator to compare max cost of objects.
// Args - lvalue and rvalue objects by reference.
// Return - Integer flag 0 for false and 1 for true.
int operator>=(const Skating& l_arg, const Skating& r_arg)
{
  int flag = 0;
  if (l_arg.weekend_cost >= r_arg.weekend_cost )
    flag = 1;
  return flag;
}

// @Dev - Outputs parent and current object to console.
// Args - None.
// Return - Integer success.
int Skating::display() const
{
  Activity::display();
  cout << *this << endl;
  return 0;
}

// @Dev - Calls parent rate() that prompts user for input to add to rating vector. Not currently in use(need more time).
// Args - None.
// Return - None.
void Skating::rate()
{
  Activity::rate();
}

// @Dev - Adds rating to rating vector. Not currently in use(need more time).
// Args - Integer argument to add to rating vector.
// Return - None.
void Skating::add_rating(int arg)
{
  Activity::add_rating(arg);
}


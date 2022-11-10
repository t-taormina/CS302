// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

// This file contains the headers for the hierarchy used in this program. The activity
// class is the root. The skiing, snowshoe, and skating class all publicly inherit from
// the activity class. In this case, these objects are used inside of a single
// implementation of a doubly linked list using templates. Thus, we have necessary
// operator overloading for functionality when using algorithms inside the linked list
// class. I have made use of most of the operators, but not all of them. With more time 
// I would have liked to write more algorithms and eventually find a use for all operators.
// See the implemenation file (activity.cpp) for descriptions and intended uses for each function.
// =================================================================================================


#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int SIZE = 100; // Used for dynamic character arrays.
const int DEFAULT = 0;
const int BEGINNER = 1;
const int INTERMEDIATE = 2;
const int ADVANCED = 3;

#ifndef ACTIVITY_H
#define ACTIVITY_H

class Activity
{ 
  public: 
    Activity();
    Activity(string arg_loc);
    Activity(string arg_loc, int level);
    Activity(const Activity&);
    ~Activity();

    Activity& operator=(const Activity& arg);
    Activity operator ++ ();
    bool operator == (const Activity& arg) const;
    bool operator != (const Activity& arg) const;
    friend ostream & operator << (ostream & out, const Activity& arg);
    int display() const;
    int avg_rating() const;
    int add_rating(int arg);
    int rate();

  protected: 
    char* season;
    string location;
    vector<int> ratings;
    int level;// 0 = default
              // 1 = begginer
              // 2 = intermediate
              // 3 = expert
};

class Skiing: public Activity
{
  public: 
    Skiing();
    Skiing(float, float, int, int, string);
    Skiing(const Skiing&);
    ~Skiing();

    Skiing& operator=(const Skiing& arg);
    Skiing operator + (const int& op2);
    bool operator == (const Skiing& arg) const;
    bool operator != (const Skiing& arg) const;
    friend ostream & operator << (ostream & out, const Skiing& arg);
    friend int operator<(const Skiing&, const Skiing&); 
    friend int operator<=(const Skiing&, const Skiing&); 
    friend int operator>(const Skiing&, const Skiing&); 
    friend int operator>=(const Skiing&, const Skiing&);

    int display() const;
    
    int calculate_max_cost() const;
    int calculate_min_cost() const;
    void add_rating(int arg);
    void rate();

  protected: 
    char* review;
    float lift_cost;
    float rental_cost;
    int easy_runs;
    int hard_runs;
};


class Snowshoe: public Activity
{
  public: 
    Snowshoe();
    Snowshoe(float, int, string, string);
    Snowshoe(const Snowshoe&);
    ~Snowshoe();

    Snowshoe& operator=(const Snowshoe& arg);
    Snowshoe operator + (const int& op2);
    bool operator == (const Snowshoe& arg) const;
    bool operator != (const Snowshoe& arg) const;
    friend ostream & operator << (ostream & out, const Snowshoe& arg);
    friend int operator<(const Snowshoe&, const Snowshoe&); 
    friend int operator<=(const Snowshoe&, const Snowshoe&); 
    friend int operator>(const Snowshoe&, const Snowshoe&); 
    friend int operator>=(const Snowshoe&, const Snowshoe&);

    int display() const;
    void add_rating(int arg);
    void rate();


  private: 
    float distance;
    int difficulty;
    string trail_name;
};


class Skating: public Activity
{
  public: 
    Skating();
    Skating(float arg_wcost, float arg_wkndcost, bool arg_events, string arg_name, string arg_location);
    Skating(const Skating&);
    ~Skating();

    Skating& operator=(const Skating& arg);
    bool operator == (const Skating& arg) const;
    bool operator != (const Skating& arg) const;
    friend ostream & operator << (ostream & out, const Skating& arg);
    friend int operator<(const Skating&, const Skating&); 
    friend int operator<=(const Skating&, const Skating&); 
    friend int operator>(const Skating&, const Skating&); 
    friend int operator>=(const Skating&, const Skating&);

    int display() const;
    void add_rating(int arg);
    void rate();

  private: 
    float week_cost;
    float weekend_cost;
    bool events;
    string name;
};

#endif


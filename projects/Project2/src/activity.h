// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int SIZE = 100; // Used for dynamic character arrays.

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
    //bool operator != (const Activity& arg) const;
    friend ostream & operator << (ostream & out, Activity& arg);
    friend istream & operator >> (istream & in, Activity& arg);
    /*
    friend int operator<(const Activity&, const Activity&); 
    friend int operator<=(const Activity&, const Activity&); 
    friend int operator>(const Activity&, const Activity&); 
    friend int operator>=(const Activity&, const Activity&);
    */

    int display();
    int avg_rating();
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
    friend istream & operator >> (istream & in, const Skiing& arg);
    friend int operator<(Skiing&, Skiing&); 
    friend int operator<=(Skiing&, Skiing&); 
    friend int operator>(Skiing&, Skiing&); 
    friend int operator>=(Skiing&, Skiing&);

    int display();
    
    int calculate_max_cost();
    int calculate_min_cost();
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
    Snowshoe operator + (const Snowshoe& op2) const;
    bool operator == (const Snowshoe& arg) const;
    bool operator != (const Snowshoe& arg) const;
    friend ostream & operator << (ostream & out, const Snowshoe& arg);
    friend istream & operator >> (istream & in, const Snowshoe& arg);
    friend int operator<(const Snowshoe&, const Snowshoe&); 
    friend int operator<=(const Snowshoe&, const Snowshoe&); 
    friend int operator>(const Snowshoe&, const Snowshoe&); 
    friend int operator>=(const Snowshoe&, const Snowshoe&);

    int display();

  private: 
    float distance;
    int difficulty;
    string trail_name;
};


class Skating: public Activity
{
  public: 
    Skating();
    Skating(float arg_wcost, float arg_wecost, bool arg_events);
    Skating(const Skating&);
    ~Skating();

    Skating& operator=(const Skating& arg);
    Skating operator + (const Skating& op2) const;
    bool operator == (const Skating& arg) const;
    bool operator != (const Skating& arg) const;
    friend ostream & operator << (ostream & out, const Skating& arg);
    friend istream & operator >> (istream & in, const Skating& arg);
    friend int operator<(const Skating&, const Skating&); 
    friend int operator<=(const Skating&, const Skating&); 
    friend int operator>(const Skating&, const Skating&); 
    friend int operator>=(const Skating&, const Skating&);

    int display();

  private: 
    float week_cost;
    float weekend_cost;
    bool events;
};

#endif


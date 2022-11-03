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
    Activity(int);
    Activity(const Activity&);
    ~Activity();

    Activity& operator=(const Activity& arg);
    Activity operator ++ ();
    bool operator == (const Activity& arg) const;
    //bool operator != (const Activity& arg) const;
    friend ostream & operator << (ostream & out, const Activity& arg);
    friend istream & operator >> (istream & in, Activity& arg);
    /*
    friend int operator<(const Activity&, const Activity&); 
    friend int operator<=(const Activity&, const Activity&); 
    friend int operator>(const Activity&, const Activity&); 
    friend int operator>=(const Activity&, const Activity&);
    */

    int edit_season(char* new_season);
    int display();

  private: 
    char* season;
    int level;// 0 = default
              // 1 = begginer
              // 2 = intermediate
              // 3 = expert
};

class Skiing: public Activity
{
  public: 
    Skiing();
    Skiing(char* arg_location, float arg_dcost, float arg_lcost, int arg_level);
    Skiing(const Skiing&);
    ~Skiing();

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
    int avg_rating();
    int add_rating();
    int calculate_max_cost();
    int calculate_min_cost();

  private: 
    char* location;
    float day_cost;
    float rental_cost;
    vector<int> ratings;
};


/*
class Snowshoe: public Activity
{
  public: 
    Snowshoe();
    Snowshoe(char* arg_location, float arg_dcost, float arg_lcost);
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
    int calculate_max_cost();
    int calculate_min_cost();

  private: 
    string location;
    float cost;
    float rental_cost;
};

class Skating: public Activity
{
  public: 
    Skating();
    Skating(char* arg_location, float arg_dcost, float arg_lcost);
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
    int calculate_max_cost();
    int calculate_min_cost();

  private: 
    string location;
    float cost;
    float rental_cost;
};
*/

#endif


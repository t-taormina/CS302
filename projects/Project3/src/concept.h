// Tyler Taormina
// taormina@pdx.edu 
// November 2022
// CS302 Program 3


// This file contains the signatures for the hierarchy used in my program. This 
// hierarchy is intended to represent terms commonly used in computer science. The 
// base class is "Concept" and publicly deriving from this class are the classes
// "Intro", "Intermediate", and "Advanced". These classes represent concepts based 
// on their level difficulty. This program was built to explore dynamic binding
// and as such there are virtual functions in the base class. These functions
// are the self similar functions that are implemented throughout the hierarchy. 
// The unique functions and the required STL container are both parts of the 
// "Advanced" class. 
// =============================================================================


#ifndef CONCEPT_H
#define CONCEPT_H
#include <iostream>
#include <string>
#include <list>
#include <iterator>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::list;


class Concept
{
  public: 
    Concept();
    Concept(const string & arg_name);
    Concept(const Concept & to_copy);
    Concept& operator= (const Concept& src);
    virtual ~Concept();

    // Self similar functions.
    virtual void display() const;
    virtual void read_in();
    virtual void edit();
    virtual int match(const string & to_match);
    virtual string get_name();

  protected:
    string name;
};


class Intro: public Concept
{
  public:
    Intro();
    Intro(const string& arg_example, const string& arg_name);
    Intro(const Intro & to_copy);
    ~Intro();
    Intro & operator= (const Intro & src);

    // Self similar functions.
    void display() const;
    void read_in();
    void edit();
    int match(const string & to_match);
    string get_name();

  private: 
    string example;
    int lower_division; // used as a bool. Value is evaluated based on being 1 or 0.
};


class Intermediate: public Concept
{
  public:
    Intermediate();
    Intermediate(const Intermediate & to_copy);
    Intermediate(const string& arg_definition, const string& arg_syntax, const string& arg_name);
    ~Intermediate();
    Intermediate & operator= (const Intermediate & src);

    // Self similar functions.
    void display() const;
    void read_in();
    void edit();
    int match(const string & to_match);
    string get_name();

  private: 
    string definition;
    string syntax;
};


class Advanced: public Concept
{
  public: 
    Advanced();
    Advanced(const Advanced & to_copy);
    Advanced(const string& arg_syntax, const string& arg_name);
    ~Advanced();
    Advanced & operator= (const Advanced & src);

    // Self similar functions.
    void display() const;
    void read_in();
    void edit();
    int match(const string & to_match);
    string get_name();

    // Unique functions.
    void add_language(const string & to_add);
    void remove_language(const string & to_remove);

  private: 
    string syntax;
    list<string> language_list;
};

#endif

// Tyler Taormina
// taormina@pdx.edu 
// November 2022
// CS302 Program 3


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
    Concept(string & arg_name);
    Concept(const Concept & to_copy);
    Concept& operator= (const Concept& src);
    virtual ~Concept();

    // Self similar functions.
    virtual void display() const;
    virtual void read_in();
    virtual void edit();
    virtual bool match(const string & to_match);
    virtual string get_name();

  protected:
    string name;
};


class Intro: public Concept
{
  public:
    Intro();
    Intro(string arg_example, bool arg_lower_division, string arg_name);
    Intro(const Intro & to_copy);
    ~Intro();
    Intro & operator= (const Intro & src);

    // Self similar functions.
    void display() const;
    void read_in();
    void edit();
    bool match(string & to_match);
    string get_name();

  private: 
    string example;
    bool lower_division;
};


/*
class Intermediate: public Concept
{
  public:
    Intermediate();
    Intermediate(const Intermediate & to_copy);
    Intermediate(string arg_definition, string arg_syntax, string arg_name);
    ~Intermediate();
    Intermediate & operator= (const Intermediate & src);

    // Self similar functions.
    void display() const;
    void read_in();
    void edit();
    bool match(string & to_match);
    string get_name();

  private: 
    string definition;
    string syntax;
};


class Advanced: public concept
{
  public: 
    Advanced();
    Advanced(const Advanced & to_copy);
    Advanced(string & arg_syntax, string arg_name);
    ~Advanced();
    Advanced & operator= (const Advanced & src);

    // Self similar functions.
    void display() const;
    void read_in();
    void edit();
    bool match(string & to_match);
    string get_name();

    // Unique functions.
    void add_language(string & to_add);
    void remove_language(string & to_remove);

  private: 
    string syntax;
    list<string> language_list;
};
*/

#endif

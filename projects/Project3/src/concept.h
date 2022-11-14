// Tyler Taormina
// taormina@pdx.edu 
// November 2022
// CS302 Program 3


#ifndef CONCEPT_H
#define CONCEPT_H
#include <iostream>
#include <memory>
#include <list>
#include <iterator>
using std::memory;
using std::cout;
using std::endl;
using std::list;


class Concept
{
  public: 
    Concept();
    Concept(string & arg_name);
    Concept(const Concept & to_copy);
    virtual ~Concept();

    // Self similar functions.
    virtual void display() const;
    virtual void read_in();
    virtual void edit();
    virtual bool match(string & to_match);

  protected:
    string name;
};


class Intro: public Concept
{
  public:
    Intro();
    Intro(string arg_example, bool arg_lower_division);
    Intro(const Intro & to_copy);
    ~Intro();
    Intro & operator= (const Intro & src);

    // Self similar functions.
    void display() const;
    void read_in();
    void edit();
    bool match(string & to_match);

  private: 
    string example;
    bool lower_division;
};


class Intermediate: public Concept
{
  public:
    Intermediate();
    Intermediate(const Intermediate & to_copy);
    Intermediate(string arg_definition, string arg_syntax);
    ~Intermediate();
    Intermediate & operator= (const Intermediate & src);

    // Self similar functions.
    void display() const;
    void read_in();
    void edit();
    bool match(string & to_match);

  private: 
    string definition;
    string syntax;
};


class Advanced: public concept
{
  public: 
    Advanced();
    Advanced(const Advanced & to_copy);
    Advanced(string & arg_syntax);
    ~Advanced();
    Advanced & operator= (const Advanced & src);

    // Self similar functions.
    void display() const;
    void read_in();
    void edit();
    bool match(string & to_match);

    // Unique functions.
    void add_language(string & to_add);
    void remove_language(string & to_remove);

  private: 
    string syntax;
    list<string> language_list;
};

#endif

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
    virtual void display() const;
    virtual void read_in();
    virtual bool match();
    virtual void edit();


  protected:
    string name;
};

class Intro: public Concept
{
  public:
    Intro();
    Intro(string arg_example, bool arg_lower_division);
    Intro(const Intro & to_copy);
    ~ Intro();
    void display() const;
    void read_in();


  private: 
    string example;
    bool lower_division;
};


class Intermediate: public Concept
{
  public:
    Intermediate();
    Intermediate(const Intermediate & to_copy);
    ~Intermediate();

    void display() const;
    void read_in();

  private: 
    string definition;
    string syntax;
};

class Advanced: public concept
{
  public: 
    Advanced();
    Advanced(const Advanced & to_copy);
    ~Advanced();

    void display() const;
    void read_in();
  private: 
    list<string> syntax_examples;
    list<string> language_list;
};

#endif

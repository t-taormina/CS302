// Tyler Taormina
// taormina@pdx.edu 
// November 2022
// CS302 Program 3

#include "concept.h"

Concept::Concept(): name(""){}

Concept::Concept(string & arg_name): name(arg_name){}

Concpt::Concept(const Concept & to_copy)
{
  name = to_copy.name;
}

virtual Concept::~Concept(){}

// Self similar functions.
virtual void Concept::display() const
{
  cout << "Name: " << name << endl;
}

virtual void Concept::read_in()
{

}
virtual void edit();
virtual bool match(string & to_match);



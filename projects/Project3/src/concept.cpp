// Tyler Taormina
// taormina@pdx.edu 
// November 2022
// CS302 Program 3

#include "concept.h"

// Concept Class 
// ==========================================================

Concept::Concept(): name(""){}

Concept::Concept(string & arg_name): name(arg_name){}

Concept::Concept(const Concept & to_copy)
{
  name = to_copy.name;
}

Concept& Concept::operator= (const Concept& src)
{
  if (this == &src)
    return *this;
  name = src.name;
  return *this;
}

Concept::~Concept(){}

// Self similar functions.
void Concept::display() const
{
  cout << "Name: " << name << endl;
}

void Concept::read_in()
{
  string temp;
  cout << "Enter the name of the concept: ";
  cin >> temp;
  name = temp;
}

void Concept::edit()
{
  cout << "Enter the name of the concept: ";
  cin >> name;
}

bool Concept::match(const string & to_match)
{
  bool success = false;
  if (!to_match.compare(name))
    success = true;
  return success;
}

string Concept::get_name()
{
  return name;
}

// Intro Class
// ==========================================================

Intro::Intro(): Concept(), example(""), lower_division(true) {}

Intro::Intro(string arg_example, bool arg_lower_division, string arg_name): Concept(arg_name), example(arg_example), lower_division(arg_lower_division){}

Intro::Intro(const Intro & to_copy): Concept(to_copy), example(to_copy.example), lower_division(to_copy.lower_division){}

Intro::~Intro(){}

Intro & Intro::operator= (const Intro & src)
{
  if (this == &src)
    return *this;
  Concept::operator=(src);
  example = src.example;
  lower_division = src.lower_division;
  return *this;
}

// Self similar functions.
void Intro::display() const
{
  Concept::display();

}
void read_in();
void edit();
bool match(string & to_match);
string get_name();



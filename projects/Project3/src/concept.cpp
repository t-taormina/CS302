// Tyler Taormina
// taormina@pdx.edu 
// November 2022
// CS302 Program 3


// This file contains the implementations of the hierarchy used in this program. 
// The classes are "Concept", "Intro", "Intermediate", and "Advanced". Concept 
// is the base class and all other classes inherit publicly from the Concept class.
// There are three self similar functions in the hierarchy are: read_in(), edit(), 
// and match(). 
//
// Concept: line 8
// Intro: line 98
// Intermediate: line 181
// Advanced: line 269


#include "concept.h"

// Concept Class 
// ==========================================================
//

// Default constructor.
Concept::Concept(): name(""){}

// Parameterized constructor.
Concept::Concept(const string & arg_name): name(arg_name){}

// Copy constructor.
Concept::Concept(const Concept & to_copy)
{
  name = to_copy.name;
}

// Destructor.
Concept::~Concept(){}

// Assignment operator. 
Concept& Concept::operator= (const Concept& src)
{
  if (this == &src)
    return *this;
  name = src.name;
  return *this;
}

// @Dev    - virtual display function. 
// Args    - None.
// Returns - None.
void Concept::display() const
{
  cout << "Name: " << name << endl;
}

// @Dev    - virtual function to read in private data members. 
// Args    - None.
// Returns - None.
void Concept::read_in()
{
  string temp;
  cout << "Enter the name of the concept: ";
  getline(cin, temp);
  name = temp;
}

// @Dev    - virtual function to read in private data members. 
// Args    - None.
// Returns - None.
void Concept::edit()
{
  string temp;
  cout << "Enter the name of the concept: ";
  getline(cin, temp);
  name = temp;
}

// @Dev    - virtual function determine if a argument matches the private data member. 
// Args    - string by reference.
// Returns - integer success.
//           0 for a match 
//           + number for post alphabetically
//           - number for pre alphabetically
int Concept::match(const string & to_match)
{
  return to_match.compare(name);
}

// @Dev    - returns a copy of private data member. 
// Args    - None.
// Returns - string.
string Concept::get_name()
{
  return name;
}

// Intro Class
// ==========================================================

// Default constructor.
Intro::Intro(): Concept(), example(""), lower_division(1) {}

// Parameterized constructor.
Intro::Intro(const string& arg_example, const string& arg_name): Concept(arg_name), example(arg_example), lower_division(1){}

// Copy constructor.
Intro::Intro(const Intro & to_copy): Concept(to_copy), example(to_copy.example), lower_division(to_copy.lower_division){}

// Destructor.
Intro::~Intro(){}

// Assignment operator. 
Intro & Intro::operator= (const Intro & src)
{
  if (this == &src)
    return *this;
  Concept::operator=(src);
  example = src.example;
  lower_division = src.lower_division;
  return *this;
}

// @Dev    - display function outputs all private data members. 
// Args    - None.
// Returns - None.
void Intro::display() const
{
  Concept::display();
  cout << "Example: " << example << endl;
  if (lower_division)
    cout << "This concept is covered in lower division classes. Refer to your lower division course work for more information." << endl;
  else 
    cout << "This is not covered in lower division courses. Ask a teacher or tutor where to find more information regarding this concept." << endl;
}

// @Dev    - function to read in private data members for entire hierarchy. 
// Args    - None.
// Returns - None.
void Intro::read_in()
{
  Concept::read_in();
  string temp;
  cout << "Enter an example of the concept: ";
  getline(cin, temp);
  example = temp;
}

// @Dev    - function to read in private data members for the classes scope(no parent data). 
// Args    - None.
// Returns - None.
void Intro::edit()
{
  string temp;
  cout << "Enter an example of the concept: ";
  getline(cin, temp);
  example = temp;
}

// @Dev    - function determine if a argument matches the private data member name in 
//           parent class. 
// Args    - string by reference.
// Returns - integer success.
//           0 for a match 
//           + number for post alphabetically
//           - number for pre alphabetically
int Intro::match(const string & to_match)
{
  return Concept::match(to_match);
}

// @Dev    - returns a copy of private data member "name" from parent class. 
// Args    - None.
// Returns - string.
string Intro::get_name()
{
  return Concept::get_name();
}


// Intermediate Class
// ==========================================================

// Default constructor.
Intermediate::Intermediate(): Concept(), definition(""), syntax(""){}

// Parameterized constructor.
Intermediate::Intermediate(const string& arg_definition, const string& arg_syntax, const string& arg_name): Concept(arg_name), definition(arg_definition), syntax(arg_syntax){}

// Copy constructor.
Intermediate::Intermediate(const Intermediate & to_copy): Concept(to_copy), definition(to_copy.definition), syntax(to_copy.syntax){}

// Destructor.
Intermediate::~Intermediate(){}

// Assignment operator. 
Intermediate & Intermediate::operator= (const Intermediate & src)
{
  if (this == &src)
    return *this;
  Concept::operator=(src);
  definition = src.definition;
  syntax = src.syntax;
  return *this;
}

// @Dev    - display function outputs all private data members. 
// Args    - None.
// Returns - None.
void Intermediate::display() const
{
  Concept::display();
  cout << "Definition: " << definition << endl;
  cout << "Syntax: " << syntax << endl;
}

// @Dev    - function to read in private data members for entire hierarchy. 
// Args    - None.
// Returns - None.
void Intermediate::read_in()
{
  Concept::read_in();
  cout << "Enter the definition of the concept: ";
  string temp_def;
  getline(cin, temp_def);
  definition = temp_def;
  cout << "Enter the syntax of the concept: ";
  string temp_syn;
  getline(cin, temp_syn);
  syntax = temp_syn;
}

// @Dev    - function to read in private data members for the classes scope(no parent data). 
// Args    - None.
// Returns - None.
void Intermediate::edit()
{
  cout << "Enter the definition of the concept: ";
  string temp_def;
  getline(cin, temp_def);
  definition = temp_def;
  cout << "Enter the syntax of the concept: ";
  string temp_syn;
  getline(cin, temp_syn);
  syntax = temp_syn;
}

// @Dev    - function determine if a argument matches the private data member name in 
//           parent class. 
// Args    - string by reference.
// Returns - integer success.
//           0 for a match 
//           + number for post alphabetically
//           - number for pre alphabetically
int Intermediate::match(const string & to_match)
{
  return Concept::match(to_match);
}

// @Dev    - returns a copy of private data member "name" from parent class. 
// Args    - None.
// Returns - string.
string Intermediate::get_name()
{
  return Concept::get_name();
}


// Advanced Class
// ==========================================================

// Default constructor.
Advanced::Advanced(): Concept(){}

// Parameterized constructor.
Advanced::Advanced(const string & arg_syntax, const string& arg_name): Concept(arg_name), syntax(arg_syntax){}

// Copy constructor.
Advanced::Advanced(const Advanced & to_copy): Concept(to_copy), syntax(to_copy.syntax)
{
  if (!to_copy.language_list.empty())
  {
    for (auto it = to_copy.language_list.begin(); it != to_copy.language_list.end(); ++it)
      language_list.push_front(*it);
  }
}

// Destructor.
Advanced::~Advanced(){}

// Assignment operator. 
Advanced & Advanced::operator= (const Advanced & src)
{
  if (this == &src)
    return *this;
  Concept::operator=(src);
  syntax = src.syntax;
  if (!src.language_list.empty())
  {
    for (auto it = src.language_list.begin(); it != src.language_list.end(); ++it)
      language_list.push_front(*it);
  }
  return *this;
}

// @Dev    - display function outputs all private data members. 
// Args    - None.
// Returns - None.
void Advanced::display() const
{
  Concept::display();
  cout << "Syntax: " << syntax << endl;
  cout << "Languages that support this concept: ";
  if (!language_list.empty())
  {
    cout << *language_list.begin();
    for (auto it = ++language_list.begin(); it != language_list.end(); ++it)
      cout << ", " << *it;
  }
  cout << endl;
}

// @Dev    - function to read in private data members for entire hierarchy. 
// Args    - None.
// Returns - None.
void Advanced::read_in()
{
  Concept::read_in();
  cout << "Enter the syntax of the concept: ";
  string temp_syn;
  getline(cin, temp_syn);
  syntax = temp_syn;
}

// @Dev    - function to read in private data members for the classes scope(no parent data). 
// Args    - None.
// Returns - None.
void Advanced::edit()
{
  cout << "Enter the syntax of the concept: ";
  string temp_syn;
  getline(cin, temp_syn);
  syntax = temp_syn;
}

// @Dev    - function determine if a argument matches the private data member name in 
//           parent class. 
// Args    - string by reference.
// Returns - integer success.
//           0 for a match 
//           + number for post alphabetically
//           - number for pre alphabetically
int Advanced::match(const string & to_match)
{
  return Concept::match(to_match);
}

// @Dev    - returns a copy of private data member "name" from parent class. 
// Args    - None.
// Returns - string.
string Advanced::get_name()
{
  return Concept::get_name();
}

// @Dev    - UNIQUE function needs downcasting. Adds argument to the private data 
//           data member stl::list "languages". 
// Args    - String by reference.
// Returns - None.
void Advanced::add_language(const string & to_add)
{
  language_list.push_front(to_add);
}

// @Dev    - UNIQUE function needs downcasting. Removes argument from the private 
//           data member stl::list "languages" if present. 
// Args    - String by reference.
// Returns - None.
void Advanced::remove_language(const string & to_remove)
{
  language_list.remove(to_remove);
}


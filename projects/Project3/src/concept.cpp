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
  getline(cin, temp);
  name = temp;
}

void Concept::edit()
{
  string temp;
  cout << "Enter the name of the concept: ";
  getline(cin, temp);
  name = temp;
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

Intro::Intro(): Concept(), example(""), lower_division(1) {}

Intro::Intro(string arg_example, string arg_name): Concept(arg_name), example(arg_example), lower_division(1){}

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
  cout << "Example: " << example << endl;
  if (lower_division)
    cout << "This concept is covered in lower division classes. Refer to your lower division course work for more information." << endl;
  else 
    cout << "This is not covered in lower division courses. Ask a teacher or tutor where to find more information regarding this concept." << endl;
}

void Intro::read_in()
{
  Concept::read_in();
  string temp;
  cout << "Enter an example of the concept: ";
  getline(cin, temp);
  example = temp;
}

void Intro::edit()
{
  string temp;
  cout << "Enter an example of the concept: ";
  getline(cin, temp);
  example = temp;
}

bool Intro::match(const string & to_match)
{
  return Concept::match(to_match);
}

string Intro::get_name()
{
  return Concept::get_name();
}


// Intermediate Class
// ==========================================================

Intermediate::Intermediate(): Concept(), definition(""), syntax(""){}

Intermediate::Intermediate(const Intermediate & to_copy): Concept(to_copy), definition(to_copy.definition), syntax(to_copy.syntax){}

Intermediate::Intermediate(string arg_definition, string arg_syntax, string arg_name): Concept(arg_name), definition(arg_definition), syntax(arg_syntax){}

Intermediate::~Intermediate(){}

Intermediate & Intermediate::operator= (const Intermediate & src)
{
  if (this == &src)
    return *this;
  Concept::operator=(src);
  definition = src.definition;
  syntax = src.syntax;
  return *this;
}

// Self similar functions.
void Intermediate::display() const
{
  Concept::display();
  cout << "Definition: " << definition << endl;
  cout << "Syntax: " << syntax << endl;
}

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

bool Intermediate::match(const string & to_match)
{
  return Concept::match(to_match);
}

string Intermediate::get_name()
{
  return Concept::get_name();
}


// Advanced Class
// ==========================================================

Advanced::Advanced(): Concept(){}

Advanced::Advanced(const Advanced & to_copy): Concept(to_copy), syntax(to_copy.syntax)
{
  if (!to_copy.language_list.empty())
  {
    for (auto it = to_copy.language_list.begin(); it != to_copy.language_list.end(); ++it)
      language_list.push_front(*it);
  }
}

Advanced::Advanced(string & arg_syntax, string arg_name): Concept(arg_name), syntax(arg_syntax){}

Advanced::~Advanced(){}

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

// Self similar functions.
void Advanced::display() const
{
  Concept::display();
  cout << "Syntax: " << syntax << endl;
  cout << "Languages that suppor this concept: ";
  if (!language_list.empty())
  {
    cout << *language_list.begin();
    for (auto it = ++language_list.begin(); it != language_list.end(); ++it)
      cout << ", " << *it;
  }
  cout << endl;
}

void Advanced::read_in()
{
  Concept::read_in();
  cout << "Enter the syntax of the concept: ";
  string temp_syn;
  getline(cin, temp_syn);
  syntax = temp_syn;
}

void Advanced::edit()
{
  cout << "Enter the syntax of the concept: ";
  string temp_syn;
  getline(cin, temp_syn);
  syntax = temp_syn;
}

bool Advanced::match(const string & to_match)
{
  return Concept::match(to_match);
}

string Advanced::get_name()
{
  return Concept::get_name();
}

// Unique functions.
void Advanced::add_language(const string & to_add)
{
  language_list.push_front(to_add);
}

void Advanced::remove_language(const string & to_remove)
{
  language_list.remove(to_remove);
}





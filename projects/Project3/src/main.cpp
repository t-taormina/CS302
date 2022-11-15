// Tyler Taormina
// taormina@pdx.edu 
// November 2022
// CS302 Program 3

#include "concept.h"

string get_language();

int main()
{
  Advanced i1;
  i1.read_in();
  //i1.display();
  Advanced i2;
  i2 = i1;
  Advanced i3(i2);
  if (i3.match(i2.get_name()))
    cout << "Match!" << endl;
  else 
    cout << "No match" << endl;

  //i2.display();
  i3.display();
  for (int i = 0; i < 3; i++)
    i3.add_language(get_language());
  i3.display();
  i3.remove_language(get_language());
  i3.display();
  return 0;
}


string get_language()
{
  cout << "Please enter the name of a programming language: ";
  string temp;
  getline(cin, temp);
  return temp;
}

// Concept testing code
/*
string variable = "Variable";
Concept c1;
Concept c2(variable);
c1.read_in();
Concept c3;
c3 = c2;
c1.display();
c2.display();
c3.display();
if (c3.match(c2.get_name()))
{
  cout << "Passed" << endl;
}
*/


// Derived classes testing code.
/*
Advanced i1;
  i1.read_in();
  //i1.display();
  Advanced i2;
  i2 = i1;
  Advanced i3(i2);
  if (i3.match(i2.get_name()))
    cout << "Match!" << endl;
  else 
    cout << "No match." << endl;

  //i2.display();
  i3.display();
  for (int i = 0; i < 3; i++)
    i3.add_language(get_language());
  i3.display();
  i3.remove_language(get_language());
  i3.display();
*/

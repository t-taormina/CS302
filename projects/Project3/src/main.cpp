// Tyler Taormina
// taormina@pdx.edu 
// November 2022
// CS302 Program 3

#include "concept.h"

int main()
{
  Intermediate i1;
  i1.read_in();
  //i1.display();
  Intermediate i2;
  i2 = i1;
  Intermediate i3(i2);
  if (i3.match(i2.get_name()))
    cout << "Match!" << endl;
  else 
    cout << "No match." << endl;

  //i2.display();
  i3.display();
  return 0;
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

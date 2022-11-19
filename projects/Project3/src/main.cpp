// Tyler Taormina
// taormina@pdx.edu 
// November 2022
// CS302 Program 3

#include "bst.h"

string get_language();
int test_node();

int main()
{
    return test_node();
    //return 0;
}

int test_tree()
{
    Tree t1;
}

int test_node()
{
    Concept c1;
    c1.read_in();
    Concept c2(c1);
    shared_ptr<Concept> c_ptr = std::make_shared<Concept>(c1);
    shared_ptr<Concept> c_ptr2 = std::make_shared<Concept>(c2);
    Node n1(c_ptr);
    n1.set_left(n1.get_base());

    if (n1.get_left())
        cout << "Not Nullptr" << endl;
    else 
        cout << "Nullptr" << endl;
    n1.display();
    n1.display_left();
    
    return 0;
}

string get_language()
{
  cout << "Please enter the name of a programming language: ";
  string temp;
  getline(cin, temp);
  return temp;
}

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
    cout << "No match!" << endl;

  //i2.display();
  i3.display();
  for (int i = 0; i < 3; i++)
    i3.add_language(get_language());
  i3.display();
  i3.remove_language(get_language());
  i3.display();
*/


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

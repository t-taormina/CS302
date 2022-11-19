// Tyler Taormina
// taormina@pdx.edu 
// November 2022
// CS302 Program 3

#include "bst.h"

string get_language();
int test_node();
int test_tree();

int main()
{
    return test_tree();
}

int test_tree()
{
    Concept c1("tyler");
    Concept c2("tyler");
    Concept c3("bob");
    Concept c4("zeek");
    Concept c5("tommy");
    Concept c6("charles");
    Concept c7("bruno");
    Concept c8("kam");
    shared_ptr<Concept> c_ptr = std::make_shared<Concept>(c1);
    shared_ptr<Concept> c_ptr2 = std::make_shared<Concept>(c2);
    shared_ptr<Concept> c_ptr3 = std::make_shared<Concept>(c3);
    shared_ptr<Concept> c_ptr4 = std::make_shared<Concept>(c4);
    shared_ptr<Concept> c_ptr5 = std::make_shared<Concept>(c5);
    shared_ptr<Concept> c_ptr6 = std::make_shared<Concept>(c6);
    shared_ptr<Concept> c_ptr7 = std::make_shared<Concept>(c7);
    shared_ptr<Concept> c_ptr8 = std::make_shared<Concept>(c8);
    
    Tree t1;
    t1.insert(c_ptr);
    t1.insert(c_ptr2);
    t1.insert(c_ptr3);
    t1.insert(c_ptr4);
    t1.insert(c_ptr5);
    t1.insert(c_ptr6);
    t1.insert(c_ptr7);
    t1.insert(c_ptr8);
    int count = t1.display();
    cout << "Number of nodes: " << count << endl;
    return 0;
}

int test_node()
{
    Concept c1("tyler");
    Concept c2("aaron");
    Concept c3("bob");
    Concept c4("zeek");
    Concept c5("tommy");
    Concept c6("charles");
    Concept c7("bruno");
    Concept c8("kam");
    shared_ptr<Concept> c_ptr = std::make_shared<Concept>(c1);
    shared_ptr<Concept> c_ptr2 = std::make_shared<Concept>(c2);
    shared_ptr<Concept> c_ptr3 = std::make_shared<Concept>(c3);
    shared_ptr<Concept> c_ptr4 = std::make_shared<Concept>(c4);
    shared_ptr<Concept> c_ptr5 = std::make_shared<Concept>(c5);
    shared_ptr<Concept> c_ptr6 = std::make_shared<Concept>(c6);
    shared_ptr<Concept> c_ptr7 = std::make_shared<Concept>(c7);
    shared_ptr<Concept> c_ptr8 = std::make_shared<Concept>(c8);
    Node n1(c_ptr);
    int test = n1.compare(c_ptr2);
    cout << test << endl;
    //
    // if (n1.get_left())
    //     cout << "Not Nullptr" << endl;
    // else 
    //     cout << "Nullptr" << endl;
    // n1.display();
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

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
    Intro i1("int x = 0; // x is the variable", "variable");
    shared_ptr<Intro> ptr1 = std::make_shared<Intro>(i1);
    shared_ptr<Concept> c1 = ptr1;

    Intro i2("int q = 0; // q is the variable", "query");
    shared_ptr<Intro> ptr6 = std::make_shared<Intro>(i2);
    shared_ptr<Concept> c6 = ptr6;


    Intermediate in1("A linked list is a collection of nodes that are connect by pointers.", "LL list1;", "linked list");
    shared_ptr<Intermediate> ptr2 = std::make_shared<Intermediate>(in1);
    shared_ptr<Concept> c2 = ptr2;
 

    Advanced a1("Node * ptr; // This would make a pointer to a node object.", "pointer");
    shared_ptr<Advanced> ptr3 = std::make_shared<Advanced>(a1);
    shared_ptr<Concept> c3 = ptr3;

    Advanced a2("Node& ref; // This would make a reference to a Node object.", "zee");
    shared_ptr<Advanced> ptr4 = std::make_shared<Advanced>(a2);
    shared_ptr<Concept> c4 = ptr4;

    Advanced a3("Node& ref; // This would make a reference to a Node object.", "zff");
    shared_ptr<Advanced> ptr5 = std::make_shared<Advanced>(a3);
    shared_ptr<Concept> c5 = ptr5;
    
    /*
    c2->display();
    auto ptr = std::dynamic_pointer_cast<Advanced>(c2);
    ptr->add_language("python");
    ptr->display();
    */
 
    Concept cremove("pointer");
    shared_ptr<Concept> rem = std::make_shared<Concept>(cremove);

    
    Tree t1;
    t1.insert(c3);// pointer
    t1.insert(c2);// LL goes left
    t1.insert(c1);//var goes right
    t1.insert(c4);//zee goes right and then right 
    t1.insert(c5);//zff goes right and then right and then right
    //t1.insert(c6);// query goes right, left, left and  should be root
    cout << endl;
    cout << "DISPLAY" << endl;
    int count = t1.display();
    cout << "Number of nodes: " << count << endl;

    cout << "Removing ";
    rem->display();
    cout << endl;
    t1.remove(rem);
    cout << "DISPLAY" << endl;
    count = t1.display();
    cout << "Number of nodes: " << count << endl;
    cout << "Remove all count" << endl;
    count = t1.remove_all();
    cout << "Number of nodes: " << count << endl;
    return 0;
}

 // 
 //    Concept c1("tyler");
 //    Concept c2("tyler");
 //    Concept c3("bob");
 //    Concept c4("zeek");
 //    Concept c5("tommy");
 //    Concept c6("charles");
 //    Concept c7("bruno");
 //    Concept c8("kam");
 //    shared_ptr<Concept> c_ptr = std::make_shared<Concept>(c1);
 //    shared_ptr<Concept> c_ptr2 = std::make_shared<Concept>(c2);
 //    shared_ptr<Concept> c_ptr3 = std::make_shared<Concept>(c3);
 //    shared_ptr<Concept> c_ptr4 = std::make_shared<Concept>(c4);
 //    shared_ptr<Concept> c_ptr5 = std::make_shared<Concept>(c5);
 //    shared_ptr<Concept> c_ptr6 = std::make_shared<Concept>(c6);
 //    shared_ptr<Concept> c_ptr7 = std::make_shared<Concept>(c7);
 //    shared_ptr<Concept> c_ptr8 = std::make_shared<Concept>(c8);
    // t1.insert(c_ptr2);
    // t1.insert(c_ptr3);
    // t1.insert(c_ptr4);
    // t1.insert(c_ptr5);
    // t1.insert(c_ptr6);
    // t1.insert(c_ptr7);
    // t1.insert(c_ptr8);
    //t1.remove(c_ptr3);
    //count = t1.display();
    //cout << "Number of nodes: " << count << endl;

int test_node()
{
    Intro i1;
    i1.read_in();
    shared_ptr<Concept> cptr = std::make_shared<Intro>(i1);
    Node n1(cptr);
    n1.display();
    // Concept c2("aaron");
    // Concept c3("bob");
    // Concept c4("zeek");
    // Concept c5("tommy");
    // Concept c6("charles");
    // Concept c7("bruno");
    // Concept c8("kam");
    /*
    shared_ptr<Concept> c_ptr = std::make_shared<Concept>(c1);
    shared_ptr<Concept> c_ptr2 = std::make_shared<Concept>(c2);
    shared_ptr<Concept> c_ptr3 = std::make_shared<Concept>(c3);
    shared_ptr<Concept> c_ptr4 = std::make_shared<Concept>(c4);
    shared_ptr<Concept> c_ptr5 = std::make_shared<Concept>(c5);
    shared_ptr<Concept> c_ptr6 = std::make_shared<Concept>(c6);
    shared_ptr<Concept> c_ptr7 = std::make_shared<Concept>(c7);
    shared_ptr<Concept> c_ptr8 = std::make_shared<Concept>(c8);
    */
    
    //int test = n1.compare(c_ptr2);
    //cout << test << endl;
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

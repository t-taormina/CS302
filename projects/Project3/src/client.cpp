// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

#include "client.h"

// This file contains a simple menu interface that could be implemented by the client. All
// functionality included in this portion is functioning. However, not all functions that
// are written are included. With more time I would like to take make use all code that is
// written but unfortunately with a heavy course load time has not permitted.
// =============================================================================

// Program driver.
int run()
{
    welcome();
    Tree tree;
    fill_tree(tree);
    int flag = 1;
    while (flag)
    {
    menu();
    int choice = validate_menu_choice();
    process_main(flag, choice, tree);
    }
    return 0;
}

// Displays main menu.
int menu()
{
   std::cout << "==================================================================\n";
   std::cout << "                         MAIN MENU" << std::endl;
   std::cout << "==================================================================\n";
  
   std::cout << "===============================\n";
   std::cout << "1) Display all terms.\n"; 
   std::cout << "2) Remove a term.\n"; 
   std::cout << "3) Add a term.\n";
   std::cout << "4) Add a laguage to an advanced term.\n";
   std::cout << "5) Delete entire tree.\n";
   std::cout << std::endl;
   std::cout << "0) Exit Program\n";
   std::cout << "Enter: ";
   return 0;
}

int concept_menu()
{
    cout << "What kind of term would you like to enter into the data structure?" << endl;
    std::cout << "===============================\n";
    std::cout << "1) Enter an introductory term.\n"; 
    std::cout << "2) Enter an intermediate term.\n"; 
    std::cout << "3) Enter an advanced term.\n";
    std::cout << std::endl;
    std::cout << "0) Exit Program\n";
    std::cout << "Enter: ";
    return 0;
}

// Validates main menu choice. 
int validate_menu_choice()
{
  int menu_choice_int = 0;
  cin >> menu_choice_int;
  std::cin.ignore(100, '\n');
 
  while (menu_choice_int > 5 || menu_choice_int < 0) 
  {
    cout << "Please select a valid menu item." << endl;
    cin >> menu_choice_int;
    std::cin.ignore(100, '\n');
  }
  return menu_choice_int;
}

// Validates submenu choice. 
int validate_sub_choice()
{
  int menu_choice_int = 0;
  cin >> menu_choice_int;
  std::cin.ignore(100, '\n');
 
  while (menu_choice_int > 3 || menu_choice_int < 0) 
  {
    cout << "Please select a valid menu item." << endl;
    cin >> menu_choice_int;
    std::cin.ignore(100, '\n');
  }
  return menu_choice_int;
}


// Provides option processing for the menu 
void process_main (int& flag, int menu_choice, Tree& tree)
{
  // Takes in user input for menu choice and calls the appropriate function.
  int no = 0;
  int proceed = 1;
  switch(menu_choice)
    {
      case 0:
        {
          cout << "Are you sure you want to exit?" << endl;
          proceed = no;
          break;
        }
 
      // Display all nodes.
      case 1: 
        {
            cout << "DISPLAYING ALL NODES IN THE TREE. PRESS ENTER:";
            cin.ignore();
            cout << endl;
            int empty = tree.display();
            if (!empty)
                cout << "EMPTY TREE" << endl;
            break;
        }

      // Remove a term from the tree.
      case 2:
        {
            cout << "Please enter the name of the item that you would like to remove: ";
            string arg;
            get_string(arg);
            Concept remove_me(arg);
            shared_ptr<Concept> rem = std::make_shared<Concept>(remove_me);
            int check = tree.remove(rem);
            if (!check)
                cout << "Item successfully removed." << endl;
            else cout << "Item not found." << endl;
            break;         
        }

      // Add a term to the tree.
      case 3: 
        {
            cout << "What kind of concept would you like to build?" << endl;
            concept_menu();
            int choice = validate_sub_choice();
            process_sub(flag, choice, tree);
            break;
        }

        // Delete the entire tree.
      case 4: 
        { 
            cout << "Please enter the name of an advanced concept to add a programming languge that supports the concept: ";
            string arg;
            get_string(arg);
            cout << "Please enter the name of the language: ";
            string lang;
            get_string(lang);
            Concept c(arg);
            shared_ptr<Concept> ptr = std::make_shared<Concept>(c);
            tree.add_language(ptr,lang);
            break;
        }


      // Delete the entire tree.
      case 5: 
        {
            tree.remove_all();
            break;
        }

      // Provide a backstop for out of bounds menu choices.
      default:
        {
            cout << "Not implemented" << endl;
            break;
        }
    }

    if (proceed == no)
    {
      cout << "Enter 0 to end program.\n" << endl;
      cout << "Enter any other number to continue program.\n" << endl;
      cin >> flag;
      cin.ignore(100, '\n');
    }
}

void process_sub(int& flag, int menu_choice, Tree& tree)
{
  // Takes in user input for menu choice and calls the appropriate function.
  int no = 0;
  int proceed = 1;
  switch(menu_choice)
    {
      case 0:
        {
          cout << "Are you sure you want to exit?" << endl;
          proceed = no;
          break;
        }
 
      // Intro .
      case 1: 
        {
            cout << "Please enter the name of the concept: ";
            string name;
            get_string(name);
            cout << "Please enter an example of the concept: ";
            string example;
            get_string(example);

            Intro i(example, name);
            shared_ptr<Intro> ptr = std::make_shared<Intro>(i);
            shared_ptr<Concept> cptr = ptr;
            tree.insert(cptr);
            break;
        }

      // Intermediate.
      case 2:
        {
            cout << "Please enter the name of the concept: ";
            string name;
            get_string(name);
            cout << "Please enter the syntax for the concept: ";
            string syntax;
            get_string(syntax);
            cout << "Please enter the definition of the concept: ";
            string def;
            get_string(def);

            Intermediate i(def, syntax, name);
            shared_ptr<Intermediate> ptr = std::make_shared<Intermediate>(i);
            shared_ptr<Concept> cptr = ptr;
            tree.insert(cptr);
            break;
        }

      // Advanced.
      case 3: 
        {
            cout << "Please enter the name of the concept: ";
            string name;
            get_string(name);
            cout << "Please enter the syntax for the concept: ";
            string syntax;
            get_string(syntax);
            Advanced i(syntax, name);
            shared_ptr<Advanced> ptr = std::make_shared<Advanced>(i);
            shared_ptr<Concept> cptr = ptr;
            tree.insert(cptr);
            break;
        }

      // Provide a backstop for out of bounds menu choices.
      default:
        {
            cout << "Not implemented" << endl;
            break;
        }
    }

    if (proceed == no)
    {
      cout << "Enter 0 to end program.\n" << endl;
      cout << "Enter any other number to continue program.\n" << endl;
      cin >> flag;
      cin.ignore(100, '\n');
    }
}


// Fills DLL with skiing objects. Small for testing purposes.
int fill_tree(Tree& tree)
{
    Intro i1("int x = 0; // x is the variable", "variable");
    shared_ptr<Intro> ptr1 = std::make_shared<Intro>(i1);
    shared_ptr<Concept> c1 = ptr1;

    Intermediate in1("A linked list is a collection of nodes that are connect by pointers.", "LL list1;", "linked list");
    shared_ptr<Intermediate> ptr2 = std::make_shared<Intermediate>(in1);
    shared_ptr<Concept> c2 = ptr2;

    Advanced a1("Node * ptr; // This would make a pointer to a node object.", "pointer");
    shared_ptr<Advanced> ptr3 = std::make_shared<Advanced>(a1);
    shared_ptr<Concept> c3 = ptr3;

    Advanced a2("dynamic_cast<Data*>(ptr);", "dynamic cast");
    shared_ptr<Advanced> ptr4 = std::make_shared<Advanced>(a2);
    shared_ptr<Concept> c4 = ptr4;

    Advanced a3("Node::Node(const Node& src): left(src.left), right(src.right), data(src.data){}", "initialization list");
    shared_ptr<Advanced> ptr5 = std::make_shared<Advanced>(a3);
    shared_ptr<Concept> c5 = ptr5;
 
    Intro i2("bool x = true; // Boolean values can be true or false.", "boolean");
    shared_ptr<Intro> ptr6 = std::make_shared<Intro>(i2);
    shared_ptr<Concept> c6 = ptr6;
 
    Intermediate in2("A for loop is a form of control flow that allows iteration.", "for(int i = 0; i < 10; i++) //{do stuff here}", "for-loop");
    shared_ptr<Intermediate> ptr7 = std::make_shared<Intermediate>(in2);
    shared_ptr<Concept> c7 = ptr7;

    Intro i3("float y = 0; // y is the variable of type float", "float");
    shared_ptr<Intro> ptr8 = std::make_shared<Intro>(i3);
    shared_ptr<Concept> c8 = ptr8;

    tree.insert(c1);
    tree.insert(c2);
    tree.insert(c3);
    tree.insert(c4);
    tree.insert(c5);
    tree.insert(c6);
    tree.insert(c7);
    tree.insert(c8);
    return 0;
}

int get_string(string& arg)
{
    getline(cin, arg);
    return 0;
}

// Displays welcome message.
int welcome()
{
  cout << "Hello!\n" << endl;
  cout << "Welcome to a data structure that holds information about computer science." << endl;
  cout << "This data structure is built as a binary tree and has the ability to hold information that falls into 1 of 3 categories." << endl;
  cout << "The categories are: Introductory, Intermediate, and Advanced." << endl;
  cout << "There are some terms already added into the tree but feel free to add any terms that are helpful to you!" << endl;
  cout << endl;
  cout << "Press enter to continue: " << endl;
  cin.ignore();
  return 0;
}


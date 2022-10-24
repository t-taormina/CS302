// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1 CS302

#include "data_structures.h"
#include <iostream>
using namespace std;

// ALL Class
// ==============================================

// Parameterized constructor that takes an integer argument and creates the table
// array with a length of the argument passed.
ALL::ALL(int size)
{
  table = new Node* [size];
  table_size = size;
  current_index = 0;
  for (int i = 0; i < table_size; i++)
    (*(table + i)) = nullptr; // Dereference the head node for each index and set it to null
                              // so each head pointer is set to null in the array.
}

// Deconstructor (calls remove all function)
ALL::~ALL(void) 
{
  for (int i = 0; i < table_size; i++)
  {
    if ((*(table + i)) != nullptr)
    {
      int num_del = remove_all( (*(table + i)) );
      cout << "Nodes deleted: " << num_del << endl;
    }
    (*(table + i)) = nullptr;
  }
  delete [] table;
  table = nullptr;
  current_index = 0;
}

// @Dev - (PRIVATE) Removes all nodes stored in the table.
// Args -> Node object by reference.
// Returns -> Integer count of nodes deleted from each index.
int ALL::remove_all(Node*& current)
{
  if (!current)
    return 0;
  Node* temp = current->get_next();
  delete current;
  current = nullptr;
  return 1 + remove_all(temp);
}

// @Dev - Inserts node object to the next available index in the array.
// Args -> Node object by reference.
// Returns -> Current index to indicate success.
int ALL::insert(Node& to_add)
{
  if (!to_add.is_valid())
    return 0;
  if (current_index == 6)
    current_index = 0;

  // Head is null case.
  if (*(table + current_index) == nullptr)
  {
    (*(table + current_index)) = new Node;
    (*(table + current_index))->copy_node(to_add);
    (*(table + current_index))->set_next(nullptr);
    (*(table + current_index))->set_position(current_index);
    cout << "Card added at index: " << current_index << endl;
  }

  // Head is not null case.
  else
  {
    Node* temp = (*(table + current_index));
    (*(table + current_index)) = new Node;
    (*(table + current_index))->copy_node(to_add);
    (*(table + current_index))->set_next(temp);
    (*(table + current_index))->set_position(current_index);
    cout << "Card added at index: " << current_index << endl;
  }
  current_index++;
  return current_index;
}

// @Dev - .
// Args -> .
// Returns -> .
int ALL::retrieve()
{
  return 1;
}

// @Dev - Displays all nodes stored in the array. Calls recursive display all function.
// Args -> None.
// Returns -> Integer for success or failure.
int ALL::display_all(void)
{
  for (int i = 0; i < table_size; i++)
  {
    if ( (*(table + i)) != nullptr)
      display_all((*(table + i)));
  }
  return 1;
}

// @Dev - (PRIVATE) Displays all nodes stored in the array.
// Args -> Node object by reference.
// Returns -> Integer count of nodes being deleted for each linked list. 
int ALL::display_all(Node*& current)
{
  if (!current)
    return 0;
  current->display();
  return 1 + display_all(current->get_next());
}

// @Dev - Displays all nodes at the head of each index.
// Args -> None.
// Returns -> Integer for success or failure.
int ALL::display_current_hand()
{
  for (int i = 0; i < table_size; i++)
  {
    if ( (*(table + i)) != nullptr)
      (*(table + i))->display();
  }
  return 1;
}


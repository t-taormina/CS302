// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1 CS302
#include "data_structures.h"

// CLL Class: line 66
// ALL Class: line 199

// Node Class
// ==============================================

// Default Constructor
Node::Node(): Card(), next(nullptr){}

// Parameterized Constructor
Node::Node(int arg_value, int arg_suit): Card(arg_value, arg_suit), next(nullptr) {}

// Deconstructor
Node::~Node(){}

// Returns the "next" member.
Node*& Node::get_next()
{
  return next;
}

// @Dev - Sets the next data members with argument.
// Args -> Takes a node pointer.
// Returns -> None.
void Node::set_next(Node* new_next)
{
  next = new_next;
}

// @Dev - Determines if a node has a next pointer.
// Args -> None.
// Returns -> True if there is a pointer.
//            False if there is not a pointer.
bool Node::has_next() const
{
  bool check = false;
  if(next)
    check = true;
  return check;
}

// @Dev - Takes a node object and copies its data members.
// Args -> Node object by reference.
// Returns -> Integer for success.
int Node::copy_node(Node& source)
{
  next = source.next;
  value = source.value;
  suit = source.suit;
  position = source.position;
  individual = source.individual;
  community = source.community;
  return 1;
}

// CLL Class
// ==============================================

// Default Constructor
CLL::CLL(void): rear(nullptr) {}

// Deconstructor
// Calls the remove_all() function.
CLL::~CLL(void)
{
  remove_all();
}
    
// @Dev - Builds the circular linked list.
// Args -> None.
// Returns -> Integer count for the number of cards added to the deck.
int CLL::build_deck()
{
  int success = 0;
  for (int i = 0; i < 13; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (!rear)
      {
        rear = new Node(i, j);
        rear->set_next(rear);
      }
      else
      {
        Node* temp = rear->get_next();
        Node* n_node = new Node(i,j);
        rear->set_next(n_node);
        rear = rear->get_next();
        rear->set_next(temp);
      }
      success += 1;
    }
  }
  return success;
}

// @Dev - Adds a node to the circular linked list.
// Args -> Node by reference.
// Returns -> Integer success.
int CLL::add_node(Node& to_add)
{
  if (!rear)
  {
    rear = new Node();
    rear->copy_node(to_add);
    rear->set_next(rear);
  }
  else
  {
    Node* temp = rear->get_next();
    Node* add = new Node();
    add->copy_node(to_add);
    rear->set_next(add);
    add->set_next(temp);
  }
  return 1;
}
 
// @Dev - Removes a node from the circular linked list.
// Args -> Node by reference.
// Returns -> 0 Failure - Empty list(Invalid Node)
//            1 Success - Valid Node
int CLL::draw_card(Node& to_remove)
{
  if (!rear)
    return 0; // node remains empty 
  if (rear->get_next() == rear)
  {
    to_remove.copy_node(*rear);
    delete rear;
    rear = nullptr;
    return 1;
  }
  Node* temp = rear->get_next()->get_next();
  to_remove.copy_node(*rear->get_next());
  delete rear->get_next();
  rear->set_next(temp);
  return 1;
}

// @Dev - Removes all nodes from the circular linked list.
// Args -> None.
// Returns -> Integer amount of cards removed.
int CLL::remove_all()
{
  if (!rear)
    return 0;
  return remove_all(rear->get_next());
}

// @Dev - (PRIVATE) Removes all nodes from the circular linked list.
// Args -> Node pointer by reference.
// Returns -> Integer amount of cards removed.
int CLL::remove_all(Node*& curr)
{
  if (curr == this->rear)
  {
    delete curr;
    curr = nullptr;
    return 1;
  }
  Node* temp = curr->get_next();
  delete curr;
  curr = nullptr;
  return 1 + remove_all(temp);
}

// @Dev - Displays all nodes from the circular linked list.
// Args -> None.
// Returns -> Integer amount of cards displayed.
int CLL::display(void)
{
  return display(rear->get_next());
}

// @Dev - (PRIVATE) Displays all nodes from the circular linked list.
// Args -> Node pointer by reference.
// Returns -> Integer amount of cards displayed.
int CLL::display(Node*& current)
{
  if (current == this->rear)
  {
    current->display();
    return 1;
  }
  current->display();
  return 1 + display(current->get_next());
}


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
      remove_all( (*(table + i)) );
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
  }

  // Head is not null case.
  else
  {
    Node* temp = (*(table + current_index));
    (*(table + current_index)) = new Node;
    (*(table + current_index))->copy_node(to_add);
    (*(table + current_index))->set_next(temp);
    (*(table + current_index))->set_position(current_index);
  }
  current_index++;
  return current_index;
}

// @Dev - Calculates points earned based on card suit.
// Args -> Integer representing index location of card to check.
// Returns -> Integer for points earned.
int ALL::score(int index)
{
  return (*(table + index))->point_conversion();
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
int ALL::display_hand()
{
  for (int i = 0; i < table_size; i++)
  {
    if ( (*(table + i)) != nullptr)
      (*(table + i))->display();
  }
  return 1;
}


// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1 CS302
#include "data_structures.h"

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


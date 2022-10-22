// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

#include "data_structures.h"

// Node Class
// ==============================================
Node::Node(): Card(), next(nullptr){}

Node::Node(int arg_value, int arg_suit): Card(arg_value, arg_suit), next(nullptr) {}

/*
Node::Node(const Node& source): Card(source)
{
  next = source.get_next();
}
*/

Node::~Node(){}

Node*& Node::get_next()
{
  return next;
}

void Node::set_next(Node* new_next)
{
  next = new_next;
}

bool Node::has_next() const
{
  bool check = false;
  if(next)
    check = true;
  return check;
}

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
CLL::CLL(void): rear(nullptr) {}

CLL::~CLL(void)
{
  remove_all();
}
    
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

int CLL::add_card(Node*& card_to_add)
{
  return 1;
}
    
// remove next card (more like stack than a CLL)
// if a card has a rear pointer then the deck was not empty
// use this as a determinant for the empty list case
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

int CLL::remove_all()
{
  if (!rear)
    return 0;
  return remove_all(rear->get_next());
}

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

int CLL::display(void)
{
  return display(rear->get_next());
}

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


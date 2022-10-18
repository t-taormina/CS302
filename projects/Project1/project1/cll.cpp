// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

#include "data_structures.h"

// Node Class
// ==============================================
Node::Node(): next(nullptr){}

Node::Node(card_value arg_value, card_suit arg_suit): Card(arg_value, arg_suit), next(nullptr) {}

Node::~Node(){}

Node::Node*& get_next()
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



// CLL Class
// ==============================================
CLL::CLL(void){}
CLL::~CLL(void){}
    
int CLL::add_card(Card& card_to_add){}
    
// remove next card (more like stack than a CLL)
Card CLL::draw_card(){}

// not useful for this game
Card CLL::retireve_card(Card& to_remove){}
int CLL::remove_all(){}
int CLL::display(void){}



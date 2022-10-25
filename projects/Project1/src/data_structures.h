// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1 CS302

#ifndef CLL_H
#define CLL_H

#include "piece.h"
#include <iostream>
using namespace std;

// This file contains the headers for the data structures used in the game. There is
// a Node class, a Circular Linked List (CLL), and an Array of Linear Linked Lists(ALL).
// All function definitions are found in data_structures.cpp.
//================================================================================
 

class Node: public Card
{
  public:
    // Default constructor
    Node();
    // Parameterized constructor
    Node(int arg_value, int arg_suit);
    // Deconstructor
    ~Node();
    // Return next pointer.
    Node*& get_next();
    //Update next pointer with prefilled argument. Null argument results in no change.
    void set_next(Node* new_next);
    //Copies argument unless you pass a node to itself.
    int copy_node(Node& source);
    //Returns if there is a next pointer.
    bool has_next() const;

  protected:
    Node* next;
};


class CLL 
{
  public:
    // Default constructor
    CLL(void);
    // Deconstructor
    ~CLL(void);
    // Deletes all nodes using recursion and a private remove all function.
    int remove_all();
    // Fills deck to a standard 52 card deck.
    int build_deck();
    // Allows prefilled cards to be added to the deck. Null cards will not be added.
    int add_node(Node& card_to_add);
    // Removes a card.
    int draw_card(Node& to_remove);
    // Displays card suit and value.
    int display(void);

  private:
    // Private recursive call to display.
    int display(Node*& current);
    // Private recursive call to delete all nodes.
    int remove_all(Node*& curr);
    Node* rear;
};


class ALL
{
   public:
    // Default constructor with table size argument.
    // Given the logic of the game, this variable is provided as a constant.
    ALL(int size);
    // Deconstructor 
    ~ALL(void);
    // Adds prefilled node to the table in the next open space (current_index). 
    int insert(Node& to_add);
    // Scores the card at a given index. Index will be checked for appropriate bounds
    // prior to passing as argument.
    int score(int index);
    // Calls private recursive function to display all nodes.
    int display_all(void);
    // Displays all head nodes in table.
    int display_hand();
    // Calls private recursive function to delete all nodes.
    int remove_all();

  private:
    // Table array pointer.
    Node ** table;
    int table_size;
    // Index maintainer to ensure cards are dispersed evenly to the ALL.
    int current_index;
    // Private recursive call to display.
    int display_all(Node*& current);
    // Private recursive call to delete all nodes.
    int remove_all(Node*& current);
};

#endif


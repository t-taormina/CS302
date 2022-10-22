// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

#ifndef CLL_H
#define CLL_H
#include "pawn.h"


class Node: public Card
{
  public:
    Node();
    Node(int arg_value, int arg_suit);
    //Node(Node& source);
    ~Node();
    Node*& get_next();
    void set_next(Node* new_next);
    int copy_node(Node& source);
    bool has_next() const;

  protected:
    Node* next;
};


class CLL 
{
  public:
    CLL(void);
    ~CLL(void);

    int remove_all();
    int build_deck();
    int add_node(Node& card_to_add);

    // replacing my retrieve method as per project requirements
    // copies node and removes from linked list
    int draw_card(Node& to_remove);

    int display(void);

  private:
    int display(Node*& current);
    int remove_all(Node*& curr);
    Node* rear;
};

/*
class ALL: public Card
{
   public:

    // Parameterized constructor that takes an integer argument and creates the table
    // array with a length of the argument passed.
    ALL(int size);

    // Deconstructor
    ~ALL(void);

    int insert(Card& to_add);

    // Takes a character array of a name to match and an array where matches will be stored.
    int retrieve();

    // Displays all items stored in the hash table.
    int display_all(void);

    // Displays all items that have a TYPE matching the argument supplied character array.
    int display_current_hand();

    // Removes all cards.
    int remove_all();
    
  // ===============================================================================================

  private:
    Node ** ALL;
    int  table_size;
};
*/

#endif


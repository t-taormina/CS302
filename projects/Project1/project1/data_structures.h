// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

#ifndef CLL_H
#define CLL_H

#include "pawn.h" // contains card headers


class Node: public Card
{
  public:
    Node();
    ~Node();
    Node*& get_next();
    void set_next(Node* new_next);

  protected:
    Node* next;
};


class CLL 
{
  public:
    CLL(void);
    ~CLL(void);
    
    int add_card(Card& card_to_add);
    
    // remove next card (more like stack than a CLL)
    Card draw_card();

    // not useful for this game
    Card retireve_card(Card& to_remove);
    int remove_all();
    int display(void);

  private:
    int display(cll_node * current, cll_node * end);
    Node * rear;
};


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

#endif


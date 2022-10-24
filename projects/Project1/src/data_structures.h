// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1 CS302

#ifndef CLL_H
#define CLL_H
#include "piece.h"

// Contains headers for the node, circular linked list, and the array of 
// linked list classes.
//================================================================================

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
    int draw_card(Node& to_remove);
    int display(void);

  private:
    int display(Node*& current);
    int remove_all(Node*& curr);
    Node* rear;
};


// Table Size

class ALL
{
   public:
    ALL(int size);
    ~ALL(void);

    int insert(Node& to_add);
    int score(int num);
    int display_all(void);
    int display_hand();
    int remove_all();

  private:
    Node ** table;
    int current_index;
    int display_all(Node*& current);
    int table_size;
    int remove_all(Node*& current);
};

#endif


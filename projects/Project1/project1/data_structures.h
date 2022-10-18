// Tyler Taormina CS163
// June, 2022
// Program 2- Stack and queues at the Fair


// QUEUE CLASS 
// ========================
// An Queue instance has 1 member. 
// - Q_node -> struct that holds an event object as well as a pointer to another q_node.
//           rear -> pointer to the rear node in a circular linear linked list
// 
// - This class uses a circular linear linked list as its data structure. The rear represents 
// the back of the queue. The rear node holds a pointer that points to the "top" or front of 
// the queue. Nodes are enqueued at the rear and dequeued at the top.


#ifndef QUEUE_H
#define QUEUE_H

#include "event.h"


class cll_node
{
  public:
    cll_node();
    ~cll_node();


  protected:
    Card card;
    cll_node * next;
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
    int display(q_node * current, q_node * end);
    q_node * rear;
};


class ALL
{
  public:



  protected: 

};

#endif


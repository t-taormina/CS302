// Tyler Taormina
// taormina@pdx.edu 
// November 2022
// CS302 Program 3


// This file contains the signatures for the node and data structure used in 
// this program. The data structure is a binary search tree with a shared_ptr
// used for the root node. The node class also contains shared_ptr's and has 
// a left and right node along with a base class share_ptr ( A concept pointer).
// This concept pointer is used for dynamic binding and allows storage of 
// differing data types within the same tree. The only downcasting that I used
// at this point is in the add language function in the binary search tree class. 
// The downcasting allows the calling of a function that is unique to the 
// advanced concpet class. I am not very familiar with smart pointers so if you 
// see anything that could be improved on, please don't hesitate to let me know!
// =============================================================================


#ifndef NODE_H
#define NODE_H
#include "concept.h"
#include <memory>
using std::shared_ptr;

class Node
{
    public:
        Node();
        Node(const Concept& obj);
        Node(const Node& to_copy);
        ~Node();
        Node& operator=(const Node& arg);
        Node(shared_ptr<Concept> concept_ptr);

        int display();
        int compare(const shared_ptr<Concept>& Cptr);
        shared_ptr<Node>& get_left();
        int set_left(const shared_ptr<Concept>& ptr);
        shared_ptr<Node>& get_right();
        int set_right(const shared_ptr<Concept>&  ptr);
        shared_ptr<Concept> get_base();
        int set_base(const shared_ptr<Concept>& ptr);

    private:
        shared_ptr<Concept> base_ptr;
        shared_ptr<Node> left;
        shared_ptr<Node> right;
};


class Tree
{
    public:
        Tree();
        ~Tree();

        int insert(shared_ptr<Concept> Cptr);
        int display();
        int remove(shared_ptr<Concept> ptr);
        int add_language(shared_ptr<Concept> ptr, string& to_add);
        int remove_all();

    private:
        int insert(shared_ptr<Concept> Cptr, shared_ptr<Node>& curr);
        int display(shared_ptr<Node> curr);
        int remove(shared_ptr<Concept> ptr, shared_ptr<Node>& curr, int& flag);
        int add_language(shared_ptr<Concept> ptr, shared_ptr<Node>& curr, string& to_add);
        int remove_all(shared_ptr<Node> & curr);
        int in_order_successor(shared_ptr<Node>& to_replace, shared_ptr<Node>& curr);
        shared_ptr<Node> root;
};

#endif

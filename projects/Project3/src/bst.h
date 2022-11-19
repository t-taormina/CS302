// Tyler Taormina
// taormina@pdx.edu 
// November 2022
// CS302 Program 3

#ifndef NODE_H
#define NODE_H
#include "concept.h"
#include <memory>
#include <string>
using std::shared_ptr;

class Node
{
    public:
        Node();
        Node(shared_ptr<Concept> concept_ptr);
        //Node(const Node & to_copy);
        //Node & operator=(const Node & src);
        ~Node();

        int display();
        int display_left();
        shared_ptr<Node> get_left();
        int set_left(shared_ptr<Concept> ptr);
        shared_ptr<Node> get_right();
        int set_right(shared_ptr<Concept> ptr);
        shared_ptr<Concept> get_base();

    private:
        shared_ptr<Concept> base_ptr;
        shared_ptr<Node> left;
        shared_ptr<Node> right;
};


class Tree
{
    public:
        Tree();
        Tree(const Tree & to_copy);
        Tree & operator=(const Tree & src);
        ~Tree();

        insert(shared_ptr<Concept> Cptr);
        remove(shared_ptr<Concept> ptr);
        remove_all();
        display();



    private:
        insert(shared_ptr<Concept> Cptr, shared_ptr<Node> curr);
        shared_ptr<Node> root;
};

#endif
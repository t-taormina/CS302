// Tyler Taormina
// taormina@pdx.edu 
// November 2022
// CS302 Program 3

#include "bst.h"


// Node class
// ================================================================

Node::Node(): base_ptr(nullptr), left(nullptr), right(nullptr){}

Node::Node(shared_ptr<Concept> concept_ptr): left(nullptr), right(nullptr)
{
    base_ptr = std::move( concept_ptr );
}

//Node::Node(const Node & to_copy){}

//Node & Node::operator=(const Node & src){}

Node::~Node()
{
    base_ptr.reset();
    left.reset();
    right.reset();
}

int Node::display()
{
    if (base_ptr)
        base_ptr->display();
    return 0;
}

int Node::display_left()
{
    if (left)
        left->display();
    return 0;
}

shared_ptr<Node> Node::get_left()
{
    return left;
}

int Node::set_left(shared_ptr<Concept> ptr)
{
    left = std::make_shared<Node>( Node(ptr) );
    return 0;
}

shared_ptr<Node> Node::get_right()
{
    return right;
}

int Node::set_right(shared_ptr<Concept> ptr)
{
    right = std::make_shared<Node>( Node(ptr) );
    return 0;
}

shared_ptr<Concept> Node::get_base()
{
    return base_ptr;
}


// ================================================================


// Tree Class
// ================================================================

Tree::Tree(): root(nullptr){}

Tree::Tree(const Tree & to_copy){}

Tree & Tree::operator=(const Tree & src){}

Tree::~Tree(){}

Tree::insert(shared_ptr<Concept> Cptr){}

//PRIVATE RECURSIVE METHOD
Tree::insert(shared_ptr<Concept> Cptr, shared_ptr<Node> curr)
{
}

Tree::remove(shared_ptr<Concept> ptr){}

Tree::remove_all(){}

Tree::display()
{}

//PRIVATE RECURSIVE METHOD
Tree::display(shared_ptr<Node> curr)
{}



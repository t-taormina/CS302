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

int Node::compare(shared_ptr<Concept> Cptr)
{
    return base_ptr->match(Cptr->get_name());
}

shared_ptr<Node>& Node::get_left()
{
    return left;
}

int Node::set_left(shared_ptr<Concept> ptr)
{
    left = std::make_shared<Node>( Node(ptr) );
    return 0;
}

shared_ptr<Node>& Node::get_right()
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

//WRAPPER FOR RECURSIVE METHOD
int Tree::insert(shared_ptr<Concept> Cptr)
{
    return insert(Cptr, root);
}

//PRIVATE RECURSIVE METHOD
int Tree::insert(shared_ptr<Concept> Cptr, shared_ptr<Node>& curr)
{
    if (!curr)
    {
        curr = std::make_shared<Node>( Node(Cptr) );
        return 0;
    }
    if (curr->compare(Cptr) < 0)
        return insert(Cptr, curr->get_left()); 
    if (curr->compare(Cptr) > 0)
        return insert(Cptr, curr->get_right());
    else
        return 1;
}

//WRAPPER FOR RECURSIVE METHOD
int Tree::display()
{
    return display(root);
}

//PRIVATE RECURSIVE METHOD
int Tree::display(shared_ptr<Node> curr)
{
    if (!curr)
        return 0;
    int count = 0;
    count = display(curr->get_left());
    curr->display();
    count++;
    return count += display(curr->get_right());
}

//WRAPPER FOR RECURSIVE METHOD
int Tree::remove(shared_ptr<Concept> ptr)
{
    if (!root)
        return 0;
    return remove(ptr, root);
}

int Tree::remove(shared_ptr<Concept> ptr, shared_ptr<Node>& curr)
{
    if (!curr)
        return 0;
    int result = 0;
    result = remove(ptr, curr->get_left());
    result = remove(ptr, curr->get_right());
    if (!curr->compare(ptr))
    {
        // Case with no children.
        if (!curr->get_left() && !curr->get_right())
        {
            curr.reset();
            return 1;
        }

        // Case with one child left.
        else if (curr->get_left() && !curr->get_right())
        {
            curr = std::move( curr->get_left() );
            return 1;
        }

        // Case with one child right.
        else if (!curr->get_left() && curr->get_right())
        {
            curr = std::move( curr->get_right() );
            return 1;
        }

        // Case with two children.
        else
        {
            return 1;
        }
    }
}

int Tree::remove_all(){}


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

Node::Node(const Node& to_copy):base_ptr(to_copy.base_ptr), left(to_copy.left), right(to_copy.right)
{}


Node& Node::operator=(const Node& arg)
{
    base_ptr = arg.base_ptr;
    left = arg.left;
    right = arg.right;
    return *this;
}

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
    cout << endl;
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

int Node::set_base(shared_ptr<Concept> ptr)
{
    base_ptr.reset();
    base_ptr = std::move( ptr );
    return 0;
}
// ================================================================


// Tree Class
// ================================================================

Tree::Tree(): root(nullptr){}

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
            curr.reset();

        // Case with one child left.
        else if (curr->get_left() && !curr->get_right())
            curr = std::move( curr->get_left() );

        // Case with one child right.
        else if (!curr->get_left() && curr->get_right())
            curr = std::move( curr->get_right() );

        // Case with two children.
        else
            in_order_successor(curr, curr->get_right()); 
    }
    return 0;
}


int Tree::in_order_successor(shared_ptr<Node>& to_replace, shared_ptr<Node>& curr)
{
    if (!curr->get_left())
    {
        to_replace->set_base( curr->get_base() );
        curr = std::move( curr->get_right() );
        return 1;
    }
    else return in_order_successor(to_replace, curr->get_left());
}

//WRAPPER FOR RECURSIVE METHOD
int Tree::remove_all()
{
    return remove_all(root);
}

//PRIVATE RECURSIVE METHOD
int Tree::remove_all(shared_ptr<Node> & curr)
{
    if (!curr)
        return 1;
    int count = 0;
    count = 1 + remove_all(curr->get_left());
    count = 1 + remove_all(curr->get_right());
    curr->display();
    curr.reset();
    return count;
}

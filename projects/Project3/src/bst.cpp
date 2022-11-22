// Tyler Taormina
// taormina@pdx.edu 
// November 2022
// CS302 Program 3


// This file contains the implementation for the data structure and nodes used 
// for this program. The data structure is a binary search tree using the 
// shared_ptr smart pointer. This tree supports insertion alphabetically, 
// removal by matching name (case sensitive as of now), full removal, full 
// display, and a "add_language()" function that will add an argument to the 
// stl::list "languages" found in the Advanced concept objects. 
// =============================================================================


#include "bst.h"

// Node class
// =============================================================================

// Default constructor.
Node::Node(): base_ptr(nullptr), left(nullptr), right(nullptr){}

// Parameterized constructor.
Node::Node(shared_ptr<Concept> concept_ptr): left(nullptr), right(nullptr)
{
    base_ptr = std::move( concept_ptr );
}

// Copy constructor.
Node::Node(const Node& to_copy):base_ptr(to_copy.base_ptr), left(to_copy.left), right(to_copy.right)
{}

// Destructor.
Node::~Node()
{
    base_ptr.reset();
    left.reset();
    right.reset();
}

// Assignment operator. 
Node& Node::operator=(const Node& arg)
{
    base_ptr = arg.base_ptr;
    left = arg.left;
    right = arg.right;
    return *this;
}

// @Dev    - displays all items stored in the node data member. 
// Args    - None.
// Returns - Integer success.
int Node::display()
{
    if (base_ptr)
        base_ptr->display();
    cout << endl;
    return 0;
}

// @Dev    - function determine if a argument name matches 
//           the name stored in node data. 
// Args    - constant Concept pointer by reference.
// Returns - integer success.
//           0 for a match 
//           + number for post alphabetically
//           - number for pre alphabetically
int Node::compare(const shared_ptr<Concept>& Cptr)
{
    return base_ptr->match(Cptr->get_name());
}

// @Dev    - returns left child node
// Args    - None.
// Returns - Reference to node pointer.
shared_ptr<Node>& Node::get_left()
{
    return left;
}

// @Dev    - sets left child node to argument passed.
// Args    - constant Concept pointer by reference.
// Returns - Integer success.
int Node::set_left(const shared_ptr<Concept>& ptr)
{
    left = std::make_shared<Node>( Node(ptr) );
    return 0;
}

// @Dev    - returns right child node
// Args    - None.
// Returns - Reference to node pointer.
shared_ptr<Node>& Node::get_right()
{
    return right;
}

// @Dev    - sets left child node to argument passed.
// Args    - constant Concept pointer by reference.
// Returns - Integer success.
int Node::set_right(const shared_ptr<Concept>& ptr)
{
    right = std::make_shared<Node>( Node(ptr) );
    return 0;
}

// @Dev    - returns concept pointer to the private data member. 
// Args    - None.
// Returns - Reference to Concept pointer.
shared_ptr<Concept> Node::get_base()
{
    return base_ptr;
}

// @Dev    - sets data pointer to argument passed.
// Args    - constant Concept pointer by reference.
// Returns - Integer success.
int Node::set_base(const shared_ptr<Concept>& ptr)
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
    if (!root) return 0;
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
    int flag = 0;
    remove(ptr, root, flag);
    return flag;
}

//PRIVATE RECURSIVE METHOD
int Tree::remove(shared_ptr<Concept> ptr, shared_ptr<Node>& curr, int& flag)
{
    if (!curr)
        return 0;
    remove(ptr, curr->get_left(), flag);
    remove(ptr, curr->get_right(), flag);
    if (!curr->compare(ptr))
    {
        flag = 1;
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
        return 1;
    }
    else return 0;
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
    curr.reset();
    return count;
}

//WRAPPER FOR RECURSIVE METHOD
int Tree::add_language(shared_ptr<Concept> ptr, string& to_add)
{
    if (!root)
        return 0;
    return add_language(ptr, root, to_add);
}

//PRIVATE RECURSIVE METHOD
int Tree::add_language(shared_ptr<Concept> ptr, shared_ptr<Node>& curr, string& to_add)
{
    if (!curr)
        return 0;
    int count = 0;
    count = add_language(ptr, curr->get_left(), to_add);
    if (!curr->compare(ptr)) //Down cast.
    {
        shared_ptr<Advanced> ptr = std::dynamic_pointer_cast<Advanced>(curr->get_base());
        if(ptr)
        {
            ptr->add_language(to_add);
            count++;
            return count;
        }
    }
    return count += add_language(ptr, curr->get_right(), to_add);
}


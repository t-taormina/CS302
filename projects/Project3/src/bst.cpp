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

// Node: line 19
// BST: line 130

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

// Default constructor.
Tree::Tree(): root(nullptr){}

// Parameterized constructor.
Tree::~Tree(){}

// @Dev    - wrapper for recursive function call. Inserts argument alphabetically. 
// Args    - Concept pointer.
// Returns - None.
int Tree::insert(const shared_ptr<Concept>& Cptr)
{
    return insert(Cptr, root);
}

// @Dev    - recursive function call. Inserts argument alphabetically. 
// Args    - Concept pointer and a node pointer used for traversal.
// Returns - integer success.
//           0 for successful add.
//           1 if the arg is already in the tree (no duplicates).
int Tree::insert(const shared_ptr<Concept>& Cptr, shared_ptr<Node>& curr)
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

// @Dev    - wrapper for recursive function call to alphabetically display tree. 
// Args    - None.
// Returns - Integer count of all nodes in tree.
int Tree::display()
{
    if (!root) return 0;
    return display(root);
}

// @Dev    - recursive function call to alphabetically display tree. 
// Args    - Node pointer used for traversal and display function call.
// Returns - Integer count of all nodes in tree.
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

// @Dev    - wrapper for recursive function to remove node matching argument passed. 
// Args    - Concept pointer to remove.
// Returns - Integer success.
//           0 for successful removal.
//           1 for no matching node.
int Tree::remove(const shared_ptr<Concept>&  ptr)
{
    if (!root)
        return 0;
    int flag = 1;
    remove(ptr, root, flag);
    return flag;
}

// @Dev    - recursive function to remove node matching argument passed. Uses
//           in_order_successor(...) recursive function. 
// Args    - Concept pointer to remove, node pointer for traversal, and integer 
//           flag for success/fail.
// Returns - Integer success.
//           0 for successful removal.
//           1 for no matching node.
int Tree::remove(const shared_ptr<Concept>& ptr, shared_ptr<Node>& curr, int& flag)
{
    if (!curr)
        return 0;
    remove(ptr, curr->get_left(), flag);
    remove(ptr, curr->get_right(), flag);
    if (!curr->compare(ptr))
    {
        flag = 0;
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

// @Dev    - replaces to_replace node pointer with in order successor data.
// Args    - node pointer that is getting replaced and a node pointer for traversal
//           that will be replacing the to_replace node.
// Returns - Integer success.
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

// @Dev    - wrapper function to call recursive function to remove all nodes.
// Args    - None.
// Returns - Integer success.
int Tree::remove_all()
{
    return remove_all(root);
}

// @Dev    - recursive function to remove all nodes.
// Args    - Node pointer for traversal.
// Returns - Integer success.
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

// @Dev    - wrapper function to call recursive function to remove add string data 
//           to node that matches the concept pointer argument.
// Args    - concept pointer to match and string to add.
// Returns - integer success.
int Tree::add_language(shared_ptr<Concept> ptr, string& to_add)
{
    if (!root)
        return 0;
    return add_language(ptr, root, to_add);
}

// @Dev    - function to remove add string data to node that matches the concept
//           pointer argument. This function uses dynamic casting to call the 
//           unique function "add_language" in Advanced class. If the object 
//           that is matched the variable "ptr" will be set to nullptr and no 
//           function call wii be made. This will leave data structure unchanged.  
// Args    - concept pointer to match, node pointer for traversal, and string to add.
// Returns - integer success.
//           0 unsuccessful 
//           1 success
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


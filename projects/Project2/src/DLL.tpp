// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

// This file contains the implementation of the node and DLL classes which make up the
// data structures used for this program. They are programmed using templates to be used
// with the hierarchy provided in "activity.h". At this point, exception handling is at
// a minimum and could be improved for a safer program. Given the functionality that is
// implemented in the client program provided, this data structure could be expanded with
// different algorithms to provide additional functionality. With more time I would like
// to implement sorting functions, grouping based on data charaterstics, etc. 
// =========================================================================================

#ifndef DLL_TPP
#define DLL_TPP
#include <iostream>
using namespace std;


// Default constructor.
template <typename T>
Node<T>::Node(): prev(nullptr), next(nullptr){}

// Parameterized constructor.
template <typename T>
Node<T>::Node(const T& source): data(source), prev(nullptr), next(nullptr){}

// Copy constructor.
template <typename T>
Node<T>::Node(const Node<T>& source): data(source.data), prev(source.prev), next(source.next){}

// Returns data object stored in the node.
template <typename T>
const T& Node<T>::get_data()
{
  return data;
}

// Sets data object stored in the node.
template <typename T>
void Node<T>::set_data(const T& source)
{
  data = source;
}

// Returns the next data member stored in the node.
template <typename T>
typename Node<T>::ptr & Node<T>::get_next()
{
  return next;
}

// Returns the previous data member stored in the node.
template <typename T>
typename Node<T>::ptr & Node<T>::get_previous()
{
  return prev;
}

// Sets the next data member stored in the node.
template <typename T>
void Node<T>::set_next(const ptr & source)
{
  next = source;
}

// Sets the previous data member stored in the node.
template <typename T>
void Node<T>::set_prev(const ptr & source)
{
  prev = source;
}

// Displays the data member stored. 
template <typename T>
void Node<T>::display() const
{
  this->data.display();
}

// Assigns the data member stored to argument supplied. 
template <typename T>
Node<T>& Node<T>::operator=(const Node<T> & arg)
{
  data = arg.data;
  prev = arg.prev;
  next = arg.next;
  return *this;
}

// Compares calling data to the argments data field. 
template <typename T>
bool Node<T>::less_than(const Node<T> & new_data) const
{
  bool flag = false;
  if (data < new_data.data)
    flag = true;
  return flag;
}

// Compares calling data to the argments data field. 
template <typename T>
bool Node<T>::less_than_or_equal(const Node<T> & new_data) const
{
  bool flag = false;
  if (data <= new_data)
    flag = true;
  return flag;
}

// Compares calling data to the argments data field. 
template <typename T>
bool Node<T>::greater_than(const Node<T> & new_data) const
{
  bool flag = false;
  if (data > new_data.data)
    flag = true;
  return flag;
}

// Compares calling data to the argments data field. 
template <typename T>
bool Node<T>::greater_than_or_equal(const Node<T> & new_data) const
{
  bool flag = false;
  if (data >= new_data.data)
    flag = true;
  return flag;
}

// Compares calling data to the argments data field. 
template <typename T>
bool Node<T>::equal_to(const Node<T> & new_data) const
{
  bool flag = false;
  if (data == new_data.data)
    flag = true;
  return flag;
}

// Compares calling data to the argments data field. 
template <typename T>
bool Node<T>::not_equal_to(const Node<T> & new_data) const
{
  bool flag = false;
  if (data != new_data.data)
    flag = true;
  return flag;
}

//========================================================


// DLL CLASS
//========================================================

// Default constructor.
template <typename T>
DLL<T>::DLL(): head(nullptr), tail(nullptr){}

// Deconstructor.
template <typename T>
DLL<T>::~DLL()
{
  if (!head)
    return;
  remove_all(head);
}

// **PRIVATE**
// Recursive call to remove all nodes in the list.
template <typename T>
void DLL<T>::remove_all(ptr & head)
{
  if (!head)
    return;
  Node<T> * temp = head->get_next();
  delete head;
  head = nullptr;
  return remove_all(temp);
}

// Recursive copy constructor to copy supplied doubly linked list in the params.
template <typename T>
DLL<T>::DLL(const DLL<T>& source)
{
  if (!source.head)
    head = tail = nullptr;
  else
  {
    head = new Node<T>();
    head->set_data(source.head->get_data());
    copy(head->get_next(), head, source.head->get_next());
  }
}

// Assignment operator to assign a DLL object to the supplied DLL in the params.
template <typename T>
DLL<T> & DLL<T>::operator=(const DLL<T> & arg)
{
  if (!arg.head)
    return *this;
  else 
  {
    remove_all(head);
    head = new Node<T>();
    head->set_data(arg.head->get_data());
    copy(head->get_next(), head, arg.head->get_next());
  }
  return *this;
}

// Recursive wrapper to copy DLL supplied in the params. 
template <typename T>
void DLL<T>::copy(const DLL<T> & arg)
{
  if (!arg.head)
    return;
  else 
  {
    remove_all(head);
    head = new Node<T>();
    head->set_data(arg.head->get_data());
    copy(head->get_next(), head, arg.head->get_next());
  }
}
  
// **PRIVATE**
// Recursive copy of entire DLL.
template <typename T>
void DLL<T>::copy(ptr & curr, ptr & prev, const ptr & source)
{
  if (!source)
  {
    tail = prev;
    return;
  }
  curr = new Node<T>();
  curr->set_data(source->get_data());
  curr->set_prev(prev);
  prev->set_next(curr);
  return copy(curr->get_next(), curr, source->get_next());
}

// Inserts nodes at the head.
template <typename T>
void DLL<T>::insert(const T & obj)
{
  Node<T> * node = new Node<T>(obj);
  if (!head)
  {
    head = node;
    return;
  }
  Node<T> * temp = head;
  head = node;
  head->set_next(temp);
  temp->set_prev(head);
}

// Recursive wrapper to display entire list.
template <typename T>
void DLL<T>::display() const
{
  if (!head)
    return;
  return display(head);
}

// **PRIVATE**
// Recursive function that displays entire list.
template <typename T>
void DLL<T>::display(const ptr & curr) const
{
  if (!curr)
    return;
  curr->display();
  return display(curr->get_next());
}

// Wrapper to recursively find and display the node containing the "least" of a given field. 
template <typename T>
void DLL<T>::display_cheapest() 
{
  if (!head)
    return;
  Node<T> * temp = head;
  display_cheapest(temp, head->get_next());
}

// **PRIVATE**
// Recursive function to find and display the node containing the "least" of a given field. 
template <typename T>
void DLL<T>::display_cheapest(ptr& temp, ptr & curr) 
{
  if (!curr)
  {
    temp->display();
    return;
  }
  if (temp->get_data().greater_than((curr->get_data())))
    temp->set_data(curr->get_data());
  display_cheapest(temp, curr->get_next());
}

// Wrapper to recursively find and display the node containing the "highest" of a given field. 
template <typename T>
void DLL<T>::display_highest()
{
  if (!head)
    return;
  Node<T> * temp = head;
  display_highest(temp, head->get_next());
}

// **PRIVATE**
// Recursive function to find and display the node containing the "highest" of a given field. 
template <typename T>
void DLL<T>::display_highest(ptr & temp, ptr & curr)
{
  if (!curr)
  {
    temp->display();
    return;
  }
  if (temp->get_data().less_than((curr->get_data())))
    temp->set_data(curr->get_data());
  display_highest(temp, curr->get_next());
}
#endif

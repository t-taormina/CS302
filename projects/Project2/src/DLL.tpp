// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

#ifndef DLL_TPP
#define DLL_TPP
#include <iostream>
using namespace std;

template <typename T>
Node<T>::Node(): prev(nullptr), next(nullptr){}

template <typename T>
Node<T>::Node(const T& source): data(source), prev(nullptr), next(nullptr){}

template <typename T>
Node<T>::Node(const Node<T>& source): data(source.data), prev(source.prev), next(source.next){}

template <typename T>
typename Node<T>::ptr & Node<T>::get_next()
{
  return next;
}

template <typename T>
typename Node<T>::ptr & Node<T>::get_previous()
{
  return prev;
}

template <typename T>
void Node<T>::set_next(const ptr & source)
{
  next = source;
}

template <typename T>
void Node<T>::set_prev(const ptr & source)
{
  prev = source;
}

template <typename T>
void Node<T>::display() const
{
  this->data.display();
}

template <typename T>
Node<T>& Node<T>::operator=(const Node<T> arg)
{
  if (*this == arg)
    return *this;
  data = arg.data;
  return *this;
}

template <typename T>
bool Node<T>::less_than(const T & new_data) const
{
  bool flag = false;
  if (data < new_data)
    flag = true;
  return flag;
}

template <typename T>
bool Node<T>::less_than_or_equal(const T & new_data) const
{
  bool flag = false;
  if (data <= new_data)
    flag = true;
  return flag;
}

template <typename T>
bool Node<T>::greater_than(const T & new_data) const
{
  bool flag = false;
  if (data > new_data)
    flag = true;
  return flag;
}

template <typename T>
bool Node<T>::greater_than_or_equal(const T & new_data) const
{
  bool flag = false;
  if (data >= new_data)
    flag = true;
  return flag;
}

template <typename T>
bool Node<T>::equal_to(const T & new_data) const
{
  return true;
}

template <typename T>
bool Node<T>::not_equal_to(const T & new_data) const
{
  return true;
}


//========================================================



// DLL CLASS
//========================================================

template <typename T>
DLL<T>::DLL(): head(nullptr), tail(nullptr){}

template <typename T>
DLL<T>::~DLL()
{
  if (!head)
    return;
  remove_all(head);
}

template <typename T>
DLL<T>::DLL(const DLL<T>& source)
{
  if (!source.head)
    head = tail = nullptr;
  else
  {
    head = new Node<T>();
    head = source.head;
    Node<T> * curr = new Node<T>();
    curr->set_prev(head);
    head->set_next(curr);
    copy(curr, source.head->get_next());
  }
}

template <typename T>
DLL<T> & DLL<T>::operator=(const DLL<T> & arg)
{
  if (*this == arg)
    return *this;
  copy(this->head, arg->head);
  return *this;
}

template <typename T>
void DLL<T>::copy(const DLL<T> & arg)
{
  if (!arg->get_next())
  {
    
  }
  
}
  
template <typename T>
void DLL<T>::copy(ptr & dest, const ptr & source)
{
  if (!source->get_next())
  {
    dest = source;
    tail = dest;
    return;
  }
  dest = source;
  Node<T> * curr = new Node<T>();
  curr->set_prev(dest);
  dest->set_next(curr);
  return copy(curr, source->get_next());
}

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

template <typename T>
void DLL<T>::display() const
{
  if (!head)
    return;
  return display(head);
}

template <typename T>
void DLL<T>::display(const ptr & head) const
{
  if (!head)
    return;
  head->display();
  return display(head->get_next());
}

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

#endif

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
const T& Node<T>::get_data()
{
  return data;
}

template <typename T>
void Node<T>::set_data(const T& source)
{
  data = source;
}
    

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
Node<T>& Node<T>::operator=(const Node<T> & arg)
{
  data = arg.data;
  prev = arg.prev;
  next = arg.next;
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
bool Node<T>::greater_than(const Node<T> & new_data) const
{
  bool flag = false;
  if (data > new_data.data)
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
  bool flag = false;
  if (data == new_data)
    flag = true;
  return flag;
}

template <typename T>
bool Node<T>::not_equal_to(const T & new_data) const
{
  bool flag = false;
  if (data != new_data)
    flag = true;
  return flag;
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
void DLL<T>::remove_all(ptr & head)
{
  if (!head)
    return;
  Node<T> * temp = head->get_next();
  delete head;
  head = nullptr;
  return remove_all(temp);
}

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
void DLL<T>::display(const ptr & curr) const
{
  if (!curr)
    return;
  curr->display();
  return display(curr->get_next());
}

template <typename T>
void DLL<T>::display_cheapest() 
{
  if (!head)
    return;
  Node<T> * temp = head;
  display_cheapest(temp, head->get_next());
}

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

#endif

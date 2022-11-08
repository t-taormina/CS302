// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

#include "DLL.h"

Node<T>::Node(): prev(nullptr), next(nullptr){}

Node<T>::Node(const T& source): data(source), prev(nullptr), next(nullptr){}

Node<T>::Node(const Node<T>& source): data(source.data), prev(source.prev), next(source.next){}

ptr & Node<T>::get_next()
{
  return next;
}

ptr & Node<T>::get_previous()
{
  return prev;
}

ostream & Node<T> operator << (ostream & out, const Node<T>& obj)
{
  out << obj.data;
  return out;
}

void Node<T>::display() const
{
  cout << data << endl;
}

istream & operator >> (istream & in, const Node& arg)
{
  return in;
}

int operator<(Node& l_arg, Node& r_arg)
{
  int flag = 0;
  if (l_arg < r_arg)
    flag = 1;
  return flag;
}

int operator<=(Node& l_arg, Node& r_arg)
{
  int flag = 0;
  if (l_arg <= r_arg)
    flag = 1;
  return flag;
}

int operator>(Node& l_arg, Node& r_arg)
{
  int flag = 0;
  if (l_arg > r_arg)
    flag = 1;
  return flag;

}

int operator>=(Node& l_arg, Node& r_arg)
{
  int flag = 0;
  if (l_arg >= r_arg)
    flag = 1;
  return flag;
}

//========================================================

DLL::DLL(): head(nullptr), tail(nullptr){}

DLL::~DLL()
{
}

DLL::DLL(const DLL<T>& source)
{
}

DLL<T> & DLL::operator=(const DLL<T> & arg)
{
}

void DLL::insert(const T & data)
{
}

ostream & operator << (ostream & out, const DLL& obj)
{
}

void DLL::display(const ptr & head) const
{
}



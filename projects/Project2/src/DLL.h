// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

#ifndef DLL_H
#define DLL_H
#include "activity.h"

template <typename T>
class Node
{
  public: 
    typedef Node<T> * ptr;

    Node<T>();
    Node<T>(const T& source);
    Node<T>(const Node<T>& source);
    Node<T> & operator=(const Node<T> & arg);
    const T& get_data();
    void set_data(const T& source);
    void set_next(const ptr & source);
    void set_prev(const ptr & source);
    ptr & get_next();
    ptr & get_previous();
    bool less_than(const Node<T> & new_data) const;
    bool greater_than(const Node<T> & new_data) const;
    bool less_than_or_equal(const Node<T> & new_data) const;
    bool greater_than_or_equal(const Node<T> & new_data) const;
    bool equal_to(const Node<T> & new_data) const;
    bool not_equal_to(const Node<T> & new_data) const;
    void display() const;

    /*
    friend ostream & operator << (ostream & out, const Node<T>& obj);
    Node operator + (const int& op2);
    bool operator == (const Node& arg) const;
    bool operator != (const Node& arg) const;
    friend ostream & operator << (ostream & out, const Node& arg);
    friend int operator<(Node&, Node&); 
    friend int operator<=(Node&, Node&); 
    friend int operator>(Node&, Node&); 
    friend int operator>=(Node&, Node&);
    */

  private: 
    T data;
    ptr prev;
    ptr next;
};


template <typename T>
class DLL
{
  public:
    typedef Node<T> * ptr;
    
    DLL();
    ~DLL();
    DLL(const DLL<T>& source);
    DLL<T> & operator=(const DLL<T> & arg);
    void copy(const DLL<T> & arg);
    void insert(const T & obj);
    void display() const;
    void display_cheapest();
    void display_highest();
    void rate(string& loc);

  private: 
    ptr head;
    ptr tail;
    
    void remove_all(ptr & head);
    void copy(ptr & dest, const ptr & source);
    void copy(ptr & curr, ptr & prev, const ptr & source);
    void display(const ptr & curr) const;
    void display_cheapest(ptr & temp, ptr & curr);
    void display_highest(ptr & temp, ptr & curr);
    void rate(string& loc, ptr & curr);
};

#include "DLL.tpp"
#endif


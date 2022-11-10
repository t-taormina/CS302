// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

// This file contains the headers for the data structure used in this program. The data
// structure is a doubly linked list using templates. The node does not inherit from the
// derived classes in the hierarchy. This was a design decision based on having
// implemented the first program such that the node did derive from the hierarchy. I did
// this because I wanted to experience a different relationship between my objects and my
// data structure. For the most part, the code is similar. If I were to go back and
// reimplement, I would probably choose to have my node inherit from the derived objects
// as it seemed more intuitive and may have prevented some of the errors that I encountered.
// This was my first time programming with templates so please leave feedback anywhere you
// see room for improvement!
// ==========================================================================================

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
    
    // Recursive functions requiring private data members.
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


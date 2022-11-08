// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

#ifndef DLL_H
#define DLL_H
#include <memory>

template <typename T>
class Node
{
  public: 
    typedef Node<T> * ptr;
    Node<T>();
    Node<T>(const T& source);
    Node<T>(const Node<T>& source);
    ptr & get_next();
    ptr & get_previous();
    void display() const;
    //template <typename U>
    friend ostream & operator << (ostream & out, const Node<T>& obj);
    Node& operator=(const Node& arg);
    Node operator + (const int& op2);
    bool operator == (const Node& arg) const;
    bool operator != (const Node& arg) const;
    friend ostream & operator << (ostream & out, const Node& arg);
    friend int operator<(Node&, Node&); 
    friend int operator<=(Node&, Node&); 
    friend int operator>(Node&, Node&); 
    friend int operator>=(Node&, Node&);


  private: 
    T data;
    ptr prev;
    ptr next;
};

template <typename t>
class DLL
{
  public:
    typedef Node<T> * ptr;
    
    DLL();
    ~DLL();
    DLL(const DLL<T>& source);
    DLL<T> & operator=(const DLL<T> & arg);
    void insert(const T & data);
    friend ostream & operator << (ostream & out, const DLL& obj);

  private: 
    ptr head;
    ptr tail;
    
    void copy(ptr & dest, const ptr & source);
    void insert(ptr & tail, const T & data);
    void display(const ptr & head) const;
};

#endif


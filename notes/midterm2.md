# Midterm 2 CS302

### Generic Programming 
Templates
- What are templates and why are they useful?
    - templates allow programmers to apply parametric polymorphism on a class-by-class basis
    - isolate type dependencies for a particular class of objects
    - shifts the burden of creating duplicate classes to handle various data types to the compiler.
- Where does the template keyword belong?
    - the template keyword belongs on the line preceding the class declaration
```
template<class TYPE, TYPE VALUE>
class Node
{
    //data members
    //methods
};
```
- What is the template formal argument list?
    - the template formal argument list is inside the <>
    - consists of a comma seperated list containing identifiers for each formal argument in the list
    - must be at least one formal argument specified
    - scope of the formal arguments is that of the class template itself
- How do you create an object of class template?
    - You call the templated class specifying the data type between the <>
```
Node<Skiing> ski_node;
```

- What do type dependicies mean?
    - allows the identifier listed to be substituted for the data types specified by the client at instantiation time
- What role does operator overloading have with templates?
    - since we don't know what types of abstact data we will be working with when using templated classes, overloading operators allows blind usage of operators under the assumption that they have been defined for each class. 
    - What happens if an expected operator is not overloaded?
        - the compiler will complain about incompatible data types
- Can you create a template for a node class?
```
template <typename T>
class Node
{
    public:
        typedef Node<T> * ptr;

        Node<T>();
        Node<T>(const T & src);
        Node<T>(const Node<T> & src);

    private:
        T data;
        ptr next;

};
```
    - Why would we want to do this?
        - It would allow us to create nodes that hold can hold any number of abstract data types. 
        - This is nice since we would only have to write one node class to be used with many data types

### Operator overloading
- What are they and why are they useful?
- What is the syntax?
- How do we handle lvalue vs rvalue operators? 
- Why is it important to have the const keyword?
    - for member functions
    - for arguments
- What happens if we don't supply an assignment operator?
    - What is self assignment?
    - What does the = operator return?


### Dynamic Binding
- What is it and why is it useful?
- Where does the virtual keyword belong?
- What does it mean to build a self similar interface?
- Rules of dynamic binding?
- What is upcasting?
- What is downcasting?
- What is RTTI and why would we use it?
- What is an abstract base class and why would we use them?

### Syntax for Dynamic binding
- Show how to create a virtual function: 
- Show how to cause dynamic binding to take place: 
- Syntax of upcasting: 
- Syntax of downcasting: 
- Syntax of an abstract base class: 

### Python Programming
- How to put together a program
- Use of strings
- Use of arrays and lists
- Creating abstractions in python

### Data structures 
- Linear linked list and doubly linked lists


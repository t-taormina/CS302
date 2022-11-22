# Midterm 2 CS302

### Generic Programming 
Templates
- What are templates and why are they useful?
templates give the compiler the responsiblity of making duplicate classes when using varying data types

- Where does the template keyword belong?
the line before the class declaration

- What is the template formal argument list?
what is inside the <>

- How do you create an object of class template?
specify the data type inside <>

```c++
Node<Skiing> ski_node;
```

- What do type dependicies mean?
allows the identifier listed to substituted for the data types specified by the client at instantiation time

- What role does operator overloading have with templates?
operator overloading allows our classes to be used as natural data types or along with other classes that have operators implemented

- What happens if an expected operator is not overloaded?
the compiler will throw an error about incompatible types

- Can you create a template for a node class?
```c++
template <typename T>
class node
{
    public:
        typedef node<T> * ptr;
        node<T>();
        node<T>(const node<T> & src);
        ~node<T>();

    private:
        T data;
        ptr left;
        ptr right;
};
```
- Why would we want to do this?
it would allow one node class to be used for different data types


### Operator overloading
- What are they and why are they useful?
makes for a more complete abstraction and more natural usage by clients


- What is the syntax?
```c++
derived& operator=(const derived& src);
friend ostream& operator<< (ostream& out, const derived& src);
friend int operator<(const derived& left, const derived& right);
```

- How do we handle lvalue vs rvalue operators? 


- Why is it important to have the const keyword?
- for member functions
- for arguments

- What happens if we don't supply an assignment operator?
a shallow copy will be made

- What is self assignment?
using the assignment operator to assign an object to itself

- What does the = operator return?
reference to an object


### Dynamic Binding
- What is it and why is it useful?
occurs when a pointer or reference is associated with a member function based on the dynamic type of the object
dynamic type is the type of the object that is pointed or referred to, not the static type of its pointer or reference

- Where does the virtual keyword belong?
```c++
virtual int display();
```
- What does it mean to build a self similar interface?
same name, argument list, and return type

- Rules of dynamic binding?
virtual functions cannot be static member functions
virtual keyword is only in base class
self similar interface
derived functions don't need to be implemented if inherited behavior is desired

- What is upcasting?
a base class reference or pointer that is pointing or reffering to a derived object

- What is downcasting?
when a pointer to a direct or indirect base class is converted to a pointer to a derived class

- What is RTTI and why would we use it?
runtime type identification and we use it for dynamic binding

- What is an abstract base class and why would we use them?
a base class that can only be derived from, objects cannot be instantiated from it
needs protected constructors or a pure virtual function

```c++
```

### Syntax for Dynamic binding
```c++
```
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


# Midterm 2 CS302

### Generic Programming 
Templates
- What are templates and why are they useful?
    - templates allow programmers to apply parametric polymorphism on a class-by-class basis
    - isolate type dependencies for a particular class of objects
    - shifts the burden of creating duplicate classes to handle various data types to the compiler.
- Where does the template keyword belong?
    - the template keyword belongs on the line preceding the class declaration
```c++
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
```c++
Node<Skiing> ski_node;
```

- What do type dependicies mean?
    - allows the identifier listed to be substituted for the data types specified by the client at instantiation time
- What role does operator overloading have with templates?
    - since we don't know what types of abstact data we will be working with when using templated classes, overloading operators allows blind usage of operators under the assumption that they have been defined for each class. 
    - What happens if an expected operator is not overloaded?
        - the compiler will complain about incompatible data types
- Can you create a template for a node class?
```c++
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
    - It allows programmers to complete the process of data abstaction
    - Essential when working with templates so that our classes work with already existing classes using operators
- What is the syntax?
```c++
derived& operator=(const derived& arg);
friend ostream& operator<<(ostream& out, const derived& arg);
friend int operator<(const derived& arg1, const derived& arg2);
```
- How do we handle lvalue vs rvalue operators? 
    - Rvalue
        - return by value
    - Lvalue 
        - return by reference
```c++
Derived & operator++(); // Lvalue return by reference.
Derived operator++(int); // Rvalue return by value.
```
- Why is it important to have the const keyword?
    - for member functions
    - for arguments
- What happens if we don't supply an assignment operator?
    - What is self assignment?
        - when you assign an object to itself.
    - What does the = operator return?
        - Lvalue, object by reference


### Dynamic Binding
- What is it and why is it useful?
    - occurs when a pointer or reference is associated with a member function based on the dynamic type of the object.
    - also known as runtime binding
    - dynamic type of an object is the type of the object actually pointed or reffered to rather than the static type of is pointer or reference.
- Where does the virtual keyword belong?
    - preceding the function name in the base class public member functions
```c++
virtual int display();
virtual int match();
```
- What does it mean to build a self similar interface?
    - To have virtual functions with the same signature and return types.
- Rules for overridding?
    - inheritance using public derivation
    - public member function must be virtual in either direct or indirect base class
    - derived member function must have same signature and return type
    - overridden function must be accessed through a direct or indirect base class reference or pointer

- Rules of dynamic binding?
    - virtual functions cannot be static member functions
    - signature and return type must be the same for all implementations of the virtual function
    - while the function must be defined as virtual in the base class, it does not need to be defined in those derived classes where the inherited behavior does not need to differ
    - the keyword virtual is only within the base class

- What is upcasting?
    - Assigning pointers to derived class objects to point to base class objects.
    - Can also use derived class objects to initialize references to base class objects.
- What is downcasting?
    - when a pointer to a direct or indirect base class is converted to a pointer to a derived class
```c++
student s;
account* pa = &s; // Up cast
student* ps;
ps = dynamic_cast<student*>(pa); //Down cast
savings i;
pa = &i;
ps = dynamic_cast<student*>(pa); //result is a zero
```
- What is RTTI and why would we use it?
    - Run time type identification 
    - uses type information stored in objects by the compiler to determine at run time the actual type of an object pointed or referred to
- What is an abstract base class and why would we use them?
    - an abstract base class is a base class that can only be derived from, no objects can be instantiated from it
    - a base class becomes abstact when its constructors are protected or by declaring a virtual function "pure"
    - derived classes must implement all  pure virtual functions or they become abstract themselves
```c++
virtual void statement()=0; // pure virtual function for abstract base class
```

### Syntax for Dynamic binding
```c++
student s;
account* pa = &s; // Up Casting
student* ps;
ps = dynamic_cast<student*>(pa); // Down casting

// Abstract base class
class base
{
    protected: 
        base();
        base(const base& to_copy);
        // etc...
    // or...
    virtual int display()=0; // pure virtual
}

virtual int statement(); // just virtual
```


### Python Programming
```python
class Point:
    #constructor
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    # + 
    def __add__(self,second):
        temp = Point(self.x + second.x, self.y + second.y)
        return temp

    # +=
    def __iadd__(self, second):
        self.x += second.x
        self.y += second.y
        return self

    # << 
    def __str__(self):
        return (f'x: {self.x}, y: {self.y}')

    # *
    def __mul__(self, second):
        temp = Point(self.x * second.x, self.y * second.y)
        return temp

    # *=
    def __imul__(self,other):
        self.x *= other.x
        self.y *= other.y
        return self



        
# Python program to demonstrate
# slicing of elements in a Array
 
# importing array module
import array as arr
 
# creating a list
l = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
 
a = arr.array('i', l)
print("Initial Array: ")
for i in (a):
    print(i, end =" ")
print('\n')

for i in range(len(l)):
    print(l[i], end = " ")
print('\n')
```

### Data structures 
- Linear linked list and doubly linked lists


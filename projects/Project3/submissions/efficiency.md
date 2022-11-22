# Program 3 Write Up
Tyler Taormina - taormina@pdx.edu CS302 Fall 2022

### Efficiency Writeup
The purpose of this program was to build a hierarchy of classes and a binary 
search tree in such a way that dynamic binding could be achieved in the implementation. 
To do this a specific class structure is needed. The base class must have virtual 
functions that are implemented by the derived classes. Moreover, the functions in 
the derived classes need to have the same name, arguments, and return types as the 
virtual functions in the base class. This is called a self similar interface and 
it is a necessary prerequisite for dynamic binding. The three 3 functions that 
had a self similar interface were the display, match, and edit functions. In 
addition to those three, the destructor was also marked as virtual in the base 
class and re-implemented in the derived classes. Another requirement for this project
was to have a single derived class that had a unique function. That is, it did not 
have a matching virtual function in the base class. I achieved dynamic binding 
by using the smart pointer "shared_ptr" inside of my node and binary search tree 
classes. My node consisted of three shared pointers: left, right, and a pointer 
to the base class of the hierarchy. The binary search tree held a single smart 
pointer to a node object which represents the root of the tree. To achieve 
dynamic binding an upcast must be done. This allows a base class pointer to point 
to a derived class object. It allows all of the differing objects in the 
hierarchy to be stored in a single binary tree. The base class pointer calls the 
virtual base class function, which calls the derived class function that corresponds
to the type being pointed to. It is very cool. For the unique function in the 
advanced class, down casting is necessary. Since the function has no corresponding 
virtual function in the base class, it is necessary to convert the base class 
pointer to a derived class pointer. This is achievable with the "dynamic_cast" 
call. In the case of smart pointers, it can be achieved with the  
"dynamic_pointer_cast" call. These are both included in the std library. With 
the down casting done, any unique function in a derived class can be called. 
Again, this is very cool stuff. Outside of having fun with casting pointers to 
abstract data types, my algorithms were standard for a binary tree. I passed 
constant references everywhere that made sense and did as little copying as 
possible. Recursion was used in all repetitive portions of functions. Please let 
me know how you think I did! 

### GDB Experience



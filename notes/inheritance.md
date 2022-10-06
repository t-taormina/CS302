# Inheritance lecture
- inheritance involves making use of a base and derived class (or a super and sub class)
- the base class contains the similarities and the derived class contains the differences 
- think... base class: vehicle 
  - and derived classes: car, bike, train, boat, etc. 
- classes can contain three levels of restriction for the data that they contain 
  - public = accessbile for everyone (client accessible; public derivation gives access to public funtions of a parent class)
  - protected = accessible for derived classes
  - private = only accessible by the particular class
- every class needs to have a purpose or job to do 
- AVOID GETTERS!
- Don't build data structures into your "items". Put your items into a seperate data structure. Think about data structures last or seperately.
- Data structues will always "contain" objects from other classes
- multiple inheritance where a derived class has multiple parents
- Initialization lists = what I already use in my .cpp class files for constructors
  - only apply to constructors
  - the only way to tell the compiler which base class constructor to use

### Constructors
- default constructor = uses initialization list to establish default values for members in a class.
- copy constructor = allows a object instance to be created using values from another object as the initial member values.
  - copy constructors are invoked when... 
    - you pass a class object by value 
    - return a class object by value
    - or create an object the initial value of another object of that same class 
    - only use the latter of these, the others uses memory and decreases program efficiency
  - only implement copy constructors when using dynamic memeory, otherwise the C++ provided copy constructor will be sufficient
  - double free errors result from passing by value (use &) pass by reference 
- if you are using dynamic memory be sure to implement a copy constructor, a deconstructor, and a assignment operator

### Assignment operator
- ClassName& operator=(const ClassName& arg); 
- Things to consider
  - How to chek for self assignment:
  - Delete the current dynamic memory
  - Perform a deep copy
CODE
```
Class& operator=(const Class& arg)
{
  security::operator=(arg);
  if (this == &arg)
    return *this; //or return arg since they are the same thing 
  if(name)
    delete [] name;
  name = new char [strlen(source.name) + 1];
  strcpy(name, source.name);
  return *this;
}
```

### Program 1 info
- a game
- Use at least 5 classes with at least one inheritance hierarchy
- no public data
- no structs
- move on to using the STL for one data structure per assignment
- recursive solutions for repetitive algorithms

### Future
- Generic programming is a case where will return a class by value 



- REMINDER ==> don't use cout statements, use GDB


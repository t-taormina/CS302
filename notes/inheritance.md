# Inheritance lecture
- inheritance involves making use of a base and derived class (or a super and sub class)
- the base class contains the similarities and the derived class contains the differences 
- think... base class: vehicle 
  - and derived classes: car, bike, train, boat, etc. 
- classes can contain three levels of restriction for the data that they contain 
  - public = accessbile for everyone (client accessible; public derivation gives access to public funtions of the base class)
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
  - double free errors result from passing by value (use &!) 
  - 


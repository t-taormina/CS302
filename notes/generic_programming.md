# Generic Programming 
- let the compiler do the work

### Namespaces
- namespace is a grouping of identifiers
- have to use the "using namespace (name of namespace)"
- there is "file scope" which only allows the namespace to be used in a specific file (can be exteneded to global)
- there is no "public" or "private"
- namespaces can be built from multiple locations

### Static Members
- useful with recursion
- do more research

### Templates
- writing code independently of the data types that will be used

- Function templates 
  - writing a function once independent of the data types
  - a paramterization of type dependencies that allows the compiler to automatically generate as many overloaded functions as needed.

- Template Function
  - a specific instance of a function that is instantiated (i.e. generated) 
  - different from "Function Templates"
 
- Specialized Template Function
  - specialized versions of a template function that work with cases that don't fit the
    normal pattern.

##### Steps to creating a function template
- determine what type dependencies exist
- start both the function's definition and prototype with the template keyword
- follow the template keyword by the identifiers that represent each type dependency 
  - type dependencies must be preceded by the keyword 'class' or 'typename'
  - they are placed inside of angle brackets (<>)
  - see below
``` 
template<typename TYPE> 
// or 
template<class TYPE>
```
  - this says that the following function will use the identifier TYPE instead of the explicit data type
  - operator overloading becomes essential when using templates
  -

### Typedefs
- a way to create a new mnemonic name for an existing type
- creates a synonym for something in existence
- typically used in C
``` 
typedef struct node Node
```
- with templates this can shorten some of our code...
```
typedef Node<TYPE> node_type; 
```
- naming is really important when using typedefs


### Smart Pointers
- pointer class with safeguards to help with management dynamic memory
- implemented as templates
- no longer need to explicitly use delete to free memory
- to create smart pointers
  - #inlcude <memory> header file
- three types 
  - unique_ptr = if the object goes out of scope, memory released
  - shard_ptr = allows two or more pointers to share the same memory
  - weak_ptr = multiple shared pointers but no reference counting
```
std::unique_ptr<data_type> smrt_ptr;
// don't use new or malloc
std::unique_ptr<int> int_ptr (new int);
// different ways to initialize
auto ptr = make_unique<Movie>("initial values");
// moves pointer to new owner
auto new_owner = std::move(ptr);
```
- can still use -> and * Operators



 

# STL - Standard template library
 
- new for-loops
  - for ([initialization;] range_declaration:range_expression
```
int arraay[] {1,2,3,4,5};
for (int element:array_name)
  total += element;
```
- also can create references for each element
```
for (int& element:array_name)
  ++element; modifies each element. 
```

### Auto keyword
- tells the compiler to deduce the data type based on the context
- usefule when working with templatees
- not recommended for basic variables
  - auto variable {init_value}

steps through ann array based on the array type
```
for (auto element:array)
```

### Containers from STL
- 3 major components of STL
  - template container classes
  - generic algorithms written as template functions
  - iterator classes
- provides specialized containers to supoort different types of data handling
  - array, vector, deque (works at both ends), and list ( a doubly linked list)

#### Array container
- fixed size
- quick acces when we know the location (by index)
- can automatically compare all elements of two arrays
- syntax
```
std::aray<data_type, size> array_name; // does not initialize
std::array array_name {.4, 1.0}; // data type deduced
array_name.size() // returns the number of elements
array_name.fill(initial_value); 
array_name[index] = 10; // does not range check (risks out of bounds)
array_name.at(index); // does range check 
```


#ifndef PET_H
#define PET_H
#include <iostream>
#include <cstdlib>
using namespace std;

class Animal
{
  public:
    Animal();
    Animal(const Animal&);
    ~Animal();
    Animal& operator=(const Animal&);
    friend ostream& operator<<(ostream& out, const Animal&);

  protected: 
    string breed;
};

class Pet: public Animal
{
  public:
    Pet();
    Pet(const Pet&);
    ~Pet();
    Pet& operator=(const Pet&);
    friend ostream& operator<<(ostream& out, const Pet&);
    //friend istream& operator>>(istream& in, const Pet&);
    
    // Member function format.
    int operator==(const Pet&, const Pet&) const;
    int  operator!=(const Pet&, const Pet&) const;

    // Relational operators that are not members.
    friend int  operator<(const Pet&, const Pet&);
    friend int  operator<=(const Pet&, const Pet&);
    friend int  operator>(const Pet&, const Pet&);
    friend int  operator>=(const Pet&, const Pet&);


  protected:
    string name;
    int age;
};

#endif


// Code for operator overloading.
#include "pet.h"
Pet::Pet(): name(""), breed(""), age(0) {}

Pet::Pet(const Pet& to_copy)
{
  name = to_copy.name;
  breed = to_copy.breed;
  age = to_copy.age;
}

Pet::~Pet(){}

Pet& operator=(const Pet&)
{
}

// As a friend function
ostream& operator<<(ostream& out, const Pet& pet)
{
  // Kick start the base class but decide where you want the info displayed.
  // (Before or after member data. In this case before.)
  out << static_cast<const Animal&> (pet);
  // Alternative is to call a named function called dislay
  // that is a member of the pet class and it calls its parent's
  // display with    Animal::display(out);

  if (pet.name == "")
  {
    NO_DATA no_data;
    throw no_data;
  }
  out << pet.name << '\t' << " age: " << pet.age << " years";
}

istream& operator>>(istream& in, const Pet&);

// BASE CLASS
// As a member function
int Animal::operator==(const Animal& operand) const
{
  if (!operand.valid_breed())
  {
    NO_DATA no_data;
    throw no_data;
  }
  return breed == operand.breed;
}

// DERIVED CLASS
// As a member function
int Pet::operator==(const Pet& pet) const
{
  if (!pet.valid_name())
  {
    NO_DATA no_data;
    throw no_data;
  }
  int result = Animal::operator==(pet);
  return result && (name == pet.name);
}

int Pet::operator!=(const Pet&, const Pet&) const
{
}

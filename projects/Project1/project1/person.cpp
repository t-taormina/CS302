// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

#include "person.h"
#include <iostream>
#include <cstring>
using namespace std;


Person::Person(): first_name(nullptr), last_name(nullptr), wins(0), losses(0){}

Person::Person(char* f_name, char* l_name): first_name(f_name), last_name(l_name), wins(0), losses(0) {}

Person::Person(const Person& to_copy)
{
  // implement later, its been a busy week 
}

Person::~Person()
{
  if (first_name)
  {
    delete[] first_name;
    first_name = nullptr;
  }
  if (last_name)
  {
    delete[] last_name;
    last_name = nullptr;
  }
}

void Person::display() const
{
  if (first_name)
    cout << "First name: " << first_name << endl;
  if (last_name)
    cout << "Last name: " << last_name << endl;
  cout << "Wins: " << wins << endl;
  cout << "Losses: " << losses << endl;
}

void Person::edit_first_name(char* edit)
{
  if (!edit)
    return;

  if (first_name)
  {
    delete [] first_name;
    first_name = nullptr;
  }

  first_name = new char[strlen(edit)+1];
  strcpy(first_name,edit);
}

void Person::edit_last_name(char* edit)
{
  if (!edit)
    return;

  if (last_name)
  {
    delete [] last_name;
    last_name = nullptr;
  }

  last_name = new char[strlen(edit)+1];
  strcpy(last_name,edit);
}


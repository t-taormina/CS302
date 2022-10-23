// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1    

#include "person.h"
#include <iostream>
#include <cstring>
using namespace std;
const int SIZE = 100;


// Default Constructor.
Person::Person(): wins(0), losses(0){
  first_name = new char[SIZE];
  last_name = new char[SIZE];
  cout << "Please provide your first name: ";
  std::cin.get(first_name, SIZE, '\n');
  std::cin.ignore(SIZE, '\n');
  cout << "Please provide your last name: ";
  std::cin.get(last_name, SIZE, '\n');
  std::cin.ignore(SIZE, '\n');
}

// Parameterized Constructor.
Person::Person(const Person& to_copy): wins(to_copy.wins), losses(to_copy.losses) 
{
  first_name = new char[strlen(to_copy.first_name) + 1];
  strcpy(first_name, to_copy.first_name);

  last_name = new char[strlen(to_copy.last_name) + 1];
  strcpy(last_name, to_copy.last_name);
}

// Deconstructor.
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

// @Dev - Displays member data for "position".
// Args -> None.
// Returns -> None.
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


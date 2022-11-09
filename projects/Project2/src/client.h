// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

#ifndef CLIENT_H
#define CLIENT_H
#include "activity.h"
#include "DLL.h"
#include <iostream>
using std::cout;
using std::endl;

int run();
int welcome();
int menu();
int validate_menu_choice();
void processChoice (int& flag, int menu_choice);
int fill_ski(DLL<Node<Skiing>> dll);
int fill_shoe(DLL<Node<Snowshoe>> dll);
int fill_skate(DLL<Node<Skating>> dll);

#endif


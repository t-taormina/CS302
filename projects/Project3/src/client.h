// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

// This file contains the headers for the current client code (client.cpp). The aim of
// this file is to provide a sample use case for the hierarchy and data structures in this
// program. The client code I have introduced makes use of most implemented functions, but
// not all. The functions I have laid out make a base to be expanded on. Some functions
// may be arbitrary at the moment but could prove useful if this project is given more
// time to grow. 
// =============================================================================

#ifndef CLIENT_H
#define CLIENT_H
#include "bst.h"

int run();
int welcome();
int menu();
int concept_menu();
int validate_menu_choice();
int validate_sub_choice();
void process_main(int& flag, int menu_choice, Tree& tree);
void process_sub(int& flag, int menu_choice, Tree& tree);
int fill_tree(Tree & tree);
int get_string(string& arg);

#endif


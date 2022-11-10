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

#ifndef CLIENT_H
#define CLIENT_H
#include "DLL.h"
#include <iostream>
using std::cout;
using std::endl;

int run();
int welcome();
int menu();
void ski_menu();
void shoe_menu();
void skate_menu();
int validate_menu_choice();
int validate_submenu_choice();
void process_main(int& flag, int menu_choice, DLL<Node<Skiing>>& ski, DLL<Node<Snowshoe>>& shoe, DLL<Node<Skating>>& skate);
void process_ski(int& flag, int menu_choice, DLL<Node<Skiing>>& ski);
void process_shoe(int& flag, int menu_choice, DLL<Node<Snowshoe>>& shoe);
void process_skate(int& flag, int menu_choice, DLL<Node<Skating>>& skate);
int fill_ski(DLL<Node<Skiing>> & dll);
int fill_shoe(DLL<Node<Snowshoe>> & dll);
int fill_skate(DLL<Node<Skating>> & dll);

#endif


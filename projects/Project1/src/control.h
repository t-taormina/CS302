// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1 CS302

#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <vector>
#include <string>
#include "piece.h"
#include "person.h"
#include "data_structures.h"

// Contains headers for client functions.
//================================================================================
// These functions control the flow of the game and are a rough sketch of what the client
// might choose to do given the class hierarchy and data structures I have written for
// this game.

int run();
int display_hands(ALL& p1, ALL& p2);
int display_hand(ALL& p);
int welcome_message();
int game_loop(CLL& cll, ALL& all1, ALL& all2, std::vector<Pawn>& pawns1, std::vector<Pawn>& pawns2, Player& player1, Player& player2);
int turn_loop(CLL& cll, ALL& all1, ALL& all2, std::vector<Pawn>& pawns1, std::vector<Pawn>& pawns2, Player& player1, Player& player2);
int deal_loop(CLL& cll, ALL& all1, ALL& all2);
int pawn_loop(std::vector<Pawn>& pawns1, std::vector<Pawn>& pawns2);
int check_pawns(ALL& all, std::vector<Pawn>& pawns, Player& attacker, int num);
int easy_view(ALL& all, std::vector<Pawn>& pawns, int player);
int attack_roll(ALL& all, std::vector<Pawn>& pawns, Player& attacker);
int roll_message();
int goodbye();

#endif


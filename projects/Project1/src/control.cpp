// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1 CS302

#include "control.h"
using namespace std;
using std::string;

const int SIZE = 6;
const int PAWNS = 4;

// Program Driver.
int run()
{ 
  welcome_message();
  cout << endl;
  cout << "Please enter your information." << endl;
  cout << "Player 1... " << endl;
  Player player1 = Player();
  cout << endl;
  cout << "Player 2... " << endl;
  Player player2 = Player();
  cout << endl;

  int flag = 1;

  while(flag > 0)
  {
    CLL cll = CLL();
    cll.build_deck();

    ALL all1 = ALL(SIZE);
    ALL all2 = ALL(SIZE);

    std::vector<Pawn> p1(PAWNS, Pawn());
    std::vector<Pawn> p2(PAWNS, Pawn());
    flag = game_loop(cll, all1, all2, p1, p2, player1, player2);
  }
  goodbye();
  return 0;
}

// Master loop.
int game_loop(CLL& cll, ALL& all1, ALL& all2, std::vector<Pawn>& pawns1, std::vector<Pawn>& pawns2, Player& player1, Player& player2)
{
  for (int i = 0; i < 4; i++)
  {
    turn_loop(cll, all1, all2, pawns1, pawns2, player1, player2);
    cout << endl;
    cout << "=======================================" << endl;
    cout << "After that round, the score is..." << endl;
    cout << "Player 1: ";
    player1.display_points();

    cout << "Player 2: ";
    player2.display_points();
    cout << "=======================================" << endl;
    cout << endl;
    if (i == 2)
      cout << "Final Round!" << endl;
    else
      cout << "Lets start Round " << i + 2 << "!" << endl;
    cout << endl;
  }
  if (player1.is_winner(player2))
  {
    cout << "Player 1 wins!... Congrats." << endl;
    player1.add_win();
    player2.add_loss();
  }
  else if (player2.is_winner(player1))
  {
    cout << "Player 2 wins!... Congrats." << endl;
    player2.add_win();
    player1.add_loss();
  }
  else
  {
    cout << "It is a tie! No one wins..." << endl;
  }
  int play_again;
  cout << "Would you like to play again?" << endl;
  cout << "Enter 1 for yes and 0 for no" << endl;
  cin >> play_again;
  return play_again;
}

// Loops through each round in the game.
int turn_loop(CLL& cll, ALL& all1, ALL& all2, std::vector<Pawn>& pawns1, std::vector<Pawn>& pawns2, Player& player1, Player& player2)
{
  deal_loop(cll, all1, all2);
  display_hands(all1, all2);
  cout << endl;
  cout << "Now we will establish where each players defensive pawns will be positioned..." << endl;
  pawn_loop(pawns1, pawns2);
  cout << endl;
  roll_message();
  cout << endl;
  easy_view(all2, pawns2, 2);
  cout << "Player 1... Attack!" << endl;
  attack_roll(all2, pawns2, player1);
  cout << endl;
  cout << "Press enter to continue..." << endl;
  cout << endl;
  easy_view(all1, pawns1, 1);
  cout << "Player 2... Attack!" << endl;
  attack_roll(all1, pawns1, player2);
  return 0;
}

// Loops through attacking logic.
int attack_roll(ALL& all, std::vector<Pawn>& pawns, Player& attacker)
{
  Dice di = Dice();
  for (int i = 0; i < PAWNS; i++)
  {
    cin.ignore();
    int pos = di.roll();
    cout << pos << endl;
    check_pawns(all, pawns, attacker, pos);
  }
  return 0;
}

// Checks pawn positions and awards points based on card values.
int check_pawns(ALL& all, std::vector<Pawn>& pawns, Player& attacker, int num)
{
  bool flag = true;
  for (int i = 0; i < PAWNS; i++)
  {
    if (pawns[i].is_position(num))
      flag = false;
  }
  if(flag)
  {
    int score = all.score(num);
    attacker.add_points(score);
    cout << "You scored " << score << " points!" << endl;
  }
  else
    cout << "No points awarded..." << endl;
  return 0;
}

// Provides a visual for each players cards and pawn positions.
int easy_view(ALL& all, std::vector<Pawn>& pawns, int player)
{
  cout << "Player " << player << " has this layout right now." << endl;
  display_hand(all);
  for (int i = 0; i < PAWNS; i++)
  {
    cout << "Pawn ";
    pawns[i].display_position();
  }
  return 0;
}

// Determines and sets position for all pawns during a round.
int pawn_loop(std::vector<Pawn>& pawns1, std::vector<Pawn>& pawns2)
{
  Dice di = Dice();
  cout << "Player 1 will roll 4 times to establish where their pawns are positioned for defense!" << endl;
  cout << "Press enter to roll..." << endl;
  cin.ignore();
  for (int i = 0; i < PAWNS; i++)
  {
    int pos = di.roll();
    pawns1[i].change_position(pos);
    cout << "Pawn " << i + 1 << " position: " << pos << endl;
  }
  cout << endl;

  cout << "Player 2 will roll 4 times to establish where their pawns are positioned for defense!" << endl;
  cout << "Press enter to roll..." << endl;
  cin.ignore();
  for (int j = 0; j < PAWNS; j++)
  {
    int pos = di.roll();
    cout << "Pawn " << j + 1 << " position: " << pos << endl;
    pawns2[j].change_position(pos);
  }
  cout << endl;
  cout << "Press enter to continue..." << endl;
  cin.ignore();
  return 0;
}

// Deals cards to each player's array of linked lists (ALL).
int deal_loop(CLL& cll, ALL& all1, ALL& all2)
{
  for (int j = 0; j < 12; j++)
  {
    Node card = Node();
    cll.draw_card(card);
    if (j % 2 == 0)
      all1.insert(card);
    else 
      all2.insert(card);
  }
  return 0;
}

// Displays the head node of each index in the specified array of linked lists (ALL).
int display_hand(ALL& all)
{
  return all.display_hand();
}

// Displays the head node of each index in both players array of linked lists (ALL).
int display_hands(ALL& p1, ALL& p2)
{
  cout << "Player 1's hand..." << endl;
  p1.display_hand();
  cout << endl;
  cout << "Player 2's hand..." << endl;
  p1.display_hand();
  return 0;
}

// Displays welcome message.
int welcome_message()
{    
  cout << "Welcome to Dice Soccer!" << endl;
  cout << "There will be 4 rounds per game..." << endl;
  cout << "The player with the highest score at the end wins!" << endl;
  return 0;
}

// Displays information about the rolling dice process.
int roll_message()
{
  cout << "Each player will now roll their dice 4 times..." << endl;
  cout << "If you roll a number that doesn't have a pawn protecting the card, you score!" << endl;
  cout << "Aces are 3 points, other face cards are 2, and everything else is 1..." << endl;
  cout << "Player 1 will be the first to attack..." << endl;
  cout << "Press enter to roll the dice... Good luck!" << endl;
  return 0;
}

// Farewell and signature.
int goodbye()
{  
  cout << endl;
  cout << endl;
  cout << "Thanks for playing!" << endl;
  cout << "By Tyler Taormina" << endl;
  return 0;
}

// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1 CS302

#include "control.h"
using namespace std;
using std::string;

const int SIZE = 6;
const int PAWNS = 4;

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
    flag = game_loop(cll, all1, all2, p1, p2);
  }
  goodbye();
  return 0;
}

int game_loop(CLL& cll, ALL& all1, ALL& all2, std::vector<Pawn>& pawns1, std::vector<Pawn>& pawns2)
{
  for (int i = 0; i < 4; i++)
    turn_loop(cll, all1, all2, pawns1, pawns2);
  return 0;
}

int turn_loop(CLL& cll, ALL& all1, ALL& all2, std::vector<Pawn>& pawns1, std::vector<Pawn>& pawns2)
{
  deal_loop(cll, all1, all2);
  display_hands(all1, all2);
  cout << endl;
  cout << "Now we will establish where each players defensive pawns will be positioned..." << endl;
  pawn_loop(pawns1, pawns2);
  cout << endl;
  roll_message();
  easy_view(all2, pawns2);
  
  
  cout << "" << endl;
  return 0;
}

int attack_roll()
{
  Dice di = Dice();
  for (int i = 0; i < PAWNS; i++)
  {
  }
  return 0;
}

int easy_view(ALL& all, std::vector<Pawn>& pawns, int player)
{
  cout << "Player " << player << endl;
  display_hand(all);
  for (int i = 0; i < PAWNS; i++)
    cout << "Pawn at Position: " << pawns[i].display_position() << endl;
}

int pawn_loop(std::vector<Pawn>& pawns1, std::vector<Pawn>& pawns2)
{
  Dice di = Dice();
  cout << "Player 1 will roll 4 times to establish where their pawns are positioned for defense!" << endl;
  cout << "Press enter to roll..." << endl;
  cin.ignore();
  for (int i = 0; i < PAWNS; i++)
  {
    int pos = di.roll();
    cout << "Pawn " << i + 1 << " position: " << pos << endl;
    pawns1[i].change_position(pos);
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
  return 0;
}

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

int display_hand(ALL& p)
{
  p.display_hand();
}

int display_hands(ALL& p1, ALL& p2)
{
  cout << "Player 1's hand..." << endl;
  p1.display_hand();
  cout << "Player 2's hand..." << endl;
  p1.display_hand();
  return 0;
}

int welcome_message()
{    
  cout << "Welcome to Dice Soccer!" << endl;
  cout << "There will be 4 rounds per game..." << endl;
  cout << "The player with the highest score at the end wins!" << endl;
  return 0;
}

int roll_message()
{
  cout << "Each player will now roll their dice 4 times..." << endl;
  cout << "If you roll a number that doesn't have a pawn protecting the card, you score!" << endl;
  cout << "Aces are 3 points, other face cards are 2, and everything else is 1..." << endl;
  cout << "Player 1 will be the first to attack..." << endl;
  cout << "Press enter to roll the dice... Good luck!" << endl;
  return 0;
}

int goodbye()
{  
  cout << "Thanks for playing!" << endl;
  cout << "By Tyler Taormina" << endl;
  return 0;
}

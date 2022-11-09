// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

#include "client.h"

int run()
{
  DLL<Node<Skiing>> ski;
  fill_ski(ski);
  DLL<Node<Snowshoe>> shoe;
  fill_shoe(shoe);
  DLL<Node<Skating>> skate;
  fill_skate(skate);
  welcome();
  menu();
}

int menu()
{
   std::cout << "==================================================================\n";
   std::cout << "                         MENU" << std::endl;
   std::cout << "==================================================================\n";
  
   std::cout << "===============================\n";
   std::cout << "1) \n"; 
   std::cout << "2) \n"; 
   std::cout << "3) \n";
   std::cout << "4) \n";
   std::cout << "5) \n";
   std::cout << "6) \n";
   std::cout << "7) \n";
   std::cout << "8) \n";
   std::cout << std::endl;
   std::cout << "0) Exit Program\n";
   std::cout << "Enter: ";
   return 0;
}

// Returns-> Integer value for the menu choice
int validate_menu_choice()
{
  int menu_choice_int = 0;
  cin >> menu_choice_int;
  std::cin.ignore(100, '\n');
 
  while (menu_choice_int > 8 || menu_choice_int < 0) 
  {
    cout << "Please select a valid menu item." << endl;
    cin >> menu_choice_int;
    std::cin.ignore(100, '\n');
  }
  return menu_choice_int;
}

// Provides option processing for the menu 
void processChoice (int& flag, int menu_choice)
{
  // Takes in user input for menu choice and calls the appropriate function.
  int no = 0;
  int proceed = 1;
  switch(menu_choice)
    {
      case 0:
        {
          cout << "Are you sure you want to exit?" << endl;
          proceed = no;
          break;
        }

      // Display full graph 
      case 1: 
        {
          break;
        }

      // Insert Vertex
      case 2:
        {
          break;         
        }

      // Insert edge
      case 3: 
        {
          break;
        }

      // Display adjacent
      case 4: 
        {
          break;
        }

      // Provide a backstop for out of bounds menu choices.
      default:
          break;
    }

    if (proceed == no)
    {
      cout << "Enter 0 to end program.\n" << endl;
      cout << "Enter any other number to continue program.\n" << endl;
      cin >> flag;
      cin.ignore(100, '\n');
    }
}

int fill_ski(DLL<Node<Skiing>> & dll)
{
  Skiing s1 = Skiing(50.0, 40.0, 20, 10, "Timberline" ); 
  Skiing s2 = Skiing(90.0, 80.0, 10, 20, "Mt hood"); 
  Skiing s3 = Skiing(100.0, 70.0, 10, 20, "Bend"); 
  dll.insert(s1);
  dll.insert(s2);
  dll.insert(s3);
  return 0;
}

int fill_shoe(DLL<Node<Snowshoe>> & dll)
{
  Snowshoe s1 = Snowshoe(1.5, 3, "Short trail", "Mt. Hood"); 
  Snowshoe s2 = Snowshoe(5.5, 5, "Long trail", "Timberline"); 
  Snowshoe s3 = Snowshoe(3.0, 4, "Medium trail", "Bend"); 
  dll.insert(s1);
  dll.insert(s2);
  dll.insert(s3);
  return 0;
}

int fill_skate(DLL<Node<Skating>> & dll)
{
  Skating s1 = Skating(15.99, 20.99, false, "Sherwood Ice Arena", "Sherwood"); 
  Skating s2 = Skating(19.99, 24.99, true, "Winterhawks Skating Center", "Beaverton"); 
  Skating s3 = Skating(13.99, 19.99, false, "Lloyd Center Ice Rink", "Portland"); 
  dll.insert(s1);
  dll.insert(s2);
  dll.insert(s3);
  return 0;
}

int welcome()
{
  cout << "IT IS WINTER TIME!\n" << endl;
  cout << "With winter weather here we now have the ability to try lots of fun activities." << endl;
  cout << "This program includes information for 3 different activities that might be cool to try." << endl;
  cout << "Check out the information that we have!" << endl;
  cout << "Don't forget to check back later as more information is continuosly added." << endl;
  return 0;
}


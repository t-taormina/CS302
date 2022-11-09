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
  int flag = 1;
  while (flag)
  {
    menu();
    int choice = validate_menu_choice();
    process_main(flag, choice, ski, shoe, skate);
  }
  return 0;
}

int menu()
{
   std::cout << "==================================================================\n";
   std::cout << "                         MAIN MENU" << std::endl;
   std::cout << "==================================================================\n";
  
   std::cout << "===============================\n";
   std::cout << "1) Skiing Menu.\n"; 
   std::cout << "2) Snowshoe Menu.\n"; 
   std::cout << "3) Ice Skating Menu.\n";
   std::cout << "4) Display All Activity Options.\n";
   std::cout << "5) Display Beginner Options For Each Sport.\n";
   std::cout << std::endl;
   std::cout << "0) Exit Program\n";
   std::cout << "Enter: ";
   return 0;
}

void ski_menu()
{
   std::cout << "==================================================================\n";
   std::cout << "                         SKI MENU" << std::endl;
   std::cout << "==================================================================\n";
  
   std::cout << "===============================\n";
   std::cout << "1) .\n"; 
   std::cout << "2) .\n"; 
   std::cout << "3) .\n";
   std::cout << "4) Add review.\n";
   std::cout << "5) Rate an activity at a given location.\n";
   std::cout << std::endl;
   std::cout << "0) Return to main menu.\n";
   std::cout << "Enter: ";
}

void shoe_menu()
{
   std::cout << "==================================================================\n";
   std::cout << "                         SNOWSHOE MENU" << std::endl;
   std::cout << "==================================================================\n";
  
   std::cout << "===============================\n";
   std::cout << "1) .\n"; 
   std::cout << "2) .\n"; 
   std::cout << "3) .\n";
   std::cout << "4) Add review.\n";
   std::cout << "5) Rate an activity at a given location.\n";
   std::cout << std::endl;
   std::cout << "0) Return to main menu.\n";
   std::cout << "Enter: ";
}

void skate_menu()
{
   std::cout << "==================================================================\n";
   std::cout << "                         ICE SKATING MENU" << std::endl;
   std::cout << "==================================================================\n";
  
   std::cout << "===============================\n";
   std::cout << "1) .\n"; 
   std::cout << "2) .\n"; 
   std::cout << "3) .\n";
   std::cout << "4) Add review.\n";
   std::cout << "5) Rate an activity at a given location.\n";
   std::cout << std::endl;
   std::cout << "0) Return to main menu.\n";
   std::cout << "Enter: ";
}

// Returns-> Integer value for the menu choice
int validate_menu_choice()
{
  int menu_choice_int = 0;
  cin >> menu_choice_int;
  std::cin.ignore(100, '\n');
 
  while (menu_choice_int > 5 || menu_choice_int < 0) 
  {
    cout << "Please select a valid menu item." << endl;
    cin >> menu_choice_int;
    std::cin.ignore(100, '\n');
  }
  return menu_choice_int;
}

// Provides option processing for the menu 
void process_main (int& flag, int menu_choice, DLL<Node<Skiing>>& ski, DLL<Node<Snowshoe>>& shoe, DLL<Node<Skating>>& skate)
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
 
      // Ski submenu.
      case 1: 
        {
          int sub_flag = 1;
          while (sub_flag)
          {
            ski_menu();
            int choice = validate_menu_choice();
            process_ski(sub_flag, choice, ski);
          }
          break;
        }

      // Shoe submenu.
      case 2:
        {
          int sub_flag = 1;
          while (sub_flag)
          {
            shoe_menu();
            int choice = validate_menu_choice();
            process_shoe(sub_flag, choice, shoe);
          }
          break;         
        }

      // Skating submenu.
      case 3: 
        {
          int sub_flag = 1;
          while (sub_flag)
          {
            skate_menu();
            int choice = validate_menu_choice();
            process_skate(sub_flag, choice, skate);
          }
          break;
        }

      // Display all.
      case 4: 
        {
          cout << "              SKIING" << endl;
          cout << "----------------------------------------" << endl;
          ski.display();

          cout << "              SNOWSHOE" << endl;
          cout << "----------------------------------------" << endl;
          shoe.display();

          cout << "              SKATING" << endl;
          cout << "----------------------------------------" << endl;
          skate.display();
          break;
        }

      // Display adjacent
      case 5: 
        {
          cout << "              SKIING" << endl;
          cout << "----------------------------------------" << endl;
          ski.display_cheapest();

          cout << "              SNOWSHOE" << endl;
          cout << "----------------------------------------" << endl;
          shoe.display_cheapest();

          cout << "              SKATING" << endl;
          cout << "----------------------------------------" << endl;
          skate.display_cheapest();
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

// Provides option processing for the menu 
void process_ski(int& flag, int menu_choice, DLL<Node<Skiing>>& ski)
{
  // Takes in user input for menu choice and calls the appropriate function.
  int no = 0;
  switch(menu_choice)
    {
      case 0:
        {
          flag = no;
          break;
        }
 
      case 1: 
        {
          break;
        }

      case 2:
        {
          break;         
        }

      case 3: 
        {
          break;
        }

      case 4: 
        {
          break;
        }

      case 5: 
        {
          break;
        }

      // Provide a backstop for out of bounds menu choices.
      default:
          break;
    }
}

// Provides option processing for the menu 
void process_shoe(int& flag, int menu_choice, DLL<Node<Snowshoe>>& shoe)
{
  // Takes in user input for menu choice and calls the appropriate function.
  int no = 0;
  switch(menu_choice)
    {
      case 0:
        {
          flag = no;
          break;
        }
 
      // Ski submenu.
      case 1: 
        {
          break;
        }

      // Shoe submenu.
      case 2:
        {
          break;         
        }

      // Skating submenu.
      case 3: 
        {
          break;
        }

      // Display all.
      case 4: 
        {
          break;
        }

      // Display adjacent
      case 5: 
        {
          break;
        }

      // Provide a backstop for out of bounds menu choices.
      default:
          break;
    }
}

// Provides option processing for the menu 
void process_skate(int& flag, int menu_choice, DLL<Node<Skating>>& skate)
{
  // Takes in user input for menu choice and calls the appropriate function.
  int no = 0;
  switch(menu_choice)
    {
      case 0:
        {
          flag = no;
          break;
        }
 
      case 1: 
        {
          break;
        }

      case 2:
        {
          break;         
        }

      case 3: 
        {
          break;
        }

      case 4: 
        {
          break;
        }

      case 5: 
        {
          break;
        }

      // Provide a backstop for out of bounds menu choices.
      default:
          break;
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
  cout << "Check out the information that is here!" << endl;
  cout << "Don't forget to check back later as more information is continuosly added.\n" << endl;
  return 0;
}


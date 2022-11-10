// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

#include "client.h"

// Test functions
int test_ski();
int test_shoe();
int test_skate();
int test_node();

// Program driver
int main()
{
    return run();
}

// Testing functions
// ==================================================================================
int test_node()
{
  /*
  Skating s1 = Skating(15.99, 20.99, false, "Sherwood Ice Arena", "Sherwood"); 
  Skating s2 = Skating(19.99, 24.99, true, "Winterhawks Skating Center", "Beaverton"); 
  Skating s3 = Skating(13.99, 19.99, false, "Lloyd Center Ice Rink", "Portland"); 
  Snowshoe s1 = Snowshoe(1.5, 3, "Short trail", "Mt. Hood"); 
  Snowshoe s2 = Snowshoe(5.5, 5, "Long trail", "Timberline"); 
  Snowshoe s3 = Snowshoe(3.0, 4, "Medium trail", "Bend"); 
  */
  Skiing s1 = Skiing(50.0, 40.0, 20, 10, "Timberline" ); 
  Skiing s2 = Skiing(90.0, 80.0, 10, 20, "Mt hood"); 
  Skiing s3 = Skiing(100.0, 70.0, 10, 20, "Bend"); 
  
  /*
  Node<Skating> node = Node<Skating>(s1);
  Node<Skating> n1 = Node<Skating>(s2);
  Node<Skating> node2 = node; //= Node<Skating>(s1);
  node.display();
  node2.display();
  node2.set_data(n1.get_data());
  node2.display();
  */
  DLL<Node<Skiing>> d1;
  d1.insert(s3);
  d1.insert(s1);
  d1.insert(s2);

  DLL<Node<Skiing>> d2; //= DLL<Node<Skating>>();
  d2.copy(d1);// = d1;

  //cout << "SKATING" << endl;
  //cout << "SNOWSHOE" << endl;
  cout << "SKIING" << endl;
  cout << "====================================" << endl;
  d1.display();

  //cout << "CHEAPEST SKATING" << endl;
  //cout << "CHEAPEST SNOWSHOE" << endl;
  cout << "CHEAPEST SKIING" << endl;
  cout << "====================================" << endl;

  d2.display_cheapest();
  return 0;
}

int test_ski()
{
  Skiing s1 = Skiing(50.0, 40.0, 20, 10, "Timberline" ); 
  Skiing s2 = Skiing(90.0, 80.0, 10, 20, "Mt hood"); 

  if (s2 > s1)
    cout << "Passed" << endl;
  if (s2 >= s1)
    cout << "Passed" << endl;
  if (!(s2 < s1))
    cout << "Passed" << endl;
  if (!(s2 <= s1))
    cout << "Passed" << endl;

  int avg = s2.avg_rating();
  cout << "Average rating: " << avg << endl;
  Skiing s3 = Skiing(s2);
  cout << s3 << endl;
  for (auto i = 0; i < 3; i++)
  {
    s3.rate();
  }
  avg = s3.avg_rating();
  cout << "Average rating: " << avg << endl;
  Skiing s4 = Skiing();
  s4 = s3;
  cout << s4 << endl;
  avg = s4.avg_rating();
  cout << "Average rating: " << avg << endl;
  return 0;
}

int test_shoe()
{
  Snowshoe s1 = Snowshoe(1.5, 3, "Short trail", "Mt. Hood"); 
  Snowshoe s2 = Snowshoe(5.5, 5, "Long trail", "Timberline"); 
  Snowshoe s3 = Snowshoe(3.0, 4, "Medium trail", "Bend"); 

  if (s2 > s1)
    cout << "Passed" << endl;
  if (s2 >= s1)
    cout << "Passed" << endl;
  if (!(s2 < s1))
    cout << "Passed" << endl;
  if (!(s2 <= s1))
    cout << "Passed" << endl;

  int avg = s2.avg_rating();
  cout << "Average rating: " << avg << endl;
  Snowshoe s4 = Snowshoe (s2);
  cout << s4 << endl;
  for (auto i = 0; i < 3; i++)
  {
    s3.rate();
  }
  avg = s3.avg_rating();
  cout << "Average rating: " << avg << endl;
  Snowshoe s5 = Snowshoe();
  s5 = s1;
  cout << s5 << endl;
  avg = s5.avg_rating();
  cout << "Average rating: " << avg << endl;
  return 0;
}

int test_skate()
{
  Skating s1 = Skating(15.99, 20.99, false, "Sherwood Ice Arena", "Sherwood"); 
  Skating s2 = Skating(19.99, 24.99, true, "Winterhawks Skating Center", "Beaverton"); 

  if (s2 > s1)
    cout << "Passed" << endl;
  if (s2 >= s1)
    cout << "Passed" << endl;
  if (!(s2 < s1))
    cout << "Passed" << endl;
  if (!(s2 <= s1))
    cout << "Passed" << endl;

  int avg = s2.avg_rating();
  cout << "Average rating: " << avg << endl;
  Skating s3 = Skating (s2);
  cout << s3 << endl;
  for (auto i = 0; i < 3; i++)
  {
    s3.rate();
  }
  avg = s3.avg_rating();
  cout << "Average rating: " << avg << endl;
  Skating s4 = Skating();
  s4 = s3;
  cout << s4 << endl;
  avg = s4.avg_rating();
  cout << "Average rating: " << avg << endl;
  return 0;
}

/* 
 NO USE
friend int operator<(const Activity&, const Activity&); 
friend int operator<=(const Activity&, const Activity&); 
friend int operator>(const Activity&, const Activity&); 
friend int operator>=(const Activity&, const Activity&);
bool operator != (const Activity& arg) const;
*/


/*
int success = test_ski();
success = test_shoe();
success = test_skate();
int success = test_node();
cout << success;
*/

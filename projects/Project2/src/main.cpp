// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

#include "activity.h"

int test_ski();
int test_shoe();
int test_skate();

int main()
{
  int success = test_ski();
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
  //cin >> a2 >> endl;

}

int test_shoe()
{}

int test_skate()
{}


  /*
  a1 = Activity("Timberline", 2);
  Activity a2 = Activity(a1);
  cout << a1 << endl;
  cout << a2 << endl;
  if (a1 == a2) 
    cout << "True" << endl;
  else
    cout << "False" << endl;

  


  a2.display(); 

  int lvl = 1;
  cin >> a2 >> endl;

  ++a1;
  if (a1 == a2) 
    cout << "True" << endl;
  else
    cout << "False" << endl;
  cout << a1 << endl;
  a2.display();
  a2 = a1;

  
 NO USE
friend int operator<(const Activity&, const Activity&); 
friend int operator<=(const Activity&, const Activity&); 
friend int operator>(const Activity&, const Activity&); 
friend int operator>=(const Activity&, const Activity&);
bool operator != (const Activity& arg) const;
*/



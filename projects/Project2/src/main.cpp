// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

#include "activity.h"

int main()
{
  int lvl = 1;
//  cin >> a2 >> endl;
  char loc[9] = "Mt. Hood";
  char loc2[11] = "Timberline";
  Skiing s1 = Skiing(loc, 50.0, 40.0, 2); 
  Skiing s2 = Skiing(loc2, 90.0, 80.0, 2); 

  if (s2 > s1)
    cout << "Passed" << endl;
  if (s2 >= s1)
    cout << "Passed" << endl;
  if (!(s2 < s1))
    cout << "Passed" << endl;
  if (!(s2 <= s1))
    cout << "Passed" << endl;
  /*
  for (auto i = 0; i < 3; i++)
  {
    s2.add_rating();
  }
  int avg = s2.avg_rating();
  cout << "Average rating: " << avg << endl;
  Skiing s3 = Skiing(s2);
  cout << s3 << endl;
  avg = s3.avg_rating();
  cout << "Average rating: " << avg << endl;
  */
  return 0;
}
/*
 char seas[7] = "winter";
  int lvl = 1;
  Activity a1 = Activity(lvl);
  Activity a2 = Activity(a1);
  cout << a1 << endl;
  cout << a2 << endl;
  if (a1 == a2) 
    cout << "True" << endl;
  else
    cout << "False" << endl;

  ++a1;
  if (a1 == a2) 
    cout << "True" << endl;
  else
    cout << "False" << endl;
  cout << a1 << endl;
  a2.display();
  a2 = a1;
  a2.display();
  //cin >> a2 >> endl;
*/

/* NO USE
friend int operator<(const Activity&, const Activity&); 
friend int operator<=(const Activity&, const Activity&); 
friend int operator>(const Activity&, const Activity&); 
friend int operator>=(const Activity&, const Activity&);
bool operator != (const Activity& arg) const;
*/



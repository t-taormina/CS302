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
  success = test_shoe();
  success = test_skate();
  cout << success;
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
  Snowshoe s1 = Snowshoe(); 
  Snowshoe s2 = Snowshoe(); 

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
  Snowshoe s3 = Snowshoe (s2);
  cout << s3 << endl;
  for (auto i = 0; i < 3; i++)
  {
    s3.rate();
  }
  avg = s3.avg_rating();
  cout << "Average rating: " << avg << endl;
  Snowshoe s4 = Snowshoe();
  s4 = s3;
  cout << s4 << endl;
  avg = s4.avg_rating();
  cout << "Average rating: " << avg << endl;
  return 0;
}

int test_skate()
{
  Skating s1 = Skating(); 
  Skating s2 = Skating(); 

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



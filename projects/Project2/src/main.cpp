// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 2 CS302

#include "activity.h"

int main()
{
  char seas[7] = "winter";
  int lvl = 1;
  Activity a1 = Activity(seas,lvl);
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
  return 0;
}

/* NO USE
friend int operator<(const Activity&, const Activity&); 
friend int operator<=(const Activity&, const Activity&); 
friend int operator>(const Activity&, const Activity&); 
friend int operator>=(const Activity&, const Activity&);
bool operator != (const Activity& arg) const;
*/



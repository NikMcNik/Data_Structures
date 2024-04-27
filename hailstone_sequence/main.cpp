#include <iostream>
using namespace std;

int main()
{
   int n;
   cin >> n;

   int numCount = 0;

   while (n != 1)
   {
      cout << n << "\t";
      numCount++;

      if ((n % 2) == 0)
      {
         n = n / 2;
      }
      else if ((n % 2) != 0)
      {
         n = (n * 3) + 1;
      }

      if (numCount == 10)
      {
         numCount = 0;
         cout << endl;
      }
   }
   cout << n << endl;
   return 0;
}

#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

int main()
{

   string x;

   cout << "Do you like vi as an editor? Answer in true(0) or false(1) " << endl;

   cin >> x;

   if (x == true)
   {
      cout << "You love vi!";
   }
   else {if (x == false)
      {
	 cout << "You hate vi!";
      }

   }
   return 0;
}

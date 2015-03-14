//#include <iostrem>
#include <iostream>
#include <cmath>

//Defines the specific weight of water
#define WATER_WEIGHT 62.4;

using std::cout;
using std::cin;

//int main 
int main()
{
   //Variables needed to calculate buoyancy
   int radius, bforce, volume, weight; 

   //Prompt user for weight and radius of sphere
   cout << "Please enter the weight (lbs): ";
   cin >> weight;
   
   //cout >> "Please enter the radius: ";
   //cin << radius;
   cout << "Please enter the radius: ";
   cin >> radius;

   //Calculate the volume and buoyancy force
   //volume = 4./3. * PI * power(r, 3); 
   //b_force = voluemm * WATER_WIEGHT;
   volume = 4/3 * M_PI * pow(radius, 3);
   bforce = volume * WATER_WEIGHT;
   
   //Determine if the sphere will sink or float
   //if(bforce >== weight)
   if(bforce >= weight)
   {
      //cout >> "The sphere will float!\n";
      cout << "The sphere will float \n";
   }
   //else;
   else
   {
     cout << "The sphere will sink!\n"; 
   }

   return 0;
}

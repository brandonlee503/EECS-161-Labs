#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//Functions
bool is_positive_int_recursive(string input);

int main(int argc, char *argv[])
{
    //Check parameters
    if(argc > 2)
    {
        //Char*[] --> string
        string input = "";
        for(int i = 1; i < argc; i++)
        {
            input += argv[i];
        }
        
        //Check input
        bool valid = true;
        while(!is_positive_int_recursive(input))
        {
            cout << "Your parameter input must be a postive integers!" << endl;
            valid = false;
            break;
        }
        
        //Numbers to count
        if(valid)
        {
             int a = atoi(argv[1]);
             int b = atoi(argv[2]);
             
             for(int i = a; i <= b; i++)
             {
             cout << i << " ";
             }
             cout << endl;
        }
    }
    else
    {
        cout << "You must have two parameters!" << endl;
    }
    
    
    return 0;
}

//Recursive error checking
bool is_positive_int_recursive(string input)
{
    if(input.size() > 0)
    {
    	int index = input.size() - 1;
    	
        if(!(input.at(index) == '0' || input.at(index) == '1' || input.at(index) == '2' || input.at(index) == '3' || input.at(index) == '4' ||
             input.at(index) == '5' || input.at(index) == '6' ||  input.at(index) == '7' || input.at(index) == '8' || input.at(index) == '9'))
        {
            return false;
        }
        else
        {
        	//Modify our input
        	input = input.substr(0, input.size() - 1);
        	is_positive_int_recursive(input);
        }
    }
    
    return true;
}






#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//Function declarations
string get_positive_int();
bool is_positive_int(string input);
bool is_positive_int_recursive(string input);

int main()
{
    //Welcome user and Get user input
    cout << "Woo, lets do some counting!" << endl;
    
    //Program loop
    bool quit = false;
    while(!quit)
    {
        //Get user input
        string input = "";
        input = get_positive_int();
       // while(!is_positive_int(input))
        while(!is_positive_int_recursive(input))
        {
            cout << "Your input must be a postive integer!" << endl;
            
            //Try again
            input = get_positive_int();
        }

        //Since error checking worked out, convert to int
        int dec_num = atoi(input.c_str());
        cout << "THE NUM INPUT WAS: " << dec_num << endl;
        
        //Ask the user if they would like to waste more time
        char derp;
        cout << "\nWould you like to do more counting [Y/n]? ";
        cin >> derp;

        if(derp == 'Y' || derp == 'y') continue;
        if(derp == 'N' || derp == 'n') quit = true;
    }

    return 0;
}

//Get user input
string get_positive_int()
{
    string input = "";
    cout << "Please input a postive integer: ";
    cin >> input;

    return input;
}

//Error checking
bool is_positive_int(string input)
{
    //Make sure the first element of the string input isn't a 0 or -
    if(input.at(0) != '0' && input.at(0) != '-')
    {
        //Check each part of the string
        for(int x = 0; x < input.size(); x++)
        {
            if(!(input.at(x) == '0' || input.at(x) == '1' || input.at(x) == '2' || input.at(x) == '3' || input.at(x) == '4' ||
                input.at(x) == '5' || input.at(x) == '6' ||  input.at(x) == '7' || input.at(x) == '8' || input.at(x) == '9'))
            {
                return false;
            }
        }

        return true;
    }
    else
    {
        return false;
    }
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

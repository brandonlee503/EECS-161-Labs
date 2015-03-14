#include <iostream>

using namespace std;

#define DISKS 4 //Number of disks to maipulate - Default 2
#define COLS 3 //There are 3 pegs with Tower of Hanoi - Default 3

//Function declarations
void print_array(int b[][COLS]);
void towers(int diskSize, int b[][COLS], int source, int dest, int spare);

int main()
{
    //Init our 2D Towers array
    int b[DISKS][COLS] = {0};
    for(int i = 0; i < DISKS; i++)
    {
        b[i][0] = i + 1;
    }
    
    //Print the board and go!
    print_array(b);
    towers(DISKS, b, 0, 1, 2);
    
}

//Outputs the array passed via parameter
void print_array(int b[][COLS])
{
    for(int row = 0; row < DISKS; row++)
    {
        for(int col = 0; col < COLS; col++)
        {
            cout << b[row][col] << "  ";
        }
        cout << endl;
    }
    cout << "--------" << endl;
}

//Hanoi Magic w/ Recursion
void towers(int diskSize, int b[][COLS], int source, int dest, int spare)
{
    if(diskSize != 0)
    {
        //Move all disks smaller than this one over to the spare
		towers(diskSize - 1, b, source, spare, dest);
        
		//Move the remaining disk to the destination peg
		//cout << "Move disk "  << diskSize << " from peg " << source << " to peg " << dest << endl;
        b[diskSize - 1][dest] = b[diskSize - 1][source];
        b[diskSize - 1][source] = 0;
        
        //Output results of this step
        print_array(b);
        
		//Move the disks we just moved to the spare back over to the dest peg
		towers(diskSize - 1, b, spare, dest, source);
	}
}

#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

#define DIRECTION_RIGHT "RIGHT"
#define DIRECTION_DOWN "DOWN"

using namespace std;

int main()
{
	//1 player or 2 player?
	bool TWO_PLAYER = false; //True if two player, false if one player
	
	//Output directions
	cout << "* Directions: " << endl;
	cout << "\tEach player will place their fleet of 5 ships on the board, after that, each" << endl;
	cout << "\tplayer will take turns picking target areas on the board to attack. If a" << endl;
	cout << "\ttarget area you are attacking has an enemy ship, you will damage that ship." << endl;
	cout << "\tAfter so many hits on an enemy ship, you will sink that ship. The first person" << endl;
	cout << "\tto sink all the ships will win." << endl;
	
	//Number of players
	while(true)
    {
        string num_players = "";
        cout << "* Game Setup:" << endl;
	    cout << "\tHow many players (1-2)? ";
        cin >>  num_players;
    
        //Check if input was correct
        if(num_players != "1" && num_players != "2")
        {
            cout << "* This game only supports 1 player, or 2 player." << endl;
            cout << "* Please input a 1 or a 2." << endl << endl;
            continue;
        }
        else 
        {
        	if(num_players == "1") TWO_PLAYER = false;
        	if(num_players == "2") TWO_PLAYER = true;
        	break;
        }
    }
    

	//Player 1 Ship placement (cords)
    string P1_carrier_loc = "";
    string P1_battle_loc = "";
    string P1_cruiser_loc = "";
    string P1_submarine_loc = "";
    string P1_destroyer_loc = "";

    //Player 1 Ship direction (DOWN or RIGHT)
    string P1_carrier_dir = "";
    string P1_battle_dir = "";
    string P1_cruiser_dir = "";
    string P1_submarine_dir = "";
    string P1_destroyer_dir = "";
    
    //Player 2 Ship placement (cords)
    string P2_carrier_loc = "";
    string P2_battle_loc = "";
    string P2_cruiser_loc = "";
    string P2_submarine_loc = "";
    string P2_destroyer_loc = "";

    //Player 2 Ship direction (DOWN or RIGHT)
    string P2_carrier_dir = "";
    string P2_battle_dir = "";
    string P2_cruiser_dir = "";
    string P2_submarine_dir = "";
    string P2_destroyer_dir = "";

	cout << "* Player 1 Ship Placement:" << endl;
	cout << "\t----------------------" << endl;
	cout << "\tx| 1 | 2 | 3 | 4 | 5 |" << endl;
	cout << "\t----------------------" << endl;
	cout << "\tA|   |   |   |   |   |" << endl;
	cout << "\t----------------------" << endl;
	cout << "\tB|   |   |   |   |   |" << endl;
	cout << "\t----------------------" << endl;
	cout << "\tC|   |   |   |   |   |" << endl;
	cout << "\t----------------------" << endl;
	cout << "\tD|   |   |   |   |   |" << endl;
	cout << "\t----------------------" << endl;
	cout << "\tE|   |   |   |   |   |" << endl;
	cout << "\t----------------------" << endl;
	cout << "\tFor the following questions, please give the coordinates you would like to place each ship" << endl;
	cout << "\tFor example, input D-4 to place a ship at position D4 on the game board" << endl << endl; 
	
    //Carrier ship placement
    while(true)
    {
        cout << "\tWhere would you like to place your carrier ship? ";
        cin >> P1_carrier_loc;

        //Check placement input
        string row = "";
        string col = "";
        
        if(P1_carrier_loc.find("-") != string::npos)
        {
            row = P1_carrier_loc.substr(0, P1_carrier_loc.find("-"));
            col = P1_carrier_loc.substr(P1_carrier_loc.find("-") + 1);
        }
        else
        {
            cout << "\t * You must follow the format ROW-COL, for example: " << endl;
            cout << "\t * If you want to place your ship at D4, please input D-4." << endl;
            cout << "\t * The dash \"-\" is required!" << endl;
            continue;
        }

        //Check row placement
        if(row == "A" || row == "B" || row == "C" || row == "D" || row == "E" ||
            row == "a" || row == "b" || row == "c" || row == "d" || row == "e")
        {
            //Check col placement
        	if(col == "1" || col == "2" || col == "3" || col == "4" || col == "5")
        	{
        		break;
        	}
        	else
        	{
            	cout << "\t * You must input a valid col to place your ship!" << endl;
            	cout << "\t * Valid cols are 1, 2, 3, 4, 5. " << endl;
            	continue;
        	}
        }
        else
        {
            cout << "\t * You must input a valid row to place your ship!" << endl;
            cout << "\t * Valid rows are A, B, C, D, E." << endl;
            continue;
        }
	}
	
	//Carrier ship direction
	while(true)
	{
		cout << "\tWhat direction would you like place your carrier ship (DOWN or RIGHT): ";
		cin >> P1_carrier_dir;
		
		//Check if the user inputted the correct direction
		if(!(P1_carrier_dir == DIRECTION_DOWN || P1_carrier_dir == DIRECTION_RIGHT))
		{ 
			cout << "\t * You must input a valid direction, either DOWN or RIGHT!" << endl;
			continue;
		}
		else
		{
			break;
		}
	}
	
	//Battleship placement
	while(true)
	{
    	cout << "\tWhere would you like to place your battle ship? ";
    	cin >> P1_battle_loc;
    	
    	//Check placement input
        string row = "";
        string col = "";
        
        if(P1_battle_loc.find("-") != string::npos)
        {
            row = P1_battle_loc.substr(0, P1_battle_loc.find("-"));
            col = P1_battle_loc.substr(P1_battle_loc.find("-") + 1);
        }
        else
        {
            cout << "\t * You must follow the format ROW-COL, for example: " << endl;
            cout << "\t * If you want to place your ship at D4, please input D-4." << endl;
            cout << "\t * The dash \"-\" is required!" << endl;
            continue;
        }

        //Check row placement
        if(row == "A" || row == "B" || row == "C" || row == "D" || row == "E" ||
            row == "a" || row == "b" || row == "c" || row == "d" || row == "e")
        {
            //Check col placement
        	if(col == "1" || col == "2" || col == "3" || col == "4" || col == "5")
        	{
        		break;
        	}
        	else
        	{
            	cout << "\t * You must input a valid col to place your ship!" << endl;
            	cout << "\t * Valid cols are 1, 2, 3, 4, 5. " << endl;
            	continue;
        	}
        }
        else
        {
            cout << "\t * You must input a valid row to place your ship!" << endl;
            cout << "\t * Valid rows are A, B, C, D, E." << endl;
            continue;
        }
    }
    
    //Battle ship direction
	while(true)
	{
		cout << "\tWhat direction would you like place your battle ship (DOWN or RIGHT): ";
		cin >> P1_battle_dir;
		
		//Check if the user inputted the correct direction
		if(!(P1_battle_dir == DIRECTION_DOWN || P1_battle_dir == DIRECTION_RIGHT))
		{ 
			cout << "\t * You must input a valid direction, either DOWN or RIGHT!" << endl;
			continue;
		}
		else
		{
			break;
		}
	}
	
	//Cruiser Ship Placement
	while(true)
	{    
    	cout << "\tWhere would you like to place your cruiser ship? ";
    	cin >> P1_cruiser_loc;
    	
    	//Check placement input
        string row = "";
        string col = "";
        
        if(P1_cruiser_loc.find("-") != string::npos)
        {
            row = P1_cruiser_loc.substr(0, P1_cruiser_loc.find("-"));
            col = P1_cruiser_loc.substr(P1_cruiser_loc.find("-") + 1);
        }
        else
        {
            cout << "\t * You must follow the format ROW-COL, for example: " << endl;
            cout << "\t * If you want to place your ship at D4, please input D-4." << endl;
            cout << "\t * The dash \"-\" is required!" << endl;
            continue;
        }

        //Check row placement
        if(row == "A" || row == "B" || row == "C" || row == "D" || row == "E" ||
            row == "a" || row == "b" || row == "c" || row == "d" || row == "e")
        {
            //Check col placement
        	if(col == "1" || col == "2" || col == "3" || col == "4" || col == "5")
        	{
        		break;
        	}
        	else
        	{
            	cout << "\t * You must input a valid col to place your ship!" << endl;
            	cout << "\t * Valid cols are 1, 2, 3, 4, 5. " << endl;
            	continue;
        	}
        }
        else
        {
            cout << "\t * You must input a valid row to place your ship!" << endl;
            cout << "\t * Valid rows are A, B, C, D, E." << endl;
            continue;
        }
    }
    
    //Cruiser ship direction
	while(true)
	{
		cout << "\tWhat direction would you like place your cruiser ship (DOWN or RIGHT): ";
		cin >> P1_cruiser_dir;
		
		//Check if the user inputted the correct direction
		if(!(P1_cruiser_dir == DIRECTION_DOWN || P1_cruiser_dir == DIRECTION_RIGHT))
		{ 
			cout << "\t * You must input a valid direction, either DOWN or RIGHT!" << endl;
			continue;
		}
		else
		{
			break;
		}
	}
	    
	//Submarine Placement
	while(true)
	{
    	cout << "\tWhere would you like to place your submarine ship? ";
    	cin >> P1_submarine_loc;
    	
    	//Check placement input
        string row = "";
        string col = "";
        
        if(P1_submarine_loc.find("-") != string::npos)
        {
            row = P1_submarine_loc.substr(0, P1_submarine_loc.find("-"));
            col = P1_submarine_loc.substr(P1_submarine_loc.find("-") + 1);
        }
        else
        {
            cout << "\t * You must follow the format ROW-COL, for example: " << endl;
            cout << "\t * If you want to place your ship at D4, please input D-4." << endl;
            cout << "\t * The dash \"-\" is required!" << endl;
            continue;
        }

        //Check row placement
        if(row == "A" || row == "B" || row == "C" || row == "D" || row == "E" ||
            row == "a" || row == "b" || row == "c" || row == "d" || row == "e")
        {
            //Check col placement
        	if(col == "1" || col == "2" || col == "3" || col == "4" || col == "5")
        	{
        		break;
        	}
        	else
        	{
            	cout << "\t * You must input a valid col to place your ship!" << endl;
            	cout << "\t * Valid cols are 1, 2, 3, 4, 5. " << endl;
            	continue;
        	}
        }
        else
        {
            cout << "\t * You must input a valid row to place your ship!" << endl;
            cout << "\t * Valid rows are A, B, C, D, E." << endl;
            continue;
        }
    }
    
    //Submarine direction
	while(true)
	{
		cout << "\tWhat direction would you like place your submarine (DOWN or RIGHT): ";
		cin >> P1_submarine_dir;
		
		//Check if the user inputted the correct direction
		if(!(P1_submarine_dir == DIRECTION_DOWN || P1_submarine_dir == DIRECTION_RIGHT))
		{ 
			cout << "\t * You must input a valid direction, either DOWN or RIGHT!" << endl;
			continue;
		}
		else
		{
			break;
		}
	}
	
	//Destroyer Ship Placement
	while(true)
	{    
    	cout << "\tWhere would you like to place your destroyer ship? ";
    	cin >> P1_destroyer_loc;	
    	
    	//Check placement input
        string row = "";
        string col = "";
        
        if(P1_destroyer_loc.find("-") != string::npos)
        {
            row = P1_destroyer_loc.substr(0, P1_destroyer_loc.find("-"));
            col = P1_destroyer_loc.substr(P1_destroyer_loc.find("-") + 1);
        }
        else
        {
            cout << "\t * You must follow the format ROW-COL, for example: " << endl;
            cout << "\t * If you want to place your ship at D4, please input D-4." << endl;
            cout << "\t * The dash \"-\" is required!" << endl;
            continue;
        }

        //Check row placement
        if(row == "A" || row == "B" || row == "C" || row == "D" || row == "E" ||
            row == "a" || row == "b" || row == "c" || row == "d" || row == "e")
        {
            //Check col placement
        	if(col == "1" || col == "2" || col == "3" || col == "4" || col == "5")
        	{
        		break;
        	}
        	else
        	{
            	cout << "\t * You must input a valid col to place your ship!" << endl;
            	cout << "\t * Valid cols are 1, 2, 3, 4, 5. " << endl;
            	continue;
        	}
        }
        else
        {
            cout << "\t * You must input a valid row to place your ship!" << endl;
            cout << "\t * Valid rows are A, B, C, D, E." << endl;
            continue;
        }
    }
    
    //Destroyer ship direction
	while(true)
	{
		cout << "\tWhat direction would you like place your destroyer ship (DOWN or RIGHT): ";
		cin >> P1_destroyer_dir;
		
		//Check if the user inputted the correct direction
		if(!(P1_destroyer_dir == DIRECTION_DOWN || P1_destroyer_dir == DIRECTION_RIGHT))
		{ 
			cout << "\t * You must input a valid direction, either DOWN or RIGHT!" << endl;
			continue;
		}
		else
		{
			break;
		}
	}
	
	//Second player ship setup (Other player or CPU?)
	if(TWO_PLAYER) 
	{
		cout << "* Player 2 Ship Placement:" << endl;
		cout << "\t----------------------" << endl;
		cout << "\tx| 1 | 2 | 3 | 4 | 5 |" << endl;
		cout << "\t----------------------" << endl;
		cout << "\tA|   |   |   |   |   |" << endl;
		cout << "\t----------------------" << endl;
		cout << "\tB|   |   |   |   |   |" << endl;
		cout << "\t----------------------" << endl;
		cout << "\tC|   |   |   |   |   |" << endl;
		cout << "\t----------------------" << endl;
		cout << "\tD|   |   |   |   |   |" << endl;
		cout << "\t----------------------" << endl;
		cout << "\tE|   |   |   |   |   |" << endl;
		cout << "\t----------------------" << endl;
		cout << "\tFor the following questions, please give the coordinates you would like to place each ship" << endl;
		cout << "\tFor example, input D-4 to place a ship at position D4 on the game board" << endl << endl; 
	
		//Carrier ship placement
		while(true)
		{
			cout << "\tWhere would you like to place your carrier ship? ";
			cin >> P2_carrier_loc;

			//Check placement input
			string row = "";
			string col = "";
		
			if(P2_carrier_loc.find("-") != string::npos)
			{
				row = P2_carrier_loc.substr(0, P2_carrier_loc.find("-"));
				col = P2_carrier_loc.substr(P2_carrier_loc.find("-") + 1);
			}
			else
			{
				cout << "\t * You must follow the format ROW-COL, for example: " << endl;
				cout << "\t * If you want to place your ship at D4, please input D-4." << endl;
				cout << "\t * The dash \"-\" is required!" << endl;
				continue;
			}

			//Check row placement
			if(row == "A" || row == "B" || row == "C" || row == "D" || row == "E" ||
				row == "a" || row == "b" || row == "c" || row == "d" || row == "e")
			{
				//Check col placement
				if(col == "1" || col == "2" || col == "3" || col == "4" || col == "5")
				{
					break;
				}
				else
				{
					cout << "\t * You must input a valid col to place your ship!" << endl;
					cout << "\t * Valid cols are 1, 2, 3, 4, 5. " << endl;
					continue;
				}
			}
			else
			{
				cout << "\t * You must input a valid row to place your ship!" << endl;
				cout << "\t * Valid rows are A, B, C, D, E." << endl;
				continue;
			}
		}
	
		//Carrier ship direction
		while(true)
		{
			cout << "\tWhat direction would you like place your carrier ship (DOWN or RIGHT): ";
			cin >> P2_carrier_dir;
		
			//Check if the user inputted the correct direction
			if(!(P2_carrier_dir == DIRECTION_DOWN || P2_carrier_dir == DIRECTION_RIGHT))
			{ 
				cout << "\t * You must input a valid direction, either DOWN or RIGHT!" << endl;
				continue;
			}
			else
			{
				break;
			}
		}
	
		//Battleship placement
		while(true)
		{
			cout << "\tWhere would you like to place your battle ship? ";
			cin >> P2_battle_loc;
		
			//Check placement input
			string row = "";
			string col = "";
		
			if(P2_battle_loc.find("-") != string::npos)
			{
				row = P2_battle_loc.substr(0, P2_battle_loc.find("-"));
				col = P2_battle_loc.substr(P2_battle_loc.find("-") + 1);
			}
			else
			{
				cout << "\t * You must follow the format ROW-COL, for example: " << endl;
				cout << "\t * If you want to place your ship at D4, please input D-4." << endl;
				cout << "\t * The dash \"-\" is required!" << endl;
				continue;
			}

			//Check row placement
			if(row == "A" || row == "B" || row == "C" || row == "D" || row == "E" ||
				row == "a" || row == "b" || row == "c" || row == "d" || row == "e")
			{
				//Check col placement
				if(col == "1" || col == "2" || col == "3" || col == "4" || col == "5")
				{
					break;
				}
				else
				{
					cout << "\t * You must input a valid col to place your ship!" << endl;
					cout << "\t * Valid cols are 1, 2, 3, 4, 5. " << endl;
					continue;
				}
			}
			else
			{
				cout << "\t * You must input a valid row to place your ship!" << endl;
				cout << "\t * Valid rows are A, B, C, D, E." << endl;
				continue;
			}
		}
	
		//Battle ship direction
		while(true)
		{
			cout << "\tWhat direction would you like place your battle ship (DOWN or RIGHT): ";
			cin >> P2_battle_dir;
		
			//Check if the user inputted the correct direction
			if(!(P2_battle_dir == DIRECTION_DOWN || P2_battle_dir == DIRECTION_RIGHT))
			{ 
				cout << "\t * You must input a valid direction, either DOWN or RIGHT!" << endl;
				continue;
			}
			else
			{
				break;
			}
		}
	
		//Cruiser Ship Placement
		while(true)
		{    
			cout << "\tWhere would you like to place your cruiser ship? ";
			cin >> P2_cruiser_loc;
		
			//Check placement input
			string row = "";
			string col = "";
		
			if(P2_cruiser_loc.find("-") != string::npos)
			{
				row = P2_cruiser_loc.substr(0, P2_cruiser_loc.find("-"));
				col = P2_cruiser_loc.substr(P2_cruiser_loc.find("-") + 1);
			}
			else
			{
				cout << "\t * You must follow the format ROW-COL, for example: " << endl;
				cout << "\t * If you want to place your ship at D4, please input D-4." << endl;
				cout << "\t * The dash \"-\" is required!" << endl;
				continue;
			}

			//Check row placement
			if(row == "A" || row == "B" || row == "C" || row == "D" || row == "E" ||
				row == "a" || row == "b" || row == "c" || row == "d" || row == "e")
			{
				//Check col placement
				if(col == "1" || col == "2" || col == "3" || col == "4" || col == "5")
				{
					break;
				}
				else
				{
					cout << "\t * You must input a valid col to place your ship!" << endl;
					cout << "\t * Valid cols are 1, 2, 3, 4, 5. " << endl;
					continue;
				}
			}
			else
			{
				cout << "\t * You must input a valid row to place your ship!" << endl;
				cout << "\t * Valid rows are A, B, C, D, E." << endl;
				continue;
			}
		}
	
		//Cruiser ship direction
		while(true)
		{
			cout << "\tWhat direction would you like place your cruiser ship (DOWN or RIGHT): ";
			cin >> P2_cruiser_dir;
		
			//Check if the user inputted the correct direction
			if(!(P2_cruiser_dir == DIRECTION_DOWN || P2_cruiser_dir == DIRECTION_RIGHT))
			{ 
				cout << "\t * You must input a valid direction, either DOWN or RIGHT!" << endl;
				continue;
			}
			else
			{
				break;
			}
		}
		
		//Submarine Placement
		while(true)
		{
			cout << "\tWhere would you like to place your submarine ship? ";
			cin >> P2_submarine_loc;
		
			//Check placement input
			string row = "";
			string col = "";
		
			if(P2_submarine_loc.find("-") != string::npos)
			{
				row = P2_submarine_loc.substr(0, P2_submarine_loc.find("-"));
				col = P2_submarine_loc.substr(P2_submarine_loc.find("-") + 1);
			}
			else
			{
				cout << "\t * You must follow the format ROW-COL, for example: " << endl;
				cout << "\t * If you want to place your ship at D4, please input D-4." << endl;
				cout << "\t * The dash \"-\" is required!" << endl;
				continue;
			}

			//Check row placement
			if(row == "A" || row == "B" || row == "C" || row == "D" || row == "E" ||
				row == "a" || row == "b" || row == "c" || row == "d" || row == "e")
			{
				//Check col placement
				if(col == "1" || col == "2" || col == "3" || col == "4" || col == "5")
				{
					break;
				}
				else
				{
					cout << "\t * You must input a valid col to place your ship!" << endl;
					cout << "\t * Valid cols are 1, 2, 3, 4, 5. " << endl;
					continue;
				}
			}
			else
			{
				cout << "\t * You must input a valid row to place your ship!" << endl;
				cout << "\t * Valid rows are A, B, C, D, E." << endl;
				continue;
			}
		}
	
		//Submarine direction
		while(true)
		{
			cout << "\tWhat direction would you like place your submarine (DOWN or RIGHT): ";
			cin >> P2_submarine_dir;
		
			//Check if the user inputted the correct direction
			if(!(P2_submarine_dir == DIRECTION_DOWN || P2_submarine_dir == DIRECTION_RIGHT))
			{ 
				cout << "\t * You must input a valid direction, either DOWN or RIGHT!" << endl;
				continue;
			}
			else
			{
				break;
			}
		}
	
		//Destroyer Ship Placement
		while(true)
		{    
			cout << "\tWhere would you like to place your destroyer ship? ";
			cin >> P2_destroyer_loc;	
		
			//Check placement input
			string row = "";
			string col = "";
		
			if(P2_destroyer_loc.find("-") != string::npos)
			{
				row = P2_destroyer_loc.substr(0, P2_destroyer_loc.find("-"));
				col = P2_destroyer_loc.substr(P2_destroyer_loc.find("-") + 1);
			}
			else
			{
				cout << "\t * You must follow the format ROW-COL, for example: " << endl;
				cout << "\t * If you want to place your ship at D4, please input D-4." << endl;
				cout << "\t * The dash \"-\" is required!" << endl;
				continue;
			}

			//Check row placement
			if(row == "A" || row == "B" || row == "C" || row == "D" || row == "E" ||
				row == "a" || row == "b" || row == "c" || row == "d" || row == "e")
			{
				//Check col placement
				if(col == "1" || col == "2" || col == "3" || col == "4" || col == "5")
				{
					break;
				}
				else
				{
					cout << "\t * You must input a valid col to place your ship!" << endl;
					cout << "\t * Valid cols are 1, 2, 3, 4, 5. " << endl;
					continue;
				}
			}
			else
			{
				cout << "\t * You must input a valid row to place your ship!" << endl;
				cout << "\t * Valid rows are A, B, C, D, E." << endl;
				continue;
			}
		}
	
		//Destroyer ship direction
		while(true)
		{
			cout << "\tWhat direction would you like place your destroyer ship (DOWN or RIGHT): ";
			cin >> P2_destroyer_dir;
		
			//Check if the user inputted the correct direction
			if(!(P2_destroyer_dir == DIRECTION_DOWN || P2_destroyer_dir == DIRECTION_RIGHT))
			{ 
				cout << "\t * You must input a valid direction, either DOWN or RIGHT!" << endl;
				continue;
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		//CPU Mode -- Generate positions for player 2 ships / direction
        int rand_row, rand_col, rand_dir = 0; //Stores our random location and direction
        srand(time(NULL)); //Set seed
        
        //Loop through and randomize each ship's location and direction
        for(int ship = 0; ship < 5; ship++)
        {
            //RANDOMIZE!
            rand_row = rand()%5; //Row A-E
            rand_col = rand()%5; //Col 1-5
            rand_dir = rand()%2; //Two directions (Down 0, Right 1)

            //Make sense of the randomness
            string ship_loc, ship_dir = "";
            if(rand_row == 0) ship_loc += "A-";
            if(rand_row == 1) ship_loc += "B-";
            if(rand_row == 2) ship_loc += "C-";
            if(rand_row == 3) ship_loc += "D-";
            if(rand_row == 4) ship_loc += "E-";
            if(rand_col < 4) rand_col++; //Put the range from 0-4 to 1-5
            // ship_loc += to_string(rand_col); //Append the randomized col value
            if(rand_col == 1) ship_loc += "1";
            if(rand_col == 2) ship_loc += "2";
            if(rand_col == 3) ship_loc += "3";
            if(rand_col == 4) ship_loc += "4";
            if(rand_col == 5) ship_loc += "5";
    
            if(rand_dir == 0) ship_dir = "DOWN";
            if(rand_dir == 1) ship_dir = "RIGHT";

            //Which ship are we managing?
            switch(ship)
            {
                case 0:
                    P2_carrier_loc = ship_loc;
                    P2_carrier_dir = ship_dir;
                    break;
                case 1:
                    P2_battle_loc = ship_loc;
                    P2_battle_dir = ship_dir;
                    break;
                case 2:
                    P2_cruiser_loc = ship_loc;
                    P2_cruiser_dir = ship_dir;
                    break;
                case 3:
                    P2_submarine_loc = ship_loc;
                    P2_submarine_dir = ship_dir;
                    break;
                case 4:
                    P2_destroyer_loc = ship_loc;
                    P2_destroyer_dir = ship_dir;
                    break;
                default:
                    cout << "[ERROR]: Something really messed up..." << endl;
                    break;
            }
        }
    }

    //Attack loop -- Where each player attacks the other's ships
    bool attack = true;
    cout << endl << "*LET THE GAME BEGIN!" << endl;
    while(attack)
    {
        //2 Player mode?
        if(TWO_PLAYER)
        {
            string P1_attack, P2_attack = "";
            cout << "\t[Player 1]: Cords to attack P2 (D-4, for example)? ";
            cin >> P1_attack;
            //attack() // Attacks the ship

            cout << "\t[Player 2]: Cords to attack P1 (D-4, for example)? ";
            cin >> P2_attack;
            //attack() // Attacks the ship
        
        }
        else //CPU mode
        {
            string P1_attack, P2_attack = "";
            cout << "\t[Player 1]: Cords to attack CPU (D-4 for example)? ";
            cin >> P1_attack;
            //attack() Attacks the ship
            
            //CPU Randomization
            int rand_row = rand()%5; //Row A-E
            int rand_col = rand()%5; //Col 1-5
            
            if(rand_row == 0) P2_attack += "A-";
            if(rand_row == 1) P2_attack += "B-";
            if(rand_row == 2) P2_attack += "C-";
            if(rand_row == 3) P2_attack += "D-";
            if(rand_row == 4) P2_attack += "E-";
            if(rand_col < 4) rand_col++; //Put the range from 0-4 to 1-5
            //P2_attack += to_string(rand_col); //Compiler issues on OSU linux 
            //Append the randomized col value
            if(rand_col == 1) P2_attack += "1";
            if(rand_col == 2) P2_attack += "2";
            if(rand_col == 3) P2_attack += "3";
            if(rand_col == 4) P2_attack += "4";
            if(rand_col == 5) P2_attack += "5";

            //CPU attack
            cout << "\t[CPU]: CPU attacked ship at " << P2_attack << endl;
            //attack() Attack the ship
        }
    }
	
	return 0;
}

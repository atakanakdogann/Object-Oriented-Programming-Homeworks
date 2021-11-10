/*
	Atakan AKDOGAN
	1801042612
	HW2
*/
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

enum Cell	{ space,peg,dot };

void buildBoard(int boardMode,const int &gameMode);
void printBoard(vector<vector<Cell>> Game,int size,int boardMode);		/*FUNCTION INITILIZATIONS*/
void playGame(vector<vector<Cell>> &Game,int &size,int &boardMode);
bool isFinished(vector<vector<Cell>> Game,int size,int boardMode);
void ComputerGame(vector<vector<Cell>> &Game,int size,int boardMode);

int main()
{
	/* 
		###	Main Function	###
	-Here I am taking Board and Mode selections
	-And also Some error checkings about inputs
	*/
	int boardMode,gameMode;

	cout << "Welcome to Peg Solitaire Game! Please select the board mode 1 to 6" << endl;
	cout << "Note: LOAD and SAVE commands works when you start the game!" << endl;
	cout << "Note 2: Valid input style is B3-R etc.. or SAVE/LOAD ***.txt !"  << endl;
	cin >> boardMode;

	cout << "Please enter the Game Mode" << endl ;
	cout << "1-Human Player Game" << endl << "2-Computer Game" << endl;
	cin >> gameMode;
	if (boardMode < 1 || boardMode > 6 || gameMode < 1 || gameMode > 2 )
	{
		cout << "You put wrong numbers. Restarting..." << endl;
		main();
	}
	buildBoard(boardMode,gameMode);

}

void buildBoard(int boardMode ,const int &gameMode)
{
	/*
		###	Build Board Function	###
	-After decide the board and mode selections
	function builds boards case by case in for loops
	-At the end of the builds automatically goes 
	to play except board 6
	-For board 6; everything is going in case 6. 
	*/
	vector<vector<Cell>> Game;

	auto score = 0,count = 0;
	decltype(count) max = 1,a = 1;
	int size,k;
	switch(boardMode){
		case 1:
			size = 7;
			Game.resize(size);
			for (int i = 0; i < size; i++)
			{
				Game[i].resize(size);			// RESIZE TABLES FOR MEMORY
			}

			for (int i = 0; i < size; i++)
			{
				if (i < 2 )
				{
					for (int j = 0; j < 2-i; j++)
					{
						Game[i][j] = space;
					}
					for (int j = 2-i; j < 5+(2*i); j++)		//FILLS TABLE
					{
						Game[i][j] = peg;
					}
					for (int j = 5+i; j < 7; j++)
					{
						Game[i][j] = space;
					}
				}
				else if (i >=2 && i <= 4)
				{
					for (int j = 0; j < size; j++)
					{
						Game[i][j] = peg;
					}
				}
				else if (i > 4 )
				{
					
					for (int j = 0; j < a; j++)
					{
						Game[i][j] = space;
					}
					for (int j = a; j < 7-a; j++)
					{
						Game[i][j] = peg;
					}
					for (int j = 7-a; j < 7; j++)
					{
						Game[i][j] = space;
					}
					a++;
				}
					
				Game[2][3] = dot;
			}

			break;

		case 2:
			size = 9;
			Game.resize(size);
			for (int i = 0; i < size; i++)
			{
				Game[i].resize(size);
			}

			for (int i = 0; i < size; i++)
			{
				if (i < 3 || i > 5)
				{
					for (int j = 0; j < 3; j++)
					{
						Game[i][j] = space;
					}
					for (int j = 3; j < 6; j++)
					{
						Game[i][j] = peg;
					}
					for (int j = 6; j < 9; j++)
					{
						Game[i][j] = space;
					}
				}
				else if (i >=3 && i <= 5)
				{
					for (int j = 0; j < size; j++)
					{
						Game[i][j] = peg;
					}
				}
					
			}
			Game[4][4] = dot;
			break;

		case 3:
			size = 8;
			Game.resize(size);
			for (int i = 0; i < size; i++)
			{
				Game[i].resize(size);
			}

			for (int i = 0; i < size; i++)
			{
				if (i < 3 || i > 5)
				{
					for (int j = 0; j < 2; j++)
					{
						Game[i][j] = space;
					}
					for (int j = 2; j < 5; j++)
					{
						Game[i][j] = peg;
					}
					for (int j = 5; j < 8; j++)
					{
						Game[i][j] = space;
					}
				}

				else if (i >=3 && i <= 5)
				{
					for (int j = 0; j < size; j++)
					{
						Game[i][j] = peg;
					}
				}
			}

			Game[4][3] = dot;
			break;

		case 4:
			size = 7;
			Game.resize(size);
			for (int i = 0; i < size; i++)
			{
				Game[i].resize(size);
			}

			for (int i = 0; i < size; i++)
			{
				if (i < 2 || i > 4)
				{
					for (int j = 0; j < 2; j++)
					{
						Game[i][j] = space;
					}
					for (int j = 2; j < 5; j++)
					{
						Game[i][j] = peg;
					}
					for (int j = 5; j < 7; j++)
					{
						Game[i][j] = space;
					}
				}

				else if (i >=2 && i <= 4)
				{
					for (int j = 0; j < size; j++)
					{
						Game[i][j] = peg;
					}
				}
					

			}
			Game[3][3] = dot; 
			break;

		case 5:
			size = 9;
			Game.resize(size);
			for (int i = 0; i < size; i++)
			{
				Game[i].resize(size);
			}
			a = 4;
			for (int i = 0; i < size;i++)
			{
				if (i < 4)
				{
					for (int j = 0; j < a; j++)
					{
						Game[i][j] = space;
					}
					for (int j = a; j < size-a; j++)
					{
						Game[i][j] = peg;
					}
					for (int j = size-a; j < size; j++)
					{
						Game[i][j] = space;
					}
					a--;
				}
				else if (i == 4)
				{
					for (int j = 0; j < size; j++)
					{
						Game[i][j] = peg;
					}
				}
				else if (i > 4)
				{
					for (int j = 0; j < a+1; j++)
					{
						Game[i][j] = space;
					}
					for (int j = a+1; j < size-a+1; j++)
					{
						Game[i][j] = peg;
					}
					for (int j = size-a-1; j < size; j++)
					{
						Game[i][j] = space;
					}
					a++;
				}
				Game[4][4 ] = dot; 
			}


			break;

		case 6:
			Game = {{space,space,space,space,dot,space,space,space,space},
			{space,space,space,peg,space,peg,space,space,space},
			{space,space,peg,space,peg,space,peg,space,space},			//FILLS MANUALLY
			{space,peg,space,peg,space,peg,space,peg,space},
			{peg,space,peg,space,peg,space,peg,space,peg}};

			size = 9;
			Game.resize(5);
			for (int i = 0; i < 5; i++)
			{
				Game[i].resize(size);
			}
			
			break;
	}
	srand((unsigned)time(0));
	printBoard(Game,size,boardMode);
	if (gameMode == 1)
	{
		while(!isFinished(Game,size,boardMode))
		{
			playGame(Game,size,boardMode);
			printBoard(Game,size,boardMode);			// PLAYS UNTIL FINISH
		}
		cout << "Well Done" << endl;
		
	}

	else if (gameMode == 2)
	{
		
		while(!isFinished(Game,size,boardMode))
		{
			ComputerGame(Game,size,boardMode);
			printBoard(Game,size,boardMode);
		}
		cout << "Well Done" << endl;
		
	}
	for (int i = 0; i < Game.size(); i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Game[i][j] == peg)
			{
				score++;
			}
		}
	}
	cout << "Score of the Game is: " << score << endl;
	
}

void printBoard(vector<vector<Cell>> Game,int size, int boardMode)
{
	/*
		###	Print Function	###
	-First prints alphabet till size
	-Then prints numbers for row
	-For table , if table is peg,prints 'p' .If dot prints '.' ... 
	*/
		cout << "  ";
		for (char c = 'A'; c < size + 'A'; c++)		// ALPHABET
		{
			cout << c << " " ;
		}
		cout << endl;

		for (int i = 0; i < Game.size(); i++)
		{
			cout << i << " " ;
			for (int j = 0; j < size; j++)
			{
				switch (Game[i][j]) {
					case peg:
						cout << "p";
						break;

					case dot:
						cout << ".";
						break;

					case space:
						cout << " ";
						break;
				}
				cout << " " ;
			}
			cout << endl;
		}
}
	

void playGame(vector<vector<Cell>> &Game,int &size,int &boardMode)
{
	/*
		###	Play Function	###
	-Here first asks move and direction
	-Does some error checkings
	-If everything is normal,puts pegs and dots for Cells.
	*/
	
		char char1,foo,direction;
		string foo2,filename;
		int row,column;
		int gameMode;

		ofstream outfile;
		ifstream infile;

		cout << "Please make a move: " ;
		cin >> char1 ;
		if (char1 == 'S' || char1 == 's')
		{
			cin >> foo2 >> filename;
			if (foo2 != "AVE")
			{
				cerr << "Wrong Command! Please retry." << endl;
				playGame(Game,size,boardMode);
			}
			outfile.open(filename);
			for (int i = 0; i < Game.size(); i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (Game[i][j] == peg)
					{
						outfile << "p" ;
					}
					else if (Game[i][j] == dot)				// SAVES GAME
					{
						outfile << "." ;
					}
					else if (Game[i][j] == space)
					{
						outfile << " " ;
					}
				}
				outfile << endl;
			}
			playGame(Game,size,boardMode);
		}

		else if (char1 == 'L' || char1 == 'l')
		{
			auto i = 0,height = 0,length = 0;
			string array[20];
			cin >> foo2 >> filename;
			if (foo2 != "OAD")
			{
				cerr << "Wrong Command! Please retry." << endl;
				playGame(Game,size,boardMode);
			}
			infile.open(filename);						//LOADS FROM FILE
			while (!infile.eof())
			{
				getline(infile,array[i], '\n');				
				if (array[i].length() > length)
				{
					length = array[i].length();
				}
				i++;
				height++;
			}
			Game.resize(height);
			for (int i = 0; i < height; i++)
			{
				Game[i].resize(length);
			}
			for (int i = 0; i < height; i++)
			{
				
				for (int j = 0; j < length; j++)
				{
					
					if(array[i][j] == 'p')
					{
						Game[i][j] = peg;
					}
					else if(array[i][j] == '.')				//FILLS GAME VECTOR
					{
						Game[i][j] = dot;
					}
					else if(array[i][j] == ' ')
					{
						Game[i][j] = space;
					}
				}
			}
		size = length;
		boardMode = 7;
		cout << "Please enter the Game Mode" << endl ;
		cout << "1-Human Player Game" << endl << "2-Computer Game" << endl;
		cin >> gameMode;
		if (gameMode == 1)
		{
			return;
		}
		else if (gameMode == 2)
		{
			while(!isFinished(Game,size,boardMode))				//PLAYS FILE VECTOR
			{
				ComputerGame(Game,size,boardMode);
				printBoard(Game,size,boardMode);
			}
			cout << "Well Done" << endl;
			return;
			
		}
			


			
		}

		else
		{
			cin >> row >> foo >> direction ;
			column = char1 - 'A';
			if (column < 0 || column > size || row < 0 || row > size )
			{
				cerr << "Coordinates are wrong! Try again. " << endl;
				playGame(Game,size,boardMode);									//ERROR CHECKINGS
			}
			else if (direction != 'R' && direction != 'D' && direction != 'L' &&direction != 'U')
			{
				cerr << "Directions are wrong! Try again. " << endl;
				playGame(Game,size,boardMode);
			}
		
			if (boardMode != 6)
			{
				if (Game[row][column] == peg)
				{

					switch (direction) {
						case 'R':

							if (Game[row][column+1] == peg)
							{
								if (Game[row][column+2] == dot)
								{
									Game[row][column] = dot;
									Game[row][column+1] = dot;
									Game[row][column+2] = peg;		//DOES MOVE
									return;
								}
							}
							break;

						case 'L':
							if (Game[row][column-1] == peg)
							{
								if (Game[row][column-2] == dot)
								{
									Game[row][column] = dot;
									Game[row][column-1] = dot;
									Game[row][column-2] = peg;
									return;
								}
							}
							break;

						case 'U':
							if (Game[row-1][column] == peg)
							{
								if (Game[row-2][column] == dot)
								{
									Game[row][column] = dot;
									Game[row-1][column] = dot;
									Game[row-2][column] = peg;
									return;
								}
							}
							break;

						case 'D':
							if (Game[row+1][column] == peg)
							{
								if (Game[row+2][column] == dot)
								{
									Game[row][column] = dot;
									Game[row+1][column] = dot;
									Game[row+2][column] = peg;
									return;
								}
							}
							break;
					}
				}

				cerr << "You made an invalid move! Try again" << endl;
				return;
			}
		
			else if (boardMode == 6)
			{
				if (Game[row][column] == peg)
				{
					switch (direction) {
						case 'R':

							if (Game[row][column+2] == peg)
							{
								if (Game[row][column+4] == dot)
								{
									Game[row][column] = dot;
									Game[row][column+2] = dot;
									Game[row][column+4] = peg;
									return;
								}
							}
							break;

						case 'L':
							if (Game[row][column-2] == peg)
							{
								if (Game[row][column-4] == dot)
								{
									Game[row][column] = dot;
									Game[row][column-2] = dot;
									Game[row][column-4] = peg;
									return;
								}
							}
							break;

						case 'U':

							if (Game[row-1][column-1] == peg && Game[row-2][column-2] == dot)
							{
									Game[row][column] = dot;
									Game[row-1][column-1] = dot;
									Game[row-2][column-2] = peg;
									return;
							}
							else if (Game[row-1][column+1] == peg && Game[row-2][column+2] == dot)
							{
								Game[row][column] = dot;
								Game[row-1][column+1] = dot;
								Game[row-2][column+2] = peg;
								return;
							}
							break;

						case 'D':
							if (Game[row+1][column+1] == peg && Game[row+2][column+2] == dot)
							{
								Game[row][column] = dot;
								Game[row+1][column+1] = dot;
								Game[row+2][column+2] = peg;
								return;
							
							}
							else if (Game[row+1][column-1] == peg && Game[row+2][column-2] == dot)
							{
								Game[row][column] = dot;
								Game[row+1][column-1] = dot;
								Game[row+2][column-2] = peg;
								return;
							}
							break;
					}
				}
				cerr << "You made an invalid move! Try again" << endl;
				return;
			}
	}

}



bool isFinished(vector<vector<Cell>> Game,int size,int boardMode)
{
	/*
		###	Control Function	###
	-Basically function searches trio like this:
	-(Doesn't matter which way) peg,peg,dot
	-If there is that trio in table,returns false
	*/
	if(boardMode != 6)
	{

		for (int i = 0; i < Game.size(); i++)
		{
			for (int j = 0; j < size-2; j++)
			{
				if (Game[i][j] == peg && Game[i][j+1] == peg && Game[i][j+2] == dot)
				{
					return false;
				}
			}
		}

		for (int i = 0; i < Game.size()-2; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (Game[i][j] == peg && Game[i+1][j] == peg && Game[i+2][j] == dot)
				{
					return false;
				}
			}
		}

		for (int i = 0; i < Game.size(); i++)
		{
			for (int j = 2; j < size; j++)
			{
				if (Game[i][j] == peg && Game[i][j-1] == peg && Game[i][j-2] == dot)
				{
					return false;
				}
			}
		}

		for (int i = 2; i < Game.size(); i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (Game[i][j] == peg && Game[i-1][j] == peg && Game[i-2][j] == dot)
				{
					return false;
				}
			}
		}
		return true;
	}

	else if (boardMode == 6)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < size-2; j++)
			{
				if (Game[i][j] == peg && Game[i][j+2] == peg && Game[i][j+4] == dot)
				{
					return false;
				}
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (Game[i][j] == peg && Game[i+1][j+1] == peg && Game[i+2][j+2] == dot)
				{
					return false;
				}
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (Game[i][j] == peg && Game[i+1][j-1] == peg && Game[i+2][j-2] == dot)
				{
					return false;
				}
			}
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 2; j < size; j++)
			{
				if (Game[i][j] == peg && Game[i][j-2] == peg && Game[i][j-4] == dot)
				{
					return false;
				}
			}
		}

		for (int i = 2; i < 5; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (Game[i][j] == peg && Game[i-1][j-1] == peg && Game[i-2][j-2] == dot)
				{
					return false;
				}
			}
		}

		for (int i = 2; i < 5; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (Game[i][j] == peg && Game[i-1][j+1] == peg && Game[i-2][j+2] == dot)
				{
					return false;
				}
			}
		}
		return true;
	}
	return true;	
}



void ComputerGame(vector<vector<Cell>> &Game,int size,int boardMode)
{
	/*
		###	Computer Play Function	###
	-First Computer generates random number for direction. 
	-0 to Right,1 to Down,2 to Left,3 to Up
	-If there is peg,peg,peg trio according to random direction; move is done.
	-Else function calls again.
	*/
	if(boardMode != 6)
	{
		int randomNumber;
		randomNumber = (rand()%4);

		switch (randomNumber) {
			case 0:
				for (int i = 0; i < Game.size(); i++)
				{
					for (int j = 0; j < size-2; j++)
					{
						if (Game[i][j] == peg && Game[i][j+1] == peg && Game[i][j+2] == dot)
						{
							Game[i][j] = dot;
							Game[i][j+1] = dot;
							Game[i][j+2] = peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-R" << endl;
							return;
						}
					}
				}
				ComputerGame(Game,size,boardMode);
				break;

			case 1:
				for (int i = 0; i < Game.size()-2; i++)
				{
					for (int j = 0; j < size; j++)
					{
						if (Game[i][j] == peg && Game[i+1][j] == peg && Game[i+2][j] == dot)
						{
							Game[i][j] = dot;
							Game[i+1][j] = dot;
							Game[i+2][j] = peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-D" << endl;
							return;
						}
					}
				}
				ComputerGame(Game,size,boardMode);
				break;

			case 2:
				for (int i = 0; i < Game.size(); i++)
				{
					for (int j = 2; j < size; j++)
					{
						if (Game[i][j] == peg && Game[i][j-1] == peg && Game[i][j-2] == dot)
						{
							Game[i][j] = dot;
							Game[i][j-1] = dot;
							Game[i][j-2] = peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-L" << endl;
							return;
						}
					}
				}
				ComputerGame(Game,size,boardMode);
				break;

			case 3:
				for (int i = 2; i < Game.size(); i++)
				{
					for (int j = 0; j < size; j++)
					{
						if (Game[i][j] == peg && Game[i-1][j] == peg && Game[i-2][j] == dot)
						{
							Game[i][j] = dot;
							Game[i-1][j] = dot;
							Game[i-2][j] = peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-U" << endl;
							return;
						}
					}
				}
				ComputerGame(Game,size,boardMode);
				break;
		}
	}

	else if (boardMode == 6)
	{
		int randomNumber;
		randomNumber = (rand()%6);

		switch (randomNumber) {
			case 0:
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < size-2; j++)
					{
						if (Game[i][j] == peg && Game[i][j+2] == peg && Game[i][j+4] == dot)
						{
							Game[i][j] = dot;
							Game[i][j+2] = dot;
							Game[i][j+4] = peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-R" << endl;
							return;
						}
					}
				}
				ComputerGame(Game,size,boardMode);
				break;

			case 1:
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < size; j++)
					{
						if (Game[i][j] == peg && Game[i+1][j+1] == peg && Game[i+2][j+2] == dot)
						{
							Game[i][j] = dot;
							Game[i+1][j+1] = dot;
							Game[i+2][j+2] = peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-D" << endl;
							return;
						}
					}
				}
				ComputerGame(Game,size,boardMode);
				break;

			case 2:
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < size; j++)
					{
						if (Game[i][j] == peg && Game[i+1][j-1] == peg && Game[i+2][j-2] == dot)
						{
							Game[i][j] = dot;
							Game[i+1][j-1] = dot;
							Game[i+2][j-2] = peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-D" << endl;
							return;
						}
					}
				}
				ComputerGame(Game,size,boardMode);
				break;

			case 3:
				for (int i = 0; i < 5; i++)
				{
					for (int j = 2; j < size; j++)
					{
						if (Game[i][j] == peg && Game[i][j-2] == peg && Game[i][j-4] == dot)
						{
							Game[i][j] = dot;
							Game[i][j-2] = dot;
							Game[i][j-4] = peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-L" << endl;
							return;
						}
					}
				}
				ComputerGame(Game,size,boardMode);
				break;

			case 4:
				for (int i = 2; i < 5; i++)
				{
					for (int j = 0; j < size; j++)
					{
						if (Game[i][j] == peg && Game[i-1][j-1] == peg && Game[i-2][j-2] == dot)
						{
							Game[i][j] = dot;
							Game[i-1][j-1] = dot;
							Game[i-2][j-2] = peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-U" << endl;
							return;
						}
					}
				}
				ComputerGame(Game,size,boardMode);
				break;

			case 5:
				for (int i = 2; i < 5; i++)
				{
					for (int j = 0; j < size; j++)
					{
						if (Game[i][j] == peg && Game[i-1][j+1] == peg && Game[i-2][j+2] == dot)
						{
							Game[i][j] = dot;
							Game[i-1][j+1] = dot;
							Game[i-2][j+2] = peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-U" << endl;
							return;
						}
					}
				}
				ComputerGame(Game,size,boardMode);
				break;
		}
	}
	

}

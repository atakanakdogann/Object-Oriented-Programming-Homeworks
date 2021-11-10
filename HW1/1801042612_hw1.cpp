/*
	Atakan AKDOGAN
	1801042612
	HW1
*/
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>
#include <string>
using namespace std;

enum Cell	{ peg,dot,space };

void buildBoard(int boardMode,int gameMode);
void printBoard(vector<vector<Cell>> Game, int size);
void printBoard6(vector<vector<Cell>> Game,int size);		/*FUNCTION INITILIZATIONS*/
void playGame(vector<vector<Cell>> &Game,int size);
void playGame6(vector<vector<Cell>> &Game,int size);
bool isFinished(vector<vector<Cell>> Game,int size);
bool isFinished6(vector<vector<Cell>> Game,int size);
void ComputerGame(vector<vector<Cell>> &Game,int size);
void ComputerGame6(vector<vector<Cell>> &Game,int size);

int main()
{
	/* 
		###	Main Function	###
	-Here I am taking Board and Mode selections
	-And also Some error checkings about inputs
	*/
	int boardMode,gameMode;

	cout << "Welcome to Peg Solitaire Game! Please select the board mode 1 to 6" << endl;
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

void buildBoard(int boardMode,int gameMode)
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

	int size,count = 0,max = 1;
	int score = 0;
	int a = 1,k;
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
					for (int j = 2; j < 5+(2*i); j++)		//FILLS TABLE
					{
						Game[i][j] = peg;
					}
					for (int j = 5+i; j < 7; j++)
					{
						Game[i][j] = space;
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
					for (int j = size-a; j < size; j++)
					{
						Game[i][j] = space;
					}
					a--;
				}
				else if (i > 4)
				{
					for (int j = 0; j < a+1; j++)
					{
						Game[i][j] = space;
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
			Game.resize(size);
			for (int i = 0; i < 5; i++)
			{
				Game[i].resize(size);
			}
			printBoard6(Game,size);
			if (gameMode == 1)
			{
				while(!isFinished6(Game,size))
				{
					playGame6(Game,size);				//IF GAME NOT FINISHED,CONTINUES AUTOMATICALLY
					printBoard6(Game,size);
				}
				cout << "Well Done" << endl;
			}
			else if(gameMode == 2)
			{
				srand((unsigned)time(0));
				while(!isFinished6(Game,size))
				{
					ComputerGame6(Game,size);			// COMPUTER PLAYS
					printBoard6(Game,size);
				}
				cout << "Well Done" << endl;
		
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (Game[i][j] == peg)			//WHEN GAME FINISHED,COUNTS SCORE
					{
						score++;
					}
				}
			}
			cout << "Score of the Game is: " << score << endl;
			return;
			break;
	}

	printBoard(Game,size);
	if (gameMode == 1)
	{
		while(!isFinished(Game,size))
		{
			playGame(Game,size);
			printBoard(Game,size);
		}
		cout << "Well Done" << endl;
		
	}

	else if (gameMode == 2)
	{
		srand((unsigned)time(0));
		while(!isFinished(Game,size))
		{
			ComputerGame(Game,size);
			printBoard(Game,size);
		}
		cout << "Well Done" << endl;
		
	}
	for (int i = 0; i < size; i++)
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

void printBoard(vector<vector<Cell>> Game,int size)
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

	for (int i = 0; i < size; i++)
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

void printBoard6(vector<vector<Cell>> Game,int size)
{
	/*
		###	Print Function	###
	-Only works for Table 6
	-First prints alphabet till size
	-Then prints numbers for row
	-For table , if table is peg,prints 'p' .If dot prints '.' ... 
	*/
	cout << "  ";
	for (char c = 'A'; c < size + 'A'; c++)
	{
		cout << c << " " ;
	}
	cout << endl;

	for (int i = 0; i < 5; i++)
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

void playGame(vector<vector<Cell>> &Game,int size)
{
	/*
		###	Play Function	###
	-Here first asks move and direction
	-Does some error checkings
	-If everything is normal,puts pegs and dots for Cells.
	*/
	char char1,foo,direction;
	int row,column;

	cout << "Please make a move: " ;
	cin >> char1 >> row >> foo >> direction ;

	column = char1 - 'A';
	if (column < 0 || column > size || row < 0 || row > size )
	{
		cout << "Coordinates are wrong! Try again. " << endl;
		playGame(Game,size);									//ERROR CHECKINGS
	}
	else if (direction != 'R' && direction != 'D' && direction != 'L' &&direction != 'U')
	{
		cout << "Directions are wrong! Try again. " << endl;
		playGame(Game,size);
	}

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

	cout << "You made an invalid move! Try again" << endl;
	return;

}

void playGame6(vector<vector<Cell>> &Game,int size)
{
	/*
		###	Play Function	###
	-Here first asks move and direction
	-Does some error checkings
	-If everything is normal,puts pegs and dots for Cells.
	*/
	char char1,foo,direction;
	int row,column;

	cout << "Please make a move: " ;
	cin >> char1 >> row >> foo >> direction ;

	column = char1 - 'A';
	if (column < 0 || column > size || row < 0 || row > size )
	{
		cout << "Coordinates are wrong! Try again. " << endl;
		playGame(Game,size);
	}
	else if (direction != 'R' && direction != 'D' && direction != 'L' &&direction != 'U')
	{
		cout << "Directions are wrong! Try again. " << endl;
		playGame(Game,size);
	}

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

	cout << "You made an invalid move! Try again" << endl;
	return;
}

bool isFinished(vector<vector<Cell>> Game,int size)
{
	/*
		###	Control Function	###
	-Basically function searches trio like this:
	-(Doesn't matter which way) peg,peg,dot
	-If there is that trio in table,returns false
	*/
	int i,j;
	int counter = 0,counter_2 = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-2; j++)
		{
			if (Game[i][j] == peg && Game[i][j+1] == peg && Game[i][j+2] == dot)
			{
				return false;
			}
		}
	}

	for (int i = 0; i < size-2; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Game[i][j] == peg && Game[i+1][j] == peg && Game[i+2][j] == dot)
			{
				return false;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 2; j < size; j++)
		{
			if (Game[i][j] == peg && Game[i][j-1] == peg && Game[i][j-2] == dot)
			{
				return false;
			}
		}
	}

	for (int i = 2; i < size; i++)
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

bool isFinished6(vector<vector<Cell>> Game,int size)
{
	/*
		###	Control Function	###
	-Same function for Table 6.
	-Basically function searches trio like this:
	-(Doesn't matter which way) peg,peg,dot
	-If there is that trio in table,returns false
	*/
	int i,j;

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

void ComputerGame(vector<vector<Cell>> &Game,int size)
{
	/*
		###	Computer Play Function	###
	-First Computer generates random number for direction. 
	-0 to Right,1 to Down,2 to Left,3 to Up
	-If there is peg,peg,peg trio according to random direction; move is done.
	-Else function calls again.
	*/
	int randomNumber;
	randomNumber = (rand()%4);

	switch (randomNumber) {
		case 0:
			for (int i = 0; i < size; i++)
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
			ComputerGame(Game,size);
			break;

		case 1:
			for (int i = 0; i < size-2; i++)
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
			ComputerGame(Game,size);
			break;

		case 2:
			for (int i = 0; i < size; i++)
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
			ComputerGame(Game,size);
			break;

		case 3:
			for (int i = 2; i < size; i++)
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
			ComputerGame(Game,size);
			break;
	}
	

}

void ComputerGame6(vector<vector<Cell>> &Game,int size)
{
	/*
		###	Computer Play Function	###
	-Same Function with Board 6
	-First Computer generates random number for direction. 
	-0 to Right,1 to Down-Right,2 to Down-Left,3 to Left,4 to Up-Left,5 to Up-Right
	-If there is peg,peg,peg trio according to random direction; move is done.
	-Else function calls again.
	*/
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
			ComputerGame6(Game,size);
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
			ComputerGame6(Game,size);
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
			ComputerGame6(Game,size);
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
			ComputerGame6(Game,size);
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
			ComputerGame6(Game,size);
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
			ComputerGame6(Game,size);
			break;
	}
	

}




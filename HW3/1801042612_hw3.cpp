/*
Atakan Akdogan
HW3
1801042612
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib> 
#include <ctime>
using namespace std;

class PegSolitaire{
public:
	PegSolitaire(string filename,int board_selection);
	PegSolitaire(int board_selection);
	PegSolitaire();

	//inline static int PegsFromAllGames(){return totalPegs;};
	void stats();
	void setShape(int board_selection);
	void setSize(int size);
	inline int getSize(){return size;}
	inline int getPegs(){return number_of_pegs;};
	void printBoard() const;
	void saveToFile(string filename) const;
	void loadFromFile(string filename);
	void play(int row,int column,char direction);
	void play();
	void playGame();

	bool isFinished() const;
	bool compareGames(PegSolitaire &otherGame) const;

	//static int totalPegs = 0;
	class Cell{
	public:
		enum Game{
			space,
			peg,
			dot
		};

	private:
		int row;
		int column;
		char direction;
		
	};

private:
	vector<vector<Cell::Game>> Board;
	int boardMode;
	int size;
	int number_of_pegs;
	int remain_pegs;
	int remain_emptys;
	
};

bool PegSolitaire::compareGames(PegSolitaire &otherGame) const
{
	/*
	COMPARES TWO GAMES ACCORDING TO REMAINING PEGS. 
	*/
	if (remain_pegs > otherGame.remain_pegs)
		return true;
	else
		return false;
}

void PegSolitaire::stats()
{
	/*
	IN FOR LOOP FINDS HOW MANY PEGS REMAIINED AND HOW MANY MOVES MADE ACCORDING TO TOTAL NUMBER_OF_PEGS FROM SETSHAPE FUNCTION
	*/
	remain_pegs = 0,remain_emptys = 0;
	cout << "Total pegs in this Board is "<< number_of_pegs << endl;
	for (int i = 0; i < Board.size(); i++)
	{
		for(int j = 0;j < Board[i].size();j++)
		{
			if (Board[i][j] == Cell::peg)
			{
				remain_pegs++;
			}
			else if (Board[i][j] == Cell::dot)
			{
				remain_emptys++;
			}
		}
	}
	//totalPegs--;
	cout << "Now there are " << remain_pegs << " pegs and " << remain_emptys << " empty Cells" << endl;
	cout << number_of_pegs - remain_pegs << " pegs taken from the board." << endl;
	cout << endl;
}
void PegSolitaire::setShape(int board_selection)
{
	/*
	ONLY SETS SHAPE FOR TABLE ACCORDING TO SIZE
	*/
	int a = 1;
	switch (board_selection) {
		case 1:
			boardMode = 1;
			number_of_pegs = 36;		// INITIALIZES TOTAL NUMBER OF PEGS
			for (int i = 0; i < Board.size(); i++)
			{
				if (i < 2 )
				{
					for (int j = 0; j < 2-i; j++)
					{
						Board[i][j] = Cell::space;
					}
					for (int j = 2-i; j < 5+(2*i); j++)		//FILLS TABLE
					{
						Board[i][j] = Cell::peg;
					}
					for (int j = 5+i; j < 7; j++)
					{
						Board[i][j] = Cell::space;
					}
				}
				else if (i >=2 && i <= 4)
				{
					for (int j = 0; j < Board[i].size(); j++)
					{
						Board[i][j] = Cell::peg;
					}
				}
				else if (i > 4 )
				{
					
					for (int j = 0; j < a; j++)
					{
						Board[i][j] = Cell::space;
					}
					for (int j = a; j < 7-a; j++)
					{
						Board[i][j] = Cell::peg;
					}
					for (int j = 7-a; j < 7; j++)
					{
						Board[i][j] = Cell::space;
					}
					a++;
				}
			}	
			Board[2][3] = Cell::dot;
			break;

		case 2:
			boardMode = 2;
			number_of_pegs = 44;
			for (int i = 0; i < Board.size(); i++)
			{
				if (i < 3 || i > 5)
				{
					for (int j = 0; j < 3; j++)
					{
						Board[i][j] = Cell::space;
					}
					for (int j = 3; j < 6; j++)
					{
						Board[i][j] = Cell::peg;
					}
					for (int j = 6; j < 9; j++)
					{
						Board[i][j] = Cell::space;
					}
				}
				else if (i >=3 && i <= 5)
				{
					for (int j = 0; j < Board[i].size(); j++)
					{
						Board[i][j] = Cell::peg;
					}
				}
					
			}
			Board[4][4] = Cell::dot;
			break;

		case 3:
			boardMode = 3;
			number_of_pegs = 38;
			for (int i = 0; i < Board.size(); i++)
			{
				if (i < 3 || i > 5)
				{
					for (int j = 0; j < 2; j++)
					{
						Board[i][j] = Cell::space;
					}
					for (int j = 2; j < 5; j++)
					{
						Board[i][j] = Cell::peg;
					}
					for (int j = 5; j < 8; j++)
					{
						Board[i][j] = Cell::space;
					}
				}

				else if (i >=3 && i <= 5)
				{
					for (int j = 0; j < Board[i].size(); j++)
					{
						Board[i][j] = Cell::peg;
					}
				}
			}

			Board[4][3] = Cell::dot;
			break;

		case 4:
			boardMode = 4;
			number_of_pegs = 32;
			for (int i = 0; i < Board.size(); i++)
			{
				if (i < 2 || i > 4)
				{
					for (int j = 0; j < 2; j++)
					{
						Board[i][j] = Cell::space;
					}
					for (int j = 2; j < 5; j++)
					{
						Board[i][j] = Cell::peg;
					}
					for (int j = 5; j < 7; j++)
					{
						Board[i][j] = Cell::space;
					}
				}

				else if (i >=2 && i <= 4)
				{
					for (int j = 0; j < Board[i].size(); j++)
					{
						Board[i][j] = Cell::peg;
					}
				}
					

			}
			Board[3][3] = Cell::dot;
			break;

		case 5:
			boardMode = 5;
			number_of_pegs = 40;
			a = 4;
			for (int i = 0; i < Board.size();i++)
			{
				if (i < 4)
				{
					for (int j = 0; j < a; j++)
					{
						Board[i][j] = Cell::space;
					}
					for (int j = a; j < Board[i].size()-a; j++)
					{
						Board[i][j] = Cell::peg;
					}
					for (int j = Board[i].size()-a; j < Board[i].size(); j++)
					{
						Board[i][j] = Cell::space;
					}
					a--;
				}
				else if (i == 4)
				{
					for (int j = 0; j < Board[i].size(); j++)
					{
						Board[i][j] = Cell::peg;
					}
				}
				else if (i > 4)
				{
					for (int j = 0; j < a+1; j++)
					{
						Board[i][j] = Cell::space;
					}
					for (int j = a+1; j < Board[i].size()-a+1; j++)
					{
						Board[i][j] = Cell::peg;
					}
					for (int j = Board[i].size()-a-1; j < Board[i].size(); j++)
					{
						Board[i][j] = Cell::space;
					}
					a++;
				}
				Board[4][4] = Cell::dot; 
			}
			break;

		case 6:
			boardMode = 6;
			number_of_pegs = 14;
			Board = {{Cell::space,Cell::space,Cell::space,Cell::space,Cell::dot,Cell::space,Cell::space,Cell::space,Cell::space},
			{Cell::space,Cell::space,Cell::space,Cell::peg,Cell::space,Cell::peg,Cell::space,Cell::space,Cell::space},
			{Cell::space,Cell::space,Cell::peg,Cell::space,Cell::peg,Cell::space,Cell::peg,Cell::space,Cell::space},		
			{Cell::space,Cell::peg,Cell::space,Cell::peg,Cell::space,Cell::peg,Cell::space,Cell::peg,Cell::space},
			{Cell::peg,Cell::space,Cell::peg,Cell::space,Cell::peg,Cell::space,Cell::peg,Cell::space,Cell::peg}};
			break;

	}
	//totalPegs += number_of_pegs;
}
void PegSolitaire::setSize(int board_selection)
{
	/*
	SETTER FOR SIZE
	ONLY FOR TABLE 6,SIZE IS 5 for Row and 9 for column
	*/
	if (board_selection == 1){PegSolitaire::size = 7;}
	else if (board_selection == 2){PegSolitaire::size = 9;}
	else if (board_selection == 3){PegSolitaire::size = 8;}
	else if (board_selection == 4){PegSolitaire::size = 7;}
	else if (board_selection == 5){PegSolitaire::size = 9;}
	else if (board_selection == 6){
		PegSolitaire::size = 9;
		Board.resize(5);
		for (int i = 0; i < 5; i++)
		{
			Board[i].resize(size);
		}
		return;
	}

	Board.resize(size);
	for (int i = 0; i < size; i++)
	{
		Board[i].resize(size);
	}
}

void PegSolitaire::printBoard() const
{
	/*
	ONLY PRINTS BOARD
	*/
	cout << "  ";
	for (char c = 'A'; c < Board[0].size() + 'A'; c++)		// ALPHABET
	{
		cout << c << " " ;
	}
	cout << endl;


	for (int i = 0; i < Board.size(); i++)
	{
		cout << i << " " ;
		for (int j = 0; j < Board[i].size(); j++)
		{
			switch (Board[i][j]) {
				case Cell::peg:
					cout << "p ";
					break;

				case Cell::dot:
					cout << ". ";
					break;

				case Cell::space:
					cout << "  ";
					break;
			}
		}
		cout << endl;
	}
}

void PegSolitaire::saveToFile(string filename) const
{
	/*
	SAVES FROM TABLE TO FILE
	*/
	ofstream outfile;
	outfile.open(filename);

	for (int i = 0; i < Board.size(); i++)
	{
		for (int j = 0; j < Board[i].size(); j++)
		{
			if (Board[i][j] == Cell::peg)
			{
				outfile << "p" ;
			}
			else if (Board[i][j] == Cell::dot)				// SAVES GAME
			{
				outfile << "." ;
			}
			else if (Board[i][j] == Cell::space)
			{
				outfile << " " ;
			}
		}
		outfile << endl;
	}
}

void PegSolitaire::loadFromFile(string filename)
{
	/*
	LOADS FROM FILE. TAKES FILE INTO ARRAY AND PARSE THEM AND FILLS TABLE 
	*/
	int length = 0,height = 0,i = 0,counter = 0;
	string array[20]; 
	ifstream infile;
	infile.open(filename);

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
	Board.resize(height);
	for (int i = 0; i < height; i++)
	{
		Board[i].resize(length);
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
		{			
			if(array[i][j] == 'p')
			{
				Board[i][j] = Cell::peg;
				counter++;
			}
			else if(array[i][j] == '.')				//FILLS GAME VECTOR
			{
				Board[i][j] = Cell::dot;
			}
			else if(array[i][j] == ' ')
			{
				Board[i][j] = Cell::space;
			}
		}
	}
	number_of_pegs = counter;
}

void PegSolitaire::play(int row,int column,char direction)
{
	/*
	DOES ONE MOVE ACCORDING TO ROW COLUMN DIRECTION PARAMETERS
	*/
	if (boardMode != 6)
	{
		if (Board[row][column] == Cell::peg)
		{

			switch (direction) {
				case 'R':

					if (Board[row][column+1] == Cell::peg)
					{
						if (Board[row][column+2] == Cell::dot)
						{
							Board[row][column] = Cell::dot;
							Board[row][column+1] = Cell::dot;
							Board[row][column+2] = Cell::peg;		//DOES MOVE
							number_of_pegs--;
							return;
						}
					}
					break;

				case 'L':
					if (Board[row][column-1] == Cell::peg)
					{
						if (Board[row][column-2] == Cell::dot)
						{
							Board[row][column] = Cell::dot;
							Board[row][column-1] = Cell::dot;
							Board[row][column-2] = Cell::peg;
							number_of_pegs--;
							return;
						}
					}
					break;

				case 'U':
					if (Board[row-1][column] == Cell::peg)
					{
						if (Board[row-2][column] == Cell::dot)
						{
							Board[row][column] = Cell::dot;
							Board[row-1][column] = Cell::dot;
							Board[row-2][column] = Cell::peg;
							number_of_pegs--;
							return;
						}
					}
					break;

				case 'D':
					if (Board[row+1][column] == Cell::peg)
					{
						if (Board[row+2][column] == Cell::dot)
						{
							Board[row][column] = Cell::dot;
							Board[row+1][column] = Cell::dot;
							Board[row+2][column] = Cell::peg;
							number_of_pegs--;
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
		if (Board[row][column] == Cell::peg)
		{
			switch (direction) {
				case 'R':

					if (Board[row][column+2] == Cell::peg && Board[row][column+4] == Cell::dot)
					{
						Board[row][column] = Cell::dot;
						Board[row][column+2] = Cell::dot;
						Board[row][column+4] = Cell::peg;
						number_of_pegs--;
						return;
					}
					break;

				case 'L':
					if (Board[row][column-2] == Cell::peg && Board[row][column-4] == Cell::dot)
					{
						Board[row][column] = Cell::dot;
						Board[row][column-2] = Cell::dot;
						Board[row][column-4] = Cell::peg;
						number_of_pegs--;
						return;
						
					}
					break;

				case 'U':

					if (Board[row-1][column-1] == Cell::peg && Board[row-2][column-2] == Cell::dot)
					{
							Board[row][column] = Cell::dot;
							Board[row-1][column-1] = Cell::dot;
							Board[row-2][column-2] = Cell::peg;
							number_of_pegs--;
							return;
					}
					else if (Board[row-1][column+1] == Cell::peg && Board[row-2][column+2] == Cell::dot)
					{
						Board[row][column] = Cell::dot;
						Board[row-1][column+1] = Cell::dot;
						Board[row-2][column+2] = Cell::peg;
						number_of_pegs--;
						return;
					}
					break;

				case 'D':
					if (Board[row+1][column+1] == Cell::peg && Board[row+2][column+2] == Cell::dot)
					{
						Board[row][column] = Cell::dot;
						Board[row+1][column+1] = Cell::dot;
						Board[row+2][column+2] = Cell::peg;
						number_of_pegs--;
						return;
					
					}
					else if (Board[row+1][column-1] == Cell::peg && Board[row+2][column-2] == Cell::dot)
					{
						Board[row][column] = Cell::dot;
						Board[row+1][column-1] = Cell::dot;
						Board[row+2][column-2] = Cell::peg;
						number_of_pegs--;
						return;
					}
					break;
			}
		}
		cerr << "You made an invalid move! Try again" << endl;
		return;
	}
}
void PegSolitaire::play()
{
	/*
	THIS FUNCTION DOES ONE MOVE RANDOMLY.
	IT SEARCHES "PEG PEG DOT" TRIO IN EVERY WAY
	IF THERE IS THAT TRIO DOES MOVE,ELSE TRIES AGAIN. 
	*/
	if(boardMode != 6)
	{
		int randomNumber;
		randomNumber = (rand()%4);

		switch (randomNumber) {
			case 0:
				for (int i = 0; i < Board.size(); i++)
				{
					for (int j = 0; j < Board[i].size()-2; j++)
					{
						if (Board[i][j] == Cell::peg && Board[i][j+1] == Cell::peg && Board[i][j+2] == Cell::dot)
						{
							Board[i][j] = Cell::dot;
							Board[i][j+1] = Cell::dot;
							Board[i][j+2] = Cell::peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-R" << endl;
							return;
						}
					}
				}
				play();
				break;

			case 1:
				for (int i = 0; i < Board.size()-2; i++)
				{
					for (int j = 0; j < Board[i].size(); j++)
					{
						if (Board[i][j] == Cell::peg && Board[i+1][j] == Cell::peg && Board[i+2][j] == Cell::dot)
						{
							Board[i][j] = Cell::dot;
							Board[i+1][j] = Cell::dot;
							Board[i+2][j] = Cell::peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-D" << endl;
							return;
						}
					}
				}
				play();
				break;

			case 2:
				for (int i = 0; i < Board.size(); i++)
				{
					for (int j = 2; j < Board[i].size(); j++)
					{
						if (Board[i][j] == Cell::peg && Board[i][j-1] == Cell::peg && Board[i][j-2] == Cell::dot)
						{
							Board[i][j] = Cell::dot;
							Board[i][j-1] = Cell::dot;
							Board[i][j-2] = Cell::peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-L" << endl;
							return;
						}
					}
				}
				play();
				break;

			case 3:
				for (int i = 2; i < Board.size(); i++)
				{
					for (int j = 0; j < Board[i].size(); j++)
					{
						if (Board[i][j] == Cell::peg && Board[i-1][j] == Cell::peg && Board[i-2][j] == Cell::dot)
						{
							Board[i][j] = Cell::dot;
							Board[i-1][j] = Cell::dot;
							Board[i-2][j] = Cell::peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-U" << endl;
							return;
						}
					}
				}
				play();
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
					for (int j = 0; j < Board[i].size()-2; j++)
					{
						if (Board[i][j] == Cell::peg && Board[i][j+2] == Cell::peg && Board[i][j+4] == Cell::dot)
						{
							Board[i][j] = Cell::dot;
							Board[i][j+2] = Cell::dot;
							Board[i][j+4] = Cell::peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-R" << endl;
							return;
						}
					}
				}
				play();
				break;

			case 1:
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < Board[i].size(); j++)
					{
						if (Board[i][j] == Cell::peg && Board[i+1][j+1] == Cell::peg && Board[i+2][j+2] == Cell::dot)
						{
							Board[i][j] = Cell::dot;
							Board[i+1][j+1] = Cell::dot;
							Board[i+2][j+2] = Cell::peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-D" << endl;
							return;
						}
					}
				}
				play();
				break;

			case 2:
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < Board[i].size(); j++)
					{
						if (Board[i][j] == Cell::peg && Board[i+1][j-1] == Cell::peg && Board[i+2][j-2] == Cell::dot)
						{
							Board[i][j] = Cell::dot;
							Board[i+1][j-1] = Cell::dot;
							Board[i+2][j-2] = Cell::peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-D" << endl;
							return;
						}
					}
				}
				play();
				break;

			case 3:
				for (int i = 0; i < 5; i++)
				{
					for (int j = 2; j < Board[i].size(); j++)
					{
						if (Board[i][j] == Cell::peg && Board[i][j-2] == Cell::peg && Board[i][j-4] == Cell::dot)
						{
							Board[i][j] = Cell::dot;
							Board[i][j-2] = Cell::dot;
							Board[i][j-4] = Cell::peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-L" << endl;
							return;
						}
					}
				}
				play();
				break;

			case 4:
				for (int i = 2; i < 5; i++)
				{
					for (int j = 0; j < Board[i].size(); j++)
					{
						if (Board[i][j] == Cell::peg && Board[i-1][j-1] == Cell::peg && Board[i-2][j-2] == Cell::dot)
						{
							Board[i][j] = Cell::dot;
							Board[i-1][j-1] = Cell::dot;
							Board[i-2][j-2] = Cell::peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-U" << endl;
							return;
						}
					}
				}
				play();
				break;

			case 5:
				for (int i = 2; i < 5; i++)
				{
					for (int j = 0; j < Board[i].size(); j++)
					{
						if (Board[i][j] == Cell::peg && Board[i-1][j+1] == Cell::peg && Board[i-2][j+2] == Cell::dot)
						{
							Board[i][j] = Cell::dot;
							Board[i-1][j+1] = Cell::dot;
							Board[i-2][j+2] = Cell::peg;
							cout << "Move made by computer is: " <<(char)((j)+'A') << i << "-U" << endl;
							return;
						}
					}
				}
				play();
				break;
		}
	}
}

void PegSolitaire::playGame()
{
	/*
	COMPUTER GAME FUNCTION.
	GOES TILL THE FINISH.
	*/
	while(isFinished() == false){
		play();	
		printBoard();
	}
}

bool PegSolitaire::isFinished() const
{
	/*
	THIS FUNCTION ACTUALLY SEARCHS FOR "PEG PEG DOT" TRIO IN EVERY WAY.
	IF THERE IS THAT TRIO,RETURNS FALSE. ELSE RETURNS TRUE
	*/
	if(boardMode != 6)
	{

		for (int i = 0; i < Board.size(); i++)
		{
			for (int j = 0; j < Board[i].size()-2; j++)
			{
				if (Board[i][j] == Cell::peg && Board[i][j+1] == Cell::peg && Board[i][j+2] == Cell::dot)
				{
					return false;
				}
			}
		}

		for (int i = 0; i < Board.size()-2; i++)
		{
			for (int j = 0; j < Board[i].size(); j++)
			{
				if (Board[i][j] == Cell::peg && Board[i+1][j] == Cell::peg && Board[i+2][j] == Cell::dot)
				{
					return false;
				}
			}
		}

		for (int i = 0; i < Board.size(); i++)
		{
			for (int j = 2; j < Board[i].size(); j++)
			{
				if (Board[i][j] == Cell::peg && Board[i][j-1] == Cell::peg && Board[i][j-2] == Cell::dot)
				{
					return false;
				}
			}
		}

		for (int i = 2; i < Board.size(); i++)
		{
			for (int j = 0; j < Board[i].size(); j++)
			{
				if (Board[i][j] == Cell::peg && Board[i-1][j] == Cell::peg && Board[i-2][j] == Cell::dot)
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
			for (int j = 0; j < Board[i].size()-2; j++)
			{
				if (Board[i][j] == Cell::peg && Board[i][j+2] == Cell::peg && Board[i][j+4] == Cell::dot)
				{
					return false;
				}
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < Board[i].size(); j++)
			{
				if (Board[i][j] == Cell::peg && Board[i+1][j+1] == Cell::peg && Board[i+2][j+2] == Cell::dot)
				{
					return false;
				}
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < Board[i].size(); j++)
			{
				if (Board[i][j] == Cell::peg && Board[i+1][j-1] == Cell::peg && Board[i+2][j-2] == Cell::dot)
				{
					return false;
				}
			}
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 2; j < Board[i].size(); j++)
			{
				if (Board[i][j] == Cell::peg && Board[i][j-2] == Cell::peg && Board[i][j-4] == Cell::dot)
				{
					return false;
				}
			}
		}

		for (int i = 2; i < 5; i++)
		{
			for (int j = 0; j < Board[i].size(); j++)
			{
				if (Board[i][j] == Cell::peg && Board[i-1][j-1] == Cell::peg && Board[i-2][j-2] == Cell::dot)
				{
					return false;
				}
			}
		}

		for (int i = 2; i < 5; i++)
		{
			for (int j = 0; j < Board[i].size(); j++)
			{
				if (Board[i][j] == Cell::peg && Board[i-1][j+1] == Cell::peg && Board[i-2][j+2] == Cell::dot)
				{
					return false;
				}
			}
		}
		return true;
	}
	return true;	
}


PegSolitaire::PegSolitaire(string filename,int board_selection)
{
	/*
	INITIALIZES BOARD FROM FILE CONSTURCTOR
	*/
	boardMode = 7;
	loadFromFile(filename);
}

PegSolitaire::PegSolitaire(int board_selection)
{
	/*
	NORMAL CONSTRUCTOR
	*/
	setSize(board_selection);
	setShape(board_selection);
}

PegSolitaire::PegSolitaire()
{
	/*
	NO ARGUMENT CONSTRUCTOR.
	AUTOMATICALLY CONSTRUCTS FOR TABLE 6
	CHANGEABLE WHICH TABLE
	*/
	setSize(6);
	setShape(6);
}

void deleteGame(PegSolitaire AllGames[5],int gameNumber,int &game_counter)
{
	/*
	MY ONE AND ONLY GLOBAL FUNCTION 
	*/
	for (int i = gameNumber; i < game_counter; i++)
	{
		AllGames[i] = AllGames[i+1];
	}
	game_counter--;
}

void SolitaireGame(PegSolitaire AllGames[5],int &game_counter)
{
	/*
	This function does everything about the Games. Function does:
	-Play Operations
	-Load and Save operations
	-Prints Stats about the Games
	-Change opened game with other opened Games. Or you can start a New Game with board types 1 to 6.
	-Compare two Games
	*/
	int choice1,choice2,gameNumber = 0,selection;
	string filename;
	while(1)				// GOES TILL END. UNLESS THERE IS NO ACTIVE GAME OR PRESS 9 FOR EXIT
	{
		AllGames[gameNumber].printBoard();		//PRINTS ACTIVE GAME ANND ITS STATS
		AllGames[gameNumber].stats();
		cout << "Press 0 for New Game\nPress 1 for Play\nPress 2 for Save Game\nPress 3 for Load Game from File\nPress 4 for Change Game\nPress 5 for Compare This Game with Other Game\nPress 9 for exit" << endl;
		cin >> choice1;

		switch (choice1) {
			case 1:
				/*
				Play Case
				-Case 1 is play yourself
				-Case 2 is play one random move
				-Case 3 is play by Computer till end
				*/
				cout << "Which way do you prefer?\nPress 1 for play yourself\nPress 2 for one random move\nPress 3 for Computer play" << endl;
				cin >> choice2;
				srand((unsigned)time(0));

				if (choice2 == 1)
				{
					char char1,char2,direction;
					int row,column;
					while(1) 
					{
						cout << "Please make a move" << endl;
						cin >> char1 >> row >> char2 >> direction;
						column = char1 - 'A';
					
						if (column < 0 || column > AllGames[gameNumber].getSize() || row < 0 || row > AllGames[gameNumber].getSize() )
						{
							cerr << "Coordinates are wrong! Try again. " << endl;							//ERROR CHECKINGS
						}
						else if (direction != 'R' && direction != 'D' && direction != 'L' &&direction != 'U')
						{
							cerr << "Directions are wrong! Try again. " << endl;
						}
						else
							break;
					}
					AllGames[gameNumber].play(row,column,direction); //GOES TO MEMBER FUNCTION

					if (AllGames[gameNumber].isFinished() == true)
					{
						deleteGame(AllGames,gameNumber,game_counter);		//CONTROLS ISFINISHED. IF GAME IS FINISHED, DELETE FUNCTION DELETES GAME
						if (game_counter == 0)
						{
							cout << "Congrats. You have finished All the Games. Exiting..." << endl;
							exit(1);
						}
					}
				}
				else if (choice2 == 2)
				{
					AllGames[gameNumber].play();		// MEMBER FUNCTIPN TO RANDOM MOVE
					if (AllGames[gameNumber].isFinished() == true)
					{
						deleteGame(AllGames,gameNumber,game_counter);		//SAME THING
						if (game_counter == 0)
						{
							cout << "Congrats. You have finished All the Games. Exiting..." << endl;
							exit(1);
						}
					}

				}
				else if (choice2 == 3)
				{
					AllGames[gameNumber].playGame();		//GOES TILL END AND DELETES AFTER THAT
						
					deleteGame(AllGames,gameNumber,game_counter);
					if (game_counter == 0)
						{
							cout << "Congrats. You have finished All the Games. Exiting..." << endl;
							exit(1);
						}
				}
				break;

			case 2:
				cout << "Enter a filename" << endl;
				cin >> filename;
				AllGames[gameNumber].saveToFile(filename);		//SAVES TO FILE
				break;

			case 3:
				if (game_counter > 4)		//UP LIMIT IS 5 GAME. IF THERE IS, CANNOT LOAD ANY GAME
				{
					cout << "You have already 5 Unfinished Game. First finish one of them" << endl;
					SolitaireGame(AllGames,game_counter);
				}
				cout << "Enter a filename" << endl;
				cin >> filename;
				AllGames[game_counter].loadFromFile(filename);		//MEMBER FUNCTION FOR LOAD GAME
				gameNumber = game_counter;
				game_counter++;
				break;

			case 4:
				for (int i = 0; i < game_counter; i++)
				{
					cout << "TABLE " << i+1 <<":\n";		//PRINTS ALL GAMES AND WANTS TO ENTER ONE OF THEM FOR CHANGE
					AllGames[i].printBoard();
				}
				cout << "Enter Game Number: ";
				cin >> gameNumber;
				gameNumber-=1;
				break;

			case 5:
				int j;
				for (int i = 0; i < game_counter; i++)
				{
					cout << "TABLE " << i+1 <<":\n";		//PRINTS ALL GAMES AND WANTS TO ENTER ONE OF THEM FOR COMPARE GAMES
					AllGames[i].printBoard();
				}
				cout << "Enter Game Number: ";
				cin >> j;
				j-=1;
				AllGames[j].stats();
				if(AllGames[gameNumber].compareGames(AllGames[j]) == true)
					cout << endl << "This Table has more pegs than the other Table.\n" << endl;
				else
					cout << endl << "Other Table has more pegs than this Table.\n" << endl;
				break;

			case 0:
				if (game_counter > 4)			//IF THERE IS 5 GAME, DONT START NEW ONE
				{
					cout << "You have already 5 Unfinished Game. First finish one of them" << endl;
					SolitaireGame(AllGames,game_counter);
				}
				else {
					cout << "Enter table number 1 to 6: " << endl;
					cin >> selection;
					AllGames[game_counter] = PegSolitaire(selection);
					gameNumber = game_counter;
					game_counter++;

				}
				break;

			case 9:
				exit(1);		//EXITS GAME.
				break;
		}
	}
}

int main()
{
	/*
	I implemented Object Array size 5 for 5 different Games
	Created 3 game board for when customer opens program , they should see an open Game
	I could do operations in main but I sent them to SolitaireGame function for cleaner code.
	 */
	PegSolitaire AllGames[5];
	AllGames[0] = PegSolitaire(4);
	AllGames[1] = PegSolitaire();
	AllGames[2] = PegSolitaire("FILE.txt",7);
	int game_counter = 3;
	SolitaireGame(AllGames,game_counter);
	
	return 0;
}


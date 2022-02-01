#include "PegSolitaire.h"
namespace Atakan{
/*
Derived Class PegSolitaire from BoardGame2D
No parameter constructor only initializes board according to selection number.
I selected 2 but it can be also 1
There is 2 playUser function:
with string-> according to string move,does move and returns
no parameter-> Takes string from user ans goes to playUser with move
playAuto does one move randomly
playAutoAll while is game not ended goes to playAuto and does move.
endGame controls if game is over.
boardScore only returns Score
initialize initializes board according to selections and determines size.
print prints only the board.
*/


	PegSolitaire::PegSolitaire()
	{
		initialize(2);
		srand(time(NULL));
		//playAutoAll();
	}
	void PegSolitaire::playUser(string move)
	{
		 int row = move[0]-'0';		//Some parse operations
		 int column = move[1]-'A';
		 if (move[3] == 'R')		//RIGHT operation
		 {
		 	if (column > size-2)		//Wall operations
		 	{
		 		cout << "Invalid Move. Try Again."<< endl;
		 		return;
		 	}
		 	else{

		 		if (Board[row][column] == 1 && Board[row][column+1] == 1 && Board[row][column+2] == 2)
		 		{
		 			Board[row][column] = 2;		//If move is doable,does the move and decreases Score
		 			Board[row][column+1] = 2;
		 			Board[row][column+2] = 1; 
		 			Score--;
		 		}
		 		else{
		 			cout << "Invalid Move. Try Again."<< endl;
		 			return;
		 		}
		 	}
		 }

		 else if (move[3] == 'D')		//DOWN operation
		 {
		 	if (row > size -2)		//Wall operations
		 	{
		 		cout << "Invalid Move. Try Again."<< endl;
		 		return;
		 	}
		 	else{
		 		if (Board[row][column] == 1 && Board[row+1][column] == 1 && Board[row+2][column] == 2)
		 		{
		 			Board[row][column] = 2;		//If move is doable,does the move and decreases Score
		 			Board[row+1][column] = 2;
		 			Board[row+2][column] = 1; 
		 			Score--;
		 		}
		 		else{
		 			cout << "Invalid Move. Try Again."<< endl;
		 			return;
		 		}
		 	}
		 }

		 else if (move[3] == 'L')		//LEFT operation
		 {
		 	if (column < 2)			//Wall operations
		 	{
		 		cout << "Invalid Move. Try Again."<< endl;
		 		return;
		 	}
		 	else{

		 		if (Board[row][column] == 1 && Board[row][column-1] == 1 && Board[row][column-2] == 2)
		 		{
		 			Board[row][column] = 2;		//If move is doable,does the move and decreases Score
		 			Board[row][column-1] = 2;
		 			Board[row][column-2] = 1; 
		 			Score--;
		 		}
		 		else{
		 			cout << "Invalid Move. Try Again."<< endl;
		 			return;
		 		}
		 	}
		 }

		 else if (move[3] == 'U')		//UP operation
		 {
		 	if (row < 2)			//Wall operations
		 	{
		 		cout << "Invalid Move. Try Again."<< endl;
		 		return;
		 	}
		 	else{
		 		if (Board[row][column] == 1 && Board[row-1][column] == 1 && Board[row-2][column] == 2)
		 		{
		 			Board[row][column] = 2;		//If move is doable,does the move and decreases Score
		 			Board[row-1][column] = 2;
		 			Board[row-2][column] = 1; 
		 			Score--;
		 		}
		 		else{
		 			cout << "Invalid Move. Try Again."<< endl;
		 			return;
		 		}
		 	}
		 }
	}

	void PegSolitaire::playUser()
	{
		string move;
		print();
		while(endGame() == false)
		{
			cout << "Enter your move:(2B-UP example) " << endl;
			cin >> move;
			playUser(move);
			print();
		}
		print();
		cout << "Score is "<< boardScore() << endl;
		
	}

	void PegSolitaire::playAuto()
	{
		int random;
		random = (rand()%4);		//random number for direction. 0 for right,1 for down,2 for left,3 for up
		switch(random){

			// Controls is there any "p p ." trio according to random direction. If there is does move
			case 0:
				for (int i = 0; i < size; i++)
				{
					for (int j = 0; j < size-2; j++)
					{
						if (Board[i][j] == 1 && Board[i][j+1] == 1 && Board[i][j+2] == 2)
						{
							Board[i][j] = 2;
							Board[i][j+1] = 2;
							Board[i][j+2] = 1;
							cout << "move made is"<< i << " " <<(char) ('A' + j) << " RIGHT" << endl;
							Score--;
							return;
						}
					}
				}
				playAuto();
				break;

			case 1:
				for (int i = 0; i < size-2; i++)
				{
					for (int j = 0; j < size; j++)
					{
						if (Board[i][j] == 1 && Board[i+1][j] == 1 && Board[i+2][j] == 2)
						{
							Board[i][j] = 2;
							Board[i+1][j] = 2;
							Board[i+2][j] = 1;
							cout << "move made is"<< i << " " << (char) ('A' + j) << " DOWN" << endl;
							Score--;
							return;
						}
					}
				}
				playAuto();
				break;

			case 2:
				for (int i = 0; i < size; i++)
				{
					for (int j = 2; j < size; j++)
					{
						if (Board[i][j] == 1 && Board[i][j-1] == 1 && Board[i][j-2] == 2)
						{
							Board[i][j] = 2;
							Board[i][j-1] = 2;
							Board[i][j-2] = 1;
							cout << "move made is"<< i << " " <<(char) ('A' + j)  << " LEFT" << endl;
							Score--;
							return;
						}
					}
				}
				playAuto();
				break;

			case 3:
				for (int i = 2; i < size; i++)
				{
					for (int j = 0; j < size; j++)
					{
						if (Board[i][j] == 1 && Board[i-1][j] == 1 && Board[i-2][j] == 2)
						{
							Board[i][j] = 2;
							Board[i-1][j] = 2;
							Board[i-2][j] = 1;
							cout << "move made is"<< i << " " << (char) ('A' + j) << " UP" << endl;
							Score--;
							return;
						}
					}
				}
				playAuto();
				break;
		}
	}

	void PegSolitaire::playAutoAll()
	{
		print();
		while(endGame() == false)
		{
			playAuto();
		}
		print();
		cout << "Score is "<< boardScore() << endl;
	}

	bool PegSolitaire::endGame()
	{
		//If there is"p p ." trio in every way returns false
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size-2; j++)
			{
				if (Board[i][j] == 1 && Board[i][j+1] == 1 && Board[i][j+2] == 2)
				{
					return false;
				}
			}
		}

		for (int i = 0; i < size-2; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (Board[i][j] == 1 && Board[i+1][j] == 1 && Board[i+2][j] == 2)
				{
					return false;
				}
			}
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 2; j < size; j++)
			{
				if (Board[i][j] == 1 && Board[i][j-1] == 1 && Board[i][j-2] == 2)
				{
					return false;
				}
			}
		}

		for (int i = 2; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (Board[i][j] == 1 && Board[i-1][j] == 1 && Board[i-2][j] == 2)
				{
					return false;
				}
			}
		}
		return true;

	}
	int PegSolitaire::boardScore() const
	{
		
		return Score;
	}

	void PegSolitaire::initialize(int selection)
	{
		//Initializes board and size,score
		if (selection == 1)
		{
			Board = {
				{0,0,1,1,1,0,0},
				{0,1,1,1,1,1,0},
				{1,1,1,2,1,1,1},
				{1,1,1,1,1,1,1},
				{1,1,1,1,1,1,1},
				{0,1,1,1,1,1,0},
				{0,0,1,1,1,0,0}};
			size = 7;
			Score = 36;
		}
		else if (selection == 2)
		{
				Board = {
				{0,0,1,1,1,0,0},
				{0,0,1,1,1,0,0},
				{1,1,1,1,1,1,1},
				{1,1,1,2,1,1,1},
				{1,1,1,1,1,1,1},
				{0,0,1,1,1,0,0},
				{0,0,1,1,1,0,0}};
			size = 7;
			Score = 32;
		}
	}	

	void PegSolitaire::print()
	{
		cout << "  ";
		for (char c = 'A'; c < size + 'A'; c++)		
		{
			cout << c << " " ;
		}
		cout << endl;

		for (int i = 0; i < size; i++)
		{
			cout << i << " " ;
			for (int j = 0; j < size; j++)
			{
				if (Board[i][j] == 0)
				{
					cout << " ";
				}
				else if (Board[i][j] == 1)
				{
					cout << "p";
				}
				else if (Board[i][j] == 2)
				{
					cout << ".";
				}
				cout << " ";
			}
			cout << endl;
		}
	}
}
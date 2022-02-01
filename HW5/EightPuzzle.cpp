#include "EightPuzzle.h"
/*
Derived Class EightPuzzle from BoardGame2D
No parameter constructor only initializes board according to selection number.
I selected 1 but it can be also 2
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
namespace Atakan{
	int oldrandom = 4;//Global int.


	EightPuzzle::EightPuzzle()
	{
		initialize(1);
		srand(time(NULL));
		//playUser();

	}

	void EightPuzzle::playUser(string move)
	{
		//This function finds where is blank part of Board. It does move according to user's input
		int iter_x,iter_y;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (Board[i][j] == -1)
				{
					iter_x = i;
					iter_y = j;
				}
			}
		}
		if (move == "RIGHT")
		{
			if (iter_y != 0)	//Some wall operation
			{
				Board[iter_x][iter_y] = Board[iter_x][iter_y-1];
				Board[iter_x][iter_y-1] = -1;
				Score++;
			}
		}
		else if (move == "DOWN")
		{
			if (iter_x != 0)		//Some wall operation
			{
				Board[iter_x][iter_y] = Board[iter_x-1][iter_y];
				Board[iter_x-1][iter_y] = -1;
				Score++;
			}
		}
		else if (move == "LEFT")
		{
			if (iter_y != size-1)		//Some wall operation
			{
				Board[iter_x][iter_y] = Board[iter_x][iter_y+1];
				Board[iter_x][iter_y+1] = -1;
				Score++;
			}
		}
		else if (move == "UP")
		{
			if (iter_x != size-1)		//Some wall operation
			{
				Board[iter_x][iter_y] = Board[iter_x+1][iter_y];
				Board[iter_x+1][iter_y] = -1;
				Score++;
			}
			else
				cout << "Wrong Command.Try Again." << endl;
		}
		else
			cout <<"Please enter RIGHT,DOWN,LEFT or UP" << endl;
	}

	void EightPuzzle::playUser()
	{
		string move;
		print();
		while(endGame() == false)
		{
			cout << "Enter your move:(UP , LEFT examples) "<<endl;
			cin >> move;
			playUser(move);
			print();
		}
		print();
		cout << "Score is "<< boardScore() << endl;
	}

	void EightPuzzle::playAuto()
	{
		//This random part is generates number for directions. After finds the position of blank. So if there is doable move, function does and returns
		int random;
		random = (rand()%4);
		int iter_x,iter_y;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (Board[i][j] == -1)
				{
					iter_x = i;
					iter_y = j;
				}
			}
		}
		if(oldrandom == random)
		{
			return;
		}

		if (Board[0][0] == 1 && Board[0][1] == 2 && Board[0][2] == 3 && iter_x == 1)
		{
			while (random == 1)
			{
				random = (rand()%4);
			}
		}

		if (Board[1][0] == 4 && Board[1][1] == 5 && Board[1][2] == 6 && Board[2][1] == 7 && Board[2][2] == 8)
		{
			while(random == 1 || random == 3)
			{
				random = (rand()%4);
			}
		}
		else if (Board[1][0] == 4 && Board[1][1] == 5 && Board[1][2] == 6 && Board[2][0] == 7 && Board[2][2] == 8)
		{
			while(random == 1 || random == 3)
			{
				random = (rand()%4);
			}
		}
		while((oldrandom==0 && random == 2) || (oldrandom==1 && random == 3) || (oldrandom==2 && random == 4) || (oldrandom==3 && random == 1) || (oldrandom==2 && random == 0))
		{
			random = (rand()%4);
		}

		if (random == 0)
		{
			if (iter_y != 0)
			{
				Board[iter_x][iter_y] = Board[iter_x][iter_y-1];
				Board[iter_x][iter_y-1] = -1;
				Score++;
				oldrandom = random;
			}
		}
		else if (random == 1)
		{
			if (iter_x != 0)
			{
				Board[iter_x][iter_y] = Board[iter_x-1][iter_y];
				Board[iter_x-1][iter_y] = -1;
				Score++;
				oldrandom = random;
			}
		}
		else if (random == 2)
		{
			if (iter_y != size-1)
			{
				Board[iter_x][iter_y] = Board[iter_x][iter_y+1];
				Board[iter_x][iter_y+1] = -1;
				Score++;
				oldrandom = random;
			}
		}
		else if (random == 3)
		{
			if (iter_x != size-1)
			{
				Board[iter_x][iter_y] = Board[iter_x+1][iter_y];
				Board[iter_x+1][iter_y] = -1;
				Score++;
				oldrandom = random;
			}
		}
		
	}

	void EightPuzzle::playAutoAll()
	{
		cout << "Initial Board:"<<endl;
		print();
		while(endGame() == false)
		{
			playAuto();
		}
		print();
		cout << "Score is "<< boardScore() << endl;
	}

	bool EightPuzzle::endGame()
	{
		//If everything in their place, returns true
		if (Board[0][0] == 1 && Board[0][1] == 2 && Board[0][2] == 3 &&
			Board[1][0] == 4 && Board[1][1] == 5 && Board[1][2] == 6 &&
			Board[2][0] == 7 && Board[2][1] == 8 && Board[2][2] == -1){
			return true;
		}
		return false;
	}

	void EightPuzzle::initialize(int selection)
	{
		//There is 2 type of board.
		if (selection == 1)
		{
			Board = {{4,3,2},
	 				{5,8,1},
	 				{6,-1,7}};
	 		size = 3;
	 		Score = 0;
		}
		else if (selection == 2)
		{
			Board = {{8,1,7},
	 				{5,4,-1},
	 				{6,3,2}};
			size = 3;
			Score = 0;
		}
	}

	void EightPuzzle::print()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (Board[i][j] == -1)
				{
					cout << "  " ;
				}
				else
					cout << Board[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	int EightPuzzle::boardScore() const
	{
		return Score;
	}
	
}
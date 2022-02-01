#include "Klotski.h"
/*
Derived Class Klotski from BoardGame2D
No parameter constructor only initializes board according to selection number.
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
	Klotski::Klotski()
	{
		initialize(1);
		srand(time(NULL));
	}
	void Klotski::playUser(string move)
	{
		//Does move according to string
		//Entered coordinates must be left-top of object.For example if vertical rectangle is at(0,0) and (1,0) you must enter for (0,0)
		//If block is 1,which is small square block,It search 1 blank part according to direction. 
		//For block 2,which is vertical rectangle, It search 1 or 2 blank part according to direction
		//For block 3,which is horizontal rectangle,It search 1 or 2 blank part according to direction
		//For block 4,which is big square,It search 2 blank part according to direction
	  	int i = move[0]-'0';
	  	int j = move[1]-'A';
	  	char direction = move[3];
	  
	  	switch(direction)
	  	{
	  	  	case 'R':		//RIGHT operation
	      	if (Board[i][j] == 1 && Board[i][j+1] == 0)
	      	{
	      		Board[i][j+1] = 1;	//IF there is blank(0) does move and returns.
	        	Board[i][j] = 0;
	        	Score++;
	      	}
	      	else if (Board[i][j] == 2 && Board[i][j+1] == 0 && Board[i+1][j+1] == 0)
	      	{
	        	Board[i][j+1] = 2;
	        	Board[i+1][j+1] = 2;
	        	Board[i][j] = 0;
	        	Board[i+1][j] = 0;
	        	Score++;
	      	}
	      	else if (Board[i][j] == 3 && Board[i][j+1] == 3 && Board[i][j+2] == 0)
	      	{
	        	Board[i][j] = 0;
	        	Board[i][j+1] = 3;
	        	Board[i][j+2] = 3;
	        	Score++;
	      	}
	      	else if (Board[i][j] == 4 && Board[i][j+1] == 4 && Board[i+1][j] == 4 && Board[i+1][j+1] == 4 && Board[i][j+1] == 0 && Board[i+1][j+1] == 0)
	      	{
	        	Board[i][j] = 0;
	        	Board[i+1][j] = 0;
	        	Board[i][j+2] = 4;
	        	Board[i+1][j+2] = 4;
	        	Score++;
	      	}
	      	break;

	    case 'D':		//DOWN operation
	      	if (Board[i][j] == 1 && Board[i+1][j] == 0)
	      	{
	        	Board[i+1][j] = 1;
	        	Board[i][j] = 0;
	        	Score++;
	      	}
	      	else if (Board[i][j] == 2 && Board[i+1][j] == 2 && Board[i+2][j] == 0)
	      	{
	        	Board[i][j] = 0;
	        	Board[i+2][j] = 2;
	        	Score++;
	      	}
	      	else if (Board[i][j] == 3 && Board[i][j+1] == 3 && Board[i+1][j] == 0 && Board[i+1][j+1] == 0)
	      	{
	        	Board[i][j] = 0;
	        	Board[i][j+1] = 0;
	        	Board[i+1][j] = 3;
	        	Board[i+1][j+1] = 3;
	        	Score++;
	      	}
	      	else if (Board[i][j] == 4 && Board[i][j+1] == 4 && Board[i+1][j] == 4 && Board[i+1][j+1] == 4 && Board[i+2][j] == 0 && Board[i+2][j+1] == 0)
	      	{
	        	Board[i][j] = 0;
	        	Board[i][j+1] = 0;
	        	Board[i+2][j] = 4;
	        	Board[i+2][j+1] = 4;
	        	Score++;
	      	}
	      	break;

	    case 'L':		//LEFT operation
	      if (Board[i][j] == 1 && Board[i][j-1] == 0)
	      {
	        Board[i][j-1] = 1;
	        Board[i][j] = 0;
	        Score++;
	      }
	      else if (Board[i][j] == 2 && Board[i][j-1] == 0 && Board[i+1][j-1] == 0)
	      {
	        Board[i][j-1] = 2;
	        Board[i+1][j-1] = 2;
	        Board[i][j] = 0;
	        Board[i+1][j] = 0;
	        Score++;
	      }
	      else if (Board[i][j] == 3 && Board[i][j+1] == 3 && Board[i][j-1] == 0)
	      {
	        Board[i][j] = 3;
	        Board[i][j-1] = 3;
	        Board[i][j+1] = 0;
	        Score++;
	      }
	      else if (Board[i][j] == 4 && Board[i][j+1] == 4 && Board[i+1][j] == 4 && Board[i+1][j+1] == 4 && Board[i][j-1] == 0 && Board[i+1][j-1] == 0)
	      {
	        Board[i][j-1] = 4;
	        Board[i+1][j-1] = 4;
	        Board[i][j+1] = 0;
	        Board[i+1][j+1] = 0;
	        Score++;
	      }
	      break;

	    case 'U':		//UP operation
	      if (Board[i][j] == 1 && Board[i-1][j] == 0)
	      {
	        Board[i-1][j] = 1;
	        Board[i][j] = 0;
	        Score++;
	      }
	      else if (Board[i][j] == 2 && Board[i+1][j] == 2 && Board[i-1][j] == 0)
	      {
	        Board[i+1][j] = 0;
	        Board[i-1][j] = 2;
	        Score++;
	      }
	      else if (Board[i][j] == 3 && Board[i][j+1] == 3 && Board[i-1][j] == 0 && Board[i-1][j+1] == 0)
	      {
	        Board[i][j] = 0;
	        Board[i][j+1] = 0;
	        Board[i-1][j] = 3;
	        Board[i-1][j+1] = 3;
	        Score++;
	      }
	      else if (Board[i][j] == 4 && Board[i][j+1] == 4 && Board[i+1][j] == 4 && Board[i+1][j+1] == 4 && Board[i-1][j] == 0 && Board[i-1][j+1] == 0)
	      {
	        Board[i+1][j] = 0;
	        Board[i+1][j+1] = 0;
	        Board[i-1][j] = 4;
	        Board[i-1][j+1] = 4;
	        Score++;
	      }
	      break;
	  }
	}

	void Klotski::playUser()
	{
		string move;
		print();
		while(endGame() == false)
		{
			
			cout << "Enter your move:(2B-UP example.Enter left-top coordinate of object)" << endl;
			cin >> move;
			playUser(move);
			print();
		}
		print();
		cout << "Score is "<< boardScore() << endl;
		
	}
	void Klotski::playAuto()
	{
		/*
		This function is a bit comlicated. First random generate for coordinates.
		And random generates for direction.
		After,checks for walls and blanks.
		If everything is okay,does move.
		There is one logic operation. If big square block gets down,it cancels to go to upside.
		*/
		int i,j;
		i = (rand()%5);
		j = (rand()%4);

		int direction = (rand()%4);

		if (Board[i][j] == 4 && Board[i+1][j] == 4 && Board[i][j+1] == 4 && Board[i+1][j+1] == 4 && Board[i+2][j] == 6 && Board[i+2][j+1] == 6 )
		{
			Board[i+2][j] = 4;
			Board[i+2][j+1] = 4;
			Board[i][j] = 0;
			Board[i][j+1] = 0;
			Score++;
			return;

		}
		
		if ((j == 0 && direction == 2) || (j == 3 && direction == 0) || (i == 0 && direction == 3) || (i == 4 && direction == 1))
		{
			return;
		}

		if (i == 2 && Board[i][j] == 4 && direction == 3)
		{
			return;
		}

		switch(direction)
	  {
	    case 0:
	      if (Board[i][j] == 1 && Board[i][j+1] == 0)
	      {
	        Board[i][j+1] = 1;
	        Board[i][j] = 0;
	        Score++;
	      }
	      else if (Board[i][j] == 2 && Board[i+1][j] == 2 && Board[i][j+1] == 0 && Board[i+1][j+1] == 0)
	      {
	        Board[i][j+1] = 2;
	        Board[i+1][j+1] = 2;
	        Board[i][j] = 0;
	        Board[i+1][j] = 0;
	        Score++;
	      }
	      else if (Board[i][j] == 3 && Board[i][j+1] == 3 && Board[i][j+2] == 0)
	      {
	      	if (j+2 > 3)
	      	{
	      		return;
	      	}
	        Board[i][j] = 0;
	        Board[i][j+1] = 3;
	        Board[i][j+2] = 3;
	        Score++;
	      }
	      else if (Board[i][j] == 4 && Board[i][j+1] == 4 && Board[i+1][j] == 4 && Board[i+1][j+1] == 4 && Board[i][j+2] == 0 && Board[i+1][j+2] == 0)
	      {
	      	if (j+2 > 3)
	      	{
	      		return;
	      	}
	        Board[i][j] = 0;
	        Board[i+1][j] = 0;
	        Board[i][j+2] = 4;
	        Board[i+1][j+2] = 4;
	        Score++;
	      }
	      break;

	    case 1:
	      if (Board[i][j] == 1 && Board[i+1][j] == 0)
	      {
	        Board[i+1][j] = 1;
	        Board[i][j] = 0;
	        Score++;
	      }
	      else if (Board[i][j] == 2 && Board[i+1][j] == 2 && Board[i+2][j] == 0)
	      {
	      	if (i+2>4)
	      	{
	      		return;
	      	}
	        Board[i][j] = 0;
	        Board[i+2][j] = 2;
	        Score++;
	      }
	      else if (Board[i][j] == 3 && Board[i][j+1] == 3 && Board[i+1][j] == 0 && Board[i+1][j+1] == 0)
	      {
	        Board[i][j] = 0;
	        Board[i][j+1] = 0;
	        Board[i+1][j] = 3;
	        Board[i+1][j+1] = 3;
	        Score++;
	      }
	      else if (Board[i][j] == 4 && Board[i][j+1] == 4 && Board[i+1][j] == 4 && Board[i+1][j+1] == 4 && Board[i+2][j] == 0 && Board[i+2][j+1] == 0)
	      {
	      	if ((i == 3 && j == 0)||(i == 3 && j == 2))
	      	{
	      		return;
	      	}
	        Board[i][j] = 0;
	        Board[i][j+1] = 0;
	        Board[i+2][j] = 4;
	        Board[i+2][j+1] = 4;
	        Score++;
	      }
	      break;

	    case 2:
	      if (Board[i][j] == 1 && Board[i][j-1] == 0)
	      {
	        Board[i][j-1] = 1;
	        Board[i][j] = 0;
	        Score++;
	      }
	      else if (Board[i][j] == 2 && Board[i+1][j] == 2 && Board[i][j-1] == 0 && Board[i+1][j-1] == 0)
	      {
	        Board[i][j-1] = 2;
	        Board[i+1][j-1] = 2;
	        Board[i][j] = 0;
	        Board[i+1][j] = 0;
	        Score++;
	      }
	      else if (Board[i][j] == 3 && Board[i][j+1] == 3 && Board[i][j-1] == 0)
	      {
	        Board[i][j] = 3;
	        Board[i][j-1] = 3;
	        Board[i][j+1] = 0;
	        Score++;
	      }
	      else if (Board[i][j] == 4 && Board[i][j+1] == 4 && Board[i+1][j] == 4 && Board[i+1][j+1] == 4 && Board[i][j-1] == 0 && Board[i+1][j-1] == 0)
	      {
	        Board[i][j-1] = 4;
	        Board[i+1][j-1] = 4;
	        Board[i][j+1] = 0;
	        Board[i+1][j+1] = 0;
	        Score++;
	      }
	      break;

	    case 3:
	      if (Board[i][j] == 1 && Board[i-1][j] == 0)
	      {
	        Board[i-1][j] = 1;
	        Board[i][j] = 0;
	        Score++;
	      }
	      else if (Board[i][j] == 2 && Board[i+1][j] == 2 && Board[i-1][j] == 0)
	      {
	        Board[i+1][j] = 0;
	        Board[i-1][j] = 2;
	        Score++;
	      }
	      else if (Board[i][j] == 3 && Board[i][j+1] == 3 && Board[i-1][j] == 0 && Board[i-1][j+1] == 0)
	      {
	        Board[i][j] = 0;
	        Board[i][j+1] = 0;
	        Board[i-1][j] = 3;
	        Board[i-1][j+1] = 3;
	        Score++;
	      }
	      else if (Board[i][j] == 4 && Board[i][j+1] == 4 && Board[i+1][j] == 4 && Board[i+1][j+1] == 4 && Board[i-1][j] == 0 && Board[i-1][j+1] == 0)
	      {
	        Board[i+1][j] = 0;
	        Board[i+1][j+1] = 0;
	        Board[i-1][j] = 4;
	        Board[i-1][j+1] = 4;
	        Score++;
	      }
	      break;
	  }
	}

	void Klotski::playAutoAll()
	{
		print();
		while(endGame() == false)
		{
			//print();
			playAuto();
		}
		print();
		cout << "Score is "<< boardScore() << endl;
	}

	bool Klotski::endGame()
	{
		//If Big Square(number 4) gets to xxxxx side, returns true.
		if (Board[5][1] == 4 && Board[5][2] == 4)
		{
	    	return true;
		}
	  	else
	    	return false;
	}

	int Klotski::boardScore() const
	{
		return Score;
	}

	void Klotski::initialize(int selection)
	{
		//1 is small square
		//2 is vertical rectangle
		//3 is horizontal rectangle
		//4 is big square
		Board.resize(7);
		for (int i = 0; i < 7; i++)
		{
			Board[i].resize(5);
		}
		Board = {
	    {2,4,4,2},{2,4,4,2},{2,3,3,2},{2,1,1,2},{1,0,0,1},{5,6,6,5}
	  };
	  Score = 0;
	  size = 5;
	}

	void Klotski::print()
	{
		//In this function,I select different colors for different objects
		cout << "  ";
		int i, j;
		for (char c = 'A'; c < 4 + 'A'; c++)
		{
			cout << "  "<< c;
		}
		cout << endl;
		for (i = 0; i < 6; i++) 
		{
		    cout << "  "<< i;
		    for (j = 0; j < 4; j++) 
		    {
			    if (Board[i][j] == 1)
			    {
			        cout << "\033[1;41m   \033[0m";
			    }
			    else if (Board[i][j] == 2)
			    {
			        cout << "\033[1;43m   \033[0m";
			    }
			    else if (Board[i][j] == 3)
			    {
			        cout << "\033[1;44m   \033[0m";
			    }
			    else if (Board[i][j] == 4)
			    {
			        cout << "\033[1;45m   \033[0m";
			    }
			    else if (Board[i][j] == 0)
			    {
			        cout << "\033[1;40m   \033[0m";
			    }
			    else if (Board[i][j] == 5)
			    {
			        cout << "   ";
			    }
			    else if (Board[i][j] == 6)
			    {
			        cout << "\033[1;5mxxx\033[0m";
			    }
			}
		    cout << endl;
		}
	}
}
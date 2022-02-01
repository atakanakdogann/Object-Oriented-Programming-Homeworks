#include "BoardGame2D.h"
/*
There is some member functions and static int initializaiton
ActiveGames is static int and keeps track of how many games do we have
operator << is printing details about games
playVector takes vector of BoardGame2D* and plays automatically.
No argument constructor is prints message and adds 1 to active games number
*/
namespace Atakan{
	int BoardGame2D::ActiveGames = 0;

	ostream& operator<<(ostream& output,const BoardGame2D& Object)
	{
		output << "Game number is:" << " "//Object.ActiveGames << endl
			   << "Game ended. WELL DONE!" << endl
			   << "Score of the Game is: " << Object.boardScore() << endl;
		return output;
	}

	void BoardGame2D::playVector(vector<BoardGame2D*> allGames)
	{
		for (int i = 0; i < ActiveGames; i++)
		{
			allGames[i]->playAutoAll();
			cout << endl << endl << endl;
		}
	}

	BoardGame2D::BoardGame2D(){
		cout << "Welcome to Game" << endl;
		ActiveGames++;
	}

	

}
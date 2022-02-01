#include "BoardGame2D.h"
#include "PegSolitaire.h"
#include "EightPuzzle.h"
#include "Klotski.h"

using namespace Atakan;


int main(int argc, char const *argv[])
{

	vector<BoardGame2D*> allGames;
	allGames.push_back(new PegSolitaire());
	//cout << allGames[0] ;
	allGames.push_back(new EightPuzzle());
	//cout << allGames[1] ;
	allGames.push_back(new Klotski());
	//cout << allGames[2] ;
	BoardGame2D::playVector(allGames);


	return 0;
}
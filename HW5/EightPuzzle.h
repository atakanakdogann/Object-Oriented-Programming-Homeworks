#ifndef EIGHTPUZZLE_H_
#define EIGHTPUZZLE_H_

#include "BoardGame2D.h"

/*
Derived Class EightPuzzle from BoardGame2D
There is overrided functions in public
As private I initialized Board,size and Score
size for Board
Score for keep scoring
2D vector for Game
*/

namespace Atakan{
	class EightPuzzle : public BoardGame2D{
	public:
		void playUser(string move)override;
		void playUser()final;
		void playAuto()override;
		void playAutoAll()final;
		bool endGame()override;
		int boardScore()const override;
		//ostream& operator<<(ostream& output,const PegSolitaire& Object);

		EightPuzzle();

		void initialize(int selection)override;
		void print()override;



	private:
		vector<vector<int>> Board;
		int size;
		int Score;

	};
}

#endif
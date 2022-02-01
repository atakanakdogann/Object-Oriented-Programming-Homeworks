#ifndef KLOTSKI_H_
#define KLOTSKI_H_

#include "BoardGame2D.h"

namespace Atakan{

/*
Derived Class PegSolitaire from BoardGame2D
There is overrided functions in public
As private I initialized Board,size and Score
size for Board
Score for keep scoring
2D vector for Game
*/
	class Klotski : public BoardGame2D{
	public:
		void playUser(string move)override;
		void playUser()final;
		void playAuto()override;
		void playAutoAll()final;
		bool endGame()override;
		int boardScore()const override;

		Klotski();

		void initialize(int selection)override;
		void print()override;

	private:
		vector<vector<int>> Board;
		int size;
		int Score;

	};
}

#endif
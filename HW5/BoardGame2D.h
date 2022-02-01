#ifndef BOARDGAME2D_H_
#define BOARDGAME2D_H_

/*
Abstract Class and Member Function Definitions
Some of std functions initialized
Some of libraries.
vector for boards
string for move
cstdlib and ctime for random number generation
*/

#include <iostream>
#include <vector>
#include <ostream>
#include <string>
#include <cstdlib>
#include <ctime>

namespace Atakan{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;
	using std::vector;
	using std::ostream;
	class BoardGame2D{
	public:
		virtual void playUser(string move) = 0;
		virtual void playUser() = 0;
		virtual void playAuto() = 0;
		virtual void playAutoAll() = 0;
		virtual bool endGame() = 0;
		virtual int boardScore()const = 0;
		virtual void initialize(int selection) = 0;
		virtual void print() = 0;
		static void playVector(vector<BoardGame2D*> allGames);

		friend ostream& operator<<(ostream& output,const BoardGame2D& Object);

		BoardGame2D();

	protected:
		static int ActiveGames;
	};
}

#endif
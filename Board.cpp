#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>
#include <string.h>
using namespace std;
namespace ariel {
	string Board::read(unsigned int row, unsigned int column, Direction direction,unsigned int length) {
		string answer;
		map <coridnation, char >::iterator it;
		for (unsigned int i = 0; i < length; i++) {
			it = board.find(direction == Direction::Horizontal ? pair<unsigned int, unsigned int>(row, column + i) : pair<unsigned int, unsigned int>(row + i, column));
			if (it == board.end()) {
				answer += "_";
			}
			else {
				answer += it->second;
			}

		}
		return answer;
	}

	void Board::post(unsigned int row, unsigned int column, Direction direction, const string &post) {

		for (unsigned int i = 0; i < post.length(); i++) {
			board[direction == Direction::Horizontal ? pair<unsigned int, unsigned int>(row, column + i) : pair<unsigned int, unsigned int>(row + i, column)] = post[i];
		}
	}

	void Board::show() {
		map <coridnation, char >::iterator it = board.begin();
		unsigned int rowNumber = (it->first).first;
		while (it != board.end())
		{
			if (rowNumber != (it->first).first) {
				cout << endl;
				rowNumber = (it->first).first;
			}
			cout << it->second;
			++it;
		}
	}
}
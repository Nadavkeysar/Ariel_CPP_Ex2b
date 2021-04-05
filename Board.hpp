#ifndef __BOARD_H
#define __BOARD_H
#include <iostream>
#include <string.h>
#include "Direction.hpp"
#include <map>
#include <utility>

#include <vector>
#include <algorithm>
using namespace std;
typedef pair <unsigned int, unsigned int> coridnation;

namespace ariel {
class Board	{

    private:	
    //hi  (4,4) vertical
		map <coridnation, char> board;
                                  

    public:
      void post(unsigned int row, unsigned int column, Direction direction, const std::string &post);
	  string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
      void show();
};

}
#endif
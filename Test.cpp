#include "Board.hpp"
#include "doctest.h"
#include <string>
#include <iostream>
using namespace ariel;



TEST_CASE("TEST EMPTY BOARD")
{
	Board emptyBoard;
	//Horizontal
	CHECK(emptyBoard.read(5, 5, Direction::Horizontal, 0) == "");
	CHECK(emptyBoard.read(0, 0, Direction::Horizontal, 5) == "_____");
	CHECK(emptyBoard.read(0, 2, Direction::Horizontal, 10) == "__________");
	
	//Verical
	CHECK(emptyBoard.read(5, 5, Direction::Vertical, 0) == "");
	CHECK(emptyBoard.read(0, 0, Direction::Vertical, 5) == "_____");
	CHECK(emptyBoard.read(0, 2, Direction::Vertical, 10) == "__________");
}

TEST_CASE("CHECK POST BOARD")
{
	Board postBoard;
	//Horizontal
	CHECK_NOTHROW(postBoard.post(5, 5, Direction::Horizontal, ""));
	CHECK_NOTHROW(postBoard.post(3, 0, Direction::Horizontal, "walla"));
	CHECK_NOTHROW(postBoard.post(2, 0, Direction::Horizontal, "blabla"));
	CHECK_NOTHROW(postBoard.post(1, 0, Direction::Horizontal, "12331"));
	//Verical
	CHECK_NOTHROW(postBoard.post(4, 0, Direction::Vertical, "#12312"));
	CHECK_NOTHROW(postBoard.post(6, 0, Direction::Vertical, "asda"));
	CHECK_NOTHROW(postBoard.post(7, 0, Direction::Vertical, "blablabla"));
	CHECK_NOTHROW(postBoard.post(9, 0, Direction::Vertical, "33333$"));
}

TEST_CASE("CHECK READ BOARD")
{
	Board postBoard;
	CHECK_NOTHROW(postBoard.read(5, 5, Direction::Horizontal, 1));
	CHECK_NOTHROW(postBoard.read(5, 5, Direction::Horizontal, 2));
	CHECK_NOTHROW(postBoard.read(5, 5, Direction::Vertical, 3));
	CHECK_NOTHROW(postBoard.read(5, 5, Direction::Vertical, 4));
	CHECK_NOTHROW(postBoard.read(5, 5, Direction::Vertical, 5));
}

TEST_CASE("CHECK RERWITE POSTS")
{

	Board reWriteBoard;
	CHECK_NOTHROW(reWriteBoard.post(4, 0, Direction::Vertical, "#12312"));
	CHECK_NOTHROW(reWriteBoard.post(4, 0, Direction::Vertical, "asda"));
	CHECK_NOTHROW(reWriteBoard.post(7, 0, Direction::Vertical, "blablabla"));
	CHECK_NOTHROW(reWriteBoard.post(7, 0, Direction::Vertical, "33333$"));

}



TEST_CASE("POST READ TEST")
{
	Board realBoard;
	realBoard.post(4, 0, Direction::Vertical, "#12312");
	CHECK(realBoard.read(4, 0, Direction::Vertical, 6) == "#12312");

	realBoard.post(10, 10, Direction::Horizontal, "test");
	CHECK(realBoard.read(10, 10, Direction::Horizontal, 4) == "test");
	CHECK(realBoard.read(10, 10, Direction::Horizontal, 5) == "test_");

}



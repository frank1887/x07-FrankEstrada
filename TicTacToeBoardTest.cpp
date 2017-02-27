/**
 * Unit Tests for TicTacToeBoard
 **/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
#include <iostream>
#include <string>
using namespace std;

class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, startingOffWithX)
{
	TicTacToeBoard test;
	Piece starting = test.placePiece(0, 0);
	bool actual;
	if(starting == X)
		actual = true;
	else if(starting == O)
		actual = false;
	ASSERT_TRUE(actual);
}

TEST(TicTacToeBoardTest, switchingToO)
{
	TicTacToeBoard test;
	Piece next = test.placePiece(0, 0);
	next = test.placePiece(0, 0);
	bool shouldBeO;
	if(next == O)
		shouldBeO = true;
	else
		shouldBeO = false;
	ASSERT_TRUE(shouldBeO);
}

TEST(TicTacToeBoardTest, rowOutOfBoundsFirstCoordinate)
{
	TicTacToeBoard test;
	Piece place = test.placePiece(3, 2);
	bool shouldBeInvalid;
	if(place == Invalid)
		shouldBeInvalid = true;
	else
		shouldBeInvalid = false;
	ASSERT_TRUE(shouldBeInvalid);
}

TEST(TicTacToeBoardTest, shouldPassClearBoard)
{
	TicTacToeBoard test;
	bool shouldFail;
	test.clearBoard();
	Piece shouldBeBlank = test.getPiece(1,1);
	if(shouldBeBlank == Blank)
		shouldFail = true;
	else
		shouldFail = false;
	ASSERT_TRUE(shouldFail);
}

TEST(TicTacToeBoardTest, shouldFailClearBoard)
{
	TicTacToeBoard test;
	bool shouldFail;
	test.placePiece(1, 2);
	test.clearBoard();
	Piece shouldBeBlank = test.getPiece(1,2);
	if(shouldBeBlank == Blank)
		shouldFail = true;
	else
		shouldFail = false;
	ASSERT_TRUE(shouldFail);
}

TEST(TicTacToeBoardTest, shouldRecognizeOutOfBounds)
{
	TicTacToeBoard test;
	bool shouldFail;
	Piece outOfBounds = test.getPiece(1,3);
	if(outOfBounds == Invalid)
		shouldFail = true;
	else
		shouldFail = false;
	ASSERT_TRUE(shouldFail);
}


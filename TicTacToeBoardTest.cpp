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
/*
TEST(TicTacToeBoardTest, outOfBoundsSecondCoordinate)
{
	TicTacToeBoard test;
	Piece place = test.placePiece(1, 3);
	bool shouldBeInvalid;
	if(place == Invalid)
		shouldBeInvalid = true;
	else
		shouldBeInvalid = false;
	ASSERT_TRUE(shouldBeInvalid);
}

TEST(TicTacToeBoardTest, bothOutOfBounds)
{
	TicTacToeBoard test;
	Piece place = test.placePiece(8, 3);
	bool shouldBeInvalid;
	if(place == Invalid)
		shouldBeInvalid = true;
	else
		shouldBeInvalid = false;
	ASSERT_TRUE(shouldBeInvalid);
}
*/

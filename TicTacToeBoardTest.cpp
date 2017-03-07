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
	ASSERT_EQ(starting, X);
}

TEST(TicTacToeBoardTest, switchingToO)
{
	TicTacToeBoard test;
	Piece next = test.placePiece(0, 0);
	next = test.placePiece(0, 1);
	ASSERT_EQ(next, O);
}

TEST(TicTacToeBoardTest, placePieceRowOutOfBoundsFirstCoordinate)
{
	TicTacToeBoard test;
	Piece place = test.placePiece(3, 2);
	ASSERT_EQ(place, Invalid);
}

TEST(TicTacToeBoardTest, placePieceColOutOfBoundsFirstCoordinate)
{
	TicTacToeBoard test;
	Piece place = test.placePiece(1, 4);
	ASSERT_EQ(place, Invalid);
}

TEST(TicTacToeBoardTest, placePieceNegativeFirstCoordinate)
{
	TicTacToeBoard test;
	Piece place = test.placePiece(-1, 2);
	ASSERT_EQ(place, Invalid);
}

TEST(TicTacToeBoardTest, placePieceNegativeSecondCoordinate)
{
	TicTacToeBoard test;
	Piece place = test.placePiece(1, -2);
	ASSERT_EQ(place, Invalid);
}

TEST(TicTacToeBoardTest, placePieceNegativeBothCoordinates)
{
	TicTacToeBoard test;
	Piece place = test.placePiece(-2, -2);
	ASSERT_EQ(place, Invalid);
}

TEST(TicTacToeBoardTest, bothCoordinatesOutOfBounds)
{
	TicTacToeBoard test;
	Piece outOfBounds = test.getPiece(3,5);
	ASSERT_EQ(outOfBounds, Invalid);
}

TEST(TicTacToeBoardTest, clearBoardLeftTopCorner)
{
	TicTacToeBoard test;
	test.placePiece(0,0);
	test.clearBoard();
	Piece shouldBeBlank = test.getPiece(0,0);
	ASSERT_EQ(shouldBeBlank, Blank);
}

TEST(TicTacToeBoardTest, clearBoardCenter)
{
	TicTacToeBoard test;
	test.placePiece(1,1);
	test.clearBoard();
	Piece shouldBeBlank = test.getPiece(1,1);
	ASSERT_EQ(shouldBeBlank, Blank);
}

TEST(TicTacToeBoardTest, clearBoardRightBottomCorner)
{
	TicTacToeBoard test;
	test.placePiece(2,2);
	test.clearBoard();
	Piece shouldBeBlank = test.getPiece(2,2);
	ASSERT_EQ(shouldBeBlank, Blank);
}

TEST(TicTacToeBoardTest, getPieceBlank)
{
	TicTacToeBoard test;
	Piece shouldBeBlank = test.getPiece(2,1);
	ASSERT_EQ(shouldBeBlank, Blank);
}

TEST(TicTacToeBoardTest, getPieceRowOutOfBounds)
{
	TicTacToeBoard test;
	Piece shouldBeInvalid = test.getPiece(3,1);
	ASSERT_EQ(shouldBeInvalid, Invalid);
}

TEST(TicTacToeBoardTest, getPieceColOutOfBounds)
{
	TicTacToeBoard test;
	Piece shouldBeInvalid = test.getPiece(0,4);
	ASSERT_EQ(shouldBeInvalid, Invalid);
}

TEST(TicTacToeBoardTest, getPieceBothOutOfBounds)
{
	TicTacToeBoard test;
	Piece shouldBeInvalid = test.getPiece(3,4);
	ASSERT_EQ(shouldBeInvalid, Invalid);
}

TEST(TicTacToeBoardTest, xInitialPlacePiece)
{
	TicTacToeBoard test;
	test.placePiece(2,1);
	Piece shouldBeX = test.getPiece(2,1);
	ASSERT_EQ(shouldBeX, X);
}

TEST(TicTacToeBoardTest, OInitialPlacePiece)
{
	TicTacToeBoard test;
	test.placePiece(2,1);
	test.placePiece(2,2);
	Piece shouldBeO = test.getPiece(2,2);
	ASSERT_EQ(shouldBeO, O);
}

TEST(TicTacToeBoardTest, oPlacingPieceOverX)
{
	TicTacToeBoard test;
	Piece shouldBeX = test.placePiece(1,0);
	shouldBeX = test.placePiece(1,0);
	ASSERT_EQ(shouldBeX, X);
}

TEST(TicTacToeBoardTest, xPlacingPieceOverO)
{
	TicTacToeBoard test;
	Piece shouldBeO = test.placePiece(0,0); //X placing on 0,0
	shouldBeO = test.placePiece(1,0); //O placing on 1,0
	shouldBeO = test.placePiece(1,0); //X shouldnt place over O on 1,0
	ASSERT_EQ(shouldBeO, O);
}

TEST(TicTacToeBoardTest, winnerIsInvalid)
{
	TicTacToeBoard test;
	test.placePiece(0,0);
	test.placePiece(1,0);
	test.placePiece(0,1);
	Piece noWinner = test.getWinner();
	ASSERT_EQ(noWinner, Invalid);
}

TEST(TicTacToeBoardTest, winnerIsBlank)
{
	TicTacToeBoard test;
	test.placePiece(0,0); //X
	test.placePiece(0,1); //O
	test.placePiece(0,2); //X
	test.placePiece(1,0); //O
	test.placePiece(1,2); //X
	test.placePiece(1,1); //O
	test.placePiece(2,0); //X
	test.placePiece(2,2); //O
	test.placePiece(2,1); //X
	Piece noWinner = test.getWinner();
	ASSERT_EQ(noWinner, Blank /*X*/);
}

TEST(TicTacToeBoardTest, xWinsAcrossRow0)
{
	TicTacToeBoard test;
	test.placePiece(0,0);
	test.placePiece(2,2);
	test.placePiece(0,1);
	test.placePiece(2,1);
	test.placePiece(0,2);
	test.placePiece(1,1);
	Piece winnerIsX = test.getWinner();	
	ASSERT_EQ(winnerIsX, X);
}

TEST(TicTacToeBoardTest, oWinsAcrossRow0)
{
	TicTacToeBoard test;
	test.placePiece(1,1);
	test.placePiece(0,0);
	test.placePiece(1,1);
	test.placePiece(0,1);
	test.placePiece(1,1);
	test.placePiece(0,2);
	Piece winnerIsO = test.getWinner();	
	ASSERT_EQ(winnerIsO, O);
}

TEST(TicTacToeBoardTest, oWinsAcrossRow1)
{
	TicTacToeBoard test;
	test.placePiece(2,2);
	test.placePiece(1,0);
	test.placePiece(2,2);
	test.placePiece(1,1);
	test.placePiece(2,2);
	test.placePiece(1,2);
	Piece winnerIsO = test.getWinner();	
	ASSERT_EQ(winnerIsO, O);
}

TEST(TicTacToeBoardTest, xWinsAcrossRow2)
{
	TicTacToeBoard test;
	test.placePiece(2,0);
	test.placePiece(1,2);
	test.placePiece(2,1);
	test.placePiece(0,1);
	test.placePiece(2,2);
	Piece winnerIsX = test.getWinner();	
	ASSERT_EQ(winnerIsX, X);
}

TEST(TicTacToeBoardTest, xWinsAcrossDiagonalStaringAt00)
{
	TicTacToeBoard test;
	test.placePiece(0,0);
	test.placePiece(1,2);
	test.placePiece(1,1);
	test.placePiece(2,1);
	test.placePiece(2,2);
	Piece winnerIsX = test.getWinner();	
	ASSERT_EQ(winnerIsX, X);
}

TEST(TicTacToeBoardTest, oWinsAcrossDiagonalStaringAt00)
{
	TicTacToeBoard test;
	test.placePiece(2,1);
	test.placePiece(0,0);
	test.placePiece(2,1);
	test.placePiece(1,1);
	test.placePiece(2,1);
	test.placePiece(2,2);
	Piece winnerIsO = test.getWinner();	
	ASSERT_EQ(winnerIsO, O);
}

TEST(TicTacToeBoardTest, xWinsAcrossDiagonalStaringAt20)
{
	TicTacToeBoard test;
	test.placePiece(2,0);
	test.placePiece(1,2);
	test.placePiece(1,1);
	test.placePiece(2,1);
	test.placePiece(0,2);
	Piece winnerIsX = test.getWinner();	
	ASSERT_EQ(winnerIsX, X);
}

TEST(TicTacToeBoardTest, oWinsAcrossDiagonalStaringAt20)
{
	TicTacToeBoard test;
	test.placePiece(2,1);
	test.placePiece(2,0);
	test.placePiece(2,1);
	test.placePiece(1,1);
	test.placePiece(2,1);
	test.placePiece(0,2);
	Piece winnerIsO = test.getWinner();	
	ASSERT_EQ(winnerIsO, O);
}

TEST(TicTacToeBoardTest, xWinsColumn0)
{
	TicTacToeBoard test;
	test.placePiece(0,0);
	test.placePiece(1,2);
	test.placePiece(1,0);
	test.placePiece(2,1);
	test.placePiece(2,0);
	Piece winnerIsX = test.getWinner();	
	ASSERT_EQ(winnerIsX, X);
}

TEST(TicTacToeBoardTest, oWinsColumn0)
{
	TicTacToeBoard test;
	test.placePiece(2,1);
	test.placePiece(0,0);
	test.placePiece(2,1);
	test.placePiece(1,0);
	test.placePiece(2,1);
	test.placePiece(2,0);
	Piece winnerIsO = test.getWinner();	
	ASSERT_EQ(winnerIsO, O);
}

TEST(TicTacToeBoardTest, xWinsColumn1)
{
	TicTacToeBoard test;
	test.placePiece(0,1);
	test.placePiece(1,2);
	test.placePiece(1,1);
	test.placePiece(2,2);
	test.placePiece(2,1);
	Piece winnerIsX = test.getWinner();	
	ASSERT_EQ(winnerIsX, X);
}

TEST(TicTacToeBoardTest, oWinsColumn2)
{
	TicTacToeBoard test;
	test.placePiece(0,0);
	test.placePiece(0,2);
	test.placePiece(0,0);
	test.placePiece(1,2);
	test.placePiece(0,0);
	test.placePiece(2,2);
	Piece winnerIsO = test.getWinner();	
	ASSERT_EQ(winnerIsO, O);
}


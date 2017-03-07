#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
 **/

//Switches turn member variable to represent whether it's X's or O's turn
void TicTacToeBoard::toggleTurn()
{
	if(turn == X)
		turn = O;
	else
		turn = X;

}

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
	clearBoard();
	turn = X;
}

//Resets each board location to the Blank Piece value
void TicTacToeBoard::clearBoard()
{
	for(int i = 0; i < BOARDSIZE; i++) {
		for(int j = 0; j < BOARDSIZE; j++) {
			board[i][j] = Blank;
		}

	}

}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value
 **/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
	if(row > 2 || column > 2 || row < 0 || column < 0) {
		toggleTurn();
		return Invalid;
	}
	else if(board[row][column] != Blank) {
		toggleTurn();
		return board[row][column];
	}	
	else if(turn == X) {
		toggleTurn();
		board[row][column] = X;
		return X;
	}
	else {
		toggleTurn();
		board[row][column] = O;
		return O;
	}
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
 **/
Piece TicTacToeBoard::getPiece(int row, int column)
{
	if(row > 2 || column > 2 || row < 0 || column < 0)
		return Invalid;
	else
		return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
 **/
Piece TicTacToeBoard::getWinner()
{
	//Check diagonals
	//Diagonal 0,0 -> 1,1 -> 2,2
	if(board[0][0] == X && board[1][1] == X && board[2][2] == X) {
		return X;
	}
	if(board[0][0] == O && board[1][1] == O && board[2][2] == O) {
		return O;
	}

	//Diagonal 2,0 -> 1,1 -> 0, 2
	if(board[2][0] == X && board[1][1] == X && board[0][2] == X) {
		return X;
	}
	if(board[2][0] == O && board[1][1] == O && board[0][2] == O) {
		return O;
	}

	//Check horizontal and vertical
	for(int i = 0, j = 0; i < BOARDSIZE; i++, j++) {
		//Across 0,0 -> 0,1 -> 0,2 
		if(board[i][0] == X && board[i][1] == X && board[i][2] == X) {
			return X;
		}
		else if(board[i][0] == O && board[i][1] == O && board[i][2] == O) {
			return O;
		}
		//Top Down 0,0 -> 1,0 -> 2,0
		else if(board[0][j] == X && board[1][j] == X && board[2][j] == X) {
			return X;
		}
		else if(board[0][j] == O && board[1][j] == O && board[2][j] == O) {
			return O;
		}
	}
	for(int i = 0; i < BOARDSIZE; i++) {
		for(int j = 0; j < BOARDSIZE; j++) {
			if(board[i][j] == Blank) {
				return Invalid;
			}
		}
	}
	return Blank;
}




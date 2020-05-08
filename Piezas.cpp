#include "Piezas.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

char GLOBAL_TURN = 'X';

/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
	board.resize(4);
	for (int i = 0; i < 3; i++)
		board[i].resize(3);

	// for(int row = 2; row >= 0; row--)
	// {
	// 	for(int col = 0; col <= 3; col++)
	// 	{
	// 		cout<<"["<<row<<","<<col<<"]";
	// 	}
	// 	cout<<endl;
	// }




	for(int row = 2; row >= 0; row--)
	{
		for(int col = 0; col <= 3; col++)
		{
			board[row][col] = Blank;
		}
	}

	// for(int row = 2; row >= 0 ; row--)
	// {
	// 	for(int col = 0; col <= 3; col++)
	// 	{
	// 		cout << (char)board[row][col];
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
	for(int row = 2; row >= 0; row--)
	{
		for(int col = 0; col <= 3; col++)
		{
			board[row][col] = Blank;
		}
	}
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
	//out of bounds
	if(column > 3 || column < 0)
	{
		//switch turns on error
		if(GLOBAL_TURN == 'X')
			GLOBAL_TURN = 'O';
		else
			GLOBAL_TURN = 'X';

		return Blank;
	}

	if(board[0][column] == Blank)
	{
		if(GLOBAL_TURN == 'X')
		{
			board[0][column] = X;
			GLOBAL_TURN = 'O';
			return X;
		}
		else if(GLOBAL_TURN == 'O')
		{
			board[0][column] = O;
			GLOBAL_TURN = 'X';
			return O;
		}
	}
	else if(board[1][column] == Blank)
	{
		if(GLOBAL_TURN == 'X')
		{
			board[1][column] = X;
			GLOBAL_TURN = 'O';
			return X;
		}
		else if(GLOBAL_TURN == 'O')
		{
			board[1][column] = O;
			GLOBAL_TURN = 'X';
			return O;
		}
	}
	else if(board[2][column] == Blank)
	{
		if(GLOBAL_TURN == 'X')
		{
			board[2][column] = X;
			GLOBAL_TURN = 'O';
			return X;
		}
		else if(GLOBAL_TURN == 'O')
		{
			board[2][column] = O;
			GLOBAL_TURN = 'X';
			return O;
		}
	}
	else //column is full
	{
		//switch turns on error
		if(GLOBAL_TURN == 'X')
			GLOBAL_TURN = 'O';
		else
			GLOBAL_TURN = 'X';

		return Blank;
	}
	return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
	//bounds checking
	if(row > 2 || row < 0)
		return Invalid;
	if(column > 3 || column < 0)
		return Invalid;

	if(board[row][column] == Blank)
    	return Blank;

    // cout<<board[row][column];
    return (Piece)board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{

	// print out the board
	// for(int row = 2; row >= 0 ; row--)
	// {
	// 	for(int col = 0; col <= 3; col++)
	// 	{
	// 		cout << (char)board[row][col];
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;



	//board not filled. return invalid
	for(int row = 2; row >= 0 ; row--)
	{
		for(int col = 0; col <= 3; col++)
		{
			if((char)board[row][col] != X || (char)board[row][col] != O)
			{
				return Invalid;
			}
		}
	}

	int xLines = 0;
	int oLines = 0;

	// add up all X lines
	if(board[2][0] == X && board[2][1] == X && board[2][2] == X && board[2][3] == X)
	{
		xLines++;
	}
	if(board[1][0] == X && board[1][1] == X && board[1][2] == X && board[1][3] == X)
	{
		xLines++;
	}
	if(board[0][0] == X && board[0][1] == X && board[0][2] == X && board[0][3] == X)
	{
		xLines++;
	}
	if(board[2][0] == X && board[1][0] == X && board[0][0] == X)
	{
		xLines++;
	}
	if(board[2][1] == X && board[1][1] == X && board[0][1] == X)
	{
		xLines++;
	}
	if(board[2][2] == X && board[1][2] == X && board[0][2] == X)
	{
		xLines++;
	}
	if(board[2][3] == X && board[1][3] == X && board[0][3] == X)
	{
		xLines++;
	}


	// add up all Y lines
	if(board[2][0] == O && board[2][1] == O && board[2][2] == O && board[2][3] == O)
	{
		oLines++;
	}
	if(board[1][0] == O && board[1][1] == O && board[1][2] == O && board[1][3] == O)
	{
		oLines++;
	}
	if(board[0][0] == O && board[0][1] == O && board[0][2] == O && board[0][3] == O)
	{
		oLines++;
	}
	if(board[2][0] == O && board[1][0] == O && board[0][0] == O)
	{
		oLines++;
	}
	if(board[2][1] == O && board[1][1] == O && board[0][1] == O)
	{
		oLines++;
	}
	if(board[2][2] == O && board[1][2] == O && board[0][2] == O)
	{
		oLines++;
	}
	if(board[2][3] == O && board[1][3] == O && board[0][3] == O)
	{
		oLines++;
	}

	// check if X or O has more or equal lines
	if(xLines > oLines)
		return X;
	else if(xLines < oLines)
		return O;
	else
		return Blank;
}


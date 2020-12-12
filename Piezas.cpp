#include "Piezas.h"
#include <vector>
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
	for( int i=0; i<3; i++ )
	{
		for (int j=0; j<4; j++ )
		{
			board[i][j] = Blank;
		}
	}
	turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
	for( int i=0; i<3; i++ )
	{
		for (int j=0; j<4; j++ )
		{
			board[i][j] = Blank;
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
	if( column > 4 )
	{
		if( turn == X )
		{
			turn = O;
		}
		else
		{
			turn = X;
		}
		return Blank;
	}
	else
	{
		for( int i=0; i<3; i++)
		{
			if ( board[i][column] == Blank )
			{
				if( turn == X )
				{
					turn = O;
				}
				else
				{
					turn = X;
				}
				board[i][column] == turn;
				return turn;
			}
		}
	}
    return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
	if( row > 2 or column > 3 )
	{
		return Invalid;
	}
	Piece temp;
	temp = board[row][column];
	return temp;
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
	int x = 0;
	int o = 0;
	int xRow = 0;
	int oRow = 0;
	int xMost = 0;
	int oMost = 0;
	for( int i=0; i<4; i++)
	{
		for( int j=0; j<3; j++)
		{
			if ( board[j][i] == X )
			{
				x++;
			}
			else if ( board[i][j] == O )
			{
				o++;
			}
			else
			{
				return Invalid;
			}
		}
		if( x == 3 )
		{
			return X;
		}
		else if( o == 3 )
		{
			return O;
		}
		else
		{
			x = 0;
			o = 0;
		}
	}
	for( int i=0; i<3; i++)
	{
		for( int j=0; j<4; j++)
		{
			if ( board[i][j] == X )
			{
				x++;
				xRow++;
				if( xRow > xMost )
				{
					xMost = xRow;
				}
				if( xRow == 3 )
				{
					return X;
				}
				oRow = 0;
			}
			else if ( board[i][j] == O )
			{
				o++;
				oRow++;
				if( oRow > oMost )
				{
					oMost = oRow;
				}
				if( oRow == 3 )
				{
					return O;
				}
				xRow = 0;
			}
			else
			{
				return Invalid;
			}
		}	
	}
	if( oMost > xMost )
	{
		return O;
	}
	else if ( xMost > oMost )
	{
		return X;
	}
	else
	{
		return Blank;
	}
}

// Program sets all of an 8 by 8 array to 0, and then, starting in the left most corner, moves
// about the array making only legal moves as a knight would in chess.  Moves are designated in the 
// colMove and rowMove array

#include <iostream>
#include <iomanip>
using namespace std;

//functions
void setToZero(int board[8][8]);
void displayBoard(int oboard[8][8]);
void movingFunction(int board[8][8], int rowMove[8], int colMove[8]);

int main()
{
	// chess board 8x8
	int board[8][8];

	// all of the possible moves of the knight in 2 arrays
	int rowMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int colMove[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

	int row = 0; // starting row
	int col = 0; // starting column
	int newRow = 0; // transition row
	int newCol = 0; // transition column
	int mover = 1; // position # / tracker increase by 1 everytime a new position is found

	// function to set values to 0
	setToZero(board);

	board[row][col] = 1; // starting position in top left set to one

	bool ableToMove = true; // set to true so that while loop always executes

	// function to decide where knight will move
	movingFunction(board, rowMove, colMove);

	// function to display board
	displayBoard(board);

	cin.get();
	cin.get();
	return 0;

}

//function to initialize to zero
	void setToZero(int fboard[8][8])
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			fboard[i][j] = 0;
}

//function to display the board
void displayBoard(int oboard[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			cout << "\t" << oboard[i][j] << " ";
		}
		cout << " " << endl;
	}

}

// function that enables knight to move
void movingFunction(int board[8][8], int rowMove[8], int colMove[8])
{
	int row = 0; // starting row
	int col = 0; // starting column
	int newRow = 0; // transition row
	int newCol = 0; // transition column
	int mover = 1; // position # / tracker increase by 1 everytime a new position is found
	bool ableToMove = true; // set to true so that while loop always 

	while (ableToMove)
	{
		ableToMove = false;

		for (int i = 0; i < 8; i++)
		{
			newRow = row + rowMove[i];
			newCol = col + colMove[i];

			// ensures that knight is staying on the board
			if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8 && board[newRow][newCol] == 0)
			{
				ableToMove = true; // becomes true if able to move
				break;
			}
		}
		if (ableToMove) // if false
		{
			row = newRow;
			col = newCol;
			board[row][col] = ++mover;
		}
	}
}



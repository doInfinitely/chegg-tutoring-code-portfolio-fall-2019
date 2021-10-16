#include <iostream>
using namespace std; 

//functions
void setToZero(int board[8][8]);
void resetHeur(int heur[8][8]);
void displayBoard(int oboard[8][8]);
void movingFunction(int board[8][8], int heur[8][8], int startingRow, int startingCol);

// chess board 8x8
int board[8][8];
int heur[8][8];
int heuristic[8][8] = {{2,3,4,4,4,4,3,2},{3,4,6,6,6,6,4,3},{4,6,8,8,8,8,6,4}
,{4,6,8,8,8,8,6,4},{4,6,8,8,8,8,6,4},{4,6,8,8,8,8,6,4},{3,4,6,6,6,6,4,3}
,{2,3,4,4,4,4,3,2}};

// all of the possible moves of the knight in an 8 by 2 array
int moves[8][2] = { {2,-1}, {1,-2}, {-1,-2}, {-2,-1}, {-2,1}, {-1,2}, {1,2}, {2,1}};
int main()
{

	// function to set values to 0
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			setToZero(board);
			resetHeur(heur);
			board[i][j] = 1; // starting position in top left set to one
			movingFunction(board, heur, i, j);
			displayBoard(board); // function to display board
			cout << endl;
		}
	}


		

	return 0;
}

//function to initialize to zero
void setToZero(int fboard[8][8])
	{
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				fboard[i][j] = 0;
	}

void resetHeur(int heur[8][8])
	{
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				heur[i][j] = heuristic[i][j];
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

void movingFunction(int board[8][8], int heur[8][8], int startingRow, int startingCol)
{
	int row = startingRow; // starting row
	int col = startingCol; // starting column
	int newRow = 0; // transition row
	int newCol = 0; // transition column
	int mover = 1; // position # / tracker increase by 1 everytime a new position is found
	int tempR;
	int tempC;
	while (true) {
		int h = 9;
		for (int i = 0; i < 8; i++) // goes through the 8 by 2 array to check avail. moves
		{
			newRow = row + moves[i][0]; // row increases 
			newCol = col + moves[i][1]; // column increases

			// ensures that knight is staying on the board
			if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8 && board[newRow][newCol] == 0) 
			{
				heur[newRow][newCol]--;
				if (heur[newRow][newCol] < h)
				{
					h = heur[newRow][newCol];
					tempR = newRow;
					tempC = newCol;

				}
			}

		}
		if (h < 9)
		{
			row = tempR;
			col = tempC;
			board[row][col] = ++mover;
		} else
		{
			break;
		}
	}
	if (mover == 64) {
		cout << "full tour!:" << endl;
	}
}

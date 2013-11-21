#include<stdio.h>

static int col;
inline void setboard(int board[][col],int row,int qcol){
	board[row][qcol]=1;
}

inline void unsetboard(int board[][col],int row,int qcol){
	board[row][qcol]=0;
}

int isrowclear(int board[][col],int qrow,int qcol)
{
	int j=0;
	for(j=0;j<qcol;j++)
		if(board[qrow][j]==1)
			return 0;
	return 1;
}

int upperdiagisclear(int board[][col],int qrow,int qcol)
{
	int i, j;
	for (i = qrow,  j= qcol; j >= 0 && i>=0;i--, j--) {
		if (board[i][j]==1)  // there is already a queen along this diagonal!
			return 0;
	}
	return 1;
}
int lowerdiagisclear(int board[][col],int qrow,int qcol)
{ 
	int i, j;
	for (i = qrow, j = qcol; j >= 0 && i< col;i++, j--) {
		if (board[i][j]==1)  // there is already a queen along this diagonal!
			return 0;
	}
	return 1;
}
int issafe(int board[][col], int row, int qcol)
{
	return (lowerdiagisclear(board, row, qcol) &&
			isrowclear(board, row, qcol) &&
			upperdiagisclear(board, row, qcol));
}

int Solve(int board[][col], int qcol)
{
	int rowToTry;
	if (qcol >= col) return 1; // base case
	for (rowToTry = 0; rowToTry < col; rowToTry++)  {
		if (issafe(board, rowToTry, qcol)) {
			setboard(board, rowToTry, qcol);     // try queen here
			if (Solve(board, qcol + 1)) return 1;    // recur to place rest
			unsetboard(board, rowToTry, qcol);     // failed, remove, try again
		}
	}
	return 0;
}

void display_Board(int board[][col])
{
	int i,j;
	for(i=0;i<col;i++){
		for(j=0;j<col;j++){
			if(board[i][j]==1)
				printf(" Q ");
			else
				printf(" _ ");
		}
		printf("\n\n");
	}

}
void init_Board(int board[][col])
{
	int i,j;
	for(i=0;i<col;i++)
		for(j=0;j<col;j++)
			board[i][j]=0;

}

int main(){

	printf("\nEnter the no of column:");
	scanf("%d",&col);
	int board[col][col];
	init_Board(board);
	Solve(board,0);
	display_Board(board);
	getch();

}

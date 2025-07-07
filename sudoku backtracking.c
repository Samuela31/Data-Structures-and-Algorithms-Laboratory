//Sudoku problem
#include<stdio.h>
#include<stdbool.h>
bool issafe(int Sudoku[9][9], int row, int col, int digit){
	int i,j;
	//same digits can't be in same row
	for(j=0;j<9;j++){
		if(Sudoku[row][j]==digit){
			return false;
		}
	}

    //same digits can't be in same column
	for(i=0;i<9;i++){ //in case input is char still we can use by putting '1' and '9' in loop (loops using ASCII values automatically)
		if(Sudoku[i][col]==digit){
			return false;
		}
	}

	int s_row,s_col;
	s_row=row-row%3;
	s_col=col-col%3;

	//same digits can't be in it's 3x3 subgrid
	for(i=s_row;i<=s_row+2;i++){
		for(j=s_col;j<=s_col+2;j++){
			if(Sudoku[i][j]==digit){
				return false;
			}
		}
	}
	return true;
}

void display(int Sudoku[9][9]){
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			printf("%d ",Sudoku[i][j]); //put 0 for empty cells
		}
		printf("\n");
	}
	printf("\n");
}

void solve(int Sudoku[9][9], int row, int col){
	if(row==8 && col==9){ //when we go out of bounds (9th column) in 8th (last) row, our grid is filled fully
		display(Sudoku);
	}
	else{
		if(col==9){ //last column reach, so move to next row and reset column
			col=0;
			row++;
		}
		if(Sudoku[row][col]==0){
			for(int digit=1;digit<=9;digit++){
				if(issafe(Sudoku,row,col,digit)==true)
				{
					Sudoku[row][col]=digit;
					solve(Sudoku,row,col+1);
					Sudoku[row][col]=0; //replace cell with 0 to set it as empty cell again when backtracking
				}
			}
		}
		else{
			solve(Sudoku,row,col+1); //if current cell is not empty, move to next column in same row
		}
	}
}

int main(){

	int Sudoku[9][9]; //sudoku grid is always 9x9
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			scanf("%d",&Sudoku[i][j]);
		}
	}
	printf("\n");
	solve(Sudoku,0,0);
	return 0;
}


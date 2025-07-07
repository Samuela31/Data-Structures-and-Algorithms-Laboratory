//N-Queens problem

#include<stdio.h>
#include<stdbool.h>
bool issafe(int n,char Queen[n][n],int row,int col)
{
    int i,j;
    //checking upper rows
    for(i=row-1;i>=0;i--)
    {
        if(Queen[i][col]=='Q') //no 2 queens can be in same row
        {
            return false;
        }
    }
    //checking left upper diagonal
    for(i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
    {
        if(Queen[i][j]=='Q')
        {
            return false;
        }
    }
    //checking right upper diagonal
    for(i=row-1,j=col+1;i>=0&&j<=n-1;i--,j++)
    {
        if(Queen[i][j]=='Q')
        {
            return false;
        }
    }
    return true;
}
void display(int n,char Queen[n][n])
{
    int i,j;
    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=n-1;j++)
        {
            printf("%c ",Queen[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void solve(int n,int row,char Queen[n][n]) //each row will have 1 queen (n queens in nxn grid) in different columns
{
    if(row==n) //we've reached nth row which means all queens are placed
    {
        display(n,Queen); //function calling
    }
    else
    {
        for(int col=0;col<=n-1;col++) //col = 0
        {
            if(issafe(n,Queen,row,col)==true) //function calling
            {
                Queen[row][col] = 'Q';
                solve(n,row+1,Queen); //recursive call to place queen in next row
                Queen[row][col]='.'; //when backtracking, replace Q with . to denote it as empty cell again
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    char Queen[n][n];
    int i,j;
    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=n-1;j++)
        {
            Queen[i][j]='.'; //initialize board with . to denote empty cell
        }
    }
    solve(n,0,Queen); /// function calling to start placing queens from 0th row
    return 0;
}

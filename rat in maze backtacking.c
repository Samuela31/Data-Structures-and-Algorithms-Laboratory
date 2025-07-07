//Rat in Maze print all unique paths

#include <stdio.h>

void solve(int s_row,int s_col,int n,int m,int maze[n][m])
{ //rat reached maze end, so print path
   if(s_row==n-1&&s_col==m-1)
   {
      int row,col;
      for(row=0 ; row<=n-1 ; row++)
      {
        for(col=0 ; col<=m-1 ; col++)
        {
          printf("%d ",maze[row][col]);
        }
        printf("\n");
      }
      printf("\n");
      return;
   }
   else
   {
       //forward
       int next_row,next_col;
       next_row = s_row;
       next_col = s_col+1;
       if(next_row<=n-1&&next_col<=m-1)//to check if cell coordinates are within maze bounds
       {
          maze[next_row][next_col] = 1; //put 1 in cells where rat visits/moves
          solve(next_row,next_col,n,m,maze); //function call for movement to next cell
       }
      //downward
       next_row=s_row+1;
       next_col=s_col;
        if(next_row<=n-1&&next_col<=m-1)
       {
          maze[next_row][next_col] = 1; //put 1 in cells where rat visits/moves
          solve(next_row,next_col,n,m,maze); //function call for movement to next cell
       }
       //assigning zero when backtracking to mark cell as unvisited for next new path
       maze[s_row][s_col]=0;

   }
}
int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    int maze[N][M];
    int row,col;

    //initialize maze
    for(row=0 ; row<=N-1 ; row++)
    {
        for(col=0 ; col<=M-1 ; col++)
        {
          maze[row][col] = 0;
        }
    }
    maze[0][0] = 1; //rat is at origin
    solve(0,0,N,M,maze); // function calling
    return 0;
}

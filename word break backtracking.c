//Word break

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool solve(int n,int m,char board[n][m],char word[],int row,int col,int ind)
{
   if(ind==strlen(word))
   {
       return true;
   }
   if(row==-1 ||col==-1 || row>=n || col>=m || board[row][col] == '*' || board[row][col]!=word[ind])
   {
       return false;
   }
   else
   {
       char temp = board[row][col] ;
       board[row][col] = '*'; //since same character can't be used, we replace it with * to denote that the character is already used in current path while checking
       bool res=solve(n,m,board,word,row-1,col,ind+1)||
       solve(n,m,board,word,row,col+1,ind+1)||
       solve(n,m,board,word,row+1,col,ind+1)||
       solve(n,m,board,word,row,col-1,ind+1); //we traverse in all allowed directions for each cell in path and return true if string found
       board[row][col]=temp; //replace * with original character when backtracking
       return res;
   }
}
int main()
{
 int n,m;
 scanf("%d %d\n",&n,&m);
 char board[n][m];
 int i,j;
 for(i=0;i<n;i++)
 {
     for(j=0;j<m;j++)
     {
         scanf(" %c",&board[i][j]); //if we put "%c " it expects space at end of each character including last character
     }
 }
 char word[10000];
 scanf("%s",word);

 //check for each cell as string starting position in grid
 for(i=0;i<n;i++)
 {
     for(j=0;j<m;j++)
     {
         if(solve(n,m,board,word,i,j,0)==true) //word found in grid
         {
             printf("True");
             return 0;
         }
     }
 }
 printf("false");
 return 0;
}

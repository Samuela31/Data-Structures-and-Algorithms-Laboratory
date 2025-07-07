//Valid Parenthesis String
#include<stdio.h>
void solve(int n,char parentheses[],int open,int close,int i) //i is current index in generated string
{
    if(open==n && close==n) //when no. of open and close brackets match, our string is complete
    {
         printf("%s\n",parentheses);
    }
    else
    {
        if(open<n) //first put open parenthesis ( since closed parenthesis can't come before it
        {
            parentheses[i]='(';
            solve(n,parentheses,open+1,close,i+1);
        }
        if(open>close) //can use ) in string only if it's count is less than that of (
        {
            parentheses[i]=')';
            solve(n,parentheses,open,close+1,i+1);
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n); //n is no. of valid parenthesis pairs
    char parentheses[2*n+1];
    parentheses[2*n] = '\0';
    parentheses[0]='('; //position 0 of string will always be ( since ) can't come before it in valid parenthesis
    int open=1,close=0;
    solve(n,parentheses,open,close,1); //function calling
    return 0;
}

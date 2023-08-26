#include<stdio.h>
#include<stdlib.h>
char board[20][20];
void printBoard(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int isSafe(int col, int row, int n)
{
    //horizontal
    for(int j=0;j<n;j++)
    {
        if(board[row][j]=='Q')
        return 0;
    }

    //vertical
    for(int i=0;i<n;i++)
    {
        if(board[i][col]=='Q')
        return 0;
    }

    //upper left
    int r=row;
    for(int c=col;c>=0,r>=0;c--,r--)
    {
        if(board[r][c]=='Q')
        return 0;
    }

    //upper right
    r=row;
    for(int c=col;r>=0,c<n;r--,c++)
    {
        if(board[r][c]=='Q')
        return 0;
    }

    //lower left
    r=row;
    for(int c=col;r<n,c>=0;r++,c--)
    {
        if(board[r][c]=='Q')
        return 0;
    }

    //lower right
    r=row;
    for(int c=col;r<n,c<n;r++,c++)
    {
        if(board[r][c]=='Q')
        return 0;
    }
    return 1;
}
void helper(int col, int n)
{
    if(col==n)
    {
        printBoard(n);
        return;
    }
    for(int row=0;row<n;row++)
    {
        if(isSafe(col,row,n)==1)
        {
            board[row][col]='Q';
            helper(col+1,n);
            board[row][col]='.';
        }
    }
}
void main()
{
    int n;
    printf("Enter the size of chess board:\n");
    scanf("%d",&n);
    if(n==2||n==3)
    {
        printf("No solution exists!\n");
        exit(0);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            board[i][j]='.';
        }
    }
    helper(0,n);
    
} 
#include<stdio.h>
void main()
{
    int n,cap;
    printf("Enter the number of items:\n");
    scanf("%d",&n);
    int wt[n],pft[n];
    printf("Enter the weights of %d items:\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&wt[i]);

    }
    printf("Enter the profit of %d items:\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pft[i]);
    }
    printf("Enter the capacity of the sack:\n");
    scanf("%d",&cap);
    int v[n+1][cap+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=cap;j++)
        {
            if(i==0 || j==0)
            v[i][j]=0;
            else if(j<wt[i-1])
            {
                v[i][j]=v[i-1][j];
            }
            else if(j>=wt[i-1])
            {
                if(v[i-1][j]>=(v[i-1][j-wt[i-1]]+pft[i-1]))
                v[i][j]=v[i-1][j];
                else
                v[i][j]=v[i-1][j-wt[i-1]]+pft[i-1];
            }
        }
    }
    printf("The table is:\n");
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=cap;j++)
        {
            printf("%d     ",v[i][j]);
        }
        printf("\n");
    }
    printf("The maximum profit is %d.\n",v[n][cap]);
}
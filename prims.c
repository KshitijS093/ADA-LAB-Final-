#include<stdio.h>
int cost[10][10],vis[10],et[10][10],vt[10],i,j,k,m,sum=0,x=1,e=0,u,v,min,n;
void prims()
{
    vt[x]=1;
    vis[x]=1;
    for(i=1;i<n;i++)
    {
        j=x;
        min=999;
        while(j>0)
        {
            k=vt[j];
            for(m=2;m<=n;m++)
            {
                if(vis[m]==0)
                {
                    if(cost[k][m]<min)
                    {
                        min=cost[k][m];
                        u=k;
                        v=m;
                    }
                }
            }
            j--;
        }
        x++;
        vt[x]=v;
        vis[v]=1;
        et[i][0]=u;
        et[i][1]=v;
        e++;
        sum+=min;
    }
}
void main()
{
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    printf("enter the cost adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    prims();
    printf("Edges of spanning tree:\n");
    for(i=1;i<=e;i++)
    {
        printf("(%d,%d)\n",et[i][0],et[i][1]);
    }
    printf("Weight of minimal spanning tree:%d\n",sum);
}
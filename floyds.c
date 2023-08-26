#include<stdio.h>
void main()
{
   int n,i,j,k;
   printf("Enter the number of vertices:\n");
   scanf("%d",&n);
   int graph[n][n];
   printf("Enter the cost matrix of the graph:\n");
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
         scanf("%d",&graph[i][j]);
      }
   }
   for(k=0;k<n;k++)
   {
      for(i=0;i<n;i++)
      {
         for(j=0;j<n;j++)
         {
            if(graph[i][j]>graph[i][k]+graph[k][j])
            graph[i][j]=graph[i][k]+graph[k][j];
         }
      }
   }
   printf("The floyds matrix is:\n");
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
         printf("%d   ",graph[i][j]);
      }
      printf("\n");
   }

}